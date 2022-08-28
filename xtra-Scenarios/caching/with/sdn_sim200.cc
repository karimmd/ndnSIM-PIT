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
  Ptr<Node> consumerC19A = Names::Find<Node>("consumer-19");
  Ptr<Node> consumerC20A = Names::Find<Node>("consumer-20");
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
  Ptr<Node> consumerC16B = Names::Find<Node>("consumer-41");
  Ptr<Node> consumerC17B = Names::Find<Node>("consumer-42");
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
  Ptr<Node> consumerC11C = Names::Find<Node>("consumer-61");
  Ptr<Node> consumerC12C = Names::Find<Node>("consumer-62");
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
  Ptr<Node> consumerC6D = Names::Find<Node>("consumer-81");
  Ptr<Node> consumerC7D = Names::Find<Node>("consumer-82");
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
  Ptr<Node> consumerC24D = Names::Find<Node>("consumer-99");
  Ptr<Node> consumerC25D = Names::Find<Node>("consumer-100");


///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
  Ptr<Node> consumerC101 = Names::Find<Node>("consumer-101");
  Ptr<Node> consumerC102= Names::Find<Node>("consumer-102");
  Ptr<Node> consumerC103 = Names::Find<Node>("consumer-103");
  Ptr<Node> consumerC104 = Names::Find<Node>("consumer-104");
  Ptr<Node> consumerC105 = Names::Find<Node>("consumer-105");
  Ptr<Node> consumerC106 = Names::Find<Node>("consumer-106");
  Ptr<Node> consumerC107 = Names::Find<Node>("consumer-107");
  Ptr<Node> consumerC108 = Names::Find<Node>("consumer-108");
  Ptr<Node> consumerC109 = Names::Find<Node>("consumer-109");
  Ptr<Node> consumerC110 = Names::Find<Node>("consumer-110");
  Ptr<Node> consumerC111 = Names::Find<Node>("consumer-111");
  Ptr<Node> consumerC112 = Names::Find<Node>("consumer-112");
  Ptr<Node> consumerC113 = Names::Find<Node>("consumer-113");
  Ptr<Node> consumerC114 = Names::Find<Node>("consumer-114");
  Ptr<Node> consumerC115 = Names::Find<Node>("consumer-115");
  Ptr<Node> consumerC116 = Names::Find<Node>("consumer-116");
  Ptr<Node> consumerC117 = Names::Find<Node>("consumer-117");
  Ptr<Node> consumerC118 = Names::Find<Node>("consumer-118");
  Ptr<Node> consumerC119 = Names::Find<Node>("consumer-119");
  Ptr<Node> consumerC120 = Names::Find<Node>("consumer-120");
  Ptr<Node> consumerC121 = Names::Find<Node>("consumer-121");
  Ptr<Node> consumerC122 = Names::Find<Node>("consumer-122");
  Ptr<Node> consumerC123 = Names::Find<Node>("consumer-123");
  Ptr<Node> consumerC124 = Names::Find<Node>("consumer-124");
  Ptr<Node> consumerC125 = Names::Find<Node>("consumer-125");
  

////////////// SECOND Poll of Consumer//////////////////
  ////////////// SECOND Poll of Consumer//////////////////
  
  Ptr<Node> consumerC126 = Names::Find<Node>("consumer-126");
  Ptr<Node> consumerC127 = Names::Find<Node>("consumer-127");
  Ptr<Node> consumerC128= Names::Find<Node>("consumer-128");
  Ptr<Node> consumerC129 = Names::Find<Node>("consumer-129");
  Ptr<Node> consumerC130 = Names::Find<Node>("consumer-130");
  Ptr<Node> consumerC131 = Names::Find<Node>("consumer-131");
  Ptr<Node> consumerC132 = Names::Find<Node>("consumer-132");
  Ptr<Node> consumerC133 = Names::Find<Node>("consumer-133");
  Ptr<Node> consumerC134 = Names::Find<Node>("consumer-134");
  Ptr<Node> consumerC135 = Names::Find<Node>("consumer-135");
  Ptr<Node> consumerC136 = Names::Find<Node>("consumer-136");
  Ptr<Node> consumerC137 = Names::Find<Node>("consumer-137");
  Ptr<Node> consumerC138 = Names::Find<Node>("consumer-138");
  Ptr<Node> consumerC139 = Names::Find<Node>("consumer-139");
  Ptr<Node> consumerC140 = Names::Find<Node>("consumer-140");
  Ptr<Node> consumerC141 = Names::Find<Node>("consumer-141");
  Ptr<Node> consumerC142 = Names::Find<Node>("consumer-142");
  Ptr<Node> consumerC143 = Names::Find<Node>("consumer-143");
  Ptr<Node> consumerC144 = Names::Find<Node>("consumer-144");
  Ptr<Node> consumerC145 = Names::Find<Node>("consumer-145");
  Ptr<Node> consumerC146= Names::Find<Node>("consumer-146");
  Ptr<Node> consumerC147 = Names::Find<Node>("consumer-147");
  Ptr<Node> consumerC148 = Names::Find<Node>("consumer-148");
  Ptr<Node> consumerC149 = Names::Find<Node>("consumer-149");
  Ptr<Node> consumerC150 = Names::Find<Node>("consumer-150");

////////////// Third Poll of Consumer//////////////////
  ////////////// Third Poll of Consumer//////////////////
  Ptr<Node> consumerC151 = Names::Find<Node>("consumer-151");
  Ptr<Node> consumerC152= Names::Find<Node>("consumer-152");
  Ptr<Node> consumerC153 = Names::Find<Node>("consumer-153");
  Ptr<Node> consumerC154 = Names::Find<Node>("consumer-154");
  Ptr<Node> consumerC155 = Names::Find<Node>("consumer-155");
  Ptr<Node> consumerC156= Names::Find<Node>("consumer-156");
  Ptr<Node> consumerC157 = Names::Find<Node>("consumer-157");
  Ptr<Node> consumerC158 = Names::Find<Node>("consumer-158");
  Ptr<Node> consumerC159 = Names::Find<Node>("consumer-159");
  Ptr<Node> consumerC160 = Names::Find<Node>("consumer-160");
  Ptr<Node> consumerC161 = Names::Find<Node>("consumer-161");
  Ptr<Node> consumerC162 = Names::Find<Node>("consumer-162");
  Ptr<Node> consumerC163 = Names::Find<Node>("consumer-163");
  Ptr<Node> consumerC164 = Names::Find<Node>("consumer-164");
  Ptr<Node> consumerC165 = Names::Find<Node>("consumer-165");
  Ptr<Node> consumerC166 = Names::Find<Node>("consumer-166");
  Ptr<Node> consumerC167 = Names::Find<Node>("consumer-167");
  Ptr<Node> consumerC168 = Names::Find<Node>("consumer-168");
  Ptr<Node> consumerC169 = Names::Find<Node>("consumer-169");
  Ptr<Node> consumerC170 = Names::Find<Node>("consumer-170");
  Ptr<Node> consumerC171 = Names::Find<Node>("consumer-171");
  Ptr<Node> consumerC172 = Names::Find<Node>("consumer-172");
  Ptr<Node> consumerC173 = Names::Find<Node>("consumer-173");
  Ptr<Node> consumerC174 = Names::Find<Node>("consumer-174");
  Ptr<Node> consumerC175 = Names::Find<Node>("consumer-175");

////////////// fOURTH Poll of Consumer//////////////////
  Ptr<Node> consumerC176 = Names::Find<Node>("consumer-176");
  ////////////// fOURTH Poll of Consumer//////////////////
  Ptr<Node> consumerC177= Names::Find<Node>("consumer-177");
  Ptr<Node> consumerC178 = Names::Find<Node>("consumer-178");
  Ptr<Node> consumerC179 = Names::Find<Node>("consumer-179");
  Ptr<Node> consumerC180 = Names::Find<Node>("consumer-180");
  Ptr<Node> consumerC181 = Names::Find<Node>("consumer-181");
  Ptr<Node> consumerC182 = Names::Find<Node>("consumer-182");
  Ptr<Node> consumerC183 = Names::Find<Node>("consumer-183");
  Ptr<Node> consumerC184 = Names::Find<Node>("consumer-184");
  Ptr<Node> consumerC185 = Names::Find<Node>("consumer-185");
  Ptr<Node> consumerC186 = Names::Find<Node>("consumer-186");
  Ptr<Node> consumerC187 = Names::Find<Node>("consumer-187");
  Ptr<Node> consumerC188 = Names::Find<Node>("consumer-188");
  Ptr<Node> consumerC189 = Names::Find<Node>("consumer-189");
  Ptr<Node> consumerC190 = Names::Find<Node>("consumer-190");
  Ptr<Node> consumerC191 = Names::Find<Node>("consumer-191");
  Ptr<Node> consumerC192 = Names::Find<Node>("consumer-192");
  Ptr<Node> consumerC193 = Names::Find<Node>("consumer-193");
  Ptr<Node> consumerC194 = Names::Find<Node>("consumer-194");
  Ptr<Node> consumerC195 = Names::Find<Node>("consumer-195");
  Ptr<Node> consumerC196 = Names::Find<Node>("consumer-196");
  Ptr<Node> consumerC197 = Names::Find<Node>("consumer-197");
  Ptr<Node> consumerC198 = Names::Find<Node>("consumer-198");
  Ptr<Node> consumerC199 = Names::Find<Node>("consumer-199");
  Ptr<Node> consumerC200 = Names::Find<Node>("consumer-200");

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////










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

 
  ndn::AppHelper appC19A("CustomConsumer2");
  
  appC19A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC19A=appC19A.Install(consumerC19A);
  comsumerappC19A.Start(Seconds(12.2));
  comsumerappC19A.Stop(Seconds(32.2));

 ndn::AppHelper appC20A("CustomConsumer2");
  
  appC20A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC20A=appC20A.Install(consumerC20A);
  comsumerappC20A.Start(Seconds(12.4));
  comsumerappC20A.Stop(Seconds(32.4));

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

  ndn::AppHelper appC16B("CustomConsumer2");
  
  appC16B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC16B=appC16B.Install(consumerC16B);
  comsumerappC16B.Start(Seconds(16.6));
  comsumerappC16B.Stop(Seconds(36.6));


  ndn::AppHelper appC17B("CustomConsumer2");
  
  appC17B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC17B=appC17B.Install(consumerC17B);
  comsumerappC17B.Start(Seconds(16.8));
  comsumerappC17B.Stop(Seconds(36.8));

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

  ndn::AppHelper appC11C("CustomConsumer2");
  
 
  appC11C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC11C=appC11C.Install(consumerC11C);
  comsumerappC11C.Start(Seconds(4));
  comsumerappC11C.Stop(Seconds(24));

  
  ndn::AppHelper appC12C("CustomConsumer2");
  
 
  appC12C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC12C=appC12C.Install(consumerC12C);
  comsumerappC12C.Start(Seconds(4.2));
  comsumerappC12C.Stop(Seconds(24.2));

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

  ndn::AppHelper appC6D("CustomConsumer2");
  
  appC6D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC6D=appC6D.Install(consumerC6D);
  comsumerappC6D.Start(Seconds(4.4));
  comsumerappC6D.Stop(Seconds(24.4));


  ndn::AppHelper appC7D("CustomConsumer2");
  
  appC7D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC7D=appC7D.Install(consumerC7D);
  comsumerappC7D.Start(Seconds(4.6));
  comsumerappC7D.Stop(Seconds(24.6));

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

   ndn::AppHelper appC24D("CustomConsumer2");
  
  appC24D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC24D=appC24D.Install(consumerC24D);
  comsumerappC24D.Start(Seconds(8.2));
  comsumerappC24D.Stop(Seconds(28.2));

 ndn::AppHelper appC25D("CustomConsumer2");
  
  appC25D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC25D=appC25D.Install(consumerC25D);
  comsumerappC25D.Start(Seconds(8.4));
  comsumerappC25D.Stop(Seconds(28.4));

 

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////HUNDRED MORE////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

  ndn::AppHelper appC101("CustomConsumer2");
  
  appC101.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC101=appC101.Install(consumerC101);
  comsumerappC101.Start(Seconds(8.6));
  comsumerappC101.Stop(Seconds(28.6));

 ndn::AppHelper appC102("CustomConsumer2");
  
  appC102.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC102=appC102.Install(consumerC102);
  comsumerappC102.Start(Seconds(8.8));
  comsumerappC102.Stop(Seconds(28.8));

  ndn::AppHelper appC103("CustomConsumer2");
  
  appC103.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC103=appC103.Install(consumerC103);
  comsumerappC103.Start(Seconds(9));
  comsumerappC103.Stop(Seconds(29));

 
  ndn::AppHelper appC104("CustomConsumer2");
  
  appC104.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC104=appC104.Install(consumerC104);
  comsumerappC104.Start(Seconds(9.2));
  comsumerappC104.Stop(Seconds(29.2));

 
  ndn::AppHelper appC105("CustomConsumer2");
  
  appC105.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC105=appC105.Install(consumerC105);
  comsumerappC105.Start(Seconds(9.4));
  comsumerappC105.Stop(Seconds(29.4));

 ndn::AppHelper appC106("CustomConsumer2");
  
  appC106.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC106=appC106.Install(consumerC106);
  comsumerappC106.Start(Seconds(9.6));
  comsumerappC106.Stop(Seconds(29.6));

  ndn::AppHelper appC107("CustomConsumer2");
  
  appC107.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC107=appC107.Install(consumerC107);
  comsumerappC107.Start(Seconds(9.8));
  comsumerappC107.Stop(Seconds(29.8));

 
  ndn::AppHelper appC108("CustomConsumer2");
  
  appC108.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC108=appC108.Install(consumerC108);
  comsumerappC108.Start(Seconds(10));
  comsumerappC108.Stop(Seconds(30));

 
  ndn::AppHelper appC109("CustomConsumer2");
  
  appC109.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC109=appC109.Install(consumerC109);
  comsumerappC109.Start(Seconds(10.2));
  comsumerappC109.Stop(Seconds(30.2));

 ndn::AppHelper appC110("CustomConsumer2");
  
  appC110.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC110=appC110.Install(consumerC110);
  comsumerappC110.Start(Seconds(10.4));
  comsumerappC110.Stop(Seconds(30.4));

///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Ten Consumer///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

  ndn::AppHelper appC111("CustomConsumer2");
  
  appC111.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC111=appC111.Install(consumerC111);
  comsumerappC111.Start(Seconds(10.6));
  comsumerappC111.Stop(Seconds(30.6));

 ndn::AppHelper appC112("CustomConsumer2");
  
  appC112.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC112=appC112.Install(consumerC112);
  comsumerappC112.Start(Seconds(10.8));
  comsumerappC112.Stop(Seconds(30.8));

  ndn::AppHelper appC113("CustomConsumer2");
  
  appC113.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC113=appC113.Install(consumerC113);
  comsumerappC113.Start(Seconds(11));
  comsumerappC113.Stop(Seconds(31));

 
  ndn::AppHelper appC114("CustomConsumer2");
  
  appC114.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC114=appC114.Install(consumerC114);
  comsumerappC114.Start(Seconds(11.2));
  comsumerappC114.Stop(Seconds(31.2));

 
  ndn::AppHelper appC115("CustomConsumer2");
  
  appC115.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC115=appC115.Install(consumerC115);
  comsumerappC115.Start(Seconds(11.4));
  comsumerappC115.Stop(Seconds(31.4));

 ndn::AppHelper appC116("CustomConsumer2");
  
  appC116.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC116=appC116.Install(consumerC116);
  comsumerappC116.Start(Seconds(11.6));
  comsumerappC116.Stop(Seconds(31.6));

  ndn::AppHelper appC117("CustomConsumer2");
  
  appC117.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC117=appC117.Install(consumerC117);
  comsumerappC117.Start(Seconds(11.8));
  comsumerappC117.Stop(Seconds(31.8));

 
  ndn::AppHelper appC118("CustomConsumer2");
  
  appC118.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC118=appC118.Install(consumerC118);
  comsumerappC118.Start(Seconds(12));
  comsumerappC118.Stop(Seconds(32));

 
  ndn::AppHelper appC119("CustomConsumer2");
  
  appC119.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC119=appC119.Install(consumerC119);
  comsumerappC119.Start(Seconds(12.2));
  comsumerappC119.Stop(Seconds(32.2));

 ndn::AppHelper appC120("CustomConsumer2");
  
  appC120.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC120=appC120.Install(consumerC120);
  comsumerappC120.Start(Seconds(12.4));
  comsumerappC120.Stop(Seconds(32.4));

///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last Of Consumers////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC121("CustomConsumer2");
  
  appC121.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC121=appC121.Install(consumerC121);
  comsumerappC121.Start(Seconds(12.6));
  comsumerappC121.Stop(Seconds(32.6));

 ndn::AppHelper appC122("CustomConsumer2");
  
  appC122.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC122=appC122.Install(consumerC122);
  comsumerappC122.Start(Seconds(12.8));
  comsumerappC122.Stop(Seconds(32.8));

  ndn::AppHelper appC123("CustomConsumer2");
  
  appC123.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC123=appC123.Install(consumerC123);
  comsumerappC123.Start(Seconds(13));
  comsumerappC123.Stop(Seconds(33));

 
  ndn::AppHelper appC124("CustomConsumer2");
  
  appC124.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC124=appC124.Install(consumerC124);
  comsumerappC124.Start(Seconds(13.2));
  comsumerappC124.Stop(Seconds(33.2));

 
  ndn::AppHelper appC125("CustomConsumer2");
  
  appC125.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC125=appC125.Install(consumerC125);
  comsumerappC125.Start(Seconds(13.4));
  comsumerappC125.Stop(Seconds(33.4));



  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC126("CustomConsumer2");
  
  appC126.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC126=appC126.Install(consumerC126);
  comsumerappC126.Start(Seconds(13.6));
  comsumerappC126.Stop(Seconds(33.6));

 ndn::AppHelper appC127("CustomConsumer2");
  
  appC127.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC127=appC127.Install(consumerC127);
  comsumerappC127.Start(Seconds(13.8));
  comsumerappC127.Stop(Seconds(33.8));

  ndn::AppHelper appC128("CustomConsumer2");
  
  appC128.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC128=appC128.Install(consumerC128);
  comsumerappC128.Start(Seconds(14));
  comsumerappC128.Stop(Seconds(34));

   ndn::AppHelper appC129("CustomConsumer2");
  
  appC129.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC129=appC129.Install(consumerC129);
  comsumerappC129.Start(Seconds(14.2));
  comsumerappC129.Stop(Seconds(34.2));

 ndn::AppHelper appC130("CustomConsumer2");
  
  appC130.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC130=appC130.Install(consumerC130);
  comsumerappC130.Start(Seconds(14.4));
  comsumerappC130.Stop(Seconds(34.4));

  ndn::AppHelper appC131("CustomConsumer2");
  
  appC131.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC131=appC131.Install(consumerC131);
  comsumerappC131.Start(Seconds(14.6));
  comsumerappC131.Stop(Seconds(34.6));


  ndn::AppHelper appC132("CustomConsumer2");
  
  appC132.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC132=appC132.Install(consumerC132);
  comsumerappC132.Start(Seconds(14.8));
  comsumerappC132.Stop(Seconds(34.8));

   ndn::AppHelper appC133("CustomConsumer2");
  
  appC133.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC133=appC133.Install(consumerC133);
  comsumerappC133.Start(Seconds(15));
  comsumerappC133.Stop(Seconds(35));

 ndn::AppHelper appC134("CustomConsumer2");
  
  appC134.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC134=appC134.Install(consumerC134);
  comsumerappC134.Start(Seconds(15.2));
  comsumerappC134.Stop(Seconds(35.2));

  ndn::AppHelper appC135("CustomConsumer2");
  
  appC135.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC135=appC135.Install(consumerC135);
  comsumerappC135.Start(Seconds(15.4));
  comsumerappC135.Stop(Seconds(35.4));


//////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC136("CustomConsumer2");
  
  appC136.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC136=appC136.Install(consumerC136);
  comsumerappC136.Start(Seconds(15.6));
  comsumerappC136.Stop(Seconds(35.6));

 ndn::AppHelper appC137("CustomConsumer2");
  
  appC137.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC137=appC137.Install(consumerC137);
  comsumerappC137.Start(Seconds(15.8));
  comsumerappC137.Stop(Seconds(35.8));

  ndn::AppHelper appC138("CustomConsumer2");
  
  appC138.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC138=appC138.Install(consumerC138);
  comsumerappC138.Start(Seconds(16));
  comsumerappC138.Stop(Seconds(36));

   ndn::AppHelper appC139("CustomConsumer2");
  
  appC139.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC139=appC139.Install(consumerC139);
  comsumerappC139.Start(Seconds(16.2));
  comsumerappC139.Stop(Seconds(36.2));

 ndn::AppHelper appC140("CustomConsumer2");
  
  appC140.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC140=appC140.Install(consumerC140);
  comsumerappC140.Start(Seconds(16.4));
  comsumerappC140.Stop(Seconds(36.4));

  ndn::AppHelper appC141("CustomConsumer2");
  
  appC141.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC141=appC141.Install(consumerC141);
  comsumerappC141.Start(Seconds(16.6));
  comsumerappC141.Stop(Seconds(36.6));


  ndn::AppHelper appC142("CustomConsumer2");
  
  appC142.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC142=appC142.Install(consumerC142);
  comsumerappC142.Start(Seconds(16.8));
  comsumerappC142.Stop(Seconds(36.8));

   ndn::AppHelper appC143("CustomConsumer2");
  
  appC143.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC143=appC143.Install(consumerC143);
  comsumerappC143.Start(Seconds(17));
  comsumerappC143.Stop(Seconds(37));

 ndn::AppHelper appC144("CustomConsumer2");
  
  appC144.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC144=appC144.Install(consumerC144);
  comsumerappC144.Start(Seconds(17.2));
  comsumerappC144.Stop(Seconds(37.2));

  ndn::AppHelper appC145("CustomConsumer2");
  
  appC145.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC145=appC145.Install(consumerC145);
  comsumerappC145.Start(Seconds(17.4));
  comsumerappC145.Stop(Seconds(37.4));
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last twenty Five B//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


 ndn::AppHelper appC146("CustomConsumer2");
  
  appC146.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC146=appC146.Install(consumerC146);
  comsumerappC146.Start(Seconds(17.6));
  comsumerappC146.Stop(Seconds(37.6));

 ndn::AppHelper appC147("CustomConsumer2");
  
  appC147.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC147=appC147.Install(consumerC147);
  comsumerappC147.Start(Seconds(17.8));
  comsumerappC147.Stop(Seconds(37.8));

  ndn::AppHelper appC148("CustomConsumer2");
  
  appC148.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC148=appC148.Install(consumerC148);
  comsumerappC148.Start(Seconds(18));
  comsumerappC148.Stop(Seconds(38));

   ndn::AppHelper appC149("CustomConsumer2");
  
  appC149.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC149=appC149.Install(consumerC149);
  comsumerappC149.Start(Seconds(18.2));
  comsumerappC149.Stop(Seconds(38.2));

 ndn::AppHelper appC150("CustomConsumer2");
  
  appC150.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC150=appC150.Install(consumerC150);
  comsumerappC150.Start(Seconds(18.4));
  comsumerappC150.Stop(Seconds(38.4));

 

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

  ndn::AppHelper appC151("CustomConsumer2");
  
 
  appC151.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC151=appC151.Install(consumerC151);
  comsumerappC151.Start(Seconds(18.6));
  comsumerappC151.Stop(Seconds(38.6));

  
  ndn::AppHelper appC152("CustomConsumer2");
  
 
  appC152.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC152=appC152.Install(consumerC152);
  comsumerappC152.Start(Seconds(18.8));
  comsumerappC152.Stop(Seconds(38.6));

 ndn::AppHelper appC153("CustomConsumer2");
  
 
  appC153.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC153=appC153.Install(consumerC153);
  comsumerappC153.Start(Seconds(19));
  comsumerappC153.Stop(Seconds(39));

  
  ndn::AppHelper appC154("CustomConsumer2");
  
 
  appC154.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC154=appC154.Install(consumerC154);
  comsumerappC154.Start(Seconds(19.2));
  comsumerappC154.Stop(Seconds(39.2));

  ndn::AppHelper appC155("CustomConsumer2");
  
 
  appC155.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC155=appC155.Install(consumerC155);
  comsumerappC155.Start(Seconds(19.4));
  comsumerappC155.Stop(Seconds(39.4));

  
  ndn::AppHelper appC156("CustomConsumer2");
  
 
  appC156.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC156=appC156.Install(consumerC156);
  comsumerappC156.Start(Seconds(19.6));
  comsumerappC156.Stop(Seconds(39.6));


ndn::AppHelper appC157("CustomConsumer2");
  
 
  appC157.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC157=appC157.Install(consumerC157);
  comsumerappC157.Start(Seconds(19.8));
  comsumerappC157.Stop(Seconds(39.8));

  
  ndn::AppHelper appC158("CustomConsumer2");
  
 
  appC158.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC158=appC158.Install(consumerC158);
  comsumerappC158.Start(Seconds(3.4));
  comsumerappC158.Stop(Seconds(23.4));

ndn::AppHelper appC159("CustomConsumer2");
  
 
  appC159.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC159=appC159.Install(consumerC159);
  comsumerappC159.Start(Seconds(3.6));
  comsumerappC159.Stop(Seconds(23.6));

  
  ndn::AppHelper appC160("CustomConsumer2");
  
 
  appC160.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC160=appC160.Install(consumerC160);
  comsumerappC160.Start(Seconds(3.8));
  comsumerappC160.Stop(Seconds(23.8));




//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

  ndn::AppHelper appC161("CustomConsumer2");
  
 
  appC161.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC161=appC161.Install(consumerC161);
  comsumerappC161.Start(Seconds(4));
  comsumerappC161.Stop(Seconds(24));

  
  ndn::AppHelper appC162("CustomConsumer2");
  
 
  appC162.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC162=appC162.Install(consumerC162);
  comsumerappC162.Start(Seconds(4.2));
  comsumerappC162.Stop(Seconds(24.2));

 ndn::AppHelper appC163("CustomConsumer2");
  
 
  appC163.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC163=appC163.Install(consumerC163);
  comsumerappC163.Start(Seconds(4.6));
  comsumerappC163.Stop(Seconds(24.6));

  
  ndn::AppHelper appC164("CustomConsumer2");
  
 
  appC164.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC164=appC164.Install(consumerC164);
  comsumerappC164.Start(Seconds(4.8));
  comsumerappC164.Stop(Seconds(24.8));

  ndn::AppHelper appC165("CustomConsumer2");
  
 
  appC165.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC165=appC165.Install(consumerC165);
  comsumerappC165.Start(Seconds(5));
  comsumerappC165.Stop(Seconds(25));

  
  ndn::AppHelper appC166("CustomConsumer2");
  
 
  appC166.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC166=appC166.Install(consumerC166);
  comsumerappC166.Start(Seconds(5.2));
  comsumerappC166.Stop(Seconds(25.2));


ndn::AppHelper appC167("CustomConsumer2");
  
 
  appC167.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC167=appC167.Install(consumerC167);
  comsumerappC167.Start(Seconds(5.4));
  comsumerappC167.Stop(Seconds(25.4));

  
  ndn::AppHelper appC168("CustomConsumer2");
  
 
  appC168.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC168=appC168.Install(consumerC168);
  comsumerappC168.Start(Seconds(5.6));
  comsumerappC168.Stop(Seconds(25.6));

ndn::AppHelper appC169("CustomConsumer2");
  
 
  appC169.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC169=appC169.Install(consumerC169);
  comsumerappC169.Start(Seconds(5.8));
  comsumerappC169.Stop(Seconds(25.8));

  
  ndn::AppHelper appC170("CustomConsumer2");
  
 
  appC170.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC170=appC170.Install(consumerC170);
  comsumerappC170.Start(Seconds(6));
  comsumerappC170.Stop(Seconds(26));



 ndn::AppHelper appC171("CustomConsumer2");
  
 
  appC171.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC171=appC171.Install(consumerC171);
  comsumerappC171.Start(Seconds(6.4));
  comsumerappC171.Stop(Seconds(26.4));

  
  ndn::AppHelper appC172("CustomConsumer2");
  
 
  appC172.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC172=appC172.Install(consumerC172);
  comsumerappC172.Start(Seconds(6.8));
  comsumerappC172.Stop(Seconds(26.8));

 ndn::AppHelper appC173("CustomConsumer2");
  
 
  appC173.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC173=appC173.Install(consumerC173);
  comsumerappC173.Start(Seconds(7));
  comsumerappC173.Stop(Seconds(27));

  
  ndn::AppHelper appC174("CustomConsumer2");
  
 
  appC174.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC174=appC174.Install(consumerC174);
  comsumerappC174.Start(Seconds(7.5));
  comsumerappC174.Stop(Seconds(27.5));

  ndn::AppHelper appC175("CustomConsumer2");
  
 
  appC175.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC175=appC175.Install(consumerC175);
  comsumerappC175.Start(Seconds(8));
  comsumerappC175.Stop(Seconds(28));

  

  //////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////D Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC176("CustomConsumer2");
  
  appC176.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC176=appC176.Install(consumerC176);
  comsumerappC176.Start(Seconds(3.4));
  comsumerappC176.Stop(Seconds(23.4));

 ndn::AppHelper appC177("CustomConsumer2");
  
  appC177.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC177=appC177.Install(consumerC177);
  comsumerappC177.Start(Seconds(3.6));
  comsumerappC177.Stop(Seconds(23.6));

  ndn::AppHelper appC178("CustomConsumer2");
  
  appC178.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC178=appC178.Install(consumerC178);
  comsumerappC178.Start(Seconds(3.8));
  comsumerappC178.Stop(Seconds(23.8));

   ndn::AppHelper appC179("CustomConsumer2");
  
  appC179.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC179=appC179.Install(consumerC179);
  comsumerappC179.Start(Seconds(4));
  comsumerappC179.Stop(Seconds(24));

 ndn::AppHelper appC180("CustomConsumer2");
  
  appC180.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC180=appC180.Install(consumerC180);
  comsumerappC180.Start(Seconds(4.2));
  comsumerappC180.Stop(Seconds(24.2));

  ndn::AppHelper appC181("CustomConsumer2");
  
  appC181.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC181=appC181.Install(consumerC181);
  comsumerappC181.Start(Seconds(4.4));
  comsumerappC181.Stop(Seconds(24.4));


  ndn::AppHelper appC182("CustomConsumer2");
  
  appC182.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC182=appC182.Install(consumerC182);
  comsumerappC182.Start(Seconds(4.6));
  comsumerappC182.Stop(Seconds(24.6));

   ndn::AppHelper appC183("CustomConsumer2");
  
  appC183.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC183=appC183.Install(consumerC183);
  comsumerappC183.Start(Seconds(4.8));
  comsumerappC183.Stop(Seconds(24.8));

 ndn::AppHelper appC184("CustomConsumer2");
  
  appC184.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC184=appC184.Install(consumerC184);
  comsumerappC184.Start(Seconds(5));
  comsumerappC184.Stop(Seconds(25));

  ndn::AppHelper appC185("CustomConsumer2");
  
  appC185.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC185=appC185.Install(consumerC185);
  comsumerappC185.Start(Seconds(5.2));
  comsumerappC185.Stop(Seconds(25.2));


//////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////B Ten Consumers//////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////
  ndn::AppHelper appC186("CustomConsumer2");
  
  appC186.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC186=appC186.Install(consumerC186);
  comsumerappC186.Start(Seconds(5.4));
  comsumerappC186.Stop(Seconds(25.4));

 ndn::AppHelper appC187("CustomConsumer2");
  
  appC187.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC187=appC187.Install(consumerC187);
  comsumerappC187.Start(Seconds(5.6));
  comsumerappC187.Stop(Seconds(25.6));

  ndn::AppHelper appC188("CustomConsumer2");
  
  appC188.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC188=appC188.Install(consumerC188);
  comsumerappC188.Start(Seconds(5.8));
  comsumerappC188.Stop(Seconds(25.8));

   ndn::AppHelper appC189("CustomConsumer2");
  
  appC189.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC189=appC189.Install(consumerC189);
  comsumerappC189.Start(Seconds(6));
  comsumerappC189.Stop(Seconds(26));

 ndn::AppHelper appC190("CustomConsumer2");
  
  appC190.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC190=appC190.Install(consumerC190);
  comsumerappC190.Start(Seconds(6.2));
  comsumerappC190.Stop(Seconds(26.2));

  ndn::AppHelper appC191("CustomConsumer2");
  
  appC191.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC191=appC191.Install(consumerC191);
  comsumerappC191.Start(Seconds(6.4));
  comsumerappC191.Stop(Seconds(26.4));


  ndn::AppHelper appC192("CustomConsumer2");
  
  appC192.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC192=appC192.Install(consumerC192);
  comsumerappC192.Start(Seconds(6.8));
  comsumerappC192.Stop(Seconds(26.8));

   ndn::AppHelper appC193("CustomConsumer2");
  
  appC193.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC193=appC193.Install(consumerC193);
  comsumerappC193.Start(Seconds(7));
  comsumerappC193.Stop(Seconds(27));

 ndn::AppHelper appC194("CustomConsumer2");
  
  appC194.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC194=appC194.Install(consumerC194);
  comsumerappC194.Start(Seconds(7.2));
  comsumerappC194.Stop(Seconds(27.2));

  ndn::AppHelper appC195("CustomConsumer2");
  
  appC195.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC195=appC195.Install(consumerC195);
  comsumerappC195.Start(Seconds(7.4));
  comsumerappC195.Stop(Seconds(27.4));
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Last twenty Five B//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


 ndn::AppHelper appC196("CustomConsumer2");
  
  appC196.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC196=appC196.Install(consumerC196);
  comsumerappC196.Start(Seconds(7.6));
  comsumerappC196.Stop(Seconds(27.6));

 ndn::AppHelper appC197("CustomConsumer2");
  
  appC197.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC197=appC197.Install(consumerC197);
  comsumerappC197.Start(Seconds(7.8));
  comsumerappC197.Stop(Seconds(27.8));

  ndn::AppHelper appC198("CustomConsumer2");
  
  appC198.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC198=appC198.Install(consumerC198);
  comsumerappC198.Start(Seconds(8));
  comsumerappC198.Stop(Seconds(28));

   ndn::AppHelper appC199("CustomConsumer2");
  
  appC199.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC199=appC199.Install(consumerC199);
  comsumerappC199.Start(Seconds(8.2));
  comsumerappC199.Stop(Seconds(28.2));

 ndn::AppHelper appC200("CustomConsumer2");
  
  appC200.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC200=appC200.Install(consumerC200);
  comsumerappC200.Start(Seconds(8.4));
  comsumerappC200.Stop(Seconds(28.4));

 

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  



//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////HUNDRED MORE////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  


//////////////////////////////////////////////////////////////////////////////////////////  

//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
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

 
 
  ndn::AppHelper appC1A("CustomConsumer2");
  
  appC1A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1A=appC1A.Install(consumerC1A);
  comsumerappC1A.Start(Seconds(4));
  comsumerappC1A.Stop(Seconds(24));

 ndn::AppHelper appC2A("CustomConsumer2");
  
  appC2A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2A=appC2A.Install(consumerC2A);
  comsumerappC2A.Start(Seconds(4));
  comsumerappC2A.Stop(Seconds(24));

  ndn::AppHelper appC3A("CustomConsumer2");
  
  appC3A.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3A=appC3A.Install(consumerC3A);
  comsumerappC3A.Start(Seconds(5));
  comsumerappC3A.Stop(Seconds(25));

  
  ndn::AppHelper appC1B("CustomConsumer2");
  
  appC1B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1B=appC1B.Install(consumerC1B);
  comsumerappC1B.Start(Seconds(4));
  comsumerappC1B.Stop(Seconds(24));

 ndn::AppHelper appC2B("CustomConsumer2");
  
  appC2B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2B=appC2B.Install(consumerC2B);
  comsumerappC2B.Start(Seconds(5));
  comsumerappC2B.Stop(Seconds(25));

  ndn::AppHelper appC3B("CustomConsumer2");
  
  appC3B.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC3B=appC3B.Install(consumerC3B);
  comsumerappC3B.Start(Seconds(6));
  comsumerappC3B.Stop(Seconds(26));

  

  ndn::AppHelper appC1C("CustomConsumer2");
  
 
  appC1C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1C=appC1C.Install(consumerC1C);
  comsumerappC1C.Start(Seconds(7));
  comsumerappC1C.Stop(Seconds(27));

  
  ndn::AppHelper appC2C("CustomConsumer2");
  
 
  appC2C.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC2C=appC2C.Install(consumerC2C);
  comsumerappC2C.Start(Seconds(7));
  comsumerappC2C.Stop(Seconds(27));

  

  ndn::AppHelper appC1D("CustomConsumer2");
  
 
  appC1D.SetAttribute("Frequency", StringValue("1"));
  ApplicationContainer comsumerappC1D=appC1D.Install(consumerC1D);
  comsumerappC1D.Start(Seconds(8));
  comsumerappC1D.Stop(Seconds(28));

  
  ndn::AppHelper appC2D("CustomConsumer2");
  
 
  appC2D.SetAttribute("Frequency", StringValue("1"));
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
