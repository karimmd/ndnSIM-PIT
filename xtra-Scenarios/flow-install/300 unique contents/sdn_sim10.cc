
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/file-aggregator.h"
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"
//#include "ns3/ndnSIM/model/ndn-control-router.hpp"
//#include "ns3/ndnSIM/model/ndn-l3-protocol.hpp"
#include "ns3/ndnSIM/helper/ndn-fib-helper.hpp"
#include "ns3/ndnSIM/model/ndn-net-device-transport.hpp"
//======================================================================


//========= Calling Header Files From Custom Applications===============

#include "ns3/ndnSIM/apps/ndn-controller-app.hpp"
//#include "ns3/ndnSIM/examples/ndn-load-balancer/ControllerStrategy.hpp"

//======================================================================


//namespace nfd_fw = nfd::fw;

//================ Calling Main Functions ==============================

namespace ns3 {
//namespace ndn{

int
main(int argc, char* argv[])

{

//========Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize

  CommandLine cmd;
  cmd.Parse (argc, argv);

//===== Reading a Topology File from a given directory =================

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("/home/userx/GIT/ndnSIM-PIT/ns-3/src/ndnSIM/examples/topologies/core-access-500consumers.txt");
  topologyReader.Read();

//======================================================================


//====== Installation of NDN stack on all Nodes ========================

  ndn::StackHelper ndnHelper;
// ndnHelper.SetDefaultRoutes(true);
  ndnHelper.InstallAll();
  
Ptr<Node> controller = Names::Find<Node>("controller-1");
///////////// First Poll of Producer//////////////////
  Ptr<Node> producerP1A = Names::Find<Node>("producer-1");
  Ptr<Node> producerP2A = Names::Find<Node>("producer-2");
  Ptr<Node> producerP3A = Names::Find<Node>("producer-3");
  Ptr<Node> producerP4A = Names::Find<Node>("producer-4");
  Ptr<Node> producerP5A = Names::Find<Node>("producer-5");

  ////////////// sECOND Poll of Producer//////////////////
  Ptr<Node> producerP1B = Names::Find<Node>("producer-6");
  Ptr<Node> producerP2B = Names::Find<Node>("producer-7");
  Ptr<Node> producerP3B = Names::Find<Node>("producer-8");
  Ptr<Node> producerP4B = Names::Find<Node>("producer-9");
  Ptr<Node> producerP5B = Names::Find<Node>("producer-10");
 
////////////// tHIRD Poll of Producer//////////////////
  Ptr<Node> producerP1C = Names::Find<Node>("producer-11");
  Ptr<Node> producerP2C = Names::Find<Node>("producer-12");
  Ptr<Node> producerP3C = Names::Find<Node>("producer-13");
  Ptr<Node> producerP4C = Names::Find<Node>("producer-14");
  Ptr<Node> producerP5C = Names::Find<Node>("producer-15");

  Ptr<Node> producerP1D = Names::Find<Node>("producer-16");
  Ptr<Node> producerP2D = Names::Find<Node>("producer-17");
  Ptr<Node> producerP3D = Names::Find<Node>("producer-18");
  Ptr<Node> producerP4D = Names::Find<Node>("producer-19");
  Ptr<Node> producerP5D = Names::Find<Node>("producer-20");
  
  //////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////

  Ptr<Node> consumerC1A = Names::Find<Node>("consumer-1");
  Ptr<Node> consumerC2A = Names::Find<Node>("consumer-2");
  Ptr<Node> consumerC3A = Names::Find<Node>("consumer-3");
//  Ptr<Node> consumerC4A = Names::Find<Node>("consumer-4");
 // Ptr<Node> consumerC5A = Names::Find<Node>("consumer-5");
 // Ptr<Node> consumerC6A = Names::Find<Node>("consumer-6");
 // Ptr<Node> consumerC7A = Names::Find<Node>("consumer-7");
 // Ptr<Node> consumerC8A = Names::Find<Node>("consumer-8");
 // Ptr<Node> consumerC9A = Names::Find<Node>("consumer-9");
 // Ptr<Node> consumerC10A = Names::Find<Node>("consumer-10");
 // Ptr<Node> consumerC11A = Names::Find<Node>("consumer-11");
 // Ptr<Node> consumerC12A = Names::Find<Node>("consumer-12");
 // Ptr<Node> consumerC13A = Names::Find<Node>("consumer-13");
  //Ptr<Node> consumerC14A = Names::Find<Node>("consumer-14");
  //Ptr<Node> consumerC15A = Names::Find<Node>("consumer-15");
 // Ptr<Node> consumerC16A = Names::Find<Node>("consumer-16");
 // Ptr<Node> consumerC17A = Names::Find<Node>("consumer-17");
 // Ptr<Node> consumerC18A = Names::Find<Node>("consumer-18");
  //Ptr<Node> consumerC21A = Names::Find<Node>("consumer-21");
 // Ptr<Node> consumerC22A = Names::Find<Node>("consumer-22");
 // Ptr<Node> consumerC23A = Names::Find<Node>("consumer-23");
 // Ptr<Node> consumerC24A = Names::Find<Node>("consumer-24");
 // Ptr<Node> consumerC25A = Names::Find<Node>("consumer-25");
  

////////////// SECOND Poll of Consumer//////////////////
  ////////////// SECOND Poll of Consumer//////////////////
  
  Ptr<Node> consumerC1B = Names::Find<Node>("consumer-26");
  Ptr<Node> consumerC2B = Names::Find<Node>("consumer-27");
  Ptr<Node> consumerC3B = Names::Find<Node>("consumer-28");
  //Ptr<Node> consumerC4B = Names::Find<Node>("consumer-29");
  //Ptr<Node> consumerC5B = Names::Find<Node>("consumer-30");
  //Ptr<Node> consumerC6B = Names::Find<Node>("consumer-31");
  //Ptr<Node> consumerC7B = Names::Find<Node>("consumer-32");
 // Ptr<Node> consumerC8B = Names::Find<Node>("consumer-33");
 // Ptr<Node> consumerC9B = Names::Find<Node>("consumer-34");
 // Ptr<Node> consumerC10B = Names::Find<Node>("consumer-35");
 // Ptr<Node> consumerC11B = Names::Find<Node>("consumer-36");
 // Ptr<Node> consumerC12B = Names::Find<Node>("consumer-37");
 // Ptr<Node> consumerC13B = Names::Find<Node>("consumer-38");
 // Ptr<Node> consumerC14B = Names::Find<Node>("consumer-39");
 // Ptr<Node> consumerC15B = Names::Find<Node>("consumer-40");
 // Ptr<Node> consumerC18B = Names::Find<Node>("consumer-43");
 // Ptr<Node> consumerC19B = Names::Find<Node>("consumer-44");
 // Ptr<Node> consumerC20B = Names::Find<Node>("consumer-45");
 // Ptr<Node> consumerC21B = Names::Find<Node>("consumer-46");
 // Ptr<Node> consumerC22B = Names::Find<Node>("consumer-47");
 // Ptr<Node> consumerC23B = Names::Find<Node>("consumer-48");
  //Ptr<Node> consumerC24B = Names::Find<Node>("consumer-49");
 // Ptr<Node> consumerC25B = Names::Find<Node>("consumer-50");

////////////// Third Poll of Consumer//////////////////
  ////////////// Third Poll of Consumer//////////////////
  Ptr<Node> consumerC1C = Names::Find<Node>("consumer-51");
  Ptr<Node> consumerC2C = Names::Find<Node>("consumer-52");
  //Ptr<Node> consumerC3C = Names::Find<Node>("consumer-53");
  //Ptr<Node> consumerC4C = Names::Find<Node>("consumer-54");
  //Ptr<Node> consumerC5C = Names::Find<Node>("consumer-55");
  //Ptr<Node> consumerC6C = Names::Find<Node>("consumer-56");
  //Ptr<Node> consumerC7C = Names::Find<Node>("consumer-57");
 // Ptr<Node> consumerC8C = Names::Find<Node>("consumer-58");
 // Ptr<Node> consumerC9C = Names::Find<Node>("consumer-59");
 // Ptr<Node> consumerC10C = Names::Find<Node>("consumer-60");
 // Ptr<Node> consumerC13C = Names::Find<Node>("consumer-63");
 // Ptr<Node> consumerC14C = Names::Find<Node>("consumer-64");
 // Ptr<Node> consumerC15C = Names::Find<Node>("consumer-65");
  //Ptr<Node> consumerC16C = Names::Find<Node>("consumer-66");
 // Ptr<Node> consumerC17C = Names::Find<Node>("consumer-67");
 // Ptr<Node> consumerC18C = Names::Find<Node>("consumer-68");
 // Ptr<Node> consumerC19C = Names::Find<Node>("consumer-69");
 // Ptr<Node> consumerC20C = Names::Find<Node>("consumer-70");
 // Ptr<Node> consumerC21C = Names::Find<Node>("consumer-71");
 // Ptr<Node> consumerC22C = Names::Find<Node>("consumer-72");
 // Ptr<Node> consumerC23C = Names::Find<Node>("consumer-73");
 // Ptr<Node> consumerC24C = Names::Find<Node>("consumer-74");
 // Ptr<Node> consumerC25C = Names::Find<Node>("consumer-75");

////////////// fOURTH Poll of Consumer//////////////////
  ////////////// fOURTH Poll of Consumer//////////////////
  Ptr<Node> consumerC1D = Names::Find<Node>("consumer-76");
  Ptr<Node> consumerC2D = Names::Find<Node>("consumer-77");
  //Ptr<Node> consumerC3D = Names::Find<Node>("consumer-78");
  //Ptr<Node> consumerC4D = Names::Find<Node>("consumer-79");
  //Ptr<Node> consumerC5D = Names::Find<Node>("consumer-80");
  //Ptr<Node> consumerC8D = Names::Find<Node>("consumer-83");
  //Ptr<Node> consumerC9D = Names::Find<Node>("consumer-84");
 // Ptr<Node> consumerC10D = Names::Find<Node>("consumer-85");
 // Ptr<Node> consumerC11D = Names::Find<Node>("consumer-86");
 // Ptr<Node> consumerC12D = Names::Find<Node>("consumer-87");
 // Ptr<Node> consumerC13D = Names::Find<Node>("consumer-88");
 // Ptr<Node> consumerC14D = Names::Find<Node>("consumer-89");
 // Ptr<Node> consumerC15D = Names::Find<Node>("consumer-90");
 // Ptr<Node> consumerC16D = Names::Find<Node>("consumer-91");
 // Ptr<Node> consumerC17D = Names::Find<Node>("consumer-92");
 // Ptr<Node> consumerC18D = Names::Find<Node>("consumer-93");
 // Ptr<Node> consumerC19D = Names::Find<Node>("consumer-94");
 // Ptr<Node> consumerC20D = Names::Find<Node>("consumer-95");
 // Ptr<Node> consumerC21D = Names::Find<Node>("consumer-96");
 // Ptr<Node> consumerC22D = Names::Find<Node>("consumer-97");
  //Ptr<Node> consumerC23D = Names::Find<Node>("consumer-98");
  
  ndn::AppHelper appC1A("CustomConsumer2");
  
  appC1A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1A=appC1A.Install(consumerC1A);
  comsumerappC1A.Start(Seconds(8.6));
  comsumerappC1A.Stop(Seconds(28.6));

 ndn::AppHelper appC2A("CustomConsumer2");
  
  appC2A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2A=appC2A.Install(consumerC2A);
  comsumerappC2A.Start(Seconds(8.8));
  comsumerappC2A.Stop(Seconds(28.8));

  ndn::AppHelper appC3A("CustomConsumer2");
  
  appC3A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC3A=appC3A.Install(consumerC3A);
  comsumerappC3A.Start(Seconds(9));
  comsumerappC3A.Stop(Seconds(29));

 
  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC1B("CustomConsumer2");
  
  appC1B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1B=appC1B.Install(consumerC1B);
  comsumerappC1B.Start(Seconds(13.6));
  comsumerappC1B.Stop(Seconds(33.6));

 ndn::AppHelper appC2B("CustomConsumer2");
  
  appC2B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2B=appC2B.Install(consumerC2B);
  comsumerappC2B.Start(Seconds(13.8));
  comsumerappC2B.Stop(Seconds(33.8));

  ndn::AppHelper appC3B("CustomConsumer2");
  
  appC3B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC3B=appC3B.Install(consumerC3B);
  comsumerappC3B.Start(Seconds(14));
  comsumerappC3B.Stop(Seconds(34));

  
//////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////


 
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

  ndn::AppHelper appC1C("CustomConsumer2");
  
 
  appC1C.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1C=appC1C.Install(consumerC1C);
  comsumerappC1C.Start(Seconds(18.6));
  comsumerappC1C.Stop(Seconds(38.6));

  
  ndn::AppHelper appC2C("CustomConsumer2");
  
 
  appC2C.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2C=appC2C.Install(consumerC2C);
  comsumerappC2C.Start(Seconds(18.8));
  comsumerappC2C.Stop(Seconds(38.6));


  


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  



  
 
  //////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////D Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC1D("CustomConsumer2");
  
  appC1D.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1D=appC1D.Install(consumerC1D);
  comsumerappC1D.Start(Seconds(3.4));
  comsumerappC1D.Stop(Seconds(23.4));

 ndn::AppHelper appC2D("CustomConsumer2");
  
  appC2D.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2D=appC2D.Install(consumerC2D);
  comsumerappC2D.Start(Seconds(3.6));
  comsumerappC2D.Stop(Seconds(23.6));

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last twenty Five B//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1B("CustomProducer");
  
  appP1B.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP1B=appP1B.Install(producerP1B);
  producerappP1B.Start(Seconds(1));
  producerappP1B.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2B("CustomProducer");
  
  appP2B.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP2B=appP2B.Install(producerP2B);
  producerappP2B.Start(Seconds(1));
  producerappP2B.Stop(Seconds(40));


  ndn::AppHelper appP3B("CustomProducer");
  
  appP3B.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP3B=appP3B.Install(producerP3B);
  producerappP3B.Start(Seconds(1));
  producerappP3B.Stop(Seconds(40));


  ndn::AppHelper appP4B("CustomProducer");
  
  appP4B.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP4B=appP4B.Install(producerP4B);
  producerappP4B.Start(Seconds(1));
  producerappP4B.Stop(Seconds(40));


  ndn::AppHelper appP5B("CustomProducer");
  
  appP5B.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP5B=appP5B.Install(producerP5B);
  producerappP5B.Start(Seconds(1));
  producerappP5B.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1C("CustomProducer");
  
  appP1C.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP1C=appP1C.Install(producerP1C);
  producerappP1C.Start(Seconds(1));
  producerappP1C.Stop(Seconds(40));

  ndn::AppHelper appP2C("CustomProducer");
  
  appP2C.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP2C=appP2C.Install(producerP2C);
  producerappP2C.Start(Seconds(1));
  producerappP2C.Stop(Seconds(40));


  ndn::AppHelper appP3C("CustomProducer");
  
  appP3C.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP3C=appP3C.Install(producerP3C);
  producerappP3C.Start(Seconds(1));
  producerappP3C.Stop(Seconds(40));


  ndn::AppHelper appP4C("CustomProducer");
  
  appP4C.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP4C=appP4C.Install(producerP4C);
  producerappP4C.Start(Seconds(1));
  producerappP4C.Stop(Seconds(40));



   ndn::AppHelper appP5C("CustomProducer");
  
  appP5C.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP5C=appP5C.Install(producerP5C);
  producerappP5C.Start(Seconds(1));
  producerappP5C.Stop(Seconds(40));

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1A("CustomProducer");
  
  appP1A.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP1A=appP1A.Install(producerP1A);
  producerappP1A.Start(Seconds(1));
  producerappP1A.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2A("CustomProducer");
  
  appP2A.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP2A=appP2A.Install(producerP2A);
  producerappP2A.Start(Seconds(1));
  producerappP2A.Stop(Seconds(40));


  ndn::AppHelper appP3A("CustomProducer");
  
  appP3A.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP3A=appP3A.Install(producerP3A);
  producerappP3A.Start(Seconds(1));
  producerappP3A.Stop(Seconds(40));


  ndn::AppHelper appP4A("CustomProducer");
  
  appP4A.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP4A=appP4A.Install(producerP4A);
  producerappP4A.Start(Seconds(1));
  producerappP4A.Stop(Seconds(40));


  ndn::AppHelper appP5A("CustomProducer");
  
  appP5A.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP5A=appP5A.Install(producerP5A);
  producerappP5A.Start(Seconds(1));
  producerappP5A.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1D("CustomProducer");
  
  appP1D.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP1D=appP1D.Install(producerP1D);
  producerappP1D.Start(Seconds(1));
  producerappP1D.Stop(Seconds(40));

  ndn::AppHelper appP2D("CustomProducer");
  
  appP2D.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP2D=appP2D.Install(producerP2D);
  producerappP2D.Start(Seconds(1));
  producerappP2D.Stop(Seconds(40));


  ndn::AppHelper appP3D("CustomProducer");
  
  appP3D.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP3D=appP3D.Install(producerP3D);
  producerappP3D.Start(Seconds(1));
  producerappP3D.Stop(Seconds(40));


  ndn::AppHelper appP4D("CustomProducer");
  
  appP4D.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP4D=appP4D.Install(producerP4D);
  producerappP4D.Start(Seconds(1));
  producerappP4D.Stop(Seconds(40));



   ndn::AppHelper appP5D("CustomProducer");
  
  appP5D.SetAttribute("Cashing",UintegerValue(1));
  
                  
  ApplicationContainer producerappP5D=appP5D.Install(producerP5D);
  producerappP5D.Start(Seconds(1));
  producerappP5D.Stop(Seconds(40));



ndn::AppHelper controllerapp("ControllerApp");   // Initialize Controller App
 
  controllerapp.Install(controller);

/*
//======================================================================


//=================== Content Store Policies ===========================

  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Freshness::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Probability::Random", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Stats::Random","MaxSize",  "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lfu", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Fifo", "MaxSize", "100");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru");
  //ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "100");
                                         
//======================================================================


//======= Getting Node and Define Node to their Specific Application ===
  
  
   



////////////// First Poll of Consumer//////////////////
  Ptr<Node> consumerC1A = Names::Find<Node>("C1A");
  Ptr<Node> consumerC2A = Names::Find<Node>("C2A");
  Ptr<Node> consumerC3A = Names::Find<Node>("C3A");
  Ptr<Node> consumerC4A = Names::Find<Node>("C4A");
  Ptr<Node> consumerC5A = Names::Find<Node>("C5A");

////////////// SECOND Poll of Consumer//////////////////
  Ptr<Node> consumerC1B = Names::Find<Node>("C1B");
  Ptr<Node> consumerC2B = Names::Find<Node>("C2B");
  Ptr<Node> consumerC3B = Names::Find<Node>("C3B");
  Ptr<Node> consumerC4B = Names::Find<Node>("C4B");
  Ptr<Node> consumerC5B = Names::Find<Node>("C5B");

////////////// Third Poll of Consumer//////////////////
  Ptr<Node> consumerC1C = Names::Find<Node>("C1C");
  Ptr<Node> consumerC2C = Names::Find<Node>("C2C");
 Ptr<Node> consumerC3C = Names::Find<Node>("C3C");
  Ptr<Node> consumerC4C = Names::Find<Node>("C4C");
  Ptr<Node> consumerC5C = Names::Find<Node>("C5C");

////////////// fOURTH Poll of Consumer//////////////////
  Ptr<Node> consumerC1D = Names::Find<Node>("C1D");
  Ptr<Node> consumerC2D = Names::Find<Node>("C2D");
  Ptr<Node> consumerC3D = Names::Find<Node>("C3D");
  Ptr<Node> consumerC4D = Names::Find<Node>("C4D");
  Ptr<Node> consumerC5D = Names::Find<Node>("C5D");
 

 ////////////// First Poll of Producer//////////////////
  Ptr<Node> producerP1A = Names::Find<Node>("P1A");
  Ptr<Node> producerP2A = Names::Find<Node>("P2A");
  Ptr<Node> producerP3A = Names::Find<Node>("P3A");
  Ptr<Node> producerP4A = Names::Find<Node>("P4A");
  Ptr<Node> producerP5A = Names::Find<Node>("P5A");

  ////////////// sECOND Poll of Producer//////////////////
  Ptr<Node> producerP1B = Names::Find<Node>("P1B");
  Ptr<Node> producerP2B = Names::Find<Node>("P2B");
  Ptr<Node> producerP3B = Names::Find<Node>("P3B");
  Ptr<Node> producerP4B = Names::Find<Node>("P4B");
  Ptr<Node> producerP5B = Names::Find<Node>("P5B");
 
////////////// tHIRD Poll of Producer//////////////////
  Ptr<Node> producerP1C = Names::Find<Node>("P1C");
  Ptr<Node> producerP2C = Names::Find<Node>("P2C");
  Ptr<Node> producerP3C = Names::Find<Node>("P3C");
  Ptr<Node> producerP4C = Names::Find<Node>("P4C");
  Ptr<Node> producerP5C = Names::Find<Node>("P5C");

  Ptr<Node> producerP1D = Names::Find<Node>("P1D");
  Ptr<Node> producerP2D = Names::Find<Node>("P2D");
  Ptr<Node> producerP3D = Names::Find<Node>("P3D");
  Ptr<Node> producerP4D = Names::Find<Node>("P4D");
  Ptr<Node> producerP5D = Names::Find<Node>("P5D");
 

 // std::cout << "Producer1" << producer1->GetId() <<std::endl;
//======================================================================



//==== List of Available forwarding strategy and Custom Strategy =======
// ndn::StrategyChoiceHelper::InstallAll("/Controller", "/localhost/nfd/strategy/broadcast");
// ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/multicast");
// ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/best-route");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/client-control");
  ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/ncc");
  //ndn::StrategyChoiceHelper::InstallAll("/edu.bit.cn/", "/localhost/nfd/strategy/best-route");
  
//============== Custom Strategy =======================================
  
  //ndn::StrategyChoiceHelper::Install<nfd_fw::ControllerStrategy>(Names::Find<Node>("R0"), "/edu.bit.cn/");    

//======================================================================


//=== Installation of NDN applications (Consumer, Producer and Custom)==

 
 //=== Installation of NDN applications (Consumer, Producer and Custom)==

 
 
  ndn::AppHelper appC1A("CustomConsumer");
  
  appC1A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1A=appC1A.Install(consumerC1A);
  comsumerappC1A.Start(Seconds(4));
  comsumerappC1A.Stop(Seconds(24));

 ndn::AppHelper appC2A("CustomConsumer");
  
  appC2A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2A=appC2A.Install(consumerC2A);
  comsumerappC2A.Start(Seconds(4));
  comsumerappC2A.Stop(Seconds(24));

  ndn::AppHelper appC3A("CustomConsumer");
  
  appC3A.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC3A=appC3A.Install(consumerC3A);
  comsumerappC3A.Start(Seconds(5));
  comsumerappC3A.Stop(Seconds(25));

  
  ndn::AppHelper appC1B("CustomConsumer");
  
  appC1B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1B=appC1B.Install(consumerC1B);
  comsumerappC1B.Start(Seconds(4));
  comsumerappC1B.Stop(Seconds(24));

 ndn::AppHelper appC2B("CustomConsumer");
  
  appC2B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2B=appC2B.Install(consumerC2B);
  comsumerappC2B.Start(Seconds(5));
  comsumerappC2B.Stop(Seconds(25));

  ndn::AppHelper appC3B("CustomConsumer");
  
  appC3B.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC3B=appC3B.Install(consumerC3B);
  comsumerappC3B.Start(Seconds(6));
  comsumerappC3B.Stop(Seconds(26));

  

  ndn::AppHelper appC1C("CustomConsumer");
  
 
  appC1C.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1C=appC1C.Install(consumerC1C);
  comsumerappC1C.Start(Seconds(7));
  comsumerappC1C.Stop(Seconds(27));

  
  ndn::AppHelper appC2C("CustomConsumer");
  
 
  appC2C.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2C=appC2C.Install(consumerC2C);
  comsumerappC2C.Start(Seconds(7));
  comsumerappC2C.Stop(Seconds(27));

  

  ndn::AppHelper appC1D("CustomConsumer");
  
 
  appC1D.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC1D=appC1D.Install(consumerC1D);
  comsumerappC1D.Start(Seconds(8));
  comsumerappC1D.Stop(Seconds(28));

  
  ndn::AppHelper appC2D("CustomConsumer");
  
 
  appC2D.SetAttribute("Frequency", StringValue("15"));
  ApplicationContainer comsumerappC2D=appC2D.Install(consumerC2D);
  comsumerappC2D.Start(Seconds(8));
  comsumerappC2D.Stop(Seconds(28));



  
  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1B("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP1B=appP1B.Install(producerP1B);
  producerappP1B.Start(Seconds(1));
  producerappP1B.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2B("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP2B=appP2B.Install(producerP2B);
  producerappP2B.Start(Seconds(1));
  producerappP2B.Stop(Seconds(40));


  ndn::AppHelper appP3B("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP3B=appP3B.Install(producerP3B);
  producerappP3B.Start(Seconds(1));
  producerappP3B.Stop(Seconds(40));


  ndn::AppHelper appP4B("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP4B=appP4B.Install(producerP4B);
  producerappP4B.Start(Seconds(1));
  producerappP4B.Stop(Seconds(40));


  ndn::AppHelper appP5B("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP5B=appP5B.Install(producerP5B);
  producerappP5B.Start(Seconds(1));
  producerappP5B.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1C("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP1C=appP1C.Install(producerP1C);
  producerappP1C.Start(Seconds(1));
  producerappP1C.Stop(Seconds(40));

  ndn::AppHelper appP2C("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP2C=appP2C.Install(producerP2C);
  producerappP2C.Start(Seconds(1));
  producerappP2C.Stop(Seconds(40));


  ndn::AppHelper appP3C("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP3C=appP3C.Install(producerP3C);
  producerappP3C.Start(Seconds(1));
  producerappP3C.Stop(Seconds(40));


  ndn::AppHelper appP4C("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP4C=appP4C.Install(producerP4C);
  producerappP4C.Start(Seconds(1));
  producerappP4C.Stop(Seconds(40));



   ndn::AppHelper appP5C("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP5C=appP5C.Install(producerP5C);
  producerappP5C.Start(Seconds(1));
  producerappP5C.Stop(Seconds(40));

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1A("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP1A=appP1A.Install(producerP1A);
  producerappP1A.Start(Seconds(1));
  producerappP1A.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2A("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP2A=appP2A.Install(producerP2A);
  producerappP2A.Start(Seconds(1));
  producerappP2A.Stop(Seconds(40));


  ndn::AppHelper appP3A("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP3A=appP3A.Install(producerP3A);
  producerappP3A.Start(Seconds(1));
  producerappP3A.Stop(Seconds(40));


  ndn::AppHelper appP4A("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP4A=appP4A.Install(producerP4A);
  producerappP4A.Start(Seconds(1));
  producerappP4A.Stop(Seconds(40));


  ndn::AppHelper appP5A("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP5A=appP5A.Install(producerP5A);
  producerappP5A.Start(Seconds(1));
  producerappP5A.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1D("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP1D=appP1D.Install(producerP1D);
  producerappP1D.Start(Seconds(1));
  producerappP1D.Stop(Seconds(40));

  ndn::AppHelper appP2D("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP2D=appP2D.Install(producerP2D);
  producerappP2D.Start(Seconds(1));
  producerappP2D.Stop(Seconds(40));


  ndn::AppHelper appP3D("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP3D=appP3D.Install(producerP3D);
  producerappP3D.Start(Seconds(1));
  producerappP3D.Stop(Seconds(40));


  ndn::AppHelper appP4D("ns3::ndn::Producer");
  
  
                  
  ApplicationContainer producerappP4D=appP4D.Install(producerP4D);
  producerappP4D.Start(Seconds(1));
  producerappP4D.Stop(Seconds(40));



   ndn::AppHelper appP5D("ns3::ndn::Producer");
  
                  
  ApplicationContainer producerappP5D=appP5D.Install(producerP5D);
  producerappP5D.Start(Seconds(1));
  producerappP5D.Stop(Seconds(40));




/////////////////////////////////////////////////////////////////////////////
  */


//======================================================================
//===== Manual Routing (Depends on the nature of Experiment)============
//======================================================================
/*
 ndn::FibHelper::AddRoute("C1", "/Controller", "R5", 0);
 ndn::FibHelper::AddRoute("R5", "/Controller", "R0", 0);
 ndn::FibHelper::AddRoute("P1", "/Controller", "R6", 0);
 ndn::FibHelper::AddRoute("R6", "/Controller", "R0", 0);
*/
//======= Trace Simulation Results as Txt File =========================

  //ndn::CsTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_Cs_tracer.txt", Seconds(1.0));
  //ndn::L3RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_L3_rate_trace.txt", Seconds(1.0));
  //ndn::AppDelayTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_app_delays_trace.txt");
  //L2RateTracer::InstallAll("/home/usery/ndnSIM/my-simulations/results/ndn_l2_drop_trace.txt", Seconds(1.0));

//======================================================================

   
//==== Schedule simulation time and run the simulation =================

  Simulator::Stop(Seconds(40.0));

  //Simulator::Schedule(Seconds(5.0), ndn::LinkControlHelper::FailLinkByName, "R1", "R2");
  //Simulator::Schedule(Seconds(15.0), ndn::LinkControlHelper::UpLinkByName, "R1", "R2");

  Simulator::Run();
  Simulator::Destroy();

//======================================================================

  return 0;
}
 // ndn namespace
} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
