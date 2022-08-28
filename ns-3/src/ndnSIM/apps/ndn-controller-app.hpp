/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 Beijing Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author:  <email@email.com>
 */

#ifndef CONTROLLER_APP_H_
#define CONTROLLER_APP_H_

#include "ns3/ndnSIM-module.h"
#include "ns3/integer.h"
#include "ns3/double.h"
#include "ns3/string.h"
#include "ns3/random-variable-stream.h"
#include "ns3/nstime.h"
#include "ns3/application.h"
#include "ns3/ptr.h"
#include "ns3/callback.h"
#include "ns3/traced-callback.h"
#include "ns3/boolean.h"
#include "ns3/names.h"


#include "apps/ndn-app.hpp"
#include "NFD/rib/rib-manager.hpp"
#include "ns3/ndnSIM/helper/ndn-strategy-choice-helper.hpp"

#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/ndnSIM/utils/ndn-rtt-estimator.hpp"

#include "ns3/nstime.h"
#include "ns3/data-rate.h"

#include <set>
#include <map>
#include <unordered_map>

#include <vector>
#include <list>
#include <utility>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/tag.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <fstream>
#include <unordered_map> 



namespace ns3 {
class Node;
class NodeContainer;
class Channel;

namespace ndn {


class ControllerApp : public ndn::App {
public:
  static TypeId
  GetTypeId();

  ControllerApp();

 void findPath(Ptr<Node> node);
 void findPath(const NodeContainer& nodes);
 void findAll();

std::list<pair<Ptr<Node>,Ptr<Node>>> calcPath(Ptr<Node> source,Ptr<Node> dest);
protected:
  // inherited from Application base class.
  virtual void
  StartApplication();

  virtual void
  StopApplication();

  virtual void
  OnInterest(shared_ptr<const Interest> interest);


  virtual void
  OnData(shared_ptr<const Data> data);
  void
  FindPath(Ptr<Node> sourceNode,Ptr<Node> destNode);
  void 
  discoverPath(Ptr<Node> sourceNode,Ptr<Node> destNode);
  void
  discoverNode(Ptr<Node> controllNode,Ptr<Node> destNode);
  void
   discoverDistance(Ptr<Node> controllNode,Ptr<Node> destNode);
private:
void SendInterest(std::string pre,int node, int prod,std::string prefsent, int seq, int csStore);
void refresh(std::string pref,int prod, int tm);
void TmCount(std::string pref, int producer);
void
  findPath(Ptr<Channel> channel);
private:
  Name m_postfix;
  uint32_t m_signature;
  Name m_keyLocator;
  Name m_prefix;
  uint32_t m_virtualPayloadSize;
  Time m_freshness;
  uint32_t m_seq;
  Name node_prefix;
  std::map<std::string,int> cs_val;
  std::multimap<std::string, pair<int, int>> table;
  std::map<int, pair<int, string>> consumerTable;
  std::multimap<int, pair<int,int>> tempTable;
  std::multimap<std::string, pair<int, int>> csTable;
  int seq;
  std::string m_filename;
   std::ofstream m_ofile;
   
   std::unordered_map<int, float> flowInst; 
  
  
  
};


} //namespace ndn
} // namespace ns3


#endif  //CONTROLLER_APP_H_