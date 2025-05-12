#include "CSVReader.h"
#include <fstream>
#include <sstream>


CSVReader::CSVReader(const std::string &filename)
  : filename(filename)
{
    
}

CSVReader::~CSVReader() {
    
}


std::vector<Sensor> CSVReader::loadSensors()  {
    
    return {};
}

std::vector<Measurement> CSVReader::loadMeasurements()  {
    
    return {};
}

std::vector<User> CSVReader::loadUsers()  {
    
    return {};
}

std::vector<Provider> CSVReader::loadProviders()  {
    
    return {};
}

std::vector<Cleaner> CSVReader::loadCleaners()  {
    
    return {};
}

std::vector<Attribute> CSVReader::loadAttributes() {

    std::ifstream file(this->filename);
    if (!file) {
        std::cerr << "Error, open File\n";
        return {};
    }

    std::vector<std::string> AttributeID;
    std::vector<std::string> Unit;
    std::vector<std::string> Description;

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;  

        std::stringstream ss(linha);
        std::string s1, s2, s3;

        
        if (!std::getline(ss, s1, ';')) continue;
        
        if (!std::getline(ss, s2, ';')) continue;
        
        if (!std::getline(ss, s3, ';')) continue;

        
        try {
            // armazena
            AttributeID.push_back(s1);
            Unit.push_back(s2);
            Description.push_back(s3);
        } catch (const std::exception& e) {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    std::vector<Attribute> attributes;

    for(int i=0; i<AttributeID.size(); i++){
        attributes.push_back(Attribute(AttributeID[i], Unit[i], Description[i]));
    }

    this->attributes = attributes;

    return attributes;
}