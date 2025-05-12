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

    vector<Sensor> loadSensors() ;
    vector<Measurement> loadMeasurements() ;
    vector<User> loadUsers() ;
    vector<Provider> loadProviders() ;
    vector<Cleaner> loadCleaners() ;
    vector<Attribute> loadAttributes() ;

    const std::vector<Sensor>&      getSensors() ;
    const std::vector<Measurement>& getMeasurements() ;
    const std::vector<User>&        getUsers() ;
    const std::vector<Provider>&    getProviders() ;
    const std::vector<Cleaner>&     getCleaners() ;
    const std::vector<Attribute>&   getAttributes() ;

private:
    string filename;
    vector<Sensor> sensors;
    vector<Measurement> measurements;
    vector<User> users;
    vector<Provider> providers;
    vector<Cleaner> cleaners;
    vector<Attribute> attributes;
};

#endif // CSVREADER_H