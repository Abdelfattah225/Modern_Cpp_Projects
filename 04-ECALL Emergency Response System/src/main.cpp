
#include "functions.hpp"

int main()
{
    /**varilabes*/
    double speed , x_location , y_location , acc ;

    ECALL_System ECALL ;
    GPS_System GPS;
    car Vehicle;
    log Log_File , Error_log_file ;
    SMS_Service SMS ;
    remote_server Cloud ;
    
    Take_Vehicle_Data(speed , vehicle_ID , x_location , y_location , acc ,Vehicle);
    ECALL.detect_an_accident(Vehicle,Log_File,Log_file_path,SMS);
    SMS.sends_emergency_notification(Cloud,Error_log_file,Error_log_file_path);
    Cloud.recieve_accident();
    
}