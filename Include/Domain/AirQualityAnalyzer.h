#ifndef AIRQUALITYANALYZER 
#define AIRQUALITYANALYZER  

#include<vector>
#include"Sensor.h"

using namespace std;

class AirQualityAnalyzer
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
