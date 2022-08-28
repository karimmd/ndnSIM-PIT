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

#ifndef NFD_DAEMON_FW_CONTROLLER_STRATEGY_HPP
#define NFD_DAEMON_FW_CONTROLLER_STRATEGY_HPP


#include <boost/random/mersenne_twister.hpp>
#include "face/face.hpp"
#include "fw/strategy.hpp"
#include "fw/algorithm.hpp"

namespace nfd {
namespace fw {

class ControllerStrategy : public Strategy {
public:
  ControllerStrategy(Forwarder& forwarder, const Name& name = getStrategyName());

  virtual ~ControllerStrategy() override;

  virtual void
  afterReceiveInterest(const Face& inFace, const Interest& interest,
                       const shared_ptr<pit::Entry>& pitEntry) override;

  static const Name&
  getStrategyName();

protected:
  boost::random::mt19937 m_randomGenerator;
};

} // namespace fw
} // namespace nfd


#endif // NFD_DAEMON_FW_BEST_ROUTE_STRATEGY_HPP