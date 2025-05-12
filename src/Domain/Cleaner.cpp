#include "../../Include/Domain/Cleaner.h"
#include "../../Include/Domain/Sensor.h"


Cleaner::Cleaner()
    : CleanerId(""), Latitude(0.0f), Longitude(0.0f), TimeStampStart(""), TimeStampStop("") {
    
}

Cleaner::~Cleaner() {
}

bool Cleaner::isActiveAt() {

    return true; 
}
double Cleaner::estimatedImpact() {
    return 0.0; 
}