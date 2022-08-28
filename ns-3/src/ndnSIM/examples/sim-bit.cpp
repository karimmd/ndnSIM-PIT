//======== Calling NS-3 and ndnSIM Necessary Header Files ==============

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/file-aggregator.h"
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"

//======================================================================


//========= Calling Header Files From Custom Applications===============

#include "ns3/ndnSIM/apps/ndn-controller-app.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw//controller-strategy.hpp"

//======================================================================


//================ Calling Main Functions ==============================

namespace nfd_fw = nfd::fw;
namespace ns3 {

int
main(int argc, char* argv[])

{

//========Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize

  CommandLine cmd;
  cmd.Parse (argc, argv);

//===== Reading a Topology File from a given directory =================

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("/home/usery/GIT/ndnSIM/ns-3/src/ndnSIM/examples/topologies/topo-bit.txt");
  topologyReader.Read();

//======================================================================


//====== Installation of NDN stack on all Nodes ========================

  ndn::StackHelper ndnHelper;
  ndnHelper.setCsSize(100000);
  ndnHelper.SetDefaultRoutes(true);
  ndnHelper.InstallAll();

//======================================================================



//======= Getting Node and Define Node to their Specific Application ===
  
  Ptr<Node> consumer1 = Names::Find<Node>("C1");
  Ptr<Node> consumer2 = Names::Find<Node>("C2");

  Ptr<Node> producer1 = Names::Find<Node>("P1");
  Ptr<Node> producer2 = Names::Find<Node>("P2");
  Ptr<Node> producer3 = Names::Find<Node>("P3");

  Ptr<Node> controller = Names::Find<Node>("R0");

  Ptr<Node> node1 = Names::Find<Node>("R1");
  Ptr<Node> node2 = Names::Find<Node>("R2");
  Ptr<Node> node3 = Names::Find<Node>("R3");
  Ptr<Node> node4 = Names::Find<Node>("R4");
  Ptr<Node> node5 = Names::Find<Node>("R5");
  Ptr<Node> node6 = Names::Find<Node>("R6");
  Ptr<Node> node7 = Names::Find<Node>("R7");
  Ptr<Node> node8 = Names::Find<Node>("R8");

//======================================================================



//==== List of Available forwarding strategy and Custom Strategy =======

  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/broadcast");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/client-control");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/ncc");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/best-route");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/multicast");

  ndn::StrategyChoiceHelper::InstallAll("/Controller", "/localhost/nfd/strategy/broadcast");
  ndn::StrategyChoiceHelper::InstallAll("/prefix4", "/localhost/nfd/strategy/broadcast");
  ndn::StrategyChoiceHelper::InstallAll("/prefix6", "/localhost/nfd/strategy/broadcast");
  
//============== Custom Strategy =======================================
  
//  ndn::StrategyChoiceHelper::Install<nfd_fw::ControllerStrategy>(Names::Find<Node>("R0"), "/edu.bit.cn/");    

//======================================================================


//=== Installation of NDN applications (Consumer, Producer and Custom)==

/*
  // Installing applications for multiple Consumer 
  ndn::AppHelper consumerHelper1("ns3::ndn::ConsumerCbr");
  consumerHelper1.SetAttribute("Frequency", StringValue("1"));  // 1 interests a second  
  consumerHelper1.SetPrefix("/edu.bit.cn/p1/");                 
  consumerHelper1.Install(consumer1).Start(Seconds(1.508));

  ndn::AppHelper consumerHelper2("ns3::ndn::ConsumerCbr");
  consumerHelper2.SetAttribute("Frequency", StringValue("1"));  // 1 interests a second  
  consumerHelper2.SetPrefix("/edu.bit.cn/p3/");                 
  consumerHelper2.Install(consumer1).Start(Seconds(1.808));
*/

  ndn::AppHelper app1("ControllerApp");   // Initialize Controller App
  app1.Install(controller);

/*
  // Installing applications for the  multiple producer
  ndn::AppHelper producerHelper1("ns3::ndn::Producer");
  producerHelper1.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper1.SetPrefix("/bit.edu.cn/p1/");
  producerHelper1.Install(producer1); 

  ndn::AppHelper producerHelper2("ns3::ndn::Producer");
  producerHelper2.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper2.SetPrefix("/bit.edu.cn/p2/");
  producerHelper2.Install(producer2);

  ndn::AppHelper producerHelper3("ns3::ndn::Producer");
  producerHelper3.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper3.SetPrefix("/bit.edu.cn/p3/");
  producerHelper3.Install(producer3);
*/  


 // Installing  custom producer applications 
  ndn::AppHelper app4("CustomConsumer");   // Initialize App
  app4.SetPrefix("/prefix4");
  app4.Install(consumer1);


 // Installing  custom producer applications 
  ndn::AppHelper app2("CustomProducer");   // Initialize App
  app2.SetPrefix("/prefix4");
  app2.Install(producer1);
  
  ndn::AppHelper app3("CustomProducer");   // Initialize App
  app3.SetPrefix("/prefix6");
  app3.Install(producer2);

//======================================================================


//===== Manual Routing (Depends on the nature of Experiment)============
/*
  ndn::FibHelper::AddRoute("C1", "/edu.bit.cn/", "R1", 0);
  ndn::FibHelper::AddRoute("R1", "/edu.bit.cn/", "R0", 0);
  ndn::FibHelper::AddRoute("R0", "/edu.bit.cn/", "R2", 0);
  ndn::FibHelper::AddRoute("R1", "/edu.bit.cn/", "R2", 0);
  ndn::FibHelper::AddRoute("R2", "/edu.bit.cn/", "P1", 0);

  ndn::FibHelper::AddRoute("C1", "/edu.bit.cn/", "R5", 0);
  ndn::FibHelper::AddRoute("R5", "/edu.bit.cn/", "R0", 0);
  ndn::FibHelper::AddRoute("R0", "/edu.bit.cn/", "R6", 0);
  ndn::FibHelper::AddRoute("R5", "/edu.bit.cn/", "R6", 0);
  ndn::FibHelper::AddRoute("R6", "/edu.bit.cn/", "P1", 0);

  ndn::FibHelper::AddRoute("C1", "/edu.bit.cn/", "R3", 0);
  ndn::FibHelper::AddRoute("R3", "/edu.bit.cn/", "R0", 0);
  ndn::FibHelper::AddRoute("R0", "/edu.bit.cn/", "R4", 0);
  ndn::FibHelper::AddRoute("R3", "/edu.bit.cn/", "R4", 0);
  ndn::FibHelper::AddRoute("R4", "/edu.bit.cn/", "P1", 0);
*/
//======================================================================

  
//======= Trace Simulation Results as Txt File =========================

  //ndn::CsTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_Cs_tracer.txt", Seconds(1.0));
  //ndn::L3RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_L3_rate_trace.txt", Seconds(1.0));
  //ndn::AppDelayTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_app_delays_trace.txt");
  //L2RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_l2_drop_trace.txt", Seconds(1.0));

//======================================================================

   
//==== Schedule simulation time and run the simulation =================

  Simulator::Stop(Seconds(20.0));

  //Simulator::Schedule(Seconds(5.0), ndn::LinkControlHelper::FailLinkByName, "R1", "R2");
  //Simulator::Schedule(Seconds(15.0), ndn::LinkControlHelper::UpLinkByName, "R1", "R2");

  Simulator::Run();
  Simulator::Destroy();

//======================================================================

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
