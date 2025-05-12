#include "../../Include/Domain/Sensor.h"


Sensor::Sensor() {

}

Sensor::Sensor(string sensorID, float lat, float longitude, bool status) {
    this->sensorID = sensorID;
    this->latitude = lat;
    this->longitude = longitude;
    this->status = status;
}


Sensor::~Sensor() {

}
