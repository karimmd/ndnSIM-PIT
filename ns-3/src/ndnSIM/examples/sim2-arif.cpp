//===== Scenario to Test Scenarios under Multiple Conditions============
//=============Beijing Institute of Technology==========================

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"
#include "ns3/file-aggregator.h"

#include "ns3/ndnSIM/apps/ndn-controller-app.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw/controller-strategy.hpp"

namespace nfd_fw = nfd::fw;
namespace ns3 {

/**
 * This scenario simulates a very simple network topology:
 *
 *
 *      +----------+     1Mbps      +------------+     1Mbps      +----------+
 *      | consumer | <------------> | controller | <------------> | producer |
 *      +----------+     10ms       +------------+     10ms       +----------+
 *
 *
 * Consumer requests data from producer with frequency 10 interests per second
 * (interests contain constantly increasing sequence number).
 *
 * For every received interest, producer replies with a data packet, containing
 * 1024 bytes of virtual payload.
 *
 * To run scenario and see what is happening, use the following command:
 *
 *     NS_LOG=ndn.Consumer:ndn.Producer ./waf --run scratch/sim2
 */

int
main(int argc, char* argv[])
{
  // setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue("1Mbps"));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue("10ms"));
  Config::SetDefault("ns3::QueueBase::MaxSize", StringValue("20p"));

  // Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
  CommandLine cmd;
  cmd.Parse(argc, argv);

  // Creating nodes
  NodeContainer nodes;
  nodes.Create(3);

  // Connecting nodes using two links
  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(1), nodes.Get(2));
 
  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.SetDefaultRoutes(true);
  ndnHelper.InstallAll();
     
  // Content Store Policies
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Freshness::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Probability::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Stats::Random","MaxSize",  "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lfu", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Fifo", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "100");
                                         


  // List of Available forwarding strategy 
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/multicast");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/broadcast");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/client-control");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/ncc");
  ndn::StrategyChoiceHelper::InstallAll("/Controller", "/localhost/nfd/strategy/broadcast");
  ndn::StrategyChoiceHelper::InstallAll("/prefix4", "/localhost/nfd/strategy/broadcast");
  ndn::StrategyChoiceHelper::InstallAll("/prefix6", "/localhost/nfd/strategy/broadcast");
  
  
  
  
 

 
  ndn::AppHelper app3("CustomProducer");   // Initialize Controller App
  app3.SetPrefix("/prefix4");
  app3.Install(nodes.Get(0));
  
  ndn::AppHelper app4("CustomProducer");   // Initialize Controller App
  app4.SetPrefix("/prefix6");
  app4.Install(nodes.Get(2));
  
   ndn::AppHelper app2("ControllerApp");   // Initialize Controller App
 //app2.SetPrefix("/prefix");
// app2.SetPrefix("/Controller");
  app2.Install(nodes.Get(1));

//ns3::ndn::FibHelper::AddRoute(nodes.Get(1), "/Controller", nodes.Get(0), 0);
//ns3::ndn::FibHelper::AddRoute(nodes.Get(0), "/Controller", nodes.Get(1), 0);
/*
 
  // Manual Routing
  
  ns3::ndn::FibHelper::AddRoute(nodes.Get(1), "/prefix", nodes.Get(2), 0);
  ns3::ndn::FibHelper::AddRoute(nodes.Get(2), "/prefix", nodes.Get(1), 1);
  ns3::ndn::FibHelper::AddRoute(nodes.Get(1), "/prefix", nodes.Get(0), 1);
*/
 
  Simulator::Stop(Seconds(20.0));

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
