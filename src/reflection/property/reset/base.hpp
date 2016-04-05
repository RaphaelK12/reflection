#ifndef reflection_property_reset_base
#define reflection_property_reset_base

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace reset
     {

      template
       <
         typename report_name
        ,typename carrier_name    //= type_name
        ,typename agent_name  //= stl_ext::identity_cast<  type_name const&, carrier_name const& >
       >
       class base_class
        : virtual public ::reflection::property::reset::pure_class< report_name >
        {
         public:
           typedef report_name   report_type;
           typedef carrier_name    carrier_type;
           typedef agent_name  agent_type;

                     base_class(){ }

            explicit base_class( carrier_type   const& carrier_param, agent_type const& agent_param = agent_type() )
              : m_carrier( carrier_param ), m_agent( agent_param )
                     {
                     }

         public:
           carrier_type   const&  carrier ( void )const
            {
             return m_carrier; 
            }
           void                carrier( carrier_type const& carrier_param )
            {
             m_carrier = carrier_param;  
            }
         protected:
           carrier_type&          F1_carrier()
            {
             return m_carrier; 
            }
         private:
           carrier_type           m_carrier;

         public: 
           report_type process( void )
            {
             return F1_agent()( F1_carrier() );
            }

         public: 
           agent_type const&   agent()const{ return m_agent; }
           void                 agent( agent_type const& agent_param ){ m_agent = agent_param; }
         //agent_type   &   agent(){ return m_agent; }
         protected:
           agent_type      &   F1_agent(){ return m_agent; }
         private:
           agent_type          m_agent;

        };

      }
    }
  }

#endif