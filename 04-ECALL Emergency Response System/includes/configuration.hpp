#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <iostream>
#include <string>

/*choose the status of sending message 
    0 --> successful 
    1 --> failed 
*/
#define status_of_sending_message 0 
/** add any ID of vehicle */
std::string vehicle_ID = "a b c 1 2 3 ";
/** set paht of log file that stored in ECALL system */
std::string Log_file_path ="../resources/log_file.txt";
std::string Error_log_file_path ="../resources/Error_log_file.txt";
/** location form server */
double x_location_from_server = 4965 ;
double y_location_from_server = 54848;


#endif