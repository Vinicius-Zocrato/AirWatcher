#ifndef AIRQUALITYANALIZER 
#define AIRQUALITYANALIZER  

#include<vector>
#include"Sensor.h"

using namespace std;

class AirQualityAnalizer
{
private:
    

public:

    double calculateAirQuality();
    double calculateSimilarity();
    vector<Sensor> findMostSiminarSensors();
    double computeAvarege();
    vector<Sensor> rankSensorByQuality();

};



#endif;
