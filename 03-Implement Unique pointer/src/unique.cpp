

/**
 * requirement:
 * 1. Follow principle (RAII) ---> source acq. is initialization.
 *      a. constructor : rquist resource
 *      b. destructor : clean up resource 
 * 2. unique --> any data type.
 * 
 */

// Dependencies
#include "header.hpp"

#include <iostream>
#include <string>
#include <array>

template<typename T>
class unique_ptr
{
    private:
    T * ptr ;
    public:
    //1. constructor --> create resource (allocate)

    explicit unique_ptr(T * pointer)
    {
        //1. forward pointer --> member variable.
        ptr = pointer ;
       
    }
     
     // 2. accessing pointer 
     int operator*()
        {
            return *(ptr);
        } 

    /**
     * function set value of pointer 
     */
    void setValue(T value)
    {
        *ptr = value ;
    }
    /**
     * function to print address of pointer
     */
    void get()
    {
        std::cout << ptr << " " << std::endl;
    }
    /**
     * function to change pointer
     */
    void changePointer(T * pointer)
    {
        delete ptr ;
        ptr = pointer ; 
    }
    //2. destructor  --> releaze resource.
     ~unique_ptr()
     {
           delete ptr ; 
     }

};


void print(unique_ptr<int> a )
{

}
int main()
{
    // usage of unique pointer 
     unique_ptr<int> p(new int);
    int x = 1000; 
    p.get();
    p.changePointer(new int);
    p.setValue(x);
    std::cout << *p << std::endl;
    p.get();
}