#ifndef _MATH_HPP_
		#define _MATH_HPP_
#include <string>
#include <type_traits>


using namespace std;
	
namespace lib // create new scope   
{


		
        // variadic template --> can take more than one arguments 
        // caller : determine numbers of arguments

        // number of arguments (base case)

            // 1.  0 or more arguments --> base 0
            int sum()
            {
                return 0 ; // return value without any side effectt ;
            } 
            // 2.  1 or more arguments --> base 1 --> template overloading
            template <typename T>
            T sum(const T & a)
            {
                return a;
            } 
            // 3.  2 or more arguments --> base 2 (done)



template <typename T , typename U , typename ... Ts> // parameter packing (array of parameter)
         auto sum(const T & a , const U & b , const Ts & ... values) // 
        {

            static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , "T & U must be arthimetic data type" );

            // tail recursion
            // check no. of arguments --> values
            // values =  ----> add : a+b
            // values > 0 -->  add: a+b --> result
            //              --> result + values ...
            
            if constexpr( sizeof... (Ts) > 0) 
            {
                   auto r = a + b ; 
                   return sum(r , values ...);      // parameters un-pack.
            }
            else 
            {
                return a + b ;
            }
        }
}
#endif  