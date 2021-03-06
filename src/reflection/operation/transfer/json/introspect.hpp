#ifndef reflection_operation_transfer_json_introspect
#define reflection_operation_transfer_json_introspect

// ::reflection::operation::transfer::json_class<output_name,key_name,type_name>

#include "../../../type/name/id.hpp"

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"

#include "./context.hpp"



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct introspect_struct
          {
           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t    size_type;

             typedef ::reflection::operation::transfer::json::context_struct<output_name> context_type;

           public:
             typedef std::shared_ptr< context_type > contextPtr_type, context_pointer_type;
           public:
             static contextPtr_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::json::introspect_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit introspect_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_type_acquisition_index , std::bind( &this_type::recover, context_param, _1, _2, _3 ) );
               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, std::ref(observe_param), context_param, _1,_2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
                observe_param.control( observe_type::recover_action_acquisition_index   , f );
               }
             //observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );
               observe_param.control( observe_type::recover_null_pointer_index  , std::bind( &this_type::null_recover, context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_prolog_index,   std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_epilog_index ,  std::bind( &this_type::epilog, context_param, _1, _2, _3 )   );
               observe_param.control( observe_type::stage_prefix_index,   std::bind( &this_type::prefix, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_suffix_index,      std::bind( &this_type::suffix,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_stasimon_index ,   std::bind( &this_type::stasimon,    context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::string   >(), std::bind( &this_type::string , context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::wstring  >(), std::bind( &this_type::wstring, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  bool           >(), std::bind(&this_type::primitive<bool          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  char           >(), std::bind(&this_type::primitive<char          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned char  >(), std::bind(&this_type::primitive<unsigned char >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  wchar_t        >(), std::bind(&this_type::primitive<wchar_t       >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::wint_t    >(), std::bind(&this_type::primitive<std::wint_t   >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  std::int8_t    >(), std::bind(&this_type::primitive<std::int8_t   >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int16_t   >(), std::bind(&this_type::primitive<std::int16_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int32_t   >(), std::bind(&this_type::primitive<std::int32_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int64_t   >(), std::bind(&this_type::primitive<std::int64_t  >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  std::uint8_t   >(), std::bind(&this_type::primitive<std::uint8_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint16_t  >(), std::bind(&this_type::primitive<std::uint16_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint32_t  >(), std::bind(&this_type::primitive<std::uint32_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint64_t  >(), std::bind(&this_type::primitive<std::uint64_t >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<       float     >(), std::bind(&this_type::primitive<     float    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<      double     >(), std::bind(&this_type::primitive<    double    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long double    >(), std::bind(&this_type::primitive<long double   >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  void*          >(), std::bind(&this_type::primitive<void*         >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  short          >(), std::bind(&this_type::primitive<short         >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned short >(), std::bind(&this_type::primitive<unsigned short>,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  int            >(), std::bind(&this_type::primitive<int           >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned       >(), std::bind(&this_type::primitive<unsigned      >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long           >(), std::bind(&this_type::primitive<long          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long long      >(), std::bind(&this_type::primitive<long long     >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind(&this_type::primitive< unsigned long          >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind(&this_type::primitive< unsigned long long     >, context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  nullptr_t      >(), std::bind( &this_type::null_value, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  enumeration_type     >(), std::bind( &this_type::enumeration ,   context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  algorithm_type       >(), std::bind( &this_type::function,       context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  typedefinition_type  >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );

              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->indent( output_param );
               output_param << "{ " ;
               //context_param->inc(); context_param->newl(output_param); context_param->indent( output_param );
               output_param << "\"note\" : " << "\"" <<  "General recovery." << "\"";
               //context_param->newl(output_param); context_param->dec(); context_param->indent( output_param );
               output_param << "}";
               //context_param->newl(output_param);
               return report_type( true );
              }

             static report_type null_recover( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "null"; context_param->newl(output_param);
               return true;
              }

             static report_type introductum(   contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->newl(output_param);
               //context_param->indent(output_param);
               //output_param << "{";
               //context_param->inc();
               return report_type( true );
              }

             static report_type exodus  ( contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->newl(output_param);
               //context_param->dec();
               //context_param->indent(output_param);
               //output_param << "}";
               return report_type( true );
              }

             static report_type prolog(   contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->newl(output_param);
               context_param->indent(output_param);
               output_param << "{";
               context_param->newl(output_param);
               context_param->inc();
               return report_type( true );
              }

             static report_type epilog  ( contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->newl(output_param);
               context_param->dec();
               context_param->indent(output_param);
               output_param << "}";
               return report_type( true );
              }

             static report_type prefix(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;
               context_param->indent(output_param); output_param << "\"" << key_param << "\"" << ":" ; context_param->newl( output_param );
               context_param->indent(output_param); output_param << "{" ; context_param->newl(output_param); context_param->inc();

               decoration_category(       context_param, output_param, property_param );
               decoration_accessibility(  context_param, output_param, property_param );
               decoration_linkage(        context_param, output_param, property_param );
               decoration_qualification(  context_param, output_param, property_param );
               decoration_derivation(     context_param, output_param, property_param );
               decoration_relation(       context_param, output_param, property_param );

               context_param->indent(output_param); output_param << "\"value\"  : "; 

               return report_type( result );
              }

             static report_type suffix(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               context_param->newl(output_param);
               context_param->indent(output_param); output_param <<  "}";
               return report_type( true );
              }

             static report_type stasimon( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  ",";
               context_param->newl(output_param);
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  context_param->indent(output_param); 
                  output_param << "    \"type\"  : \"" << category->identifier() << "\", " ; context_param->newl(output_param);
                  return report_type( true );
                 }
                else
                 {
                  context_param->indent(output_param); output_param << "\"note\"  : \"" << "Can not detect type" << "\", "; context_param->newl(output_param);
                  return report_type( true );
                 }
                 return report_type( false );
               }

             static void decoration_accessibility(   contextPtr_type &context_param, output_type & output_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::ornament::accessibility_class accessibility_type;
               accessibility_type  const* accessibility = dynamic_cast< accessibility_type const* >( &property_param );
               if( nullptr == accessibility )
                {
                 return;
                }
               switch( accessibility->accessibility() )
                {
                 default:
                 case( accessibility_type::public_index    ): context_param->indent(output_param); output_param << "\"accessibility\": "<< "\"public\""<< ","    ; context_param->newl(output_param); break;
               //case( accessibility_type::gloabal_index   ): context_param->indent(output_param); output_param << "\"accessibility\": "<< "\"global\""<< ","    ; context_param->newl(output_param); break;
                 case( accessibility_type::protected_index ): context_param->indent(output_param); output_param << "\"accessibility\": "<< "\"protected\""<< "," ; context_param->newl(output_param); break;
                 case( accessibility_type::private_index   ): context_param->indent(output_param); output_param << "\"accessibility\": "<< "\"private\""<< ","   ; context_param->newl(output_param); break;
               //case( accessibility_type::default_index   ): context_param->indent(output_param); output_param << "\"accessibility\": "<< "\"default\""<< ","   ; context_param->newl(output_param); break;
                }
              }

             static void decoration_linkage(       contextPtr_type &context_param,output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               linkage_type  const* linkage = dynamic_cast< linkage_type const* >( &property_param );
               if( nullptr == linkage )
                {
                 return;
                }
               switch( linkage->linkage() )
                {
                 case( linkage_type::inline_index    ): context_param->indent(output_param);output_param << "\"linkage\": "<< "\"inline\"" << "," ; context_param->newl(output_param); break;
                 case( linkage_type::static_index    ): context_param->indent(output_param);output_param << "\"linkage\": "<< "\"static\""<< ","  ; context_param->newl(output_param); break;
               //case( linkage_type::extern_index    ): context_param->indent(output_param);output_param << "\"linkage\": "<< "\"extern\""<< ","  ; context_param->newl(output_param); break;
               //case( linkage_type::dll_index       ): context_param->indent(output_param);output_param << "\"linkage\": "<< "\"dll\""<< ","     ; context_param->newl(output_param); break;
               //case( linkage_type::default_index   ): context_param->indent(output_param);output_param << "\"linkage\": "<< "\"default\""<< "," ; context_param->newl(output_param); break;
                }
              }

             static void decoration_qualification( contextPtr_type &context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::qualification_class qualification_type;
               qualification_type  const* qualification = dynamic_cast< qualification_type const* >( &property_param );
               if( nullptr == qualification )
                {
                 return;
                }
               if( qualification->qualification() & qualification_type::const_index )
                {
                 context_param->indent(output_param); output_param << "\"qualification\": "<< "\"const\"" << ","; context_param->newl(output_param);
                }

               if( qualification->qualification() & qualification_type::volatile_index )
                {
                 context_param->indent(output_param);output_param << "\"qualification\": "<< "\"volatile\""<< ","; context_param->newl(output_param);
                }

               //switch( qualification->qualification() )
                {
               //case( qualification_type::extern_index    ): context_param->indent(output_param); output_param << "\"qualification\": "<< "\"extern\""<< ","  ; context_param->newl(output_param); break;
               //case( qualification_type::dll_index       ): context_param->indent(output_param); output_param << "\"qualification\": "<< "\"dll\""<< ","     ; context_param->newl(output_param); break;
               //case( qualification_type::default_index   ): context_param->indent(output_param); output_param << "\"qualification\": "<< "\"default\""<< "," ; context_param->newl(output_param); break;
                }
              }

             static void decoration_derivation(    contextPtr_type &context_param,output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::derivation_class derivation_type;
               derivation_type  const* derivation = dynamic_cast< derivation_type const* >( &property_param );
               if( nullptr == derivation )
                {
                 return;
                }
                switch( derivation->derivation() )
                 {
                  case( derivation_type::virtual_index   ): context_param->indent(output_param); output_param << "\"derivation\": "<< "\"virtual\""<< ","  ; context_param->newl(output_param); break;
                 }
              }

             static void decoration_relation(      contextPtr_type &context_param, output_type & output_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::ornament::relation_class relation_type;
               relation_type  const* relation = dynamic_cast< relation_type const* >( &property_param );
               if( nullptr == relation )
                {
                 return;
                }
               switch( relation->relation() )
                {
                 case( relation_type::friend_index   ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"friend\""   << ","  ; context_param->newl(output_param); break;
                 case( relation_type::member_index   ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"member\""   << ","  ; context_param->newl(output_param); break;
                 case( relation_type::derived_index  ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"derived\""  << ","  ; context_param->newl(output_param); break;
                 case( relation_type::base_index     ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"base\""     << ","  ; context_param->newl(output_param); break;
                 case( relation_type::injected_index ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"injected\"" << ","  ; context_param->newl(output_param); break;
                 case( relation_type::field_index    ): context_param->indent(output_param); output_param << "\"relation\": "<< "\"field\""    << ","  ; context_param->newl(output_param); break;
                }
              }

             static report_type null_value  (      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "\"" << key_param << "\"" << ": " <<  "null" ; context_param->newl(output_param);
               return report_type( true );
              }

             static report_type string(          contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  context_param->indent(output_param); output_param << "\""<<  inspect->present() << "\""; context_param->newl(output_param);
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  context_param->indent(output_param); output_param << "\""<<  direct_instance->disclose() << "\""; context_param->newl(output_param);
                  return report_type( true );
                 }
               }
               context_param->indent(output_param); output_param << "\"" << "note" << "\"" << ": " << "\""<<  "Can not retrieve the value." << "\""; context_param->newl(output_param);
               return report_type( true );
              }

             static report_type wstring(         contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  // TODO output_param << "\""<<  inspect->present() << "\"";
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  // TODO output_param << "\""<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }

               return report_type( true );
              }

             template< typename simple_name >
              static report_type primitive(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_param << inspect_instance->present();
                   //context_param->newl(output_param);
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_param << direct_instance->disclose(); // context_param->newl(output_param);
                   return report_type( true );
                  }
                }

                {
                 output_param<< "{ " << "\"note\" : " << "\"Can not retrieve value.\"" << "}"; //context_param->newl(output_param);
                }

                return report_type( true );
               }

             static report_type enumeration(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* context = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == context )
                {
                 // TODO
                 return report_type( false );
                }
               context_param->indent(output_param);output_param << "[" ; context_param->newl(output_param);
               context_param->inc();
               for( std::size_t index=0; index < context->container().size(); ++index )
                {
                 context_param->indent(output_param); output_param << "{ ";
                 output_param << "\"ordinal\": " << std::setw(3) << index << ", ";
                 output_param << "\"value\" : "   << std::setw(4) << context->container()[index].value() << ", ";
                 output_param << "\"name\":\""   << context->container()[index].name() << "\" ";
                 output_param << "    }";
                 if( index+1< context->container().size()) output_param << ",";
                 ; context_param->newl(output_param);
                }

               context_param->dec();
               context_param->indent(output_param); output_param << "] ";
               ; context_param->newl(output_param);

               return report_type( true );
              }

             static report_type function (       contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* context = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == context )
                {
                 // TODO
                 return report_type( false );
                }

               //output_param << "    \"parameters\": " ; context_param->newl(output_param);
               context_param->indent(output_param);output_param << "[ " ; context_param->newl(output_param);
               context_param->inc();
               for( std::size_t index=0; index < context->signature().size(); ++index )
                {
                 if( context->signature()[index].original()  == identificator_type::NAT() )
                  {
                   continue;
                  }
                 context_param->indent(output_param); output_param << "{ ";
                 output_param << "\"ordinal\": " << std::setw(3) << index << ", ";
                 output_param << "\"type\": "   << "\""<< context->signature()[index].original()  << "\" ";
               //output_param << "\"name\":\""   << context->container()[index].name() << "\" ";
                 output_param << "    }";
                 if( index +1 < context->signature().size() ) {  output_param << ",";  }

                 context_param->newl(output_param);
               }
               context_param->dec();
               context_param->indent(output_param); output_param << "] ";
               context_param->newl(output_param);
               return report_type( true );
              }

           private:
             static report_type typedefinition ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* context = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == context )
                {
                 // TODO
                 return report_type( false );
                }

               context_param->indent(output_param); output_param << "{ " ; context_param->newl(output_param);
               context_param->inc();
               context_param->indent(output_param); output_param << "\"object\": \"" << context->object() << "\"," ; context_param->newl(output_param);
               context_param->indent(output_param); output_param << "\"name\"  : \""   << context->name()   << "\"" ; context_param->newl(output_param);
               context_param->dec();
               context_param->indent(output_param); output_param << "}" ; context_param->newl(output_param);
               //context_param->newl(output_param);
               return report_type( true );
              }

           private:
             template < typename container_value_name >
              static  report_type container         ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef container_value_name container_type;
                container_type const*pointer = nullptr;

                {
                 typedef ::reflection::property::inspect::pure_class<container_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   pointer = &inspect_instance->present();
                   goto print_label;
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<container_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   pointer = &direct_instance->disclose();
                   goto print_label;
                  }
                }

                return report_type( true );
                print_label:

                context_param->newl(output_param); context_param->indent(output_param); output_param << "{";
                context_param->inc();

                size_type index = 0;
                for( auto const&  item: *pointer )
                 {
                  context_param->newl(output_param);
                  observe_param.view( output_param, key_type{ std::to_string( index++ ) }, ::reflection::content::inspect::pointer<identifier_type,typename container_type::value_type>( &item ) );
                  if( index != pointer->size() )
                   {
                    output_param << ",";
                    //context_param->newl(output_param);
                   }
                 }

                context_param->dec();
                context_param->newl(output_param);
                context_param->indent(output_param); output_param << "}";

                return report_type( true );
               }

           public:
             template < typename container_value_name >
              static  void register_container( observe_type & observe_param, contextPtr_type &context_param )
              {
                typedef container_value_name container_type;
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< container_type >();
                auto f = std::bind( &this_type::template container<container_type>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.register__any( i , f );
               }

            public:
             template < typename map_key_name, typename map_data_name >
              static void register_map( observe_type & observe_param, contextPtr_type &context_param )
               {
               this_type::template register_pair< map_key_name, map_data_name >( observe_param, context_param );
               this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );;
               }

           private:
             static report_type structure (      observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               boolean_type pass = true;

               if( true == pass )
                {
                 typedef  ::reflection::property::inspect::pure_class<structure_type const&>         inspect_type;
                 inspect_type const*inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   observe_param.view( output_param, inspect_instance->present() );
                   pass = false;
                  }
                 }

               if( true == pass )
                {
                 typedef  ::reflection::property::direct::pure_class<structure_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   observe_param.view( output_param, direct_instance->disclose() );
                   pass = false;
                  }
                }

               if( true == pass )
                {
                 output_param<< "{ " << "\"" << "note" << "\"" << ": " << "\""<<  "Not a structure." << "\"" << "}";
                }

               //context_param->newl(output_param);
               return report_type( true );
             }

           public:
             template< typename data_name, typename function_name  >
              static void register__any( function_name const& f, observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                return observe_param.template register__any< data_name > ( std::bind( f, context_param, _1, _2, _3 ) );
               }

           public:
             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &observe_type::template view_custom<data_name, view_name>, std::ref(observe_param) , _1, _2, _3 );
                observe_param.template register__any< data_name >( f );
               }

          };

       }
     }
   }
 }

#endif
