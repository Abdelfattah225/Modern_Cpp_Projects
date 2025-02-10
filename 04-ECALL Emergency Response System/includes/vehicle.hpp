#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <iostream>
#include <string>
#include <GPS_System.hpp>

class vehicle
{
	private:
	
	double  speed ;
	double x_location ; 
	double y_location ; 
	std::string id ;
	double acceleration; 

	public:

	// constructor
	vehicle(){}
	vehicle(std::string ID , double SPEED , double x , double y , double ACCELERATION)
	{
		speed = SPEED ; 
		x_location = x ;
		y_location = y ;
		id = ID ; 
		acceleration = ACCELERATION;
	}

	// destructor
	virtual ~vehicle() = default;
	/**Function: set ID
	 *	Inputs: string
	 	outputs: nothing
	 */
	void SetID(std::string ID)
	{
		id = ID ; 
	}
	/**Function:to set speed
	 * 	Inputs: double
	 	outputs: nothing
	 */
	void SetSPEED(double SPEED)
	{
		if(SPEED >= 0)
	 	speed = SPEED ;
		else
		std::cout << " Wrong input, speed must be positive value\n";
	}
	/**Function: to set x_location
	 * 	Inputs: double
	 	outputs: nothing
	 */
	void SetX(double x)
	{
		x_location = x ;
	}
	/**Function: to set Y_location
	 * 	Inputs: double
	 	outputs: nothing
	 */	
	void SetY(double y)
	{
		y_location = y ;
	}
	/**Function: to set acceleration
	 * 	Inputs: double
	 	outputs: nothing
	 */
	void SetAcceleration(double ACCELERATION)
	{
		acceleration = ACCELERATION ; 
	}
	/**Function: to Get ID
	 * 	Inputs: nothing
	 	outputs: string
	 */

	std::string GetID()
	{
		return id ;
	}
	/**Function: to Get speed
	 * 	Inputs: nothing
	 	outputs: double
	 */
	double GetSpeed()
	{
		return speed; 
	}
	/**Function: to Get locatoin(x,y)
	 * 	Inputs: double, double
	 	outputs: nothing
	 */
	void GetLocation(double *x , double *y)
	{
		*x = x_location ;
		*y = y_location ;
	}
	/**Function: to Get x_location
	 * 	Inputs: nothing
	 	outputs: double
	 */
	double GetX()
	{
		return x_location ;
	}
	/**Function: to Get Y_location
	 * 	Inputs: nothing
	 	outputs: double
	 */
	double GetY()
	{
		return y_location;
	}
		/**Function: to Get acceleration
	 * 	Inputs: nothing
	 	outputs: double
	 */
	double GetAcceleration()
	{
		return acceleration ;
	}
	/**Function: to Get location form Gps
	 * 	Inputs: GPS_ystem
	 	outputs: nothing
	 */
	void SetLocationFromGPS(GPS_System & GPS)
	{
		x_location = GPS.GetX();
		y_location = GPS.GetY();
	}
};

class car : public vehicle
{
	public:
	// consturctor
	car(){}
	car(std::string ID , double SPEED , double x , double y , double ACCELERATION) : vehicle(ID , SPEED , x , y , ACCELERATION){}

};

class Truck : public vehicle
{
	public:
	// contructor
		Truck(){}
	Truck(std::string ID , double SPEED , double x , double y , double ACCELERATION) : vehicle(ID , SPEED , x , y , ACCELERATION){}
	
};
#endif  