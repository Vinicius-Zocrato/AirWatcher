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

string Cleaner::getCleanerID(){
    return this->CleanerId;
}
float Cleaner::getLatitude(){
    return this->Latitude;
}
float Cleaner::getLongitude(){
    return this->Longitude;
}
tm Cleaner::getTimeStampStart(){
    return this->TimeStampStart;
}
tm Cleaner::getTimeStampStop(){
    return this->TimeStampStop;
}

void Cleaner::toString() const{
    char bufStart[20];
    char bufStop[20];
    std::strftime(bufStart, sizeof(bufStart), "%Y-%m-%d %H:%M:%S", &TimeStampStart);
    std::strftime(bufStop, sizeof(bufStop), "%Y-%m-%d %H:%M:%S", &TimeStampStop);

    std::cout << "Cleaner ID: "    << CleanerId
              << ", Latitude: "    << Latitude
              << ", Longitude: "   << Longitude
              << ", Start: "       << bufStart
              << ", Stop: "        << bufStop
              << std::endl;
}


bool Cleaner::isActiveAt(time_t time) {

    return true; 
}
double Cleaner::estimatedImpact() {
    return 0.0; 
}