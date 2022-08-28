/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2011-2015  Regents of the University of California.
 *
 * This file is part of ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "ndn-ofswitch.hpp"
#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/string.h"
#include "ns3/uinteger.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/callback.h"
#include "ns3/names.h"
#include "ns3/node-list.h"
#include "ns3/channel.h"
#include "ns3/point-to-point-net-device.h"
#include "ns3/ndnSIM/model/ndn-net-device-transport.hpp"
#include "ns3/point-to-point-channel.h"

#include "ns3/ndnSIM/NFD/daemon/fw/forwarder.hpp"

#include "table/pit.hpp"
#include "table/pit-entry.hpp"
#include "table/pit-out-record.hpp"
#include "table/cs.hpp"


#include "fw/forwarder.hpp"

#include "table/name-tree-entry.hpp"
#include "model/ndn-l3-protocol.hpp"
#include "helper/ndn-fib-helper.hpp"
#include "helper/ndn-scenario-helper.hpp"

#include "ns3/ndnSIM/NFD/rib/route.hpp"

#include <memory>
#include <vector>


NS_LOG_COMPONENT_DEFINE("OFSwitch");

namespace ns3 {
namespace ndn {

NS_OBJECT_ENSURE_REGISTERED(OFSwitch);

TypeId
OFSwitch::GetTypeId(void)
{
  static TypeId tid =
    TypeId("OFSwitch")
      .SetGroupName("Ndn")
      .SetParent<App>()
      .AddConstructor<OFSwitch>()
      .AddAttribute("Prefix", "Prefix, for which producer has the data", StringValue("/"),
                    MakeNameAccessor(&OFSwitch::m_prefix), MakeNameChecker())
      .AddAttribute(
         "Postfix",
         "Postfix that is added to the output data (e.g., for adding producer-uniqueness)",
         StringValue("/"), MakeNameAccessor(&OFSwitch::m_postfix), MakeNameChecker())
      .AddAttribute("PayloadSize", "Virtual payload size for Content packets", UintegerValue(1024),
                    MakeUintegerAccessor(&OFSwitch::m_virtualPayloadSize),
                    MakeUintegerChecker<uint32_t>())
      .AddAttribute("Freshness", "Freshness of data packets, if 0, then unlimited freshness",
                    TimeValue(Seconds(0)), MakeTimeAccessor(&OFSwitch::m_freshness),
                    MakeTimeChecker())
      .AddAttribute(
         "Signature",
         "Fake signature, 0 valid signature (default), other values application-specific",
         UintegerValue(0), MakeUintegerAccessor(&OFSwitch::m_signature),
         MakeUintegerChecker<uint32_t>())
      .AddAttribute("KeyLocator",
                    "Name to be used for key locator.  If root, then key locator is not used",
                    NameValue(), MakeNameAccessor(&OFSwitch::m_keyLocator), MakeNameChecker());
  return tid;
}

OFSwitch::OFSwitch()
:m_seq(0)

{
  NS_LOG_FUNCTION_NOARGS();
}

// inherited from Application base class.
void
OFSwitch::StartApplication()
{
  NS_LOG_FUNCTION_NOARGS();
   
  //m_filename="Consumer"+std::to_string(GetNode()->GetId())+".txt";
 m_ofile.open("switch.txt",std::ios::out | std::ios::app);
m_ofile << "Time " <<  ","  << "Size of Data"<< "," << "Content Name" << "\n";
  GetNode()->GetObject<ndn::L3Protocol>()->getForwarder()->getCs().setLimit(10000);
  App::StartApplication();
 temp="";
  FibHelper::AddRoute(GetNode(), m_prefix, m_face, 0);
}

void
OFSwitch::StopApplication()
{
  NS_LOG_FUNCTION_NOARGS();
m_ofile.close();
  App::StopApplication();
}
void
OFSwitch::installPit(int Destnode,int prodNode,std::string pref,int seq){

Ptr<Node> node=ns3::NodeList::GetNode(Destnode);
 std::shared_ptr<ndn::Name> interestPrefix = std::make_shared<ndn::Name>(pref);
  
  interestPrefix->appendSequenceNumber(seq);
  
  std::shared_ptr<ndn::Interest> interest2 = std::make_shared<ndn::Interest>(interestPrefix->toUri());
  
  //Ptr<ndn::ContentStore> cs = node->GetObject<ndn::ContentStore>();
  //auto data=cs->Lookup(interest2);
//  std::cout <<"Data In CS ........................................................"<<data->getName().toUri()<<std::endl;
  
  auto ndn2 = node->GetObject<L3Protocol>();
 
 
for (ndn::Face& face : ndn2->getForwarder()->getFaceTable()) {
      auto transport = dynamic_cast<NetDeviceTransport*>(face.getTransport());
      if (transport == nullptr)
        continue;
      auto p2p = dynamic_cast<PointToPointChannel*>(&(*(transport->GetNetDevice()->GetChannel())));
      for(uint32_t a=0; a<p2p->GetNDevices();a++){
        Ptr<NetDevice> device=p2p->GetDevice(a);
        if(device->GetNode()==GetNode()){
   	
     nfd::Pit& pit=ndn2->getForwarder()->getPit();
    std::shared_ptr<nfd::pit::Entry> pitEntry=pit.insert(*interest2).first;
 /*   if (pitEntry->hasInRecords()){
 pitEntry->clearInRecords();
    }*/
    if((node->GetId())==prodNode){
  ndn2->getForwarder()->startProcessInterest(face,*interest2);

    }

    pitEntry->insertOrUpdateInRecord(face,*interest2)->update(*interest2);  
 //int dnw = ndn::nfd::fw::findDuplicateNonce(*pitEntry, interest2->getNonce(),face);
 m_ofile << "Other : "<<interest2->getName().toUri() << "\n";


  }
      }
      
    }
  







 auto ndn1 = GetNode()->GetObject<L3Protocol>();

   
    for (ndn::Face& face : ndn1->getForwarder()->getFaceTable()) {
      auto transport = dynamic_cast<NetDeviceTransport*>(face.getTransport());
      if (transport == nullptr)
        continue;
      auto p2p = dynamic_cast<PointToPointChannel*>(&(*(transport->GetNetDevice()->GetChannel())));
      for(uint32_t a=0; a<p2p->GetNDevices();a++){
        Ptr<NetDevice> device=p2p->GetDevice(a);
        if(device->GetNode()==node){
       
        
   
for(uint32_t i=0;i<GetNode()->GetNApplications();i++){
    if((GetNode()->GetApplication(i)->GetInstanceTypeId().GetName())=="CustomComsumer2"){
 
    }else{
 
  nfd::Pit& pit=ndn1->getForwarder()->getPit();
    std::shared_ptr<nfd::pit::Entry> pitEntry=pit.insert(*interest2).first;
 
 
  pitEntry->insertOrUpdateOutRecord(face,*interest2)->update(*interest2);
  
  
  
    }
 }
    
 
 
  }
      }
      
    }
  
 

}
void
OFSwitch::OnInterest(shared_ptr<const Interest> interest)
{
  App::OnInterest(interest); // tracing inside

  NS_LOG_FUNCTION(this << interest);

  if (!m_active)
    return;
  
  Name dataName(interest->getName());
 
  if(interest->getCcode()==3){
 std::string path=interest->getCFlow();
 std::cout << "OSSWITCH : " << path<<std::endl;
  std::size_t pos=path.find(":",0);
  std::string pre=path.substr(0,pos);
  std::string strnode=path.substr((pos+1));

  std::string str2=pre;
  std::size_t p=str2.find_last_of('/');
  std::string consumerPrefix=str2.substr(0,p);
  int producer=interest->getPnode();
 // try{
  int destNode=std::stoi(strnode);
  float sec=0;
  for(int i=0;i<=99;i++){
  Simulator::Schedule(Seconds(sec),&OFSwitch::installPit, this,destNode,producer,consumerPrefix,i);
    sec=sec+0.1;
 // }catch(std::invalid_argument const &e){
  //  std::cout << "Invalid Arugment.........."<<std::endl;

 // }
         
if(interest->getCsVal()==0){
  
 Simulator::Schedule(Seconds(0.1),&OFSwitch::delCs,this,pre);
}

  }// end of loop

for(uint32_t i=0;i<GetNode()->GetNApplications();i++){
    if((GetNode()->GetApplication(i)->GetInstanceTypeId().GetName())!="CustomComsumer2"){
 
if(interest->getCsVal()==1){
  
   Simulator::Schedule(Seconds(2),&OFSwitch::SendInterest,this,pre);
 
}  
    }
}

  }// end of controll code

  auto data = make_shared<Data>();
  data->setName(dataName);
  data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));
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
 
  //m_transmittedDatas(data, this, m_face);
  //m_appLink->onReceiveData(*data);



}
void
OFSwitch::SendInterest(std::string prefix)
{
 if (m_seq==0)
 {
   m_seq=(GetNode()->GetId()*100);
 } 
 
  std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>("/Controller");
  
  nameWithSequence->appendSequenceNumber(m_seq);//GetNode()->GetId());
  std::shared_ptr<ndn::Interest> interest = std::make_shared<ndn::Interest>();
  Ptr<UniformRandomVariable> m_rand = CreateObject<UniformRandomVariable>();
  interest->setNonce(m_rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
  interest->setName(*nameWithSequence);
  
  interest->setInterestLifetime(ndn::time::seconds(1));

  interest->setBetw(GetNode()->GetId());
  interest->setPprefix(prefix);
  interest->setCcode(4);

  


  m_seq++;
  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);
 
      



}
void
OFSwitch::contentSend(){
  std::string dataPrefix;
if(GetNode()->GetObject<ndn::L3Protocol>()->getForwarder()->getCs().size()!=0){
  for(const auto cs:GetNode()->GetObject<ndn::L3Protocol>()->getForwarder()->getCs()){
 string ppref=cs.getData().getName().toUri();
   int p=ppref.find("/",1);
  std::string strloc=ppref.substr(1,(p-1));
  if(strloc!="localhost"){
    dataPrefix=cs.getData().getName().toUri();
    
  }// inner if
  
 } /// looop
}// outer if
for(uint32_t i=0;i<GetNode()->GetNApplications();i++){
    if((GetNode()->GetApplication(i)->GetInstanceTypeId().GetName())!="CustomComsumer2"){

if(GetNode()->GetObject<ndn::L3Protocol>()->getForwarder()->getCs().size()!=0){
  
  std::size_t p=dataPrefix.find_last_of('/');
  std::string consumerPrefix=dataPrefix.substr(0,p);
  if(consumerPrefix!=temp){
 //SendInterest(consumerPrefix);
 temp=consumerPrefix;
 
  }
 
}
    } // end of outer if
}// end of outer loop


}
void
OFSwitch::delCs(string pref){
ndn::Name pref2=Name(pref);
GetNode()->GetObject<ndn::L3Protocol>()->getForwarder()->getCs().deleteCs(pref2);
}
void
OFSwitch::OnData(std::shared_ptr<const ndn::Data> data)
{
  ndn::App::OnData(data); 
  std::cout << "OFSwitch: " <<GetNode()->GetId() << " \t Producer Data Name:" << data->getName() << std::endl;
  
}


} // namespace ndn
} // namespace ns3
