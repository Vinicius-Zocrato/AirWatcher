#include "../../Include/Infrastructure/CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <limits.h>
#include <filesystem>

std::string getExecutableDir() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count == -1) {
        std::cerr << "Erreur pour localiser l'exécutable" << std::endl;
        exit(1);
    }
    std::string exePath(result, count);
    return std::filesystem::path(exePath).parent_path().string();
}

    

CSVReader::CSVReader() {
    basePath = getExecutableDir() + "/Data/";
    // std::cout << "CSVReader constructor called, using basePath: " << basePath << std::endl;
}

CSVReader::~CSVReader() {}

bool parseDateTime(const std::string &s, std::tm &out_tm) {
    std::istringstream ss(s);
    ss >> std::get_time(&out_tm, "%Y-%m-%d %H:%M:%S");
    return !ss.fail();
}

void CSVReader::loadData() {
    loadAttributes(basePath + "attributes.csv");
    loadCleaners(basePath + "cleaners.csv");
    loadMeasurements(basePath + "measurements.csv");
    loadProviders(basePath + "providers.csv");
    loadSensors(basePath + "sensors.csv");
    loadUsers(basePath + "users.csv");
}

vector<Sensor> CSVReader::loadSensors(const string &filename) {
    if (this->measurements.empty()) {
        loadMeasurements(basePath + "measurements.csv");
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
        return {};
    }

    std::vector<std::string> SensorID;
    std::vector<float> latitude;
    std::vector<float> longitude;

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string s1, s2, s3;

        if (!std::getline(ss, s1, ';')) continue;
        if (!std::getline(ss, s2, ';')) continue;
        if (!std::getline(ss, s3, ';')) continue;

        try {
            SensorID.push_back(s1);
            float v1 = std::stod(s2);
            float v2 = std::stod(s3);
            latitude.push_back(v1);
            longitude.push_back(v2);
        } catch (const std::exception &e) {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    for (size_t i = 0; i < SensorID.size(); i++) {
        this->sensors.push_back(Sensor(SensorID[i], latitude[i], longitude[i], ""));
    }

    for (const auto& m : measurements) {
        for (auto& s : sensors) {
            if (m.getSensorID() == s.getId()) {
                s.addMeasurement(m);
            }
        }
    }

    return sensors;
}

vector<Measurement> CSVReader::loadMeasurements(const string &filename) {
    if (this->attributes.empty()) {
        loadAttributes(basePath + "attributes.csv");
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
        return {};
    }

    std::vector<std::string> attribute;
    std::vector<std::string> sensorID;
    std::vector<float> value;
    std::vector<std::tm> timestamp;

    std::tm tm_time = {};

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string s1, s2, s3, s4;

        if (!std::getline(ss, s1, ';')) continue;
        if (!std::getline(ss, s2, ';')) continue;
        if (!std::getline(ss, s3, ';')) continue;
        if (!std::getline(ss, s4, ';')) continue;

        try {
            if (!parseDateTime(s1, tm_time)) {
                std::cerr << "Date invalid format at: " << linha << "\n";
                continue;
            }
            timestamp.push_back(tm_time);
            sensorID.push_back(s2);
            attribute.push_back(s3);
            float v1 = std::stod(s4);
            value.push_back(v1);
        } catch (const std::exception &e) {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    for (size_t i = 0; i < value.size(); i++) {
        for (size_t j = 0; j < attributes.size(); j++) {
            if (attribute[i] == attributes[j].getAttributeID()) {
                this->measurements.push_back(Measurement(timestamp[i], attributes[j], value[i], sensorID[i]));
            }
        }
    }

    return measurements;
}

vector<User> CSVReader::loadUsers(const string &filename) {
    if (this->sensors.empty()) {
        loadSensors(basePath + "sensors.csv");
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
        return {};
    }

    std::vector<std::string> UserID;
    std::vector<std::string> SensorID;

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string s1, s2;

        if (!std::getline(ss, s1, ';')) continue;
        if (!std::getline(ss, s2, ';')) continue;

        UserID.push_back(s1);
        SensorID.push_back(s2);
    }

    for (size_t i = 0; i < UserID.size(); i++) {
        users.push_back(User(UserID[i]));
        for (auto& sensor : sensors) {
            if (SensorID[i] == sensor.getId()) {
                sensor.setUserID(UserID[i]);
                users[i].insertAssociatedSensor(sensor);
            }
        }
    }

    return users;
}

vector<Provider> CSVReader::loadProviders(const string &filename) {
    if (this->cleaners.empty()) {
        loadCleaners(basePath + "cleaners.csv");
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
        return {};
    }

    std::vector<std::string> ProviderID;
    std::vector<std::string> CleanerID;

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string s1, s2;

        if (!std::getline(ss, s1, ';')) continue;
        if (!std::getline(ss, s2, ';')) continue;

        ProviderID.push_back(s1);
        CleanerID.push_back(s2);
    }

    for (size_t i = 0; i < ProviderID.size(); i++) {
        providers.push_back(Provider(ProviderID[i]));
        for (const auto& cleaner : cleaners) {
            if (CleanerID[i] == cleaner.getCleanerID()) {
                providers[i].addCleaner(cleaner);
            }
        }
    }

    return providers;
}

std::vector<Cleaner> CSVReader::loadCleaners(const string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
        return {};
    }

    std::vector<std::string> cleanerID;
    std::vector<float> latitude;
    std::vector<float> longitude;
    std::vector<std::tm> timeStampStart;
    std::vector<std::tm> timeStampStop;

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

            std::tm tmStart = {};
            std::tm tmStop = {};

            if (!parseDateTime(s4, tmStart) || !parseDateTime(s5, tmStop)) {
                std::cerr << "Date invalid format at: " << linha << "\n";
                continue;
            }

            cleanerID.push_back(s1);
            latitude.push_back(v2);
            longitude.push_back(v3);
            timeStampStart.push_back(tmStart);
            timeStampStop.push_back(tmStop);
        } catch (const std::exception &e) {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    for (size_t i = 0; i < cleanerID.size(); i++) {
        cleaners.push_back(Cleaner(cleanerID[i], latitude[i], longitude[i], timeStampStart[i], timeStampStop[i]));
    }

    return cleaners;
}

std::vector<Attribute> CSVReader::loadAttributes(const string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error, open File: " << filename << "\n";
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

        AttributeID.push_back(s1);
        Unit.push_back(s2);
        Description.push_back(s3);
    }

    for (size_t i = 0; i < AttributeID.size(); i++) {
        attributes.push_back(Attribute(AttributeID[i], Unit[i], Description[i]));
    }

    return attributes;
}

const std::vector<Sensor>& CSVReader::getSensors() { return sensors; }
const std::vector<Measurement>& CSVReader::getMeasurements() { return measurements; }
const std::vector<User>& CSVReader::getUsers() { return users; }
const std::vector<Provider>& CSVReader::getProviders() { return providers; }
const std::vector<Cleaner>& CSVReader::getCleaners() { return cleaners; }
const std::vector<Attribute>& CSVReader::getAttributes() { return attributes; }
