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

#include "ndn-custom-consumer2.hpp"
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

///////////////////////////////////////////
#include "ns3/ndnSIM/helper/ndn-fib-helper.hpp"

/////////////////////////////////////////////
#include "table/pit.hpp"
#include "table/pit-entry.hpp"
#include "table/pit-out-record.hpp"
#include "table/cs.hpp"


#include "fw/forwarder.hpp"

#include "table/name-tree-entry.hpp"
#include "model/ndn-l3-protocol.hpp"
#include <iostream>
#include "stdlib.h"
#include <ctime>


NS_LOG_COMPONENT_DEFINE("CustomConsumer2");

namespace ns3 {
namespace ndn {

NS_OBJECT_ENSURE_REGISTERED(CustomConsumer2);

TypeId
CustomConsumer2::GetTypeId(void)
{
  static TypeId tid =
    TypeId("CustomConsumer2")
      .SetGroupName("Ndn")
      .SetParent<Consumer>()
      .AddConstructor<CustomConsumer2>()
      
      .AddAttribute("Frequency", "Frequency of interest packets", StringValue("1.0"),
                    MakeDoubleAccessor(&CustomConsumer2::m_frequency), MakeDoubleChecker<double>())

      .AddAttribute("Randomize",
                    "Type of send time randomization: none (default), uniform, exponential",
                    StringValue("none"),
                    MakeStringAccessor(&CustomConsumer2::SetRandomize, &CustomConsumer2::GetRandomize),
                    MakeStringChecker())

      .AddAttribute("MaxSeq", "Maximum sequence number to request",
                    IntegerValue(std::numeric_limits<uint32_t>::max()),
                    MakeIntegerAccessor(&CustomConsumer2::m_seqMax), MakeIntegerChecker<uint32_t>())

    ;

  return tid;
}

CustomConsumer2::CustomConsumer2()
  : m_frequency(1.0)
  , m_firstTime(false)
  , controller(true)
  , m_seq(0)
  , i(0)
  , prod{501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,57,58,519,520}
  , p(0)
  , clear(0)
{
  NS_LOG_FUNCTION_NOARGS();
  m_seqMax = std::numeric_limits<uint32_t>::max();
//  m_seq=(GetNode()->GetId()) * 100;

}

CustomConsumer2::~CustomConsumer2()
{
}

void
CustomConsumer2::StartApplication() // Called at time specified by Start
{
  NS_LOG_FUNCTION_NOARGS();
  m_filename="Consumer.txt";//+std::to_string(GetNode()->GetId())+".txt";
 m_ofile.open(m_filename,std::ios::out | std::ios::app);
//m_ofile << "Time " <<  ","  << "Size of Data"<< "," << "Content Name" << "\n";
  // do base stuff
  App::StartApplication();
//for(int i=1;i<=10;i++){
  // ndn::FibHelper::AddRoute(GetNode(), "/"+std::to_string(GetNode()->GetId())+"/"+std::to_string(i) , m_face, 0);
/*  for(int i=0;i<=10;i++){
  for(int j=0;j<=20;j++){
Simulator::Schedule(Seconds(0.05),&CustomConsumer2::SendInterest, this, "/2/"+std::to_string(i),j);
   }
  }
*/
// }
  ScheduleNextPacket();
}

void
CustomConsumer2::StopApplication() // Called at time specified by Stop
{
  NS_LOG_FUNCTION_NOARGS();

  // cancel periodic packet generation
  Simulator::Cancel(m_sendEvent);
m_ofile.close();
  // cleanup base stuff
  App::StopApplication();
}
void
CustomConsumer2::ScheduleNextPacket()
{
  
 if(i==0){
 
 p=0;
  }
 if(i>10){
 i=0;
 p=0;
  }
 //std::to_string(prod[p])
 /*if (controller) {
   
    m_sendEvent = Simulator::ScheduleNow(&CustomConsumer2::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),0); 
    controller = false;
  }
  else if (!m_sendEvent.IsRunning()){
  
    m_sendEvent = Simulator::Schedule((m_random == 0) ? Seconds(1.0 / m_frequency)
                                                      : Seconds(m_random->GetValue()),
                                      &CustomConsumer2::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),0);
    
   
  }
  */
  p=std::rand()%20;
  i=std::rand()%10;
Simulator::ScheduleNow(&CustomConsumer2::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),0);
p=std::rand()%20;
i=std::rand()%10;
Simulator::Schedule(Seconds(10),&CustomConsumer2::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),0);

 
}

void
CustomConsumer2::SetRandomize(const std::string& value)
{
  if (value == "uniform") {
    m_random = CreateObject<UniformRandomVariable>();
    m_random->SetAttribute("Min", DoubleValue(0.0));
    m_random->SetAttribute("Max", DoubleValue(2 * 1.0 / m_frequency));
  }
  else if (value == "exponential") {
    m_random = CreateObject<ExponentialRandomVariable>();
    m_random->SetAttribute("Mean", DoubleValue(1.0 / m_frequency));
    m_random->SetAttribute("Bound", DoubleValue(50 * 1.0 / m_frequency));
  }
  else
    m_random = 0;

  m_randomType = value;
}

std::string
CustomConsumer2::GetRandomize() const
{
  return m_randomType;
}
void
CustomConsumer2::SendInterest(std::string prefix, int seq)
{
 if (m_seq==0)
 {
   m_seq=(GetNode()->GetId()*100);
 }
  
  std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>("/Controller");
  std::shared_ptr<ndn::Name> interestPrefix = std::make_shared<ndn::Name>(prefix);
  
  nameWithSequence->appendSequenceNumber(m_seq);
  interestPrefix->appendSequenceNumber(seq);
  std::cout << " SEQ : "<< seq << std::endl;
  std::shared_ptr<ndn::Interest> interest = std::make_shared<ndn::Interest>();
  Ptr<UniformRandomVariable> m_rand = CreateObject<UniformRandomVariable>();
  interest->setNonce(m_rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
  interest->setName(*nameWithSequence);
  interest->setInterestLifetime(ndn::time::seconds(2));

  interest->setBetw(GetNode()->GetId());
  interest->setPprefix(interestPrefix->toUri());
  interest->setCcode(2);
  std:: cout << "Consumer Sent Interest.....:" <<interestPrefix->toUri()<< std::endl;

  

  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);

  
   
 
  m_seq++;
 // ScheduleNextPacket();



}

void
CustomConsumer2::setPIT(std::string pref,int seq){

 std::shared_ptr<ndn::Name> interestPrefix2 = std::make_shared<ndn::Name>(pref);
 interestPrefix2->appendSequenceNumber(seq);
 
 std::shared_ptr<ndn::Interest> interest2 = std::make_shared<ndn::Interest>(interestPrefix2->toUri());
//m_ofile << Simulator::Now().GetSeconds()  <<","  << interestPrefix2->toUri()<<  "\n";
   
      

//m_ofile.flush();
 
  

   nfd::Pit& pit=GetNode()->GetObject<L3Protocol>()->getForwarder()->getPit();
    
    std::shared_ptr<nfd::pit::Entry> pitEntry=pit.insert(*interest2).first;
 
  
   
 
 
  pitEntry->insertOrUpdateInRecord(*m_face,*interest2)->update(*interest2);
 

 


 
}
void
CustomConsumer2::OnData(std::shared_ptr<const ndn::Data> contentObject)
{
   NS_LOG_FUNCTION_NOARGS();
  std::string str2=contentObject->getName().toUri();
  std::size_t p=str2.find_last_of('/');
  std::string CPrefix=str2.substr(0,p);
if(CPrefix=="/Controller"){
 std::string path=contentObject->getContentMiss();
 
  std::size_t pos=path.find(":",0);
  std::string pre=path.substr(0,pos);
  std::string strExist=path.substr((pos+1));
  int exist=std::stoi(strExist);
  if(exist==0){
     p=std::rand()%30;
     i=std::rand()%10;
Simulator::ScheduleNow(&CustomConsumer2::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),0);
  }else{
float sec=0;
  for(int i=0;i<=99;i++){
  Simulator::Schedule(Seconds(sec),&CustomConsumer2::setPIT, this,pre,i);
    sec=sec+0.1;
 // }catch(std::invalid_argument const &e){
  }// for loop
 
  } 
//m_ofile << Simulator::Now().GetSeconds()  <<",\t"  << contentObject->getContentMiss()<< "\t," << contentObject->getName() << "\n";
   
}else{
m_ofile << Simulator::Now().GetSeconds()  <<","  << contentObject->getContent().size()<< "," << contentObject->getName() << "\n";

m_ofile.flush();   
  std::cout <<"Consumet.................................................." << std::endl;
  NS_LOG_DEBUG("CustomConsumer2..........: " << contentObject->getName() << ", Node..........: " << GetNode()->GetId());
      

}


//  ScheduleNextPacket();
}

void
CustomConsumer2::OnNack(shared_ptr<const lp::Nack> nack)
{
  /// tracing inside
  App::OnNack(nack);
 
  NS_LOG_INFO("NACK received for: " << nack->getInterest().getName()
              << ", reason: " << nack->getReason());
}

} // namespace ndn
} // namespace ns3
