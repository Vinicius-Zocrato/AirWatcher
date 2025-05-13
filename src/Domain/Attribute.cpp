#include "../../Include/Domain/Attribute.h"
#include <iostream>

Attribute::Attribute() {

}

Attribute::Attribute(string attributeID, string unit, string description){
    this->attributeID = attributeID;
    this->unit = unit;
    this->description = description;
}

Attribute::~Attribute() {
}


string Attribute::getUnit() const{
    return this->unit;
}

string Attribute::getDescription() const{
    return this->description;

}
string Attribute::getAttibruteID() const{
    return this->attributeID;
}

void Attribute::toString() const {
    std::cout << "AttributeID: " << attributeID
              << ", Unit: "       << unit
              << ", Description: "<< description
              << std::endl;
}