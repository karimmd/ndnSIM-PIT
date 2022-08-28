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

#include "ndn-consumer.hpp"
#include "ns3/traced-value.h"
#include <fstream>
namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-apps
 * @brief Ndn application for sending out Interest packets at a "constant" rate (Poisson process)
 */
class CustomConsumer2 : public Consumer {
public:
  static TypeId
  GetTypeId();

  /**
   * \brief Default constructor
   * Sets up randomizer function and packet sequence number
   */
  CustomConsumer2();
  virtual ~CustomConsumer2();
  
  void SendInterest(std::string prefix,int seq);

  virtual void
  OnData(shared_ptr<const Data> contentObject);
  virtual void
  OnNack(shared_ptr<const lp::Nack> nack);  
  
   void setPIT(std::string pref,int seq);
protected:


  /**
   * \brief Constructs the Interest packet and sends it using a callback to the underlying NDN
   * protocol
   */
    // from App
  virtual void
  StartApplication();

  virtual void
  StopApplication();
  
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
  
  //private:
//void SendInterest(std::string prefix,int seq);


protected:
  
  double m_frequency; // Frequency of interest packets (in hertz)
  bool m_firstTime;
  bool controller;
  
  int m_seq;
  Ptr<RandomVariableStream> m_random;
  std::string m_randomType;
  std::string m_filename;
  std::ofstream m_ofile;
  int i;
  int prod[20];
  int p;
  int clear;
};

} // namespace ndn
} // namespace ns3

#endif
