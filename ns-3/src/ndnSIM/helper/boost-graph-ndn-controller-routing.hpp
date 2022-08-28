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

#ifndef BOOST_GRAPH_NDN_CONTROLLER_ROUTING__H
#define BOOST_GRAPH_NDN_CONTROLLER_ROUTING__H

/// @cond include_hidden

#include "ns3/ndnSIM/model/ndn-common.hpp"

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/ref.hpp>

#include "ns3/ndnSIM/model/ndn-control-router.hpp"

#include "ns3/node-list.h"
#include "ns3/channel-list.h"

#include <list>
#include <map>

namespace boost {

class NdnControlRouterGraph {
public:
  typedef ns3::Ptr<ns3::ndn::ControlRouter> Vertice;
  typedef uint16_t edge_property_type;
  typedef uint32_t vertex_property_type;

  NdnControlRouterGraph()
  {
    for (ns3::NodeList::Iterator node = ns3::NodeList::Begin(); node != ns3::NodeList::End();
         node++) {
      ns3::Ptr<ns3::ndn::ControlRouter> gr = (*node)->GetObject<ns3::ndn::ControlRouter>();
      if (gr != 0)
        m_vertices.push_back(gr);
    }

    for (ns3::ChannelList::Iterator channel = ns3::ChannelList::Begin();
         channel != ns3::ChannelList::End(); channel++) {
      ns3::Ptr<ns3::ndn::ControlRouter> gr = (*channel)->GetObject<ns3::ndn::ControlRouter>();
      if (gr != 0)
        m_vertices.push_back(gr);
    }
  }

  const std::list<Vertice>&
  GetVertices() const
  {
    return m_vertices;
  }

public:
  std::list<Vertice> m_vertices;
};

class ndn_global_router_graph_category : public virtual vertex_list_graph_tag,
                                         public virtual incidence_graph_tag {
};

template<>
struct graph_traits<NdnControlRouterGraph> {
  // Graph concept
  typedef NdnControlRouterGraph::Vertice vertex_descriptor;
  typedef ns3::ndn::ControlRouter::Incidency edge_descriptor;
  typedef directed_tag directed_category;
  typedef disallow_parallel_edge_tag edge_parallel_category;
  typedef ndn_global_router_graph_category traversal_category;

  // VertexList concept
  typedef std::list<vertex_descriptor>::const_iterator vertex_iterator;
  typedef size_t vertices_size_type;

  // AdjacencyGraph concept
  typedef ns3::ndn::ControlRouter::IncidencyList::iterator out_edge_iterator;
  typedef size_t degree_size_type;

  // typedef size_t edges_size_type;
};

} // namespace boost

namespace boost {

inline graph_traits<NdnControlRouterGraph>::vertex_descriptor
source(graph_traits<NdnControlRouterGraph>::edge_descriptor e, const NdnControlRouterGraph& g)
{
  return std::get<0>(e);
}

inline graph_traits<NdnControlRouterGraph>::vertex_descriptor
target(graph_traits<NdnControlRouterGraph>::edge_descriptor e, const NdnControlRouterGraph& g)
{
  return std::get<2>(e);
}

inline std::pair<graph_traits<NdnControlRouterGraph>::vertex_iterator,
                 graph_traits<NdnControlRouterGraph>::vertex_iterator>
vertices(const NdnControlRouterGraph& g)
{
  return make_pair(g.GetVertices().begin(), g.GetVertices().end());
}

inline graph_traits<NdnControlRouterGraph>::vertices_size_type
num_vertices(const NdnControlRouterGraph& g)
{
  return g.GetVertices().size();
}

inline std::pair<graph_traits<NdnControlRouterGraph>::out_edge_iterator,
                 graph_traits<NdnControlRouterGraph>::out_edge_iterator>
out_edges(graph_traits<NdnControlRouterGraph>::vertex_descriptor u, const NdnControlRouterGraph& g)
{
  return std::make_pair(u->GetIncidencies().begin(), u->GetIncidencies().end());
}

inline graph_traits<NdnControlRouterGraph>::degree_size_type
out_degree(graph_traits<NdnControlRouterGraph>::vertex_descriptor u, const NdnControlRouterGraph& g)
{
  return u->GetIncidencies().size();
}

//////////////////////////////////////////////////////////////
// Property maps

struct EdgeWeights {
  EdgeWeights(const NdnControlRouterGraph& graph)
    : m_graph(graph)
  {
  }

private:
  const NdnControlRouterGraph& m_graph;
};

struct VertexIds {
  VertexIds(const NdnControlRouterGraph& graph)
    : m_graph(graph)
  {
  }

private:
  const NdnControlRouterGraph& m_graph;
};

template<>
struct property_map<NdnControlRouterGraph, edge_weight_t> {
  typedef const EdgeWeights const_type;
  typedef EdgeWeights type;
};

template<>
struct property_map<NdnControlRouterGraph, vertex_index_t> {
  typedef const VertexIds const_type;
  typedef VertexIds type;
};

template<>
struct property_traits<EdgeWeights> {
  // Metric property map
  typedef std::tuple<std::shared_ptr<nfd::Face>, uint16_t, double> value_type;
  typedef std::tuple<std::shared_ptr<nfd::Face>, uint16_t, double> reference;
  typedef ns3::ndn::ControlRouter::Incidency key_type;
  typedef readable_property_map_tag category;
};

const property_traits<EdgeWeights>::value_type WeightZero(nullptr, 0, 0.0);
const property_traits<EdgeWeights>::value_type
  WeightInf(nullptr, std::numeric_limits<uint16_t>::max(), 0.0);

struct WeightCompare : public std::binary_function<property_traits<EdgeWeights>::reference,
                                                   property_traits<EdgeWeights>::reference, bool> {
  bool
  operator()(std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> a,
             std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> b) const
  {
    return std::get<1>(a) < std::get<1>(b);
  }

  bool
  operator()(property_traits<EdgeWeights>::reference a, uint32_t b) const
  {
    return std::get<1>(a) < b;
  }

  bool
  operator()(uint32_t a, uint32_t b) const
  {
    return a < b;
  }
};

struct WeightCombine
  : public std::binary_function<uint32_t, property_traits<EdgeWeights>::reference, uint32_t> {
  uint32_t
  operator()(uint32_t a, property_traits<EdgeWeights>::reference b) const
  {
    return a + std::get<1>(b);
  }

  std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double>
  operator()(std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> a,
             property_traits<EdgeWeights>::reference b) const
  {
    if (std::get<0>(a) == nullptr)
      return std::make_tuple(std::get<0>(b), std::get<1>(a) + std::get<1>(b),
                             std::get<2>(a) + std::get<2>(b));
    else
      return std::make_tuple(std::get<0>(a), std::get<1>(a) + std::get<1>(b),
                             std::get<2>(a) + std::get<2>(b));
  }
};

template<>
struct property_traits<VertexIds> {
  // Metric property map
  typedef uint32_t value_type;
  typedef uint32_t reference;
  typedef ns3::Ptr<ns3::ndn::ControlRouter> key_type;
  typedef readable_property_map_tag category;
};

inline EdgeWeights
get(edge_weight_t, const NdnControlRouterGraph& g)
{
  return EdgeWeights(g);
}

inline VertexIds
get(vertex_index_t, const NdnControlRouterGraph& g)
{
  return VertexIds(g);
}

template<class M, class K, class V>
inline void
put(reference_wrapper<M> mapp, K a, V p)
{
  mapp.get()[a] = p;
}

// void
// put (cref< std::map< ns3::Ptr<ns3::ndn::ControlRouter>, ns3::Ptr<ns3::ndn::ControlRouter> > > map,

inline uint32_t
get(const boost::VertexIds&, ns3::Ptr<ns3::ndn::ControlRouter>& gr)
{
  return gr->GetId();
}

inline property_traits<EdgeWeights>::reference
get(const boost::EdgeWeights&, ns3::ndn::ControlRouter::Incidency& edge)
{
  if (std::get<1>(edge) == 0)
    return property_traits<EdgeWeights>::reference(nullptr, 0, 0.0);
  else {
    return property_traits<EdgeWeights>::reference(std::get<1>(edge),
                                                   static_cast<uint16_t>(
                                                     std::get<1>(edge)->getMetric()),
                                                   0.0);
  }
}

struct PredecessorsMap
  : public std::map<ns3::Ptr<ns3::ndn::ControlRouter>, ns3::Ptr<ns3::ndn::ControlRouter>> {
};

template<>
struct property_traits<reference_wrapper<PredecessorsMap>> {
  // Metric property map
  typedef ns3::Ptr<ns3::ndn::ControlRouter> value_type;
  typedef ns3::Ptr<ns3::ndn::ControlRouter> reference;
  typedef ns3::Ptr<ns3::ndn::ControlRouter> key_type;
  typedef read_write_property_map_tag category;
};

struct DistancesMap : public std::map<ns3::Ptr<ns3::ndn::ControlRouter>,
                                      std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double>> {
};

template<>
struct property_traits<reference_wrapper<DistancesMap>> {
  // Metric property map
  typedef std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> value_type;
  typedef std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> reference;
  typedef ns3::Ptr<ns3::ndn::ControlRouter> key_type;
  typedef read_write_property_map_tag category;
};

} // boost

namespace std {
template<>
class numeric_limits<std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double>>
{
public:
  typedef std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double> value;
  static value
  max()
  {
    return boost::WeightInf;
  }
};
}

namespace boost {

inline std::tuple<std::shared_ptr<nfd::Face>, uint32_t, double>
get(DistancesMap& map, ns3::Ptr<ns3::ndn::ControlRouter> key)
{
  boost::DistancesMap::iterator i = map.find(key);
  if (i == map.end())
    return std::tuple<std::shared_ptr<nfd::Face>, uint32_t,
                      double>(nullptr, std::numeric_limits<uint32_t>::max(), 0.0);
  else
    return i->second;
}

} // namespace boost

/// @endcond

#endif // BOOST_GRAPH_NDN_GLOBAL_ROUTING_HELPER_H
