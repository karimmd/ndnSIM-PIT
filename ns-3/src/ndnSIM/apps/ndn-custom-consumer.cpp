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

#include "ndn-custom-consumer.hpp"
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
#include "model/ndn-l3-protocol.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw/forwarder.hpp"

#include "table/pit.hpp"
#include "table/pit-entry.hpp"
#include "table/name-tree-entry.hpp"




NS_LOG_COMPONENT_DEFINE("CustomConsumer");

namespace ns3 {
namespace ndn {

NS_OBJECT_ENSURE_REGISTERED(CustomConsumer);

TypeId
CustomConsumer::GetTypeId(void)
{
  static TypeId tid =
    TypeId("CustomConsumer")
      .SetGroupName("Ndn")
      .SetParent<Consumer>()
      .AddConstructor<CustomConsumer>()

      
      .AddAttribute("Frequency", "Frequency of interest packets", StringValue("1.0"),
                    MakeDoubleAccessor(&CustomConsumer::m_frequency), MakeDoubleChecker<double>())

      .AddAttribute("Randomize",
                    "Type of send time randomization: none (default), uniform, exponential",
                    StringValue("none"),
                    MakeStringAccessor(&CustomConsumer::SetRandomize, &CustomConsumer::GetRandomize),
                    MakeStringChecker())

    ;

  return tid;
}

CustomConsumer::CustomConsumer()
  : m_frequency(1.0)
  , m_firstTime(false)
  , controller(true)
  , m_seq(0)
  ,prod{500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519}
{
  NS_LOG_FUNCTION_NOARGS();
 // m_seqMax = std::numeric_limits<uint32_t>::max();
}

CustomConsumer::~CustomConsumer()
{
}

void
CustomConsumer::StartApplication() // Called at time specified by Start
{
  NS_LOG_FUNCTION_NOARGS();
m_filename="Pure_Consumer.txt";//+std::to_string(GetNode()->GetId())+".txt";
 m_ofile.open(m_filename,std::ios::out | std::ios::app);
//m_ofile << "Time " <<  ","  << "Size of Data"<< "," << "Content Name" << "\n";
 
  // do base stuff
  App::StartApplication();
 /* for(int i=0;i<=10;i++){
  for(int j=0;j<=20;j++){
Simulator::Schedule(Seconds(0.05),&CustomConsumer::SendInterest, this, "/2/"+std::to_string(i),j);
   }
  }*/
  ScheduleNextPacket();
}

void
CustomConsumer::StopApplication() // Called at time specified by Stop
{
  NS_LOG_FUNCTION_NOARGS();

  // cancel periodic packet generation
  Simulator::Cancel(m_sendEvent);

  // cleanup base stuff
  App::StopApplication();
}

void
CustomConsumer::ScheduleNextPacket()
{
  // double mean = 8.0 * m_payloadSize / m_desiredRate.GetBitRate ();
  // std::cout << "next: " << Simulator::Now().ToDouble(Time::S) + mean << "s\n";
  if(j==0){
 p=std::rand()%30;
 i=std::rand()%10;
  }
 if(j>100){
 p=std::rand()%30;
 i=std::rand()%10;
 j=0;
  }
 
 if (controller) {
   
    m_sendEvent = Simulator::ScheduleNow(&CustomConsumer::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),j); 
    std::cout << "First Schedule" << std::endl; 
    controller = false;
  }
  else if (!m_sendEvent.IsRunning()){
  
    m_sendEvent = Simulator::Schedule((m_random == 0) ? Seconds(1.0 / m_frequency)
                                                      : Seconds(m_random->GetValue()),
                                      &CustomConsumer::SendInterest, this,"/"+std::to_string(prod[p])+"/"+std::to_string(i),j);
    
   
  std::cout << "Second Packet Schedule" << std::endl;
  }
  
  j++;
}

void
CustomConsumer::SetRandomize(const std::string& value)
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
CustomConsumer::GetRandomize() const
{
  return m_randomType;
}
void
CustomConsumer::SendInterest(std::string prefix,int seq)
{
  /////////////////////////////////////
  // Sending one Interest packet out //
  /////////////////////////////////////
/*
  // Create and configure ndn::Interest
  auto interest = std::make_shared<ndn::Interest>("/prefix");
  Ptr<UniformRandomVariable> rand = CreateObject<UniformRandomVariable>();
  interest->setNonce(rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
  interest->setInterestLifetime(ndn::time::seconds(1));

  NS_LOG_DEBUG("Sending Interest packet for " << *interest);

  // Call trace (for logging purposes)
  m_transmittedInterests(interest, this, m_face);

  m_appLink->onReceiveInterest(*interest);
*/
 //
 
  
  std::shared_ptr<ndn::Name> interestPrefix = std::make_shared<ndn::Name>(prefix);
interestPrefix->appendSequenceNumber(seq);
  
  //
  // shared_ptr<Interest> interest = make_shared<Interest> ();
  std::shared_ptr<ndn::Interest> interest = std::make_shared<ndn::Interest>();
  
  Ptr<UniformRandomVariable> m_rand = CreateObject<UniformRandomVariable>();
  interest->setNonce(m_rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
  interest->setName(*interestPrefix);


  
//=========================== Our Custom Defined Field =================

  
  //int cnode=this->GetNode()->GetId();
  //interest->setCNode(cnode);

//====================================================================== 
  
  //ndn::time::milliseconds interestLifeTime(ndn::time::seconds(1));
  interest->setInterestLifetime(ndn::time::seconds(1));
 

  // NS_LOG_INFO ("Requesting Interest: \n" << *interest);
  interest->setBetw(GetNode()->GetId());
  
  interest->setPprefix(interestPrefix->toUri());
  std::cout << "Interest : " <<interestPrefix->toUri()<< std::endl;
 // interest2->setPprefix("A");
  interest->setCcode(2);
  
  
  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);

        

ScheduleNextPacket();
 //Simulator::Schedule(Seconds(0.1), &CustomConsumer::cData, this); 



}
 
 void
CustomConsumer::OnData(shared_ptr<const ndn::Data> data)
{
  NS_LOG_FUNCTION_NOARGS();
  ndn::App::OnData(data); 
  std::cout << "Customer " <<GetNode()->GetId() << " \t Producer Data Name:" << data->getName() << std::endl;
 // std::cout << "Producer Sends Panme: " << data->getPprefix() << std::endl;
  m_ofile << Simulator::Now().GetSeconds() <<  ","  << data->getContent().size()<< "," << data->getName() << "\n";
      m_ofile.flush();

  //std::cout << "SOurce Node for Interest Pact:  " << Names::FindName(GetNode())<<"\n";
  
}
void
CustomConsumer::OnNack(shared_ptr<const lp::Nack> nack)
{
  /// tracing inside
   App::OnNack(nack);
//m_ofile << Simulator::Now().GetSeconds() << "NACK received for: "<< nack->getInterest().getName() << ", reason: " << nack->getReason()<< "\n";
  //    m_ofile.flush();

  NS_LOG_INFO("NACK received for: " << nack->getInterest().getName()
              << ", reason: " << nack->getReason());
  }
} // namespace ndn
} // namespace ns3