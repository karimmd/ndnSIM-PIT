/* *- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include "ndn-control-router.hpp"
#include "model/ndn-l3-protocol.hpp"
#include "ns3/channel.h"
    
namespace ns3 {
namespace ndn {
    
    uint32_t ControlRouter::m_idCounter = 0;
    
    NS_OBJECT_ENSURE_REGISTERED(ControlRouter);
    
    TypeId
    ControlRouter::GetTypeId()
    {
      static TypeId tid = TypeId("ns3::ndn:ControlRouter").SetGroupName("Ndn").SetParent<Object>();
      return tid;
    }
    
ControlRouter::ControlRouter()
    {
      m_id = m_idCounter;
      m_idCounter++;
    }
    
    void
ControlRouter::NotifyNewAggregate()
    {
      if (m_ndn == 0) {
        m_ndn = GetObject<L3Protocol>();
      }
      Object::NotifyNewAggregate();
    }
    
    uint32_t
ControlRouter::GetId() const
    {
      return m_id;
    }
    
    Ptr<L3Protocol>
ControlRouter::GetL3Protocol() const
    {
      return m_ndn;
    }
    
    void
ControlRouter::AddLocalPrefix(shared_ptr<Name> prefix)
    {
      m_localPrefixes.push_back(prefix);
    }
    
    void
ControlRouter::AddIncidency(shared_ptr<Face> face, Ptr<ControlRouter> gr)
    {
      m_incidencies.push_back(std::make_tuple(this, face, gr));
    }
    
ControlRouter::IncidencyList&
ControlRouter::GetIncidencies()
    {
      return m_incidencies;
    }
    
const ControlRouter::LocalPrefixList&
ControlRouter::GetLocalPrefixes() const
    {
      return m_localPrefixes;
    }
    
    void
ControlRouter::clear()
    {
      m_idCounter = 0;
    }
    
    } // namespace ndn
   } // namespace ns3
