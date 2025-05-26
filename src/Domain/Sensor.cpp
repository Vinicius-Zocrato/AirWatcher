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

void Sensor::setStatus(bool status){
    this->status = status;
}

void Sensor::setUserID(string userID){
    this->userID = userID;
}

void Sensor::addMeasurement(Measurement measurement){
    measurements.push_back(measurement);
}

vector<Measurement> Sensor::getMeasurementPeriod(tm init, tm final) {
    // Convert tm to time_t for comparison
    time_t t_init = mktime(&init);
    time_t t_final = mktime(&final);

    vector<Measurement> result;
    for (const auto& measurement : measurements) {
        time_t t_measure = mktime(const_cast<tm*>(&measurement.getTimeStamp())); // Attention: getTimeStamp() doit retourner tm
        if (t_measure >= t_init && t_measure <= t_final) {
            result.push_back(measurement);
        }
    }
    return result;
}

vector<Measurement> Sensor::getMeasurementsByAttribute(string attribute){ 
    vector<Measurement> result;
    for (const auto& measurement : measurements) {
        if (measurement.getAttribute().getAttributeID() == attribute) {
            result.push_back(measurement);
        }
    }
    return result;
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