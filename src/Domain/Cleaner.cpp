#include "../../Include/Domain/Cleaner.h"
#include "../../Include/Domain/Sensor.h"


Cleaner::Cleaner() {
    
}

Cleaner::Cleaner(string CleanerId, float Latitude, float Longitude, tm TimeStampStart, tm TimeStampStop){
    this->CleanerId = CleanerId;
    this->Latitude = Latitude;
    this->Longitude = Longitude;
    this->TimeStampStart = TimeStampStart;
    this->TimeStampStop = TimeStampStop;
}

Cleaner::~Cleaner() {
}

bool Cleaner::isActiveAt(time_t time) {

    return true; 
}
double Cleaner::estimatedImpact() {
    return 0.0; 
}