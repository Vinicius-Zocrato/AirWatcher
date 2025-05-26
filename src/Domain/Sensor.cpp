#include "../../Include/Domain/Sensor.h"
Sensor::Sensor() {

}

Sensor::Sensor(string sensorID, float lat, float longitude, string userId) {
    this->sensorID = sensorID;
    this->latitude = lat;
    this->longitude = longitude;
    this->status = true;
    this->userID = userID;
}


Sensor::~Sensor() {

}

vector<Measurement> Sensor::getMeasurements(){
    return this->measurements;
}

void Sensor::setStatus(){
    this->status = !this->status;
}

void Sensor::setUserID(string userID){
    this->userID = userID;
}

void Sensor::addMeasurement(Measurement measurement){
    measurements.push_back(measurement);
}

vector<Measurement> Sensor::getMeasurementPeriod(tm init, tm final){ //not implemented yet

    
    return {};
}

string Sensor::getId() const{
    return this->sensorID;
}

string Sensor::getUserId() const{
    return this->userID;
}


float Sensor::getLatitude() const{
    return this->latitude;
}

float Sensor::getLongitude() const{
    return this->longitude;
}

bool Sensor::getStatus() const{
    return this->status;
}

void Sensor::toString() const {
    std::cout << "Sensor ID: " << sensorID
              << ", Latitude: " << latitude
              << ", Longitude: " << longitude
              << ", UserID: " << userID
              << ", Status: " << (status ? "Active" : "Inactive")
              << std::endl;
    std::cout << "Measurements (" << measurements.size() << "):" << std::endl;
    for (const auto& m : measurements) {
        m.toString();
    }
}