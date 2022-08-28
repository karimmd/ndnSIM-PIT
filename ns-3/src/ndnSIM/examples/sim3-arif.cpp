// Main Headers
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/file-aggregator.h"
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"

// Custom Headers
#include "ns3/ndnSIM/apps/ndn-controller-app.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw/controller-strategy.hpp"



namespace nfd_fw = nfd::fw;
namespace ns3 {

int
main(int argc, char* argv[])

{

  // Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize

  CommandLine cmd;
  cmd.Parse (argc, argv);

  // Reading a Topology File 
  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("/home/arif/TEST/ndnSIM/ns-3/src/ndnSIM/examples/topologies/topo-custom-02.txt");
  topologyReader.Read();


  // Installation of NDN stack on all Nodes 
  ndn::StackHelper ndnHelper;
  //ndnHelper.SetDefaultRoutes(true);
  ndnHelper.InstallAll();


  // Content Store Policies ===========================
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Freshness::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Probability::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Stats::Random","MaxSize",  "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lfu", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Fifo", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru");
  ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "100");
                                         


  // Getting Node and Define Node to their Specific Application ===
  Ptr<Node> consumer1 = Names::Find<Node>("C1");
  Ptr<Node> consumer2 = Names::Find<Node>("C2"); 
  Ptr<Node> producer1 = Names::Find<Node>("P1"); 
  Ptr<Node> controller = Names::Find<Node>("R0");


  // forwarding strategy 
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/broadcast");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/client-control");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/ncc");
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/best-route");
  
  // Custom Strategy   
  ndn::StrategyChoiceHelper::Install<nfd_fw::ControllerStrategy>(Names::Find<Node>("R0"), "/prefix");    

  // Installing applications for Consumer 
  /*ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetAttribute("Frequency", StringValue("10"));  // 10 interests a second  
  consumerHelper.SetPrefix("/prefix");                 
  consumerHelper.Install(consumer1);
  consumerHelper.Install(consumer2);
  */
  ndn::AppHelper app("ControllerApp");   // Initialize Controller App
  //app.SetPrefix("/prefix");
  app.Install(controller);

  // Installing applications for Producer
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));  // Size of the Payload
  producerHelper.SetPrefix("/prefix");
  //producerHelper.SetPrefix("/prefix/video");
  //producerHelper.SetPrefix("/prefix/movie");     // Prefix Address
  producerHelper.Install(producer1);
  

  // Manual Routing 
  ndn::FibHelper::AddRoute("C1", "/prefix", "R5", 0);

  ndn::FibHelper::AddRoute("R5", "/prefix", "P1", 0);
  
  ndn::FibHelper::AddRoute("R0", "/prefix", "R5", 0);
  
  ndn::FibHelper::AddRoute("R5", "/prefix", "P1", 0);

  ndn::FibHelper::AddRoute("C2", "/prefix", "R2", 1);

  ndn::FibHelper::AddRoute("R2", "/prefix", "R0", 1);
  
  ndn::FibHelper::AddRoute("R0", "/prefix", "R3", 1);
  ndn::FibHelper::AddRoute("R0", "/prefix", "R4", 1);
  
  ndn::FibHelper::AddRoute("R4", "/prefix", "R5", 1);

  ndn::FibHelper::AddRoute("R5", "/prefix", "P1", 1);

  
  // Trace Simulation 
  //ndn::CsTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_Cs_tracer.txt", Seconds(1.0));
  //ndn::L3RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_L3_rate_trace.txt", Seconds(1.0));
  //ndn::AppDelayTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_app_delays_trace.txt");
  //L2RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_l2_drop_trace.txt", Seconds(1.0));


  // Schedule simulation time and run the simulation =================
  Simulator::Stop(Seconds(20.0));

  //Simulator::Schedule(Seconds(5.0), ndn::LinkControlHelper::FailLinkByName, "R1", "R2");
  //Simulator::Schedule(Seconds(15.0), ndn::LinkControlHelper::UpLinkByName, "R1", "R2");

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
