#include <iostream>
#include <string>
#include <array>
#include <thread>

class telematic

{
private:
    /* data */
    int canIn_vehicleSpeed;
    int canIn_fuelConsumption;
    int canIn_latitude;
    int canIn_longitude;

    std::array<int,4> out_res;

public:
    //default constructor, here we are using static data but in real-time we will use sensor data 

    telematic(){
        canIn_vehicleSpeed=100;
        canIn_fuelConsumption=500;
        canIn_latitude=1239;
        canIn_longitude=9234;
    }
    
    /* this send1ECUto2ECU() function will send the location data from 1 euc to another ecu */

    std::array<int,4> send1ECUto2ECU(){

        out_res[0] = canIn_vehicleSpeed;
        out_res[1] = canIn_fuelConsumption;
        out_res[2] = canIn_latitude;
        out_res[3] = canIn_longitude;

        return out_res;
    }

    /* here vehicleSpeedCalibration is a calibration variable.
    this function will basically check that speed is within the threshold or not and display 
    message accordingly */

    void CheckingSpeedIsInThresholdOrNot(double vehicleSpeedCalibration){

        if(canIn_vehicleSpeed> vehicleSpeedCalibration){
            std::cout<<"Warning: Vehicle speed "<<canIn_vehicleSpeed<<"km/h exceeds the calibration threshold "<<vehicleSpeedCalibration<<"km/h\n";
        }
        else{
            std::cout<<"Vehicle speed is within the safe threshold.\n";
        }
     
    }
    
    /* trackVehicle() function will display data of the car */

    void trackVehicle(){
            std::cout<<"Location of the car is --Latitude: "<<canIn_latitude<<" and longitude: "<<canIn_longitude<<"\n";

            std::cout<<"Speed of the car is "<<canIn_vehicleSpeed<<"\n";

            std::cout<<"Fuel Consumption of the car is "<<canIn_fuelConsumption<<"\n";

    }
    
};


int main(){

    telematic ecu;     //object of telematic class

    ecu.trackVehicle();  //calling trackVehicle() function
    ecu.CheckingSpeedIsInThresholdOrNot(120);
}


