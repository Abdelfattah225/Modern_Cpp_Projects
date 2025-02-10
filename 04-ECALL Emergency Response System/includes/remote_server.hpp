#ifndef _REMOTE_SERVER_HPP_
#define _REMOTE_SERVER_HPP_


#include <iostream>
#include <string>
#include "GPS_System.hpp"


class remote_server
{
private:
    std::string message ;
    double x_location ;
    double y_locaiton ;
public:
    remote_server(/* args */){}
    ~remote_server() = default ;
/**
 * Function: to display the content of accident to sever --> future work server must sent this message for emergency services
 * input: nothing
 * output: nothing
 */
    void recieve_accident()
    {
        std::cout << "Server: Accident detected \" "<< message << "\" \n";
    }
/**
 * Function: to transmit the current location to GPS 
 * input: GPS_system
 * output: nothing
 */
    void Transmit_location(GPS_System& GPS)
    {
        GPS.SetX(x_location);
        GPS.SetY(y_locaiton);
    }
/**
 * Function: to set the message of the accident
 * input: string
 * output: nothing
 */    
    void Set_Message(std::string msg)
    {
        message = msg;
    }
/**
 * Function: to set the x_location
 * input: double
 * output: nothing
 */    
     void SetX(double a)
    {
        x_location = a ;
    }
/**
 * Function: to set the y_location
 * input: double
 * output: nothing
 */
     void SetY(double a)
    {
        y_locaiton = a ;
    }


};



#endif