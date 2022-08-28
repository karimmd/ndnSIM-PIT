/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 Beijing Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author:  <email@email.com>
 */

#include "ndn-controller-app.hpp"

#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"
#include "ns3/callback.h"
#include "ns3/string.h"
#include "ns3/boolean.h"
#include "ns3/uinteger.h"
#include "ns3/integer.h"
#include "ns3/double.h"

#include "ns3/names.h"

#include "ns3/ndnSIM/model/ndn-control-router.hpp"
#include "utils/ndn-ns3-packet-tag.hpp"
#include "utils/ndn-rtt-mean-deviation.hpp"

#include "ns3/ndnSIM/model/ndn-l3-protocol.hpp"
#include "ns3/ndnSIM/helper/ndn-fib-helper.hpp"
#include "ns3/ndnSIM/model/ndn-net-device-transport.hpp"
 #include "ns3/net-device.h"
 #include "ns3/log.h"
 #include "ns3/assert.h"



#include <boost/ref.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/concept/assert.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "ndn-custom-producer.hpp"
#include <unordered_map>

#include "ns3/ndnSIM/helper/boost-graph-ndn-controller-routing.hpp"

#include <math.h>


NS_LOG_COMPONENT_DEFINE("ControllerApp");

namespace ns3 {
namespace ndn {


// Necessary if you are planning to use ndn::AppHelper
NS_OBJECT_ENSURE_REGISTERED(ControllerApp);

TypeId
ControllerApp::GetTypeId()
{
  static TypeId tid = TypeId("ControllerApp")
  .SetGroupName("Ndn")
  .SetParent<ndn::App>()
  .AddConstructor<ControllerApp>()
      .AddAttribute ("Prefix","Prefix, for which producer has the data",
                   StringValue ("/"),
                   MakeNameAccessor (&ControllerApp::m_prefix),
                   MakeNameChecker ())
    .AddAttribute ("Postfix", "Postfix that is added to the output data (e.g., for adding producer-uniqueness)",
                   StringValue ("/"),
                   MakeNameAccessor (&ControllerApp::m_postfix),
                   MakeNameChecker ())
    .AddAttribute ("PayloadSize", "Virtual payload size for Content packets",
                   UintegerValue (1024),
                   MakeUintegerAccessor (&ControllerApp::m_virtualPayloadSize),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Freshness", "Freshness of data packets, if 0, then unlimited freshness",
                   TimeValue (Seconds (0.5)),
                   MakeTimeAccessor (&ControllerApp::m_freshness),
                   MakeTimeChecker ())
    .AddAttribute ("Signature", "Fake signature, 0 valid signature (default), other values application-specific",
                   UintegerValue (0),
                   MakeUintegerAccessor (&ControllerApp::m_signature),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("KeyLocator", "Name to be used for key locator.  If root, then key locator is not used",
                   NameValue (),
                   MakeNameAccessor (&ControllerApp::m_keyLocator),
                   MakeNameChecker ())
    ;
  return tid;
}


ControllerApp::ControllerApp()
: seq(0)
{
  NS_LOG_FUNCTION_NOARGS ();
  m_seq = 0;

}


// inherited from Application base class.
void
ControllerApp::StartApplication()
{
  NS_LOG_FUNCTION_NOARGS();
  App::StartApplication();
  // equivalent to setting interest filter for "/prefix" prefix
  //Simulator::Schedule(Seconds(0.0), &ControllerApp::SendInterest, this);
//Ptr<CustomProducer> producer = Ptr->GetObject<CustomProducer> (); 
//Ptr<Node> n;
 m_filename="FlowInstallion.txt";//+std::to_string(GetNode()->GetId())+".txt";
 m_ofile.open(m_filename,std::ios::out | std::ios::app);
 NodeContainer nodes=NodeContainer::GetGlobal();
  for(auto node:nodes ){
  for(uint32_t i=0;i<node->GetNApplications();i++){
    if(node->GetApplication(i)->GetNode()==GetNode()){
      
      continue;
      }
  std::cout << Names::FindName(node->GetApplication(i)->GetNode()) << std::endl;
   discoverPath(GetNode(),node);
   
  }
 //  app->GetNode()
  //std::cout << " App Id:" <<node<< std::endl;
   //if(node==app->GetNode()){
    // std::cout << "App" << Names::FindName(app->GetNode()) << std::endl;
   // discoverPath(GetNode(),node);
   // }
  }

     for(auto node:nodes ){
       if(node==GetNode()){
         continue;
       }
ndn::AppHelper app("OFSwitch");
  app.SetPrefix("/"+std::to_string(node->GetId()));   // Prefix Address
  app.Install(node);
std::cout << "Node: "<< Names::FindName(node) << " Prefix" <<"/"+std::to_string(node->GetId()) << std::endl;  
     }
  //discoverPath(GetNode());
 // ndn::FibHelper::AddRoute(GetNode(), m_prefix, m_face, 0); 
  ndn::FibHelper::AddRoute(GetNode(), "/Controller", m_face, 0); 
}

void
ControllerApp::StopApplication()
{
  NS_LOG_FUNCTION_NOARGS();
  m_ofile.close();
  App::StopApplication();
}

void
ControllerApp::SendInterest(std::string pre, int node, int prod,std::string prefsent, int seq, int csStore)
{
  
  std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>(pre);
  nameWithSequence->appendSequenceNumber(seq);
  //

  // shared_ptr<Interest> interest = make_shared<Interest> ();
  std::shared_ptr<ndn::Interest> interest = std::make_shared<ndn::Interest>();
  Ptr<UniformRandomVariable> m_rand = CreateObject<UniformRandomVariable>();
  interest->setNonce(m_rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
  interest->setName(*nameWithSequence);
  
//=========================== Our Custom Defined Field =================

  
  //int cnode=this->GetNode()->GetId();
  //interest->setCNode(cnode);

//====================================================================== 
  
  //ndn::time::milliseconds interestLifeTime(ndn::time::seconds(1));
  interest->setInterestLifetime(ndn::time::seconds(1));

  // NS_LOG_INFO ("Requesting Interest: \n" << *interest);
 
//   interest->setBetw(GetNode()->GetId());
  interest->setPprefix("/Controller");
  interest->setCcode(3);
 interest->setCsVal(csStore); 
 interest->setPnode(prod);
 std::string preurl=prefsent+":"+to_string(node);
 std::cout << " Prefix: " << preurl << std::endl;
  interest->setCFlow(preurl);

  

  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);



}
void ControllerApp::TmCount(std::string pref, int producer){
   for (auto itr = table.find(pref); itr != table.end(); itr++) {
     if(itr->second.first==producer){
       itr->second.second-=1;
      
       if(itr->second.second<=30){
      //  std::cout << "Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
       std::cout << "Erase Content From Main Table ..: Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';

         table.erase(itr);
       } // end of inner if

       std::cout << "Main Table Time ...Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
        }// end of if
   }// end of for loop 
for (auto itr = csTable.find(pref); itr != csTable.end(); itr++) {
     if(itr->second.first==producer){
       itr->second.second-=1;
       if(itr->second.second<=30){
      std::cout << "Erase Content From Content Store Table ..: Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
     csTable.erase(itr);
       } // end of inner if


       std::cout << "COntent Store Time ...Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
        
     }// end of if
}// end of looop
}
void 
ControllerApp::refresh(std::string pref, int producer, int upTime){
   for (auto itr = table.find(pref); itr != table.end(); itr++) {
     if(itr->second.first==producer){
       itr->second.second+=upTime;
       if(itr->second.second<=30){
      //  std::cout << "Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
       std::cout << "Erase Content From Main Table ..: Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';

         table.erase(itr);
       } // end of inner if
       std::cout << "Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
  Simulator::Schedule(Seconds(30),&ControllerApp::TmCount,this,pref,producer);       
     }// end of if
   }// end of for loop 
for (auto itr = csTable.find(pref); itr != csTable.end(); itr++) {
     if(itr->second.first==producer){
       itr->second.second+=upTime;
       if(itr->second.second<=30){
      std::cout << "Erase Content From Content Store Table ..: Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
     csTable.erase(itr);
       } // end of inner if
       std::cout << "Key : " <<itr->first  << '\t' << "Value 1 : "<< itr->second.first <<'\t' << "Value 2 : "<< itr->second.second << '\n';
       Simulator::Schedule(Seconds(30),&ControllerApp::TmCount,this,pref,producer); 
     }// end of if
   }// end of for loop 

  } //end of function



void
ControllerApp::OnInterest(std::shared_ptr<const ndn::Interest> interest)
{
  ndn::App::OnInterest(interest); 
  // forward call to perform app-level tracing
  // do nothing else (receive interest from consumer)
  //std::cout << "Controller received an interest packet. Name: " << interest->getName() << std::endl;
 //std::cout << "Between Packet:  " << interest->getBetw()<<std::endl;
  

  NS_LOG_FUNCTION(this << interest);

  if (!m_active)
    return;
  
  Name dataName(interest->getName());
 if(interest->getCcode()==1){
std::string path=interest->getPprefix();
 std::cout << "Producer : " << path<<std::endl;
  std::size_t pos=path.find(":",0);
  std::string pre=path.substr(0,pos);
  std::string strnode=path.substr((pos+1));
  int producerNode=interest->getBetw();
  int csV=interest->getCsVal();
  try{
  int total=std::stoi(strnode);
 for(int i=0;i<=total;i++){
std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>(pre);
  
  nameWithSequence->appendSequenceNumber(i);//GetNode()->GetId());
  
  table.insert({nameWithSequence->toUri(),{producerNode,40}});
  cs_val.insert({nameWithSequence->toUri(),csV});  
  //refresh(interest->getPprefix(), interest->getBetw(), 10);
  
  std::cout << "Node ID..:" << producerNode << std::endl;
  std::cout << "Producer Name..:  " << nameWithSequence->toUri()<<std::endl;
 // std::cout << "Controll Code..:" << interest->getCcode() << std::endl;
 } //Simulator::Schedule(Seconds(40),&ControllerApp::refresh,this,interest->getPprefix(),interest->getBetw(),0);
  }catch(std::invalid_argument const &e){
    std::cout << "Invalid Arugment.........."<<std::endl;

  }
 
  }
  if(interest->getCcode()==4){
  csTable.insert({interest->getPprefix(),{interest->getBetw(),40}});
  // deleteItem(prefx,prefx.size());
  
  std::cout << "Node ID..:" << interest->getBetw() << std::endl;
  std::cout << "OFSwitch Name........:  " << interest->getPprefix()<<std::endl;
  std::cout << "Controll Code..:" << interest->getCcode() << std::endl;
//Simulator::Schedule(Seconds(40),&ControllerApp::refresh,this,interest->getPprefix(),interest->getBetw(),0);

  }
  if(interest->getCcode()==2){
  // NodeContainer c; 
 /* std::string str2=interest->getPprefix();
  std::size_t p=str2.find_last_of('/');
  std::string consumerPrefix=str2.substr(0,p);
  */

 float flowTm=Simulator::Now().GetMilliSeconds();
 if(flowInst.count(interest->getBetw())==0){
 flowInst.insert({interest->getBetw(),flowTm});
 }else{
   auto update=flowInst.find(interest->getBetw());
   if(update != flowInst.end()){ 
    update->second = flowTm;
   }
 }
 std::string consumerPrefix=interest->getPprefix();
  std::string str2=interest->getPprefix();
  std::size_t p=consumerPrefix.find_last_of('/');
  std::string con2=consumerPrefix.substr(0,p);

  //table.push_back({interest->getPprefix(),interest->getBetw()});
  std::cout << " Controller :" << interest->getName() << std::endl;
  std::cout << "Node ID..:" << interest->getBetw() << std::endl;
  std::cout << "Consumer Name..:  " << interest->getPprefix()<<std::endl;
 //auto it=table.find(interest->getPprefix());
 if(table.count(consumerPrefix)==0 && csTable.count(consumerPrefix)==0 ){
   std::cout << "Content Not Available" << std::endl;
  con2=con2+":0";
  auto data = make_shared<Data>();
  data->setName(dataName);
  data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));
  //data->setBetw(1010);
  data->setContent(make_shared< ::ndn::Buffer>(0));


  Signature signature;
  SignatureInfo signatureInfo(static_cast< ::ndn::tlv::SignatureTypeValue>(255));

  if (m_keyLocator.size() > 0) {
    signatureInfo.setKeyLocator(m_keyLocator);
  }

  signature.setInfo(signatureInfo);
  signature.setValue(::ndn::makeNonNegativeIntegerBlock(::ndn::tlv::SignatureValue, m_signature));

  data->setSignature(signature);
  data->setContentMiss(con2);

  NS_LOG_INFO("node(" << GetNode()->GetId() << ") responding with Data: " << data->getName());

  // to create real wire encoding
  data->wireEncode();

 m_transmittedDatas(data, this, m_face);
 m_appLink->onReceiveData(*data);

 
 }else{
   
  con2=con2+":1";
  auto data = make_shared<Data>();
  data->setName(dataName);
  data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));
  //data->setBetw(1010);
  data->setContent(make_shared< ::ndn::Buffer>(0));


  Signature signature;
  SignatureInfo signatureInfo(static_cast< ::ndn::tlv::SignatureTypeValue>(255));

  if (m_keyLocator.size() > 0) {
    signatureInfo.setKeyLocator(m_keyLocator);
  }

  signature.setInfo(signatureInfo);
  signature.setValue(::ndn::makeNonNegativeIntegerBlock(::ndn::tlv::SignatureValue, m_signature));

  data->setSignature(signature);
  data->setContentMiss(con2);

  NS_LOG_INFO("node(" << GetNode()->GetId() << ") responding with Data: " << data->getName());

  // to create real wire encoding
  data->wireEncode();

 m_transmittedDatas(data, this, m_face);
 m_appLink->onReceiveData(*data);

 int prod=table.find(consumerPrefix)->second.first; // first find prefix from main table
  //std::cout << "Producer Name..:  " << Names::FindName(NodeList::GetNode(prod)) <<std::endl;
 int contentStore=cs_val.find(consumerPrefix)->second; // content is cashable or not
 int distance=1000;
  /*if (consumerTable.count(interest->getBetw())>0){
 for (auto itr = consumerTable.find(interest->getBetw()); itr != consumerTable.end(); itr++) {
     if(itr->second.second!=consumerPrefix){
      std::cout <<"Consumer Prefix : "<< consumerPrefix<<" Deleted Prefix:......................... "<< itr->second.second <<" Consumer : "<< Names::FindName(NodeList::GetNode(itr->first))<<"Producer:"<<Names::FindName(NodeList::GetNode(itr->second.first))<<std::endl;

      consumerTable.erase(interest->getBetw());
         }  
}
 }*/
 
   if(csTable.find(consumerPrefix)!=csTable.end()){ // if entry exist in CS
    prod=csTable.find(consumerPrefix)->second.first; // update producer
    
   }

 if(csTable.count(consumerPrefix)!=0){ 
if(csTable.count(consumerPrefix)>1){
/// search content from CS//////////
  auto it = csTable.equal_range(consumerPrefix); 
  tempTable.clear();
  
    for (auto itr = it.first; itr != it.second; ++itr) { 
        cout << itr->first  << '\t' << itr->second.first << '\n'; 
   Ptr<Node> producer=NodeList::GetNode(itr->second.first);
   Ptr<Node> consumer=NodeList::GetNode(interest->getBetw());
         discoverDistance(consumer,producer);
    } 
    
    auto itrTemp=tempTable.equal_range(interest->getBetw());
        

    for (auto itre = itrTemp.first; itre != itrTemp.second; ++itre) { 
      if(distance>itre->second.second){ // comparing distance
       distance=itre->second.second;
       prod=itre->second.first;
      }
          } // end of loop
    
 } // end of if
 
}// end of cstable outer if which check data is available or not


//Simulator::Schedule(Seconds(1),&ControllerApp::refresh,this,consumerPrefix,prod,1);

//////////////////////////////////////////////////////////////////////////////////
   int consumerNode=interest->getBetw();
   
   Ptr<Node> producer=NodeList::GetNode(prod);
   Ptr<Node> consumer=NodeList::GetNode(consumerNode);
   std::list<pair<Ptr<Node>,Ptr<Node>>> path=calcPath(producer,consumer);
 std::cout << "Producer Name...................................:  " << Names::FindName(producer) <<std::endl;
 //int seq=1;

  for(auto p:path){
    
  
  //cout << " Node 1:" << Names::FindName(p.first) << " Node 2:" << Names::FindName(p.second) << std::endl;
 discoverNode(GetNode(),p.first);
  Simulator::ScheduleNow(&ControllerApp::SendInterest,this, "/"+std::to_string(p.first->GetId()),p.second->GetId(),prod,consumerPrefix,seq,contentStore);
 
  seq++;
 
  }/// end of path for loop
 } //end of else
 //std::cout << "ID 1..:" << producerNode << " Producer Node: " << producer<< std::endl;
 // std::cout << "ID 2..:  " << consumerNode <<" Consumer Node: " << consumer <<std::endl;
  // } // end of if statement
    } // end of control
 
  // dataName.append(m_postfix);
  // dataName.appendVersion();
/*
  auto data = make_shared<Data>();
  data->setName(dataName);
  data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));
  //data->setBetw(1010);
  data->setContent(make_shared< ::ndn::Buffer>(0));


  Signature signature;
  SignatureInfo signatureInfo(static_cast< ::ndn::tlv::SignatureTypeValue>(255));

  if (m_keyLocator.size() > 0) {
    signatureInfo.setKeyLocator(m_keyLocator);
  }

  signature.setInfo(signatureInfo);
  signature.setValue(::ndn::makeNonNegativeIntegerBlock(::ndn::tlv::SignatureValue, m_signature));

  data->setSignature(signature);

  NS_LOG_INFO("node(" << GetNode()->GetId() << ") responding with Data: " << data->getName());

  // to create real wire encoding
  data->wireEncode();
*/
// m_transmittedDatas(data, this, m_face);
 //m_appLink->onReceiveData(*data);

//Try to Print Something Like this
// Source for the Interest Packet {Node-ID,Content Name, TLV Value(Our Own Defined)}

}

void
ControllerApp::OnData(std::shared_ptr<const ndn::Data> data)
{
  ndn::App::OnData(data); 
  std::string str2=data->getName().toUri();
   std::size_t p=str2.find_last_of('/');
  u_int32_t consumerPrefix=std::stoi(str2.substr(1,(p-1)));
 if(flowInst.count(consumerPrefix)>0){ 
   std::unordered_map<int,float>::const_iterator got = flowInst.find(consumerPrefix);
   float tme=got->second;
 std::cout << "CONTROLLER CONSUMER: " << consumerPrefix << std::endl;
  m_ofile << (Simulator::Now().GetMilliSeconds()-tme)<< "\n";
      m_ofile.flush();
  //std::cout << "SOurce Node for Interest Pact:  " << Names::FindName(GetNode())<<"\n";
 }
}

void ControllerApp::findPath(Ptr<Node> node)
   {
     //std::cout <<"Node: " << node->GetId() <<std::endl;
   
     Ptr<ndn::L3Protocol> ndn = node->GetObject<ndn::L3Protocol>();
     //NS_ASSERT_MSG(ndn != 0, "Cannot install GlobalRoutingHelper before Ndn is installed on a node");
   
     Ptr<ndn::ControlRouter> gr = node->GetObject<ndn::ControlRouter>();
     if (gr != 0) {
       //std::cout << "ControlRouter is already installed: " << gr << std::endl;
       //std::cout << "ControlRouter Original Node: " << node << std::endl;
       return; // already installed
     }
   
     gr = CreateObject<ndn::ControlRouter>();
     node->AggregateObject(gr);
   
     for (auto& face : ndn->getForwarder()->getFaceTable()) {
       auto transport = dynamic_cast<ns3::ndn::NetDeviceTransport*>(face.getTransport());
       if (transport == nullptr) {
       //  std::cout << "Skipping non ndnSIM-specific transport face" << std::endl;
         continue;
       }
   
       Ptr<NetDevice> nd = transport->GetNetDevice();
       if (nd == 0) {
         std::cout << "Not a NetDevice associated with an ndnSIM-specific transport instance" << std::endl;
         continue;
       }
   
       Ptr<Channel> ch = nd->GetChannel();
   
       if (ch == 0) {
         std::cout << "Channel is not associated with NetDevice" << std::endl;
         continue;
       }
   
       if (ch->GetNDevices() == 2) // e.g., point-to-point channel
       {
         for (uint32_t deviceId = 0; deviceId < ch->GetNDevices(); deviceId++) {
           Ptr<NetDevice> otherSide = ch->GetDevice(deviceId);
           if (nd == otherSide)
             continue;
   
           Ptr<Node> otherNode = otherSide->GetNode();
           NS_ASSERT(otherNode != 0);
           /////////// my custom code///////////
         //  if(otherNode==GetNode()) continue;

           Ptr<ndn::ControlRouter> otherGr = otherNode->GetObject<ndn::ControlRouter>();
           if (otherGr == 0) {
             findPath(otherNode);
           }
           otherGr = otherNode->GetObject<ndn::ControlRouter>();
           NS_ASSERT(otherGr != 0);
           if(otherGr->GetObject<Node>()!=GetNode())
           gr->AddIncidency(face.shared_from_this(), otherGr);
         }
       }
       else {
         Ptr<ndn::ControlRouter> grChannel = ch->GetObject<ndn::ControlRouter>();
         if (grChannel == 0) {
           findPath(ch);
         }
         grChannel = ch->GetObject<ndn::ControlRouter>();
         if(grChannel->GetObject<Node>()!=GetNode())
         gr->AddIncidency(face.shared_from_this(), grChannel);
       }
     }
   }
   
   void ControllerApp::findPath(Ptr<Channel> channel)
   {
  //   std::cout << "Channel: " << channel->GetId() << std::endl;
   
     Ptr<ndn::ControlRouter> gr = channel->GetObject<ndn::ControlRouter>();
     if (gr != 0)
       return;
   
     gr = CreateObject<ndn::ControlRouter>();
    channel->AggregateObject(gr);
   
     for (uint32_t deviceId = 0; deviceId < channel->GetNDevices(); deviceId++) {
       Ptr<NetDevice> dev = channel->GetDevice(deviceId);
   
       Ptr<Node> node = dev->GetNode();
          /////////// my custom code///////////
           if(node==GetNode()) continue;
       NS_ASSERT(node != 0);
       
       Ptr<ndn::ControlRouter> grOther = node->GetObject<ndn::ControlRouter>();
       if (grOther == 0) {
         findPath(node);
       }
       grOther = node->GetObject<ndn::ControlRouter>();
       NS_ASSERT(grOther != 0);
   if(grOther->GetObject<Node>()!=GetNode())
       gr->AddIncidency(0, grOther);
     }
   }
   
      
  void ControllerApp::findPath(const NodeContainer& nodes)
{
  for (NodeContainer::Iterator node = nodes.Begin(); node != nodes.End(); node++) {
       /////////// my custom code///////////
           if(*node==GetNode()) continue;
    findPath(*node);
    
  }
} 
void ControllerApp::findAll(){
  findPath(NodeContainer::GetGlobal());
}

//////// This method Find Path Between Consumer and Producer ///////////////////////


std::list<pair<Ptr<Node>,Ptr<Node>>>  ControllerApp::calcPath(Ptr<Node> sourceNode,Ptr<Node> destNode){
 // 
 /**
   * Implementation of route calculation is heavily based on Boost Graph Library
   * See http://www.boost.org/doc/libs/1_49_0/libs/graph/doc/table_of_contents.html for more details
   */
//findAll();
  BOOST_CONCEPT_ASSERT((boost::VertexListGraphConcept<boost::NdnControlRouterGraph>));
  BOOST_CONCEPT_ASSERT((boost::IncidenceGraphConcept<boost::NdnControlRouterGraph>));

  boost::NdnControlRouterGraph graph;
 //typedef boost::graph_traits < boost::NdnControlRouterGraph >::vertex_descriptor vertex_descriptor;

  // For now we doing Dijkstra for every node.  Can be replaced with Bellman-Ford or Floyd-Warshall.
  // Other algorithms should be faster, but they need additional EdgeListGraph concept provided by
  // the graph, which
  // is not obviously how implement in an efficient manner
 // for (NodeList::Iterator node = NodeList::Begin(); node != NodeList::End(); node++) {
    
    Ptr<ControlRouter> source = (sourceNode)->GetObject<ControlRouter>();
    //std::cout << "Source:" << Names::FindName(source->GetObject<Node>())<< std::endl;
    boost::DistancesMap distances;
    boost::PredecessorsMap predecessors;
    Ptr<ControlRouter> current = (destNode)->GetObject<ControlRouter>();
    //std::cout << "Target" << Names::FindName(current->GetObject<Node>()) <<std::endl;
   

    dijkstra_shortest_paths(graph, source,
                             predecessor_map (boost::ref(predecessors))
                             .
                            distance_map(boost::ref(distances))
                              .distance_inf(boost::WeightInf)
                              .distance_zero(boost::WeightZero)
                              .distance_compare(boost::WeightCompare())
                              .distance_combine(boost::WeightCombine()));

  
    Ptr<L3Protocol> L3protocol = (source)->GetObject<L3Protocol>();
    shared_ptr<nfd::Forwarder> forwarder = L3protocol->getForwarder();
    std::list<pair<Ptr<Node>,Ptr<Node>>> path;
   Ptr<ControlRouter> node1;
   
           do{
    // nodes.push_back(target);
//std::cout << " Node 1:" << Names::FindName(current->GetObject<Node>()) << std::endl; 
 
///     distances.push_back(d[target]);
    node1=current;
   current = predecessors[current];
 path.push_back(make_pair(node1->GetObject<Node>(),current->GetObject<Node>()));
  // std::cout << " Node 2:" << Names::FindName(current->GetObject<Node>()) << std::endl;
// ndn::FibHelper::AddRoute(node1->GetObject<Node>(),"/Controller",current->GetObject<Node>(),0);
 }while(current != source);
   
 return path;

    }  // end of functon calPath

/////////////////////////////////////////////////////////////////////////////////////////
/// This method Discover Path from all App to Controller to reach through when croller start///////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void ControllerApp::discoverPath(Ptr<Node> controllNode,Ptr<Node> destNode){
 // 
 /**
   * Implementation of route calculation is heavily based on Boost Graph Library
   * See http://www.boost.org/doc/libs/1_49_0/libs/graph/doc/table_of_contents.html for more details
   */
findAll();
  BOOST_CONCEPT_ASSERT((boost::VertexListGraphConcept<boost::NdnControlRouterGraph>));
  BOOST_CONCEPT_ASSERT((boost::IncidenceGraphConcept<boost::NdnControlRouterGraph>));

  boost::NdnControlRouterGraph graph;
  //typedef boost::graph_traits < boost::NdnControlRouterGraph >::vertex_descriptor vertex_descriptor;
 //boost::adjacency_list lt;
  // For now we doing Dijkstra for every node.  Can be replaced with Bellman-Ford or Floyd-Warshall.
  // Other algorithms should be faster, but they need additional EdgeListGraph concept provided by
  // the graph, which
  // is not obviously how implement in an efficient manner
 // for (NodeList::Iterator node = NodeList::Begin(); node != NodeList::End(); node++) {
    
    Ptr<ControlRouter> source = (controllNode)->GetObject<ControlRouter>();
   // std::cout << "Source:" << Names::FindName(source->GetObject<Node>())<< std::endl;
    boost::DistancesMap distances;
    boost::PredecessorsMap predecessors;
    Ptr<ControlRouter> current = (destNode)->GetObject<ControlRouter>();
   //std::cout << "Target" << Names::FindName(current->GetObject<Node>()) <<std::endl;
   
    
    //boost::EdgeWeights weit;
    dijkstra_shortest_paths(graph, source,
                             predecessor_map (boost::ref(predecessors))
                             .
                            distance_map(boost::ref(distances))
                              .distance_inf(boost::WeightInf)
                              .distance_zero(boost::WeightZero)
                              .distance_compare(boost::WeightCompare())
                              .distance_combine(boost::WeightCombine()));

    Ptr<L3Protocol> L3protocol = (source)->GetObject<L3Protocol>();
    shared_ptr<nfd::Forwarder> forwarder = L3protocol->getForwarder();
    
   Ptr<ControlRouter> node1;
   
           do{
    // nodes.push_back(target);
//std::cout << " Node 1:" << Names::FindName(current->GetObject<Node>()) << std::endl; 
///     distances.push_back(d[target]);
    node1=current;
   current = predecessors[current];

  // std::cout << " Node 2:" << Names::FindName(current->GetObject<Node>()) << std::endl;
 ndn::FibHelper::AddRoute(node1->GetObject<Node>(),"/Controller",current->GetObject<Node>(),0);

 }while(current != source);
    }  // end of Function Discover Path
 
 //////////////////// Function To Discover Path whose shortest path is given////////////////
void ControllerApp::discoverNode(Ptr<Node> controllNode,Ptr<Node> destNode){
 // 
 /**
   * Implementation of route calculation is heavily based on Boost Graph Library
   * See http://www.boost.org/doc/libs/1_49_0/libs/graph/doc/table_of_contents.html for more details
   */
//findAll();
  BOOST_CONCEPT_ASSERT((boost::VertexListGraphConcept<boost::NdnControlRouterGraph>));
  BOOST_CONCEPT_ASSERT((boost::IncidenceGraphConcept<boost::NdnControlRouterGraph>));

  boost::NdnControlRouterGraph graph;
  //typedef boost::graph_traits < boost::NdnControlRouterGraph >::vertex_descriptor vertex_descriptor;
 //boost::adjacency_list lt;
  // For now we doing Dijkstra for every node.  Can be replaced with Bellman-Ford or Floyd-Warshall.
  // Other algorithms should be faster, but they need additional EdgeListGraph concept provided by
  // the graph, which
  // is not obviously how implement in an efficient manner
 // for (NodeList::Iterator node = NodeList::Begin(); node != NodeList::End(); node++) {
    
    Ptr<ControlRouter> source = (controllNode)->GetObject<ControlRouter>();
    std::cout << "Source:" << Names::FindName(source->GetObject<Node>())<< std::endl;
    boost::DistancesMap distances;
    boost::PredecessorsMap predecessors;
    Ptr<ControlRouter> current = (destNode)->GetObject<ControlRouter>();
   std::cout << "Target" << Names::FindName(current->GetObject<Node>()) <<std::endl;
   
    
    //boost::EdgeWeights weit;
    dijkstra_shortest_paths(graph, source,
                             predecessor_map (boost::ref(predecessors))
                             .
                            distance_map(boost::ref(distances))
                              .distance_inf(boost::WeightInf)
                              .distance_zero(boost::WeightZero)
                              .distance_compare(boost::WeightCompare())
                              .distance_combine(boost::WeightCombine()));

    Ptr<L3Protocol> L3protocol = (source)->GetObject<L3Protocol>();
    shared_ptr<nfd::Forwarder> forwarder = L3protocol->getForwarder();
    
   Ptr<ControlRouter> node1;
   std::string pref=("/"+std::to_string(destNode->GetObject<Node>()->GetId()));
   
           do{
    // nodes.push_back(target);
 
///     distances.push_back(d[target]);
    node1=current;
   current = predecessors[current];

   std::cout << " Node 1:" << Names::FindName(current->GetObject<Node>()) << std::endl;
   std::cout << " Node 2:" << Names::FindName(node1->GetObject<Node>()) << std::endl;
   std::cout << "/"+std::to_string(destNode->GetObject<Node>()->GetId()) << std::endl;
 ndn::FibHelper::AddRoute(current->GetObject<Node>(),pref,node1->GetObject<Node>(),0);
 }while(current != source);
    }  // end of Function Discover Node

void ControllerApp::discoverDistance(Ptr<Node> sourceNode,Ptr<Node> destNode){
 // 
 /**
   * Implementation of route calculation is heavily based on Boost Graph Library
   * See http://www.boost.org/doc/libs/1_49_0/libs/graph/doc/table_of_contents.html for more details
   */
//findAll();
  BOOST_CONCEPT_ASSERT((boost::VertexListGraphConcept<boost::NdnControlRouterGraph>));
  BOOST_CONCEPT_ASSERT((boost::IncidenceGraphConcept<boost::NdnControlRouterGraph>));

  boost::NdnControlRouterGraph graph;
  //typedef boost::graph_traits < boost::NdnControlRouterGraph >::vertex_descriptor vertex_descriptor;
 //boost::adjacency_list lt;
  // For now we doing Dijkstra for every node.  Can be replaced with Bellman-Ford or Floyd-Warshall.
  // Other algorithms should be faster, but they need additional EdgeListGraph concept provided by
  // the graph, which
  // is not obviously how implement in an efficient manner
 // for (NodeList::Iterator node = NodeList::Begin(); node != NodeList::End(); node++) {
    
    Ptr<ControlRouter> source = (sourceNode)->GetObject<ControlRouter>();
   // std::cout << "Source:" << Names::FindName(source->GetObject<Node>())<< std::endl;
    boost::DistancesMap distances;
    boost::PredecessorsMap predecessors;
    
    Ptr<ControlRouter> current = (destNode)->GetObject<ControlRouter>();
   //std::cout << "Target" << Names::FindName(current->GetObject<Node>()) <<std::endl;
   
    
    //boost::EdgeWeights weit;
    dijkstra_shortest_paths(graph, source,
                             predecessor_map (boost::ref(predecessors))
                             .
                            distance_map(boost::ref(distances))
                              .distance_inf(boost::WeightInf)
                              .distance_zero(boost::WeightZero)
                              .distance_compare(boost::WeightCompare())
                              .distance_combine(boost::WeightCombine()));

    Ptr<L3Protocol> L3protocol = (source)->GetObject<L3Protocol>();
    shared_ptr<nfd::Forwarder> forwarder = L3protocol->getForwarder();
    
   Ptr<ControlRouter> node1;
   int dist=0;
           do{
    // nodes.push_back(target);
//std::cout << " Node 1:" << Names::FindName(current->GetObject<Node>()) << std::endl; 
///     distances.push_back(d[target]);
   dist++;
    node1=current;
   current = predecessors[current];
   

 }while(current != source);
  tempTable.insert({sourceNode->GetId(),{destNode->GetId(), dist}});
  std::cout << "Distance...............: " << dist<<std::endl;
  
    }  // end of Function Discover Path
 


} //  namespace ndn
} //  namespace ns3
