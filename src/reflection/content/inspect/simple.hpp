#ifndef reflection_content_inspect_simple_hpp
#define reflection_content_inspect_simple_hpp
 // ::reflection::content::inspect::simple_struct<data_name>
 // ::reflection::content::inspect::simple( )

#include "../../property/inspect/simple.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename identifier_name
        ,typename       data_name
        ,typename      image_name =  data_name const&
       >
       struct simple_struct
        : public ::reflection::property::inspect::simple_struct< data_name,image_name >
        {
         typedef data_name      data_type;
         typedef image_name    image_type;

         typedef ::reflection::property::inspect::simple_struct< data_name, image_name >  simple_type;

         typedef typename simple_type::retriever_type retriever_type;

         typedef ::reflection::content::inspect::basic_class<identifier_name,data_name,image_type,data_name,retriever_type> typedef_type;

         static typedef_type make( void )                 { return typedef_type( ); }
         static typedef_type make( data_type const& value_param ){ return typedef_type( value_param ); }
        };

      template
       <
         typename identifier_name
        ,typename data_name
       >
       inline
       typename ::reflection::content::inspect::simple_struct<identifier_name,data_name, data_name const& >::typedef_type
       simple()
        {
         typedef ::reflection::content::inspect::simple_struct<identifier_name,data_name, data_name const& > simple_type;
         return simple_type::make();
        }

      template
       <
         typename identifier_name
        ,typename data_name
       >
       inline
       typename ::reflection::content::inspect::simple_struct<identifier_name,data_name, data_name const& >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::content::inspect::simple_struct<identifier_name,data_name, data_name const& > simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif


