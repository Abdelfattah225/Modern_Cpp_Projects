#ifndef _FUNCTIONS_HPP
#define _FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>

#include "configuration.hpp"
#include "ECALL_System.hpp"
#include "GPS_System.hpp"
#include "log.hpp"
#include "NotificationService.hpp"
#include "remote_server.hpp"
#include "vehicle.hpp"

/*funcion: take string and print it 
    intput: string
    output: nothing
*/
void print_msg(std::string msg)
{
    std::cout << msg <<"\n";
}
/* function take vehicle properities form User
    Input : speed , location , acceleration , Car
    output : nothing 
*/
void Take_Vehicle_Data(double& speed , std::string& ID , double& x , double& y , double& acc , car &Vehicle)
{
    print_msg("Enter Vehicle Speed : ");
    std::cin >> speed;
    Vehicle.SetSPEED(speed);
    print_msg("Enter vehicle location (latitude, longitude):");
    std::cin>> x;
    std::cin>> y;
    Vehicle.SetX(x);
    Vehicle.SetY(y);
    print_msg("Enter acceleration:");
    std::cin>> acc;
    Vehicle.SetAcceleration(acc);
    Vehicle.SetID(vehicle_ID);


}

/** function : to transfer location form server to GPS module and the the GPS return the location to vehicle data
 * inputs: server , Gps
 * output: location(string)
 */
void Get_location_form_server(remote_server& server , GPS_System& GPS)
{
    std::string location ;
    server.SetX(x_location_from_server);
    server.SetY(y_location_from_server);
    server.Transmit_location(GPS);
   
}

/** function : take vehicle data from user but location form server
     * intputs: speed , acc , car , gps
     * output: nothing
*/
void Take_Vehicle_Data(double& speed , double& acc , car &Vehicle , GPS_System& GPS)
{
    print_msg("Enter Vehicle Speed : ");
    std::cin >> speed;
    Vehicle.SetSPEED(speed);
    Vehicle.SetLocationFromGPS(GPS);
     print_msg("Enter acceleration:");
    std::cin>> acc;
    Vehicle.SetAcceleration(acc);
    Vehicle.SetID(vehicle_ID);
}
#endif