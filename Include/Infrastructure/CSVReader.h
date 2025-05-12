#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "../Domain/Sensor.h"
#include "../Domain/Measurement.h"
#include "../Domain/User.h"
#include "../Domain/Provider.h"
#include "../Domain/Cleaner.h"

class CSVReader
{
public:
    CSVReader();
    ~CSVReader();

    vector<Sensor> loadSensors(const string &filename) const;
    vector<Measurement> loadMeasurements(const string &filename) const;
    vector<User> loadUsers(const string &filename) const;
    vector<Provider> loadProviders(const string &filename) const;
    vector<Cleaner> loadCleaners(const string &filename) const;

private:
    vector<Sensor> sensors;
    vector<Measurement> measurements;
    vector<User> users;
    vector<Provider> providers;
    vector<Cleaner> cleaners;
    vector<Attribute> attributes;
};

#endif // CSVREADER_H