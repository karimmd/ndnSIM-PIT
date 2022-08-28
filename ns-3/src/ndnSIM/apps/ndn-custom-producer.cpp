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

#include "ndn-custom-producer.hpp"

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


#include "utils/ndn-ns3-packet-tag.hpp"
#include "utils/ndn-rtt-mean-deviation.hpp"

#include "table/pit.hpp"
#include "table/pit-entry.hpp"
#include "table/name-tree-entry.hpp"


#include <boost/lexical_cast.hpp>
#include <boost/ref.hpp>

NS_LOG_COMPONENT_DEFINE("CustomProducer");

namespace ns3 {
namespace ndn {


// Necessary if you are planning to use ndn::AppHelper
NS_OBJECT_ENSURE_REGISTERED(CustomProducer);

TypeId
CustomProducer::GetTypeId()
{
  static TypeId tid = TypeId("CustomProducer")
  .SetGroupName("Ndn")
  .SetParent<ndn::App>()
  .AddConstructor<CustomProducer>()
      .AddAttribute ("Pprefix","Prefix, for which producer has the data",
                   NameValue ("/"),
                   MakeNameAccessor (&CustomProducer::m_prefix),
                   MakeNameChecker ())
    .AddAttribute ("Postfix", "Postfix that is added to the output data (e.g., for adding producer-uniqueness)",
                   StringValue ("/"),
                   MakeNameAccessor (&CustomProducer::m_postfix),
                   MakeNameChecker ())
    .AddAttribute ("PayloadSize", "Virtual payload size for Content packets",
                   UintegerValue (1024),
                   MakeUintegerAccessor (&CustomProducer::m_virtualPayloadSize),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Freshness", "Freshness of data packets, if 0, then unlimited freshness",
                   TimeValue (Seconds (0.5)),
                   MakeTimeAccessor (&CustomProducer::m_freshness),
                   MakeTimeChecker ())
    .AddAttribute ("Signature", "Fake signature, 0 valid signature (default), other values application-specific",
                   UintegerValue (0),
                   MakeUintegerAccessor (&CustomProducer::m_signature),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("KeyLocator", "Name to be used for key locator.  If root, then key locator is not used",
                   NameValue (),
                   MakeNameAccessor (&CustomProducer::m_keyLocator),
                   MakeNameChecker ())
      .AddAttribute ("Cashing", "Enable or Disable cashing", IntegerValue (0),
                   MakeUintegerAccessor (&CustomProducer::cs_val),
                   MakeUintegerChecker<uint32_t> ())
    ;
  return tid;
}


CustomProducer::CustomProducer()
: cs_val(1)
,i(0)
,j(0)
,controller(true)
{
  NS_LOG_FUNCTION_NOARGS ();
 // m_seq = 0;

}


// inherited from Application base class.
void
CustomProducer::StartApplication()
{
  NS_LOG_FUNCTION_NOARGS();
  App::StartApplication();
  m_seq=GetNode()->GetId()*100;
  // equivalent to setting interest filter for "/prefix" prefix
 /*m_seq=GetNode()->GetId()*100;  
  std::cout << "Start Method" << m_prefix.end() <<std::endl;
   
  std::cout << m_prefix.size() <<std::endl;
  if(m_prefix.size()>1){
  for(auto it=m_prefix.begin();it!=m_prefix.end();it++){
     
     if(it->equals(*m_prefix.begin())){
       pref=it->toUri();
       
     continue;
     }
      std::cout << m_prefix.size() <<std::endl;
      std::cout << "Prefix ........." <<"/"+pref+"/"+it->toUri()<<std::endl;
 Simulator::ScheduleNow(&CustomProducer::SendInterest, this,"/"+pref+"/"+it->toUri()); 
 
ndn::FibHelper::AddRoute(GetNode(), "/"+pref+"/"+it->toUri(), m_face, 0); 
  } // loop end
  } /// end if
  else{
  Simulator::ScheduleNow(&CustomProducer::SendInterest, this,m_prefix.toUri()); 
  }
  */
/*std::vector<string> token_v;
std::string s=m_prefix.toUri();
 size_t start = s.find("/", 0), end=start;

    while (start != std::string::npos){
        // Find next occurence of delimiter
        end = s.find("/", start);
        // Push back the token found into vector
        token_v.push_back(s.substr(start, end-start));
        // Skip all occurences of the delimiter to find new start
        start = s.find_first_not_of("/", end);
    }
    for (std::vector<std::string>::iterator it = token_v.begin() ; it != token_v.end(); ++it)
    std::cout <<  *it << std::endl; */
//  ndn::FibHelper::AddRoute(GetNode(), m_prefix, m_face, 0); 
 // ndn::FibHelper::AddRoute(GetNode(), "/Controller", m_face, 0); 
 for(int i=0;i<=10;i++){
   ndn::FibHelper::AddRoute(GetNode(), "/"+std::to_string(GetNode()->GetId())+"/"+std::to_string(i) , m_face, 0);
  /* for(int j=0;j<=20;j++){
Simulator::ScheduleNow(&CustomProducer::SendInterest, this, "/"+std::to_string(GetNode()->GetId())+"/"+std::to_string(i),j);
   }*/
 }
 ScheduleNextPacket();
}

void
CustomProducer::StopApplication()
{
  NS_LOG_FUNCTION_NOARGS();
  App::StopApplication();
}
void CustomProducer::ScheduleNextPacket()
{
  
 if (controller) {
   
    m_sendEvent = Simulator::ScheduleNow(&CustomProducer::SendInterest, this,"/"+std::to_string(GetNode()->GetId())+"/"+std::to_string(i)+":10"); 
    controller = false;
  }
  else if (!m_sendEvent.IsRunning()){
  
    m_sendEvent = Simulator::Schedule((m_random == 0) ? Seconds(1.0 / 11)
                                                      : Seconds(m_random->GetValue()),
                                      &CustomProducer::SendInterest, this,"/"+std::to_string(GetNode()->GetId())+"/"+std::to_string(i)+":10");
    
 i++;
  }
  
}
void
CustomProducer::SendInterest(std::string prefix)
{
  if (m_seq==0)
 {
   m_seq=(GetNode()->GetId()*100);
 }

 
 
  std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>("/Controller");
  
  nameWithSequence->appendSequenceNumber(m_seq);//GetNode()->GetId());
  //
 std:: cout << "Poducer Sequence....:" << m_seq << std::endl;
 std:: cout << "Poducer Prefix....:" << prefix << std::endl;
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
  interest->setBetw(GetNode()->GetId());
  interest->setPprefix(prefix);
  interest->setCcode(1);
  interest->setCsVal(cs_val);
 // std:: cout << "Poducer Prefix....:" << m_prefix.toUri()<< std::endl;

  


  m_seq++;
  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);
  if(i<=10){
  ScheduleNextPacket();
  }
     



}

void
CustomProducer::OnInterest(std::shared_ptr<const ndn::Interest> interest)
{
  ndn::App::OnInterest(interest); 
  // forward call to perform app-level tracing
  // do nothing else (receive interest from consumer)
  std::cout << "Producer received an interest packet. Name: " << interest->getName() << std::endl;
 // std::cout << "Between Packet:  " << interest->getBetw()<<std::endl;
 // std::cout << "Producer Name:  " << interest->getPprefix()<<std::endl;
  std::cout << " Customer Which Send Request :" << interest->getBetw()<< std::endl;

  NS_LOG_FUNCTION(this << interest);
 
  if (!m_active)
    return;
  
  Name dataName(interest->getName());
 // std::cout << "Getw:" << interest->getBetw() << std::endl;
  // dataName.append(m_postfix);
  // dataName.appendVersion();

  auto data = make_shared<Data>();
  data->setName(dataName);
  data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));
  //data->setBetw(1010);
  data->setContent(make_shared< ::ndn::Buffer>(m_virtualPayloadSize));


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
  auto ndn1 = GetNode()->GetObject<L3Protocol>();
  ndn1->getForwarder()->startProcessData(*m_face,*data);
   
  m_transmittedDatas(data, this, m_face);
  m_appLink->onReceiveData(*data); 
  

 //m_face->sendData(*data);
    
//Try to Print Something Like this
// Source for the Interest Packet {Node-ID,Content Name, TLV Value(Our Own Defined)}

}

void
CustomProducer::OnData(std::shared_ptr<const ndn::Data> data)
{
  ndn::App::OnData(data); 
  std::cout << "Node: " <<GetNode()->GetId() << " \t Producer Data Name:" << data->getName() << std::endl;
 // std::cout << "Producer Sends Panme: " << data->getPprefix() << std::endl;
  
  //std::cout << "SOurce Node for Interest Pact:  " << Names::FindName(GetNode())<<"\n";
  
}



} //  namespace ndn
} //  namespace ns3