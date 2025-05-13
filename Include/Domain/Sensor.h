#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

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

    Sensor(string sensorID, float lat, float lon, string userID);

    ~Sensor();

    void addMeasurement(Measurement measurement);

    vector<Measurement> getMeasurements();

    vector<Measurement> getMeasurementPeriod(tm init, tm final); // not implemented yet

    void setStatus();

    string getId() const;

    float getLatitude() const;

    float getLongitude() const;

    string getUserId() const;

    bool getStatus() const;

    void toString() const;
};

#endif
