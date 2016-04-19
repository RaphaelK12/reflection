#ifndef reflection_content_inspect_member_hpp
#define reflection_content_inspect_member_hpp
 // ::reflection::content::inspect::member_class<data_name, image_name,class_name,storage_name>
 // ::reflection::content::inspect::member( )

#include "../../property/inspect/member.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename data_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
       >
       struct member_class
        : ::reflection::property::inspect::member_class<image_name, class_name, storage_name >
        {
         typedef data_name     data_type;
         typedef image_name    image_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef ::reflection::property::inspect::member_class<image_name, class_name, storage_name > property_type;

         typedef typename property_type::reader_type        reader_type;
         typedef typename property_type::retriever_type  retriever_type;

         typedef ::reflection::content::inspect::basic_class<data_name,image_name,storage_name,retriever_type>      type_type;

         static type_type make( storage_type const& storage_param, reader_type const& reader_param )
          {
           return type_type( storage_param, retriever_type( reader_param ) );
          }

       };

      template
       <
        typename data_name
       ,typename image_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::member_class<data_name,image_name,class_name,storage_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,image_name       ( class_name::*reader_param )()const//!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::inspect::member_class<data_name,image_name,class_name,storage_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::retriever_type( reader_param ) );
        }


      template
       <
        typename data_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::member_class<data_name,data_name const&,class_name,storage_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,data_name const&       ( class_name::*reader_param )()const//!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::inspect::member_class<data_name,data_name const&,class_name,storage_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::retriever_type( reader_param ) );
        }


      }
    }
  }

#endif