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
    vector<Sensor> getSensors() const;  
    void calculateAirQuality(double radius, float latitude, float longitude, tm init, tm fin);
    double calculateSimilarity(Sensor sensor1, Sensor sensor2, tm init, tm fin) const; 
    void findMostSimilarSensors(Sensor target, tm init, tm fin); 
    double computeAverage();  
    void rankSensorByQuality(string attribute, tm init, tm fin);
    Sensor findSensorById(const string capteurId ) const;

};

#endif
