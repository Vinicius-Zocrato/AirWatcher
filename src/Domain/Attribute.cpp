#include "../../Include/Domain/Attribute.h"

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