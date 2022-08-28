//===== Scenario to Test Scenarios under Multiple Conditions============
//=============Beijing Institute of Technology==========================


//======== Calling NS-3 and ndnSIM Necessary Header Files ==============

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
  Ptr<Node> consumerC4A = Names::Find<Node>("consumer-4");
  Ptr<Node> consumerC5A = Names::Find<Node>("consumer-5");
  Ptr<Node> consumerC6A = Names::Find<Node>("consumer-6");
  Ptr<Node> consumerC7A = Names::Find<Node>("consumer-7");
  Ptr<Node> consumerC8A = Names::Find<Node>("consumer-8");
  Ptr<Node> consumerC9A = Names::Find<Node>("consumer-9");
  Ptr<Node> consumerC10A = Names::Find<Node>("consumer-10");
  Ptr<Node> consumerC11A = Names::Find<Node>("consumer-11");
  Ptr<Node> consumerC12A = Names::Find<Node>("consumer-12");
  Ptr<Node> consumerC13A = Names::Find<Node>("consumer-13");
  Ptr<Node> consumerC14A = Names::Find<Node>("consumer-14");
  Ptr<Node> consumerC15A = Names::Find<Node>("consumer-15");
  Ptr<Node> consumerC16A = Names::Find<Node>("consumer-16");
  Ptr<Node> consumerC17A = Names::Find<Node>("consumer-17");
  Ptr<Node> consumerC18A = Names::Find<Node>("consumer-18");
  Ptr<Node> consumerC21A = Names::Find<Node>("consumer-21");
  Ptr<Node> consumerC22A = Names::Find<Node>("consumer-22");
  Ptr<Node> consumerC23A = Names::Find<Node>("consumer-23");
  Ptr<Node> consumerC24A = Names::Find<Node>("consumer-24");
  Ptr<Node> consumerC25A = Names::Find<Node>("consumer-25");
  

////////////// SECOND Poll of Consumer//////////////////
  ////////////// SECOND Poll of Consumer//////////////////
  
  Ptr<Node> consumerC1B = Names::Find<Node>("consumer-26");
  Ptr<Node> consumerC2B = Names::Find<Node>("consumer-27");
  Ptr<Node> consumerC3B = Names::Find<Node>("consumer-28");
  Ptr<Node> consumerC4B = Names::Find<Node>("consumer-29");
  Ptr<Node> consumerC5B = Names::Find<Node>("consumer-30");
  Ptr<Node> consumerC6B = Names::Find<Node>("consumer-31");
  Ptr<Node> consumerC7B = Names::Find<Node>("consumer-32");
  Ptr<Node> consumerC8B = Names::Find<Node>("consumer-33");
  Ptr<Node> consumerC9B = Names::Find<Node>("consumer-34");
  Ptr<Node> consumerC10B = Names::Find<Node>("consumer-35");
  Ptr<Node> consumerC11B = Names::Find<Node>("consumer-36");
  Ptr<Node> consumerC12B = Names::Find<Node>("consumer-37");
  Ptr<Node> consumerC13B = Names::Find<Node>("consumer-38");
  Ptr<Node> consumerC14B = Names::Find<Node>("consumer-39");
  Ptr<Node> consumerC15B = Names::Find<Node>("consumer-40");
  Ptr<Node> consumerC18B = Names::Find<Node>("consumer-43");
  Ptr<Node> consumerC19B = Names::Find<Node>("consumer-44");
  Ptr<Node> consumerC20B = Names::Find<Node>("consumer-45");
  Ptr<Node> consumerC21B = Names::Find<Node>("consumer-46");
  Ptr<Node> consumerC22B = Names::Find<Node>("consumer-47");
  Ptr<Node> consumerC23B = Names::Find<Node>("consumer-48");
  Ptr<Node> consumerC24B = Names::Find<Node>("consumer-49");
  Ptr<Node> consumerC25B = Names::Find<Node>("consumer-50");

////////////// Third Poll of Consumer//////////////////
  ////////////// Third Poll of Consumer//////////////////
  Ptr<Node> consumerC1C = Names::Find<Node>("consumer-51");
  Ptr<Node> consumerC2C = Names::Find<Node>("consumer-52");
  Ptr<Node> consumerC3C = Names::Find<Node>("consumer-53");
  Ptr<Node> consumerC4C = Names::Find<Node>("consumer-54");
  Ptr<Node> consumerC5C = Names::Find<Node>("consumer-55");
  Ptr<Node> consumerC6C = Names::Find<Node>("consumer-56");
  Ptr<Node> consumerC7C = Names::Find<Node>("consumer-57");
  Ptr<Node> consumerC8C = Names::Find<Node>("consumer-58");
  Ptr<Node> consumerC9C = Names::Find<Node>("consumer-59");
  Ptr<Node> consumerC10C = Names::Find<Node>("consumer-60");
  Ptr<Node> consumerC13C = Names::Find<Node>("consumer-63");
  Ptr<Node> consumerC14C = Names::Find<Node>("consumer-64");
  Ptr<Node> consumerC15C = Names::Find<Node>("consumer-65");
  Ptr<Node> consumerC16C = Names::Find<Node>("consumer-66");
  Ptr<Node> consumerC17C = Names::Find<Node>("consumer-67");
  Ptr<Node> consumerC18C = Names::Find<Node>("consumer-68");
  Ptr<Node> consumerC19C = Names::Find<Node>("consumer-69");
  Ptr<Node> consumerC20C = Names::Find<Node>("consumer-70");
  Ptr<Node> consumerC21C = Names::Find<Node>("consumer-71");
  Ptr<Node> consumerC22C = Names::Find<Node>("consumer-72");
  Ptr<Node> consumerC23C = Names::Find<Node>("consumer-73");
  Ptr<Node> consumerC24C = Names::Find<Node>("consumer-74");
  Ptr<Node> consumerC25C = Names::Find<Node>("consumer-75");

////////////// fOURTH Poll of Consumer//////////////////
  ////////////// fOURTH Poll of Consumer//////////////////
  Ptr<Node> consumerC1D = Names::Find<Node>("consumer-76");
  Ptr<Node> consumerC2D = Names::Find<Node>("consumer-77");
  Ptr<Node> consumerC3D = Names::Find<Node>("consumer-78");
  Ptr<Node> consumerC4D = Names::Find<Node>("consumer-79");
  Ptr<Node> consumerC5D = Names::Find<Node>("consumer-80");
  Ptr<Node> consumerC8D = Names::Find<Node>("consumer-83");
  Ptr<Node> consumerC9D = Names::Find<Node>("consumer-84");
  Ptr<Node> consumerC10D = Names::Find<Node>("consumer-85");
  Ptr<Node> consumerC11D = Names::Find<Node>("consumer-86");
  Ptr<Node> consumerC12D = Names::Find<Node>("consumer-87");
  Ptr<Node> consumerC13D = Names::Find<Node>("consumer-88");
  Ptr<Node> consumerC14D = Names::Find<Node>("consumer-89");
  Ptr<Node> consumerC15D = Names::Find<Node>("consumer-90");
  Ptr<Node> consumerC16D = Names::Find<Node>("consumer-91");
  Ptr<Node> consumerC17D = Names::Find<Node>("consumer-92");
  Ptr<Node> consumerC18D = Names::Find<Node>("consumer-93");
  Ptr<Node> consumerC19D = Names::Find<Node>("consumer-94");
  Ptr<Node> consumerC20D = Names::Find<Node>("consumer-95");
  Ptr<Node> consumerC21D = Names::Find<Node>("consumer-96");
  Ptr<Node> consumerC22D = Names::Find<Node>("consumer-97");
  Ptr<Node> consumerC23D = Names::Find<Node>("consumer-98");
  
  ndn::AppHelper appC1A("CustomConsumer2");
  
  appC1A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1A=appC1A.Install(consumerC1A);
  comsumerappC1A.Start(Seconds(8.6));
  comsumerappC1A.Stop(Seconds(28.6));

 ndn::AppHelper appC2A("CustomConsumer2");
  
  appC2A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2A=appC2A.Install(consumerC2A);
  comsumerappC2A.Start(Seconds(8.8));
  comsumerappC2A.Stop(Seconds(28.8));

  ndn::AppHelper appC3A("CustomConsumer2");
  
  appC3A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3A=appC3A.Install(consumerC3A);
  comsumerappC3A.Start(Seconds(9));
  comsumerappC3A.Stop(Seconds(29));

 
  ndn::AppHelper appC4A("CustomConsumer2");
  
  appC4A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC4A=appC4A.Install(consumerC4A);
  comsumerappC4A.Start(Seconds(9.2));
  comsumerappC4A.Stop(Seconds(29.2));

 
  ndn::AppHelper appC5A("CustomConsumer2");
  
  appC5A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC5A=appC5A.Install(consumerC5A);
  comsumerappC5A.Start(Seconds(9.4));
  comsumerappC5A.Stop(Seconds(29.4));

 ndn::AppHelper appC6A("CustomConsumer2");
  
  appC6A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC6A=appC6A.Install(consumerC6A);
  comsumerappC6A.Start(Seconds(9.6));
  comsumerappC6A.Stop(Seconds(29.6));

  ndn::AppHelper appC7A("CustomConsumer2");
  
  appC7A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC7A=appC7A.Install(consumerC7A);
  comsumerappC7A.Start(Seconds(9.8));
  comsumerappC7A.Stop(Seconds(29.8));

 
  ndn::AppHelper appC8A("CustomConsumer2");
  
  appC8A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC8A=appC8A.Install(consumerC8A);
  comsumerappC8A.Start(Seconds(10));
  comsumerappC8A.Stop(Seconds(30));

 
  ndn::AppHelper appC9A("CustomConsumer2");
  
  appC9A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC9A=appC9A.Install(consumerC9A);
  comsumerappC9A.Start(Seconds(10.2));
  comsumerappC9A.Stop(Seconds(30.2));

 ndn::AppHelper appC10A("CustomConsumer2");
  
  appC10A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC10A=appC10A.Install(consumerC10A);
  comsumerappC10A.Start(Seconds(10.4));
  comsumerappC10A.Stop(Seconds(30.4));

///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Ten Consumer///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

  ndn::AppHelper appC11A("CustomConsumer2");
  
  appC11A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC11A=appC11A.Install(consumerC11A);
  comsumerappC11A.Start(Seconds(10.6));
  comsumerappC11A.Stop(Seconds(30.6));

 ndn::AppHelper appC12A("CustomConsumer2");
  
  appC12A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC12A=appC12A.Install(consumerC12A);
  comsumerappC12A.Start(Seconds(10.8));
  comsumerappC12A.Stop(Seconds(30.8));

  ndn::AppHelper appC13A("CustomConsumer2");
  
  appC13A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC13A=appC13A.Install(consumerC13A);
  comsumerappC13A.Start(Seconds(11));
  comsumerappC13A.Stop(Seconds(31));

 
  ndn::AppHelper appC14A("CustomConsumer2");
  
  appC14A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC14A=appC14A.Install(consumerC14A);
  comsumerappC14A.Start(Seconds(11.2));
  comsumerappC14A.Stop(Seconds(31.2));

 
  ndn::AppHelper appC15A("CustomConsumer2");
  
  appC15A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC15A=appC15A.Install(consumerC15A);
  comsumerappC15A.Start(Seconds(11.4));
  comsumerappC15A.Stop(Seconds(31.4));

 ndn::AppHelper appC16A("CustomConsumer2");
  
  appC16A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC16A=appC16A.Install(consumerC16A);
  comsumerappC16A.Start(Seconds(11.6));
  comsumerappC16A.Stop(Seconds(31.6));

  ndn::AppHelper appC17A("CustomConsumer2");
  
  appC17A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC17A=appC17A.Install(consumerC17A);
  comsumerappC17A.Start(Seconds(11.8));
  comsumerappC17A.Stop(Seconds(31.8));

 
  ndn::AppHelper appC18A("CustomConsumer2");
  
  appC18A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC18A=appC18A.Install(consumerC18A);
  comsumerappC18A.Start(Seconds(12));
  comsumerappC18A.Stop(Seconds(32));

 
  
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last Of Consumers////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC21A("CustomConsumer2");
  
  appC21A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC21A=appC21A.Install(consumerC21A);
  comsumerappC21A.Start(Seconds(12.6));
  comsumerappC21A.Stop(Seconds(32.6));

 ndn::AppHelper appC22A("CustomConsumer2");
  
  appC22A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC22A=appC22A.Install(consumerC22A);
  comsumerappC22A.Start(Seconds(12.8));
  comsumerappC22A.Stop(Seconds(32.8));

  ndn::AppHelper appC23A("CustomConsumer2");
  
  appC23A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC23A=appC23A.Install(consumerC23A);
  comsumerappC23A.Start(Seconds(13));
  comsumerappC23A.Stop(Seconds(33));

 
  ndn::AppHelper appC24A("CustomConsumer2");
  
  appC24A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC24A=appC24A.Install(consumerC24A);
  comsumerappC24A.Start(Seconds(13.2));
  comsumerappC24A.Stop(Seconds(33.2));

 
  ndn::AppHelper appC25A("CustomConsumer2");
  
  appC25A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC25A=appC25A.Install(consumerC25A);
  comsumerappC25A.Start(Seconds(13.4));
  comsumerappC25A.Stop(Seconds(33.4));



  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC1B("CustomConsumer2");
  
  appC1B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1B=appC1B.Install(consumerC1B);
  comsumerappC1B.Start(Seconds(13.6));
  comsumerappC1B.Stop(Seconds(33.6));

 ndn::AppHelper appC2B("CustomConsumer2");
  
  appC2B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2B=appC2B.Install(consumerC2B);
  comsumerappC2B.Start(Seconds(13.8));
  comsumerappC2B.Stop(Seconds(33.8));

  ndn::AppHelper appC3B("CustomConsumer2");
  
  appC3B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3B=appC3B.Install(consumerC3B);
  comsumerappC3B.Start(Seconds(14));
  comsumerappC3B.Stop(Seconds(34));

   ndn::AppHelper appC4B("CustomConsumer2");
  
  appC4B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC4B=appC4B.Install(consumerC4B);
  comsumerappC4B.Start(Seconds(14.2));
  comsumerappC4B.Stop(Seconds(34.2));

 ndn::AppHelper appC5B("CustomConsumer2");
  
  appC5B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC5B=appC5B.Install(consumerC5B);
  comsumerappC5B.Start(Seconds(14.4));
  comsumerappC5B.Stop(Seconds(34.4));

  ndn::AppHelper appC6B("CustomConsumer2");
  
  appC6B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC6B=appC6B.Install(consumerC6B);
  comsumerappC6B.Start(Seconds(14.6));
  comsumerappC6B.Stop(Seconds(34.6));


  ndn::AppHelper appC7B("CustomConsumer2");
  
  appC7B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC7B=appC7B.Install(consumerC7B);
  comsumerappC7B.Start(Seconds(14.8));
  comsumerappC7B.Stop(Seconds(34.8));

   ndn::AppHelper appC8B("CustomConsumer2");
  
  appC8B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC8B=appC8B.Install(consumerC8B);
  comsumerappC8B.Start(Seconds(15));
  comsumerappC8B.Stop(Seconds(35));

 ndn::AppHelper appC9B("CustomConsumer2");
  
  appC9B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC9B=appC9B.Install(consumerC9B);
  comsumerappC9B.Start(Seconds(15.2));
  comsumerappC9B.Stop(Seconds(35.2));

  ndn::AppHelper appC10B("CustomConsumer2");
  
  appC10B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC10B=appC10B.Install(consumerC10B);
  comsumerappC10B.Start(Seconds(15.4));
  comsumerappC10B.Stop(Seconds(35.4));


//////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC11B("CustomConsumer2");
  
  appC11B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC11B=appC11B.Install(consumerC11B);
  comsumerappC11B.Start(Seconds(15.6));
  comsumerappC11B.Stop(Seconds(35.6));

 ndn::AppHelper appC12B("CustomConsumer2");
  
  appC12B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC12B=appC12B.Install(consumerC12B);
  comsumerappC12B.Start(Seconds(15.8));
  comsumerappC12B.Stop(Seconds(35.8));

  ndn::AppHelper appC13B("CustomConsumer2");
  
  appC13B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC13B=appC13B.Install(consumerC13B);
  comsumerappC13B.Start(Seconds(16));
  comsumerappC13B.Stop(Seconds(36));

   ndn::AppHelper appC14B("CustomConsumer2");
  
  appC14B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC14B=appC14B.Install(consumerC14B);
  comsumerappC14B.Start(Seconds(16.2));
  comsumerappC14B.Stop(Seconds(36.2));

 ndn::AppHelper appC15B("CustomConsumer2");
  
  appC15B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC15B=appC15B.Install(consumerC15B);
  comsumerappC15B.Start(Seconds(16.4));
  comsumerappC15B.Stop(Seconds(36.4));

   ndn::AppHelper appC18B("CustomConsumer2");
  
  appC18B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC18B=appC18B.Install(consumerC18B);
  comsumerappC18B.Start(Seconds(17));
  comsumerappC18B.Stop(Seconds(37));

 ndn::AppHelper appC19B("CustomConsumer2");
  
  appC19B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC19B=appC19B.Install(consumerC19B);
  comsumerappC19B.Start(Seconds(17.2));
  comsumerappC19B.Stop(Seconds(37.2));

  ndn::AppHelper appC20B("CustomConsumer2");
  
  appC20B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC20B=appC20B.Install(consumerC20B);
  comsumerappC20B.Start(Seconds(17.4));
  comsumerappC20B.Stop(Seconds(37.4));
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last twenty Five B//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


 ndn::AppHelper appC21B("CustomConsumer2");
  
  appC21B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC21B=appC21B.Install(consumerC21B);
  comsumerappC21B.Start(Seconds(17.6));
  comsumerappC21B.Stop(Seconds(37.6));

 ndn::AppHelper appC22B("CustomConsumer2");
  
  appC22B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC22B=appC22B.Install(consumerC22B);
  comsumerappC22B.Start(Seconds(17.8));
  comsumerappC22B.Stop(Seconds(37.8));

  ndn::AppHelper appC23B("CustomConsumer2");
  
  appC23B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC23B=appC23B.Install(consumerC23B);
  comsumerappC23B.Start(Seconds(18));
  comsumerappC23B.Stop(Seconds(38));

   ndn::AppHelper appC24B("CustomConsumer2");
  
  appC24B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC24B=appC24B.Install(consumerC24B);
  comsumerappC24B.Start(Seconds(18.2));
  comsumerappC24B.Stop(Seconds(38.2));

 ndn::AppHelper appC25B("CustomConsumer2");
  
  appC25B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC25B=appC25B.Install(consumerC25B);
  comsumerappC25B.Start(Seconds(18.4));
  comsumerappC25B.Stop(Seconds(38.4));

 

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

  ndn::AppHelper appC1C("CustomConsumer2");
  
 
  appC1C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1C=appC1C.Install(consumerC1C);
  comsumerappC1C.Start(Seconds(18.6));
  comsumerappC1C.Stop(Seconds(38.6));

  
  ndn::AppHelper appC2C("CustomConsumer2");
  
 
  appC2C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2C=appC2C.Install(consumerC2C);
  comsumerappC2C.Start(Seconds(18.8));
  comsumerappC2C.Stop(Seconds(38.6));

 ndn::AppHelper appC3C("CustomConsumer2");
  
 
  appC3C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3C=appC3C.Install(consumerC3C);
  comsumerappC3C.Start(Seconds(19));
  comsumerappC3C.Stop(Seconds(39));

  
  ndn::AppHelper appC4C("CustomConsumer2");
  
 
  appC4C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC4C=appC4C.Install(consumerC4C);
  comsumerappC4C.Start(Seconds(19.2));
  comsumerappC4C.Stop(Seconds(39.2));

  ndn::AppHelper appC5C("CustomConsumer2");
  
 
  appC5C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC5C=appC5C.Install(consumerC5C);
  comsumerappC5C.Start(Seconds(19.4));
  comsumerappC5C.Stop(Seconds(39.4));

  
  ndn::AppHelper appC6C("CustomConsumer2");
  
 
  appC6C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC6C=appC6C.Install(consumerC6C);
  comsumerappC6C.Start(Seconds(19.6));
  comsumerappC6C.Stop(Seconds(39.6));


ndn::AppHelper appC7C("CustomConsumer2");
  
 
  appC7C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC7C=appC7C.Install(consumerC7C);
  comsumerappC7C.Start(Seconds(19.8));
  comsumerappC7C.Stop(Seconds(39.8));

  
  ndn::AppHelper appC8C("CustomConsumer2");
  
 
  appC8C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC8C=appC8C.Install(consumerC8C);
  comsumerappC8C.Start(Seconds(3.4));
  comsumerappC8C.Stop(Seconds(23.4));

ndn::AppHelper appC9C("CustomConsumer2");
  
 
  appC9C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC9C=appC9C.Install(consumerC9C);
  comsumerappC9C.Start(Seconds(3.6));
  comsumerappC9C.Stop(Seconds(23.6));

  
  ndn::AppHelper appC10C("CustomConsumer2");
  
 
  appC10C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC10C=appC10C.Install(consumerC10C);
  comsumerappC10C.Start(Seconds(3.8));
  comsumerappC10C.Stop(Seconds(23.8));




//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  


 ndn::AppHelper appC13C("CustomConsumer2");
  
 
  appC13C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC13C=appC13C.Install(consumerC13C);
  comsumerappC13C.Start(Seconds(4.6));
  comsumerappC13C.Stop(Seconds(24.6));

  
  ndn::AppHelper appC14C("CustomConsumer2");
  
 
  appC14C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC14C=appC14C.Install(consumerC14C);
  comsumerappC14C.Start(Seconds(4.8));
  comsumerappC14C.Stop(Seconds(24.8));

  ndn::AppHelper appC15C("CustomConsumer2");
  
 
  appC15C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC15C=appC15C.Install(consumerC15C);
  comsumerappC15C.Start(Seconds(5));
  comsumerappC15C.Stop(Seconds(25));

  
  ndn::AppHelper appC16C("CustomConsumer2");
  
 
  appC16C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC16C=appC16C.Install(consumerC16C);
  comsumerappC16C.Start(Seconds(5.2));
  comsumerappC16C.Stop(Seconds(25.2));


ndn::AppHelper appC17C("CustomConsumer2");
  
 
  appC17C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC17C=appC17C.Install(consumerC17C);
  comsumerappC17C.Start(Seconds(5.4));
  comsumerappC17C.Stop(Seconds(25.4));

  
  ndn::AppHelper appC18C("CustomConsumer2");
  
 
  appC18C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC18C=appC18C.Install(consumerC18C);
  comsumerappC18C.Start(Seconds(5.6));
  comsumerappC18C.Stop(Seconds(25.6));

ndn::AppHelper appC19C("CustomConsumer2");
  
 
  appC19C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC19C=appC19C.Install(consumerC19C);
  comsumerappC19C.Start(Seconds(5.8));
  comsumerappC19C.Stop(Seconds(25.8));

  
  ndn::AppHelper appC20C("CustomConsumer2");
  
 
  appC20C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC20C=appC20C.Install(consumerC20C);
  comsumerappC20C.Start(Seconds(6));
  comsumerappC20C.Stop(Seconds(26));



 ndn::AppHelper appC21C("CustomConsumer2");
  
 
  appC21C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC21C=appC21C.Install(consumerC21C);
  comsumerappC21C.Start(Seconds(6.4));
  comsumerappC21C.Stop(Seconds(26.4));

  
  ndn::AppHelper appC22C("CustomConsumer2");
  
 
  appC22C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC22C=appC22C.Install(consumerC22C);
  comsumerappC22C.Start(Seconds(6.8));
  comsumerappC22C.Stop(Seconds(26.8));

 ndn::AppHelper appC23C("CustomConsumer2");
  
 
  appC23C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC23C=appC23C.Install(consumerC23C);
  comsumerappC23C.Start(Seconds(7));
  comsumerappC23C.Stop(Seconds(27));

  
  ndn::AppHelper appC24C("CustomConsumer2");
  
 
  appC24C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC24C=appC24C.Install(consumerC4C);
  comsumerappC24C.Start(Seconds(7.5));
  comsumerappC24C.Stop(Seconds(27.5));

  ndn::AppHelper appC25C("CustomConsumer2");
  
 
  appC25C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC25C=appC25C.Install(consumerC25C);
  comsumerappC25C.Start(Seconds(8));
  comsumerappC25C.Stop(Seconds(28));

  

  //////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////D Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC1D("CustomConsumer2");
  
  appC1D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1D=appC1D.Install(consumerC1D);
  comsumerappC1D.Start(Seconds(3.4));
  comsumerappC1D.Stop(Seconds(23.4));

 ndn::AppHelper appC2D("CustomConsumer2");
  
  appC2D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2D=appC2D.Install(consumerC2D);
  comsumerappC2D.Start(Seconds(3.6));
  comsumerappC2D.Stop(Seconds(23.6));

  ndn::AppHelper appC3D("CustomConsumer2");
  
  appC3D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3D=appC3D.Install(consumerC3D);
  comsumerappC3D.Start(Seconds(3.8));
  comsumerappC3D.Stop(Seconds(23.8));

   ndn::AppHelper appC4D("CustomConsumer2");
  
  appC4D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC4D=appC4D.Install(consumerC4D);
  comsumerappC4D.Start(Seconds(4));
  comsumerappC4D.Stop(Seconds(24));

 ndn::AppHelper appC5D("CustomConsumer2");
  
  appC5D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC5D=appC5D.Install(consumerC5D);
  comsumerappC5D.Start(Seconds(4.2));
  comsumerappC5D.Stop(Seconds(24.2));


   ndn::AppHelper appC8D("CustomConsumer2");
  
  appC8D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC8D=appC8D.Install(consumerC8D);
  comsumerappC8D.Start(Seconds(4.8));
  comsumerappC8D.Stop(Seconds(24.8));

 ndn::AppHelper appC9D("CustomConsumer2");
  
  appC9D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC9D=appC9D.Install(consumerC9D);
  comsumerappC9D.Start(Seconds(5));
  comsumerappC9D.Stop(Seconds(25));

  ndn::AppHelper appC10D("CustomConsumer2");
  
  appC10D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC10D=appC10D.Install(consumerC10D);
  comsumerappC10D.Start(Seconds(5.2));
  comsumerappC10D.Stop(Seconds(25.2));


//////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC11D("CustomConsumer2");
  
  appC11D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC11D=appC11D.Install(consumerC11D);
  comsumerappC11D.Start(Seconds(5.4));
  comsumerappC11D.Stop(Seconds(25.4));

 ndn::AppHelper appC12D("CustomConsumer2");
  
  appC12D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC12D=appC12D.Install(consumerC12D);
  comsumerappC12D.Start(Seconds(5.6));
  comsumerappC12D.Stop(Seconds(25.6));

  ndn::AppHelper appC13D("CustomConsumer2");
  
  appC13D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC13D=appC13D.Install(consumerC13D);
  comsumerappC13D.Start(Seconds(5.8));
  comsumerappC13D.Stop(Seconds(25.8));

   ndn::AppHelper appC14D("CustomConsumer2");
  
  appC14D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC14D=appC14D.Install(consumerC14D);
  comsumerappC14D.Start(Seconds(6));
  comsumerappC14D.Stop(Seconds(26));

 ndn::AppHelper appC15D("CustomConsumer2");
  
  appC15D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC15D=appC15D.Install(consumerC15D);
  comsumerappC15D.Start(Seconds(6.2));
  comsumerappC15D.Stop(Seconds(26.2));

  ndn::AppHelper appC16D("CustomConsumer2");
  
  appC16D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC16D=appC16D.Install(consumerC16D);
  comsumerappC16D.Start(Seconds(6.4));
  comsumerappC16D.Stop(Seconds(26.4));


  ndn::AppHelper appC17D("CustomConsumer2");
  
  appC17D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC17D=appC17D.Install(consumerC17D);
  comsumerappC17D.Start(Seconds(6.8));
  comsumerappC17D.Stop(Seconds(26.8));

   ndn::AppHelper appC18D("CustomConsumer2");
  
  appC18D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC18D=appC18D.Install(consumerC18D);
  comsumerappC18D.Start(Seconds(7));
  comsumerappC18D.Stop(Seconds(27));

 ndn::AppHelper appC19D("CustomConsumer2");
  
  appC19D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC19D=appC19D.Install(consumerC19D);
  comsumerappC19D.Start(Seconds(7.2));
  comsumerappC19D.Stop(Seconds(27.2));

  ndn::AppHelper appC20D("CustomConsumer2");
  
  appC20D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC20D=appC20D.Install(consumerC20D);
  comsumerappC20D.Start(Seconds(7.4));
  comsumerappC20D.Stop(Seconds(27.4));
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last twenty Five B//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


 ndn::AppHelper appC21D("CustomConsumer2");
  
  appC21D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC21D=appC21D.Install(consumerC21D);
  comsumerappC21D.Start(Seconds(7.6));
  comsumerappC21D.Stop(Seconds(27.6));

 ndn::AppHelper appC22D("CustomConsumer2");
  
  appC22D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC22D=appC22D.Install(consumerC22D);
  comsumerappC22D.Start(Seconds(7.8));
  comsumerappC22D.Stop(Seconds(27.8));

  ndn::AppHelper appC23D("CustomConsumer2");
  
  appC23D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC23D=appC23D.Install(consumerC23D);
  comsumerappC23D.Start(Seconds(8));
  comsumerappC23D.Stop(Seconds(28));

 

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1B("CustomProducer");
  
  appP1B.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP1B=appP1B.Install(producerP1B);
  producerappP1B.Start(Seconds(1));
  producerappP1B.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2B("CustomProducer");
  
  appP2B.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP2B=appP2B.Install(producerP2B);
  producerappP2B.Start(Seconds(1));
  producerappP2B.Stop(Seconds(40));


  ndn::AppHelper appP3B("CustomProducer");
  
  appP3B.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP3B=appP3B.Install(producerP3B);
  producerappP3B.Start(Seconds(1));
  producerappP3B.Stop(Seconds(40));


  ndn::AppHelper appP4B("CustomProducer");
  
  appP4B.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP4B=appP4B.Install(producerP4B);
  producerappP4B.Start(Seconds(1));
  producerappP4B.Stop(Seconds(40));


  ndn::AppHelper appP5B("CustomProducer");
  
  appP5B.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP5B=appP5B.Install(producerP5B);
  producerappP5B.Start(Seconds(1));
  producerappP5B.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1C("CustomProducer");
  
  appP1C.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP1C=appP1C.Install(producerP1C);
  producerappP1C.Start(Seconds(1));
  producerappP1C.Stop(Seconds(40));

  ndn::AppHelper appP2C("CustomProducer");
  
  appP2C.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP2C=appP2C.Install(producerP2C);
  producerappP2C.Start(Seconds(1));
  producerappP2C.Stop(Seconds(40));


  ndn::AppHelper appP3C("CustomProducer");
  
  appP3C.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP3C=appP3C.Install(producerP3C);
  producerappP3C.Start(Seconds(1));
  producerappP3C.Stop(Seconds(40));


  ndn::AppHelper appP4C("CustomProducer");
  
  appP4C.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP4C=appP4C.Install(producerP4C);
  producerappP4C.Start(Seconds(1));
  producerappP4C.Stop(Seconds(40));



   ndn::AppHelper appP5C("CustomProducer");
  
  appP5C.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP5C=appP5C.Install(producerP5C);
  producerappP5C.Start(Seconds(1));
  producerappP5C.Stop(Seconds(40));

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1A("CustomProducer");
  
  appP1A.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP1A=appP1A.Install(producerP1A);
  producerappP1A.Start(Seconds(1));
  producerappP1A.Stop(Seconds(40));

 /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP2A("CustomProducer");
  
  appP2A.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP2A=appP2A.Install(producerP2A);
  producerappP2A.Start(Seconds(1));
  producerappP2A.Stop(Seconds(40));


  ndn::AppHelper appP3A("CustomProducer");
  
  appP3A.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP3A=appP3A.Install(producerP3A);
  producerappP3A.Start(Seconds(1));
  producerappP3A.Stop(Seconds(40));


  ndn::AppHelper appP4A("CustomProducer");
  
  appP4A.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP4A=appP4A.Install(producerP4A);
  producerappP4A.Start(Seconds(1));
  producerappP4A.Stop(Seconds(40));


  ndn::AppHelper appP5A("CustomProducer");
  
  appP5A.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP5A=appP5A.Install(producerP5A);
  producerappP5A.Start(Seconds(1));
  producerappP5A.Stop(Seconds(40));

  /////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appP1D("CustomProducer");
  
  appP1D.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP1D=appP1D.Install(producerP1D);
  producerappP1D.Start(Seconds(1));
  producerappP1D.Stop(Seconds(40));

  ndn::AppHelper appP2D("CustomProducer");
  
  appP2D.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP2D=appP2D.Install(producerP2D);
  producerappP2D.Start(Seconds(1));
  producerappP2D.Stop(Seconds(40));


  ndn::AppHelper appP3D("CustomProducer");
  
  appP3D.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP3D=appP3D.Install(producerP3D);
  producerappP3D.Start(Seconds(1));
  producerappP3D.Stop(Seconds(40));


  ndn::AppHelper appP4D("CustomProducer");
  
  appP4D.SetAttribute("Cashing",UintegerValue(0));
  
                  
  ApplicationContainer producerappP4D=appP4D.Install(producerP4D);
  producerappP4D.Start(Seconds(1));
  producerappP4D.Stop(Seconds(40));



   ndn::AppHelper appP5D("CustomProducer");
  
  appP5D.SetAttribute("Cashing",UintegerValue(0));
  
                  
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
  
  appC1A.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC1A=appC1A.Install(consumerC1A);
  comsumerappC1A.Start(Seconds(4));
  comsumerappC1A.Stop(Seconds(24));

 ndn::AppHelper appC2A("CustomConsumer");
  
  appC2A.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC2A=appC2A.Install(consumerC2A);
  comsumerappC2A.Start(Seconds(4));
  comsumerappC2A.Stop(Seconds(24));

  ndn::AppHelper appC3A("CustomConsumer");
  
  appC3A.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC3A=appC3A.Install(consumerC3A);
  comsumerappC3A.Start(Seconds(5));
  comsumerappC3A.Stop(Seconds(25));

  
  ndn::AppHelper appC1B("CustomConsumer");
  
  appC1B.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC1B=appC1B.Install(consumerC1B);
  comsumerappC1B.Start(Seconds(4));
  comsumerappC1B.Stop(Seconds(24));

 ndn::AppHelper appC2B("CustomConsumer");
  
  appC2B.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC2B=appC2B.Install(consumerC2B);
  comsumerappC2B.Start(Seconds(5));
  comsumerappC2B.Stop(Seconds(25));

  ndn::AppHelper appC3B("CustomConsumer");
  
  appC3B.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC3B=appC3B.Install(consumerC3B);
  comsumerappC3B.Start(Seconds(6));
  comsumerappC3B.Stop(Seconds(26));

  

  ndn::AppHelper appC1C("CustomConsumer");
  
 
  appC1C.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC1C=appC1C.Install(consumerC1C);
  comsumerappC1C.Start(Seconds(7));
  comsumerappC1C.Stop(Seconds(27));

  
  ndn::AppHelper appC2C("CustomConsumer");
  
 
  appC2C.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC2C=appC2C.Install(consumerC2C);
  comsumerappC2C.Start(Seconds(7));
  comsumerappC2C.Stop(Seconds(27));

  

  ndn::AppHelper appC1D("CustomConsumer");
  
 
  appC1D.SetAttribute("Frequency", StringValue("10"));
  ApplicationContainer comsumerappC1D=appC1D.Install(consumerC1D);
  comsumerappC1D.Start(Seconds(8));
  comsumerappC1D.Stop(Seconds(28));

  
  ndn::AppHelper appC2D("CustomConsumer");
  
 
  appC2D.SetAttribute("Frequency", StringValue("10"));
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
