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
    vector<Sensor> getSensors() const;  //not   implemented yet
    double calculateAirQuality(int radius, float latitude, float longitude, const string& attributeID); // not implemented yet
    double calculateSimilarity(const std::vector<Measurement>& m1,const std::vector<Measurement>& m2); 
    vector<Sensor> findMostSimilarSensors(Sensor target, int topN); //not implemented yet
    double computeAverage();  
    vector<Sensor> rankSensorByQuality();
    Sensor findSensorById(const string capteurId ) const;

};



#endif;
