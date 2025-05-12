#include "../../Include/Domain/Sensor.h"
Sensor::Sensor() {

}

Sensor::Sensor(string sensorID, float lat, float longitude) {
    this->sensorID = sensorID;
    this->latitude = lat;
    this->longitude = longitude;
    this->status = true;
}


Sensor::~Sensor() {

}

vector<Measurement> Sensor::getMeasurements(){
    return this->measurements;
}

void Sensor::setStatus(){
    this->status = !this->status;
}

vector<Measurement> Sensor::getMeasurementPeriod(string init, string final){ //not implemented yet

    

    return this->measurements;
}


float Sensor::getLatitude(){
    return this->latitude;
}

float Sensor::getLongitude(){
    return this->longitude;
}

bool Sensor::getStatus() const{
    return this->status;
}
