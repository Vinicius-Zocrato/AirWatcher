#include "../../Include/Infrastructure/CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <iomanip>

CSVReader::CSVReader()
{
#ifdef MAP
    cout << "CSVReader constructor called" << endl;
#endif
}

vector<Sensor> CSVReader::loadSensors(const string &filename) const
{
    // CSV FILE FORMAT: sensorID, latitude, longitude
    // The attribute "status" is not included in the CSV file
    // It is set to true by default in the constructor of the Sensor class

    // We need to get the userID for each sensor

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file!" << endl;
        return {};
    }

    string line;

    vector<Sensor> sensors;
    vector<User> users = loadUsers("users.csv");

    while (getline(file, line))
    {
        stringstream ss(line);
        string sensorID;
        double latitude, longitude;
        string userID = "Government";

        getline(ss, sensorID, ';');
        ss >> latitude;
        ss.ignore(1);
        ss >> longitude;

        for (const auto &user : users)
        {
            for (const auto &sensor : user.getAssociatedSensors())
            {
                if (sensor.getId() == sensorID)
                {
                    userID = user.getUserId();
                    break;
                }
            }
        }

        Sensor sensor(sensorID, latitude, longitude, true, userID);
        sensors.push_back(sensor);
    }

    return sensors;
}

vector<Measurement> CSVReader::loadMeasurements(const string &filename) const
{
    // CSV FILE FORMAT: timestamp, sensorID, attribute, value
    vector<Measurement> measurements;
    // Load measurements from CSV file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file!" << endl;
        return {};
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string timestamp;
        double value;
        Attribute attribute;
        string sensorID;

        getline(ss, timestamp, ';');
        ss >> sensorID;
        ss.ignore(1);
        ss >> attribute;
        ss.ignore(1);
        ss >> value;
        ss.ignore(1);

        Measurement measurement(timestamp, attribute, value, sensorID);
        measurements.push_back(measurement);
    }

    return measurements;
}

vector<User> CSVReader::loadUsers(const string &filename) const
{
    vector<User> users;
    // THE CSV FILE FORMAT: userID, sensorID
    // The attribute "score" is not included in the CSV file
    // It is set to 0 by default in the constructor of the User class
    // The attribute "isReliable" is not included in the CSV file
    // It is set to true by default in the constructor of the User class
    map<string, vector<Sensor>> userSensorsMap;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file!" << endl;
        return {};
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string userId;
        string sensorID;

        getline(ss, userId, ';');
        getline(ss, sensorID, ';');
        User user;
        user.setUserId(userId);
        user.setScore(0);
        user.setIsReliable(true);
        userSensorsMap[userId].push_back(Sensor(sensorID, 0, 0, true, userId));

        user.setAssociatedSensors(userSensorsMap[userId]);
        users.push_back(user);
    }
    return users;
}

vector<Provider> CSVReader::loadProviders(const string &filename) const
{
    vector<Provider> providers;
    // Load providers from CSV file
    return providers;
}

bool parseDateTime(const std::string &s, std::tm &out_tm)
{
    std::istringstream ss(s);
    ss >> std::get_time(&out_tm, "%Y-%m-%d %H:%M:%S");
    return !ss.fail();
}

std::vector<Cleaner> CSVReader::loadCleaners(const string &filename) const
{

    std::ifstream file(this->filename);
    if (!file)
    {
        std::cerr << "Error, open File\n";
        return {};
    }

    std::vector<std::string> cleanerID;
    std::vector<float> latitude;
    std::vector<float> longitude;
    std::vector<std::tm> timeStampStart;
    std::vector<std::tm> timeStampStop;

    std::tm tm_start = {};
    std::tm tm_stop = {};

    std::string linha;
    while (std::getline(file, linha))
    {
        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string s1, s2, s3, s4, s5;

        if (!std::getline(ss, s1, ';'))
            continue;

        if (!std::getline(ss, s2, ';'))
            continue;

        if (!std::getline(ss, s3, ';'))
            continue;

        if (!std::getline(ss, s4, ';'))
            continue;

        if (!std::getline(ss, s5, ';'))
            continue;

        try
        {
            float v2 = std::stod(s2);
            float v3 = std::stod(s3);

            cleanerID.push_back(s1);
            latitude.push_back(v2);
            longitude.push_back(v3);

            std::tm tmStart = {};
            std::tm tmStop = {};

            if (!parseDateTime(s4, tmStart) ||
                !parseDateTime(s5, tmStop))
            {
                std::cerr << "Date invalid format at: " << linha << "\n";
                continue;
            }

            timeStampStart.push_back(tmStart);
            timeStampStop.push_back(tmStop);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    std::vector<Cleaner> cleaners;

    for (size_t i = 0; i < cleanerID.size(); i++)
    {
        cleaners.push_back(Cleaner(cleanerID[i], latitude[i], longitude[i], timeStampStart[i], timeStampStop[i]));
    }

    return {};

    this->cleaners = cleaners;

    return cleaners;
}

std::vector<Attribute> CSVReader::loadAttributes()
{

    std::ifstream file(this->filename);
    if (!file)
    {
        std::cerr << "Error, open File\n";
        return {};
    }

    std::vector<std::string> AttributeID;
    std::vector<std::string> Unit;
    std::vector<std::string> Description;

    std::string linha;
    while (std::getline(file, linha))
    {
        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string s1, s2, s3;

        if (!std::getline(ss, s1, ';'))
            continue;

        if (!std::getline(ss, s2, ';'))
            continue;

        if (!std::getline(ss, s3, ';'))
            continue;

        try
        {
            // armazena
            AttributeID.push_back(s1);
            Unit.push_back(s2);
            Description.push_back(s3);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro convert values: " << linha << "\n";
        }
    }

    std::vector<Attribute> attributes;

    for (int i = 0; i < AttributeID.size(); i++)
    {
        attributes.push_back(Attribute(AttributeID[i], Unit[i], Description[i]));
    }

    this->attributes = attributes;

    return attributes;
}

const std::vector<Sensor> &CSVReader::getSensors()
{
    return sensors;
}

const std::vector<Measurement> &CSVReader::getMeasurements()
{
    return measurements;
}

const std::vector<User> &CSVReader::getUsers()
{
    return users;
}

const std::vector<Provider> &CSVReader::getProviders()
{
    return providers;
}

const std::vector<Cleaner> &CSVReader::getCleaners()
{
    return cleaners;
}

const std::vector<Attribute> &CSVReader::getAttributes()
{
    return attributes;
}
