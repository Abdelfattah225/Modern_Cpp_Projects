#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdio>

namespace f = std::filesystem ;

class log
{
    private:
    std::string path;   
    
  	/**Function: to read file and return it as string to allow write function take it and modify it
	 * 	Inputs: nothing
	 	outputs: string
	 */
    
    std::string read_append()
    {
        std::string line , result ;
        std::ifstream file(path);

        if(file.is_open())
        {
            std::string line ;
            while (std::getline(file,line))
            {
                result.append(line);
            }
        }
        else
                std::cout << "File Not Exist\n";

        file.close();
        return result ;


    }


    public:

        log(){}
        //argument constructor
        log(std::string p)
        {
            path = p ;
        }

        // destructor --> last function call before object releaze the memory.
        ~log() = default ;
    /**Function: to read all content of logs file
	 * 	Inputs: nothing
	 	outputs: nothing
	 */
        void Read_logs()
        {
            std::ifstream file(path);

            if(file.is_open())
            {
                std::string line ;
                while (std::getline(file,line))
                {
                    std::cout << line << "\n";
                }
            }
            else
                    std::cout << "File Not Exist\n";

            file.close();
        }

    /**Function: to append content to a file already exist 
	 * 	Inputs: string
	 	outputs: nothing
	 */
        void Append_log(std::string content )
        {
            std::string result = read_append();
            std::ofstream file(path);

            if(file.is_open())
            {
                result.append(content) ; 
                file.write(result.c_str() ,  result.size());

            }
             file.close();

        }
    /**Function: set path of file
	 * 	Inputs: string
	 	outputs: nothing
	 */
        void SetPath(std::string p)
        {
            path = p ;
        }


};





#endif
