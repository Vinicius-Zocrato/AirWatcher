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
    string userID;
    vector<Measurement> measurements;

public:
    Sensor();

<<<<<<< HEAD
    Sensor(string sensorID, float lat, float lon, bool status, string userID);
=======
    Sensor(string sensorID, float lat, float lon);
>>>>>>> 7315d89dcce92ce9c7fd458bc2ee1139c85479a0

    ~Sensor();

    void addMeasurement(Measurement measurement);

    vector<Measurement> getMeasurements();

    vector<Measurement> getMeasurementPeriod(string init, string final); // not implemented yet

    void setStatus();

    float getLatitude();

    float getLongitude();

    float getStatus();
};

#endif
