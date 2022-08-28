/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2011-2015  Regents of the University of California.
 *
 * This file is part of ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef NDN_OFSwitch_H
#define NDN_OFSwitch_H

#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/ndnSIM-module.h"

#include "ndn-app.hpp"
#include "ns3/ndnSIM/model/ndn-common.hpp"

#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include <vector>
#include <fstream>
namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-apps
 * @brief A simple Interest-sink applia simple Interest-sink application
 *
 * A simple Interest-sink applia simple Interest-sink application,
 * which replying every incoming Interest with Data packet with a specified
 * size and name same as in Interest.cation, which replying every incoming Interest
 * with Data packet with a specified size and name same as in Interest.
 */
class OFSwitch : public App {
public:
  static TypeId
  GetTypeId(void);

  OFSwitch();

  // inherited from NdnApp
  virtual void
  OnInterest(shared_ptr<const Interest> interest);

  //void setData(Ptr<Node> node,ndn::Face face ,const ndn::Interest& interest2);
virtual void
  OnData(shared_ptr<const Data> data);
protected:
  // inherited from Application base class.
  virtual void
  StartApplication(); // Called at time specified by Start

  virtual void
  StopApplication(); // Called at time specified by Stop

private:
void SendInterest(std::string prefix);  
void contentDel(std::shared_ptr<ndn::Interest> interest);
void contentSend();  
void delCs(string pref);
void installPit(int Destnode,int prodNode,std::string pref,int seq);
private:
  Name m_prefix;
  Name m_postfix;
  uint32_t m_virtualPayloadSize;
  Time m_freshness;
  uint32_t m_signature;
  Name m_keyLocator;
  std::string temp;
  std::ofstream m_ofile;
 
  protected:
   uint32_t m_seq;
};

} // namespace ndn
} // namespace ns3

#endif // NDN_PRODUCER_H
