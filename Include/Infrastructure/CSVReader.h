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
    CSVReader(const std::string &filename);
    ~CSVReader();

    std::vector<Sensor> loadSensors() const;
    std::vector<Measurement> loadMeasurements() const;
    std::vector<User> loadUsers() const;
    std::vector<Provider> loadProviders() const;
    std::vector<Cleaner> loadCleaners() const;

private:
    std::string filename;
    std::vector<Sensor> sensors;
    std::vector<Measurement> measurements;
    std::vector<User> users;
    std::vector<Provider> providers;
    std::vector<Cleaner> cleaners;
};

#endif // CSVREADER_H