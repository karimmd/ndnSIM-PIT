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

#ifndef NDN_CONSUMER_CBR_H
#define NDN_CONSUMER_CBR_H

#include "ns3/ndnSIM/model/ndn-common.hpp"



#include "ns3/ndnSIM/model/ndn-common.hpp"

#include "ndn-consumer.hpp"

#include "ns3/random-variable-stream.h"
#include "ns3/nstime.h"
#include "ns3/data-rate.h"

#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/ndnSIM/utils/ndn-rtt-estimator.hpp"

#include <set>
#include <map>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/tag.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <fstream>

namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-apps
 * @brief Ndn application for sending out Interest packets at a "constant" rate (Poisson process)
 */
class CustomConsumer : public Consumer {
public:
  static TypeId
  GetTypeId();

  /**
   * \brief Default constructor
   * Sets up randomizer function and packet sequence number
   */
  CustomConsumer();
  virtual ~CustomConsumer();
// From App
  virtual void
  OnData(shared_ptr<const Data> data);

  // From App
  virtual void
  OnNack(shared_ptr<const lp::Nack> nack);
  
  virtual void
  ScheduleNextPacket();

  /**
   * @brief Set type of frequency randomization
   * @param value Either 'none', 'uniform', or 'exponential'
   */
  void
  SetRandomize(const std::string& value);

  /**
   * @brief Get type of frequency randomization
   * @returns either 'none', 'uniform', or 'exponential'
   */
  std::string
  GetRandomize() const;

//void SendInterest2(const Name& pref);

 void SendInterest(std::string prefix,int seq);

  
protected:
  /**
   * \brief Constructs the Interest packet and sends it using a callback to the underlying NDN
   * protocol
   */

  virtual void
  StartApplication();

  virtual void
  StopApplication();

 

protected:
  Name m_interestName; 
  double m_frequency; // Frequency of interest packets (in hertz)
  bool m_firstTime;
  bool controller;
  int m_seq;
  Ptr<RandomVariableStream> m_random;
  std::string m_randomType;
  EventId m_sendEvent;
  std::string m_filename;
   std::ofstream m_ofile;
int i=0,j=0;
int prod[20];
  int p;
};

} // namespace ndn
} // namespace ns3

#endif