#ifndef AIRQUALITYANALYZER 
#define AIRQUALITYANALYZER  

#include<vector>
#include"Sensor.h"

using namespace std;

class AirQualityAnalyzer
{
private:
    
    vector<Sensor> sensors;

public:

    AirQualityAnalyzer();
    double calculateAirQuality();
    double calculateSimilarity();
    vector<Sensor> findMostSiminarSensors();
    double computeAvarege();
    vector<Sensor> rankSensorByQuality();
    Sensor findSensorById(const string capteurId ) const;

};



#endif;
