#include "../../Include/Domain/Measurement.h"

Measurement::Measurement(){

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
void Measurement::toString() const {
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timestamp);
    std::cout << "Timestamp: " << buf
              << ", Value: " << value
              << ", Attribute: ";
    attribute.toString();  
}