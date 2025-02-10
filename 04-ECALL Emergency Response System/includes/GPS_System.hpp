#ifndef _GPS_SYSTEM_HPP_
#define _GPS_SYSTEM_HPP_

#include "vehicle.hpp"

class GPS_System
{
private:
    double x ;
    double y ; 
public:
//constructor
    GPS_System(){}
//destructor
    ~GPS_System()= default ;
/**
 * Function: to set the x_location
 * input: double
 * output: nothing
 */
    void SetX(double a)
    {
        x = a ;
    }
/**
 * Function: to get the x_location
 * input: nothing
 * output: double
 */
    double GetX()
    {
        return x ;
    }
/**
 * Function: to set the x_location
 * input: double
 * output: nothing
 */
     void SetY(double a)
    {
        y = a ;
    }
 /**
 * Function: to get the y_location
 * input: nothing
 * output: double
 */   
    double GetY()
    {
        return y ;
    }


};



#endif

