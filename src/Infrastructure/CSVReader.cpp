#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip> 

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

bool parseDateTime(const std::string& s, std::tm& out_tm) {
    std::istringstream ss(s);
    ss >> std::get_time(&out_tm, "%Y-%m-%d %H:%M:%S");
    return !ss.fail();
}

std::vector<Cleaner> CSVReader::loadCleaners()  {

    std::ifstream file(this->filename);
    if (!file) {
        std::cerr << "Error, open File\n";
        return {};
    }

    std::vector<std::string> cleanerID;
    std::vector<float> latitude;
    std::vector<float> longitude;
    std::vector<std::tm> timeStampStart;
    std::vector<std::tm> timeStampStop;

    std::tm tm_start = {};
    std::tm tm_stop    = {};

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;  

        std::stringstream ss(linha);
        std::string s1, s2, s3, s4, s5;

        
        if (!std::getline(ss, s1, ';')) continue;
        
        if (!std::getline(ss, s2, ';')) continue;
        
        if (!std::getline(ss, s3, ';')) continue;

        if (!std::getline(ss, s4, ';')) continue;

        if (!std::getline(ss, s5, ';')) continue;

        
        try {
            float v2 = std::stod(s2);
            float v3 = std::stod(s3);

            cleanerID.push_back(s1);
            latitude.push_back(v2);
            longitude.push_back(v3);

            std::tm tmStart = {};
            std::tm tmStop  = {};

            if (!parseDateTime(s4, tmStart) ||
                !parseDateTime(s5,  tmStop)) {
                std::cerr << "Date invalid format at: " << linha << "\n";
                continue;
            }

            timeStampStart.push_back(tmStart);
            timeStampStop.push_back(tmStop);
        } catch (const std::exception& e) {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }




    std::vector<Cleaner> cleaners;

    for (size_t i = 0; i < cleanerID.size(); i++)
    {
        cleaners.push_back(Cleaner(cleanerID[i], latitude[i], longitude[i], timeStampStart[i], timeStampStop[i]));
    }
    

    this->cleaners = cleaners;

    return cleaners;
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