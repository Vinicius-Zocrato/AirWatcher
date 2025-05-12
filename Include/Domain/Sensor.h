#ifndef SENSOR_H   
#define SENSOR_H  

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Measurement.h"
using namespace std;

class Sensor
{
private:
    string sensorID;
    float latitude;
    float longitude;
    bool status;
    vector<Measurement> measurements;

public:
    Sensor();

    Sensor(string sensorID, float lat, float lon);

    ~Sensor();

    void addMeasurement(Measurement measurement);

    vector<Measurement> getMeasurements();

    vector<Measurement> getMeasurementPeriod(string init, string final); //not implemented yet


    void setStatus();

    float getLatitude();

    float getLongitude();

    bool getStatus() const ;
};

#endif
