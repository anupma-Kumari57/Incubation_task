#include <iostream>
#include <string>
#include <vector>
#include <thread>

class telematic
{
private:
    /* data */
    double latitude;
    double longitude;
public:
    //default constructor, here we are using static data but in real-time we will use gps sensor data 

    telematic(){
        latitude=12390930;
        longitude=923489821;
    }
    
    /* this senGPSToServer() function will send the location data from vehicle to the server or other vehicle we can use
    various communication model for it to send data */

    std::vector<double> senGPSToServer(){
        std::vector<double> res;
        res.push_back(latitude);
        res.push_back(longitude);

        return res;
    }
    
    /* trackVehicle() function will display location of the car after every 10 seconds new location will be send as per 
    sensor data which is sensed by the GPS sensor but here we are using staic data so same location will be shown everytime */

    void trackVehicle(){
        while(true){
            std::cout<<"Location of the car is --Latitude: "<<latitude<<" and longitude: "<<longitude<<"\n";

            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
    }
    
};


int main(){

    telematic ecu;     //object of telematic class

    ecu.trackVehicle();  //calling trackVehicle() function
}