#ifndef _NOTIFICATIONSERVICE_HPP
#define _NOTIFICATIONSERVICE_HPP

#include <configuration.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "log.hpp"
#include "remote_server.hpp"

// cover all cases of sending message 
#define ERROR_SENDING_MESSAGE status_of_sending_message

class NotificationService
{
    protected:
    std::vector<remote_server> m_remote_servers ;
    std::string vehicle_data;

   

    public:
    log error_log;

    NotificationService(){}
    virtual void create_error_logs(log & err , std::string p)=0;
     //Pure virtuall function for applying polymorphism concept.
    virtual void sends_emergency_notification(remote_server& server , log& error,  std::string path)=0;
    virtual void SetVehicleData(std::string msg)=0;

};

class SMS_Service : public NotificationService
{
    private:
    /**Function: to create error logs if message not sent
     *  inputs: log , string
     *  outputs: nothing
     */
     virtual void create_error_logs(log & err , std::string p ) override
      {
        err.SetPath(p);
        err.Append_log(vehicle_data);
        std::cout << "msg : "<< vehicle_data << "Saved in Erorr log file in path: "<< p <<"\n";
      } 


    public:
    // defualt consturctor
    SMS_Service(){

    }

    /**Function: to send emergnecy notification to server 
     *  inputs: remote_sever ,log , string
     *  outputs: nothing
     */
    
      virtual void sends_emergency_notification(remote_server& server , log& error , std::string path) override
      {
        #if ERROR_SENDING_MESSAGE == 0
            std::cout << "NotificationService: Sending SMS message \" " << vehicle_data << "\" \n";
            server.Set_Message(vehicle_data);
            std::cout << "NotificationService: message sent successfully \n";
        #elif ERROR_SENDING_MESSAGE == 1
            std::cout << "NotificationService: Sending SMS message \" " << vehicle_data << "\" \n";
            std::cout << "NotificationService: ERROR to sending the messge\n";
            /*create error logs */
          create_error_logs(error,path);
        #else
            std::cout << "ERROR in set the ERROR_SENDING_MESSAGE\n";
        #endif   

      }
    /**Function: Set vehicle properties
     *  inputs: string
     *  outputs: nothing
     */
    
      virtual void SetVehicleData(std::string msg) override
      {
            vehicle_data = msg ;
      }

     
};



class Email_Service : public NotificationService
{
     private:

     virtual void create_error_logs(log & err , std::string p , std::string message)
      {
        err.SetPath(p);
        err.Append_log(message);
        std::cout << "msg : "<< message << "Saved in Erorr log file in path: "<< p <<"\n";
      } 

    public:
      virtual void sends_emergency_notification(remote_server& server , std::string message , log& error , std::string path)
      {
        #if ERROR_SENDING_MESSAGE == 0
            std::cout << "Sending Email message :" << message << "\n";
            server.Set_Message(message);
        #elif ERROR_SENDING_MESSAGE == 1
            std::cout << "Sending Email message :" << message << "\n";
            std::cout << "ERROR to sending the messge\n";
            /*create error logs */
            create_error_logs(error,path,message);

        #else
            std::cout << "ERROR in set the ERROR_SENDING_MESSAGE\n";
        #endif   

      }
       

};

#endif
