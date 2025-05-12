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

    vector<Sensor> loadSensors(const string &filename) ;
    vector<Measurement> loadMeasurements(const string &filename) ;
    vector<User> loadUsers(const string &filename) ;
    vector<Provider> loadProviders(const string &filename) ;
    vector<Cleaner> loadCleaners(const string &filename) ;
    vector<Cleaner> loadAttributes(const string &filename) ;

    const std::vector<Sensor>&      getSensors() ;
    const std::vector<Measurement>& getMeasurements() ;
    const std::vector<User>&        getUsers() ;
    const std::vector<Provider>&    getProviders() ;
    const std::vector<Cleaner>&     getCleaners() ;
    const std::vector<Attribute>&   getAttributes() ;

private:
    vector<Sensor> sensors;
    vector<Measurement> measurements;
    vector<User> users;
    vector<Provider> providers;
    vector<Cleaner> cleaners;
    vector<Attribute> attributes;
};

#endif // CSVREADE