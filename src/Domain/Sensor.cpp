#include "../../Include/Domain/Sensor.h"
<<<<<<< HEAD

Sensor::Sensor()
{
}

Sensor::Sensor(string sensorID, float lat, float longitude, bool status, string userID)
{
    this->userID = userID;
=======
Sensor::Sensor() {

}

<<<<<<< HEAD
Sensor::Sensor(string sensorID, float lat, float longitude, bool status = true) {
>>>>>>> 7315d89dcce92ce9c7fd458bc2ee1139c85479a0
=======
Sensor::Sensor(string sensorID, float lat, float longitude) {
>>>>>>> 7787ca97a99465dd459c6706c5380fd28d67f1bc
    this->sensorID = sensorID;
    this->latitude = lat;
    this->longitude = longitude;
    this->status = true;
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
