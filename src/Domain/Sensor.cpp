#include "../../Include/Domain/Sensor.h"

Sensor::Sensor(string sensorID, float lat, float longitude, bool status, string userID)
{
    this->userID = userID;

    this->sensorID = sensorID;
    this->latitude = lat;
    this->longitude = longitude;
    this->status = status;
}

Sensor::~Sensor()
{
}

vector<Measurement> Sensor::getMeasurements()
{
    return this->measurements;
}

void Sensor::setStatus()
{
    this->status = !this->status;
}

vector<Measurement> Sensor::getMeasurementPeriod(string init, string final)
{ // not implemented yet

    return this->measurements;
}

float Sensor::getLatitude()
{
    return this->latitude;
}

float Sensor::getLongitude()
{
    return this->longitude;
}

float Sensor::getStatus()
{
    return this->status;
}
