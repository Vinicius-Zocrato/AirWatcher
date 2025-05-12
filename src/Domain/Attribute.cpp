#include "../../Include/Domain/Attribute.h"
#include <iostream>

Attribute::Attribute() {
    this->attributeID = "";
    this->unit = "";
    this->description = "";
}

Attribute::Attribute(string attributeID, string unit, string description){
    this->attributeID = attributeID;
    this->unit = unit;
    this->description = description;
}

Attribute::~Attribute() {
}

void Attribute::toString() const {
    std::cout << "AttributeID: " << attributeID
              << ", Unit: "       << unit
              << ", Description: "<< description
              << std::endl;
}