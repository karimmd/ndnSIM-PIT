/*-*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef NDN_CONTROL_ROUTER_H
#define NDN_CONTROL_ROUTER_H
   
#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/object.h"
#include "ns3/ptr.h"
   
   #include <list>
   #include <tuple>
   
   namespace ns3 {
   
   class Channel;
   
   namespace ndn {
   
   class L3Protocol;
   
   class ControlRouter : public Object {
   public:
     typedef std::tuple<Ptr<ControlRouter>, shared_ptr<Face>, Ptr<ControlRouter>> Incidency;
     typedef std::list<Incidency> IncidencyList;
     typedef std::list<shared_ptr<Name>> LocalPrefixList;
   
     static TypeId
     GetTypeId();
   
     ControlRouter();
   
     uint32_t
     GetId() const;
   
     Ptr<L3Protocol>
     GetL3Protocol() const;
   
     void
     AddLocalPrefix(shared_ptr<Name> prefix);
   
     void
     AddIncidency(shared_ptr<Face> face, Ptr<ControlRouter> ndn);
   
     IncidencyList&
     GetIncidencies();
   
     const LocalPrefixList&
     GetLocalPrefixes() const;
   
     static void
     clear();
   
   protected:
     virtual void
     NotifyNewAggregate(); 
   
   private:
     uint32_t m_id;
   
     Ptr<L3Protocol> m_ndn;
     LocalPrefixList m_localPrefixes;
     IncidencyList m_incidencies;
   
     static uint32_t m_idCounter;
   };
   
   inline bool
   operator==(const ControlRouter::Incidency& a, const ControlRouter::Incidency& b)
   {
     return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b)
            && std::get<2>(a) == std::get<2>(b);
   }
   
   inline bool
   operator!=(const ControlRouter::Incidency& a, const ControlRouter::Incidency& b)
   {
     return !(a == b);
   }
   
   } // namespace ndn
   } // namespace ns3
   
#endif // NDN_GLOBAL_ROUTER_H