#ifndef _ECALL_HPP
#define _ECALL_HPP

#include "configuration.hpp"
#include "vehicle.hpp"
#include "log.hpp"
#include "NotificationService.hpp"

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

#define Speed_threshold 0
#define Acceleration_theshold -8.5

class ECALL_System
{

private:

    std::string vehicle_data;
/**
 * Function: to create log file contain the vehicle properties
 * input: log , string ,string
 * output: nothing
 */
    void Create_log_file(log& log_file , std::string path, std::string msg)
    {
        log_file.SetPath(path);
        log_file.Append_log(msg);    
    }
/**
 * Function: to initiate an emergency_call by send message to the service
 * input: SMS_service
 * output: nothing
 */    
    void initiate_an_emergency_call(SMS_Service& notification)
    {
        std::cout << "ECALL System : initiate_an_emergency_call \n";

        notification.SetVehicleData(vehicle_data);
    }
/**
 * Function: to get the present time
 * input: nothing
 * output: string
 */
    std::string print_time()
    {
         auto now = std::chrono::system_clock::now();
         std::time_t now_c = std::chrono::system_clock::to_time_t(now);
         return ctime(&now_c);  
    }
public:
// constructor
    ECALL_System(/* args */){}
// destructor
    ~ECALL_System(){}
/**
 * Function: to detect the accident by compare the thresold of speed and acceleration with vehicle's speed and acceleration
 * input: double
 * output: nothing
 */
    void detect_an_accident(car& veh , log& log_file , std::string path , SMS_Service& notification)
    {
        if(veh.GetSpeed() == Speed_threshold && veh.GetAcceleration() < Acceleration_theshold)
        {   
            std::cout << "ECALL System : Accident detection \n";
            /*convert all data of vehicle to one string*/
            vehicle_data = "\nSpeed: " + std::to_string(veh.GetSpeed()) + "\n" +
            "Location: " + std::to_string(veh.GetX()) + " x-axis, " + 
            std::to_string(veh.GetY()) + " y-axis\n" +
            "Acceleration: " + std::to_string(veh.GetAcceleration()) + "\nID : " + vehicle_ID + "\nTime: " + print_time();
            initiate_an_emergency_call(notification);
        }
    }
    

};


#endif