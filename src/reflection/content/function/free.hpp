#ifndef reflection_content_function_free_hpp
 #define reflection_content_function_free_hpp

 // ::reflection::content::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
 // ::reflection::content::function::free( )

#include "../../property/function/free.hpp"

#include "./_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
        ,typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
        >
       class free_class
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name   >   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using free_type::execute;

           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth, fifth_name fifth )
            {
             return this->free_type::execute( first, second, third, fourth, fifth );
            }

        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class free_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,void>   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using free_type::execute;
           
           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth )
            {
             return this->free_type::execute( first, second, third, fourth );
            }

        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name >
       class free_class<identifier_name,return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,void,void>              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,void,void>   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using free_type::execute;

           return_type execute( first_name first, second_name second, third_name third )
            {
             return this->free_type::execute( first, second, third );
            }

        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name >
       class free_class<identifier_name,return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,void,void,void>              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,void,void,void>   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using free_type::execute;

           return_type execute( first_name first, second_name second ) const
            {
             return this->free_type::execute( first, second );
            }
        };


      template< typename identifier_name, typename return_name, typename first_name >
       class free_class<identifier_name,return_name,first_name,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,void,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,void,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,void,void,void,void>                content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,void,void,void,void>   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using free_type::execute;

           return_type execute( first_name first )const
            {
             return this->free_type::execute( first );
            }
        };

      template< typename identifier_name, typename return_name >
       class free_class<identifier_name,return_name,void,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,void,void,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,void,void,void,void,void>
        {
         public:
           typedef return_name    return_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,void,void,void,void,void>                content_type;
           typedef ::reflection::property::function::free_class<return_name,void,void,void,void,void>   free_type;

           typedef typename free_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):free_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;

           return_type execute()const
            {
             return this->free_type::execute();
            }

        };

      template< typename identifier_name, typename return_name >
       inline
       ::reflection::content::function::free_class<identifier_name, return_name,void,void,void,void,void>
       free
        (
         return_name (*pointer_param)()
        )
        {
         typedef ::reflection::content::function::free_class<identifier_name, return_name, void, void, void, void, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name,void,void,void,void >
       free
        (
         return_name  (*pointer_param)( first_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name, void, void, void, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name,void,void,void>
       free
        (
         return_name  (*pointer_param)( first_name, second_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name,return_name, first_name, second_name, void, void, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name,void,void>
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name,return_name, first_name, second_name, third_name, void, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name,void>
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       free
        (
         return_name (*pointer_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name > free_type;

         return free_type( pointer_param );
        }

      }
    }
  }

#endif
