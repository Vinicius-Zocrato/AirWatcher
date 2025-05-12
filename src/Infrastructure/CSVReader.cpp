#include "../../Include/Infrastructure/CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    vector<User> userIDs = loadUsers("users.csv");

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

        for (const auto &user : userIDs)
        {
            if (user.getUserId() == sensorID)
            {
                userID = user.getUserId();
                break;
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

vector<Cleaner> CSVReader::loadCleaners(const string &filename) const
{
    vector<Cleaner> cleaners;
    // Load cleaners from CSV file
    return cleaners;
}
