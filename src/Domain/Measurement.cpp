#include "../../Include/Domain/Measurement.h"

Measurement::Measurement(){
    this->timestamp = "";
    this->attribute = Attribute();
    this->value = 0.0f;
}
Measurement::~Measurement(){
}