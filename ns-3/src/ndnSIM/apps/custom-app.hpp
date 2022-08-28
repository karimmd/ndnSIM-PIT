// custom-app.hpp

#ifndef CUSTOM_APP_H_
#define CUSTOM_APP_H_

#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/ndnSIM/apps/ndn-consumer.hpp"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "ns3/callback.h"
#include "ns3/traced-callback.h"
#include "ns3/boolean.h"
#include "ns3/names.h"

namespace ns3 {
namespace ndn {  

class CustomApp : public ndn::Consumer {
public:
  // register NS-3 type "CustomApp"
  static TypeId
  GetTypeId();
  CustomApp();

  protected:
  
  // (overridden from ndn::App) Callback that will be called when Interest arrives
  
  // (overridden from ndn::App) Callback that will be called when Data arrives
  virtual void
  OnData(std::shared_ptr<const ndn::Data> contentObject);
  protected:
  virtual void
  ScheduleNextPacket();
// (overridden from ndn::App) Processing upon start of the application
  virtual void
  StartApplication();

  // (overridden from ndn::App) Processing when application is stopped
  virtual void
  StopApplication();



private:
   Name m_prefix;
   Name m_postfix;
   Name controller;
  uint32_t m_virtualPayloadSize;
  Time m_freshness;

  uint32_t m_signature;
  Name m_keyLocator;
  void
  SendInterest();
   void
  OnInterest(std::shared_ptr<const ndn::Interest> interest);

  protected:
  uint32_t m_seq;
  Time m_interestLifeTime;


  
};
} // namespace ndn
} // namespace ns3

#endif // CUSTOM_APP_H