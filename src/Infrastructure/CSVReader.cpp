#include "CSVReader.h"
#include <fstream>
#include <sstream>


CSVReader::CSVReader(const std::string &filename)
  : filename(filename)
{
    
}

CSVReader::~CSVReader() {
    
}


std::vector<Sensor> CSVReader::loadSensors() const {
    
    return {};
}

std::vector<Measurement> CSVReader::loadMeasurements() const {
    
    return {};
}

std::vector<User> CSVReader::loadUsers() const {
    
    return {};
}

std::vector<Provider> CSVReader::loadProviders() const {
    
    return {};
}

std::vector<Cleaner> CSVReader::loadCleaners() const {
    
    return {};
}

std::vector<Attribute> CSVReader::loadAtributes() const{


    return {};
}