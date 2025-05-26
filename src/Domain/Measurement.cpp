#include "../../Include/Domain/Measurement.h"
#include <iostream>

Measurement::Measurement(){

}

Measurement::Measurement(tm timestamp, Attribute attribute, float value, string sensorID){
    this->timestamp = timestamp;
    this->attribute = attribute;
    this->value = value;
    this->sensorID = sensorID;
}

Measurement::~Measurement(){

}

tm Measurement::getTimeStamp()const{
    return this->timestamp;

}
Attribute Measurement::getAttribute()const{
    return this->attribute;
}
float Measurement::getValue()const{
    return this->value;
}
string Measurement::getSensorID()const{
    return this->sensorID;
}
void Measurement::toString() const {
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timestamp);
    std::cout << "Timestamp: " << buf
              << ", Value: " << value
              << ", SensorID: " << sensorID
              << ", Attribute: ";

    attribute.toString();  
}