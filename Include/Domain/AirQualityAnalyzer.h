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
    AirQualityAnalyzer(vector<Sensor> sensors);
    double calculateAirQuality();
    double calculateSimilarity(const std::vector<Measurement>& m1,
    const std::vector<Measurement>& m2);
    vector<Sensor> findMostSimilarSensors(Sensor target,vector<Sensor> others, int topN);
    double computeAverage();
    vector<Sensor> rankSensorByQuality();
    Sensor findSensorById(const string capteurId ) const;

};



#endif;
