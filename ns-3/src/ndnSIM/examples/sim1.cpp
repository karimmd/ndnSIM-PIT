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
  nodes.Create(10);

  // Connecting nodes using three links
  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(1), nodes.Get(2));
  p2p.Install(nodes.Get(2), nodes.Get(3));
  p2p.Install(nodes.Get(3), nodes.Get(4));
  p2p.Install(nodes.Get(3), nodes.Get(5));
  p2p.Install(nodes.Get(3), nodes.Get(6));
  p2p.Install(nodes.Get(4), nodes.Get(7));
  p2p.Install(nodes.Get(5), nodes.Get(8));
  p2p.Install(nodes.Get(6), nodes.Get(9));

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
  ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "100");
                                         


  // List of Available forwarding strategy 
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/broadcast");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/client-control");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/ncc");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/best-route");
  ndn::StrategyChoiceHelper::InstallAll("/bit.edu.cn", "/localhost/nfd/strategy/multicast");
  // Custom Strategy   
  //ndn::StrategyChoiceHelper::Install<nfd_fw::ControllerStrategy>(nodes.Get(2), "/prefix");  

  

  // Installing applications
  // Node0=Consumer, Node1=Controller, Node2=Producer

  // Consumer
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  // Consumer will request /prefix/0, /prefix/1, ...
  consumerHelper.SetPrefix("/bit.edu.cn");
  consumerHelper.SetAttribute("Frequency", StringValue("10")); // 10 interests a second
  consumerHelper.Install(nodes.Get(0));   // first node


  //auto apps = consumerHelper.Install(nodes.Get(0));                        
  //apps.Stop(Seconds(10.0)); // stop the consumer app at 10 seconds mark

  // Controller
  //ndn::AppHelper app("ControllerApp");   // Initialize Controller App
  //app.Install(nodes.Get(2)); // middle node

  // Producer
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  // Producer will reply to all requests starting with /prefix
  producerHelper.SetPrefix("/bit.edu.cn");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(nodes.Get(7)); 
  producerHelper.Install(nodes.Get(8)); 
  producerHelper.Install(nodes.Get(9)); 



  Simulator::Stop(Seconds(30.0));
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