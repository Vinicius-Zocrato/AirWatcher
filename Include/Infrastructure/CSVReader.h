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
    CSVReader(const string &filename);
    ~CSVReader();

    vector<Sensor> loadSensors() const;
    vector<Measurement> loadMeasurements() const;
    vector<User> loadUsers() const;
    vector<Provider> loadProviders() const;
    vector<Cleaner> loadCleaners() const;
    vector<Attribute> loadAtributes() const;

private:
    string filename;
    vector<Sensor> sensors;
    vector<Measurement> measurements;
    vector<User> users;
    vector<Provider> providers;
    vector<Cleaner> cleaners;
    vector<Attribute> atributes;
};

#endif // CSVREADER_H