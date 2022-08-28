// custom-app.cpp

#include "custom-app.hpp"

#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"
#include "ns3/string.h"
#include "ns3/names.h"

#include "ns3/callback.h"


#include "ns3/uinteger.h"

#include "model/ndn-l3-protocol.hpp"
#include "helper/ndn-fib-helper.hpp"

#include <memory>


#include "ns3/ndnSIM/helper/ndn-stack-helper.hpp"
#include "ns3/ndnSIM/helper/ndn-fib-helper.hpp"

#include "ns3/random-variable-stream.h"

NS_LOG_COMPONENT_DEFINE("CustomApp");

namespace ns3 {
namespace ndn {
NS_OBJECT_ENSURE_REGISTERED(CustomApp);

// register NS-3 type
TypeId
CustomApp::GetTypeId()
{
  static TypeId tid = TypeId("CustomApp")
  .SetGroupName("Ndn")
  .SetParent<ndn::Consumer>()
  .AddConstructor<CustomApp>()
    .AddAttribute ("Producer","Prefix, for which producer has the data",
                   StringValue ("/"),
                   MakeNameAccessor (&CustomApp::m_prefix),
                   MakeNameChecker ())
    .AddAttribute ("Controller","Prefix, for which producer has the data",
                   StringValue ("/"),
                   MakeNameAccessor (&CustomApp::controller),
                   MakeNameChecker ())
    .AddAttribute ("PayloadSize", "Virtual payload size for Content packets",
                   UintegerValue (1024),
                   MakeUintegerAccessor (&CustomApp::m_virtualPayloadSize),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Freshness", "Freshness of data packets, if 0, then unlimited freshness",
                   TimeValue (Seconds (0.5)),
                   MakeTimeAccessor (&CustomApp::m_freshness),
                   MakeTimeChecker ())
    .AddAttribute ("Signature", "Fake signature, 0 valid signature (default), other values application-specific",
                   UintegerValue (0),
                   MakeUintegerAccessor (&CustomApp::m_signature),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("KeyLocator", "Name to be used for key locator.  If root, then key locator is not used",
                   NameValue (),
                   MakeNameAccessor (&CustomApp::m_keyLocator),
                   MakeNameChecker ())
    ;
      return tid;
}

CustomApp::CustomApp()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_seq = 0;
}


// Processing upon start of the application
void
CustomApp::StartApplication()
{
  // initialize ndn::App
  ndn::App::StartApplication();

  // Add entry to FIB for `/prefix/sub`
  //ndn::FibHelper::AddRoute(GetNode(), "/prefix", m_face, 0);

  // Schedule send of first interest
 Simulator::Schedule(Seconds(0.0), &CustomApp::SendInterest, this);
 ndn::FibHelper::AddRoute(GetNode(), m_prefix, m_face, 0);
 ndn::FibHelper::AddRoute(GetNode(), "/Controller", m_face, 0);
}

// Processing when application is stopped
void
CustomApp::StopApplication()
{
  // cleanup ndn::App
  ndn::App::StopApplication();
}

void
CustomApp::SendInterest()
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
  std::shared_ptr<ndn::Name> nameWithSequence = std::make_shared<ndn::Name>("/Controller");
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
  interest->setBetw(1010);

  

  m_transmittedInterests(interest, this, m_face);
  m_appLink->onReceiveInterest(*interest);



}
void
CustomApp::ScheduleNextPacket()
{
  Simulator::Schedule(Seconds(0.0), &CustomApp::SendInterest, this);
}


// Callback that will be called when Interest arrives
void
CustomApp::OnInterest(std::shared_ptr<const ndn::Interest> interest)
{
  ndn::App::OnInterest(interest);

  NS_LOG_DEBUG("Received Interest packet for " << interest->getName());

  // Note that Interests send out by the app will not be sent back to the app !

  auto data = std::make_shared<ndn::Data>(interest->getName());
  data->setFreshnessPeriod(ndn::time::milliseconds(1000));
  data->setContent(std::make_shared< ::ndn::Buffer>(1024));
  ndn::StackHelper::getKeyChain().sign(*data);

  NS_LOG_DEBUG("Sending Data packet for " << data->getName());

  // Call trace (for logging purposes)
  m_transmittedDatas(data, this, m_face);

  m_appLink->onReceiveData(*data);
}

// Callback that will be called when Data arrives
void
CustomApp::OnData(std::shared_ptr<const ndn::Data> data)
{
  NS_LOG_DEBUG("Receiving Data packet for " << data->getName());

  std::cout << "DATA received for name " << data->getName() << std::endl;
}
} // namespace ndn
} // namespace ns3