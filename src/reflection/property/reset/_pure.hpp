#ifndef reflection_property_reset_pure
#define reflection_property_reset_pure

// ::reflection::property::reset<report_name>
// ::reflection::property::reset::check
// ::reflection::property::reset::process

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace reset
     {

      template
       <
        typename report_name = void 
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef report_name report_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual report_type process()=0;
        };

      template< typename report_name = void >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::reset::pure_class<report_name> reset_type;
         return nullptr != dynamic_cast< reset_type const*>( &property_param );
        }

      template< typename report_name = void  >
       inline report_name process( ::reflection::property::pure_class & property_param )
        {
         typedef ::reflection::property::reset::pure_class<report_name> reset_type;
         return dynamic_cast< reset_type &>( property_param ).process();
        }

     }
   }
 }

 #endif
