#ifndef SENSORVALIDATOR_H
#define SENSORVALIDATOR_H

#include <string>
#include <vector>
#include "User.h"

using namespace std;

class SensorValidator {
private: 
    vector <User> maliciousUsers;
public:
    SensorValidator();

    // Getters
    vector<User> getMaliciousUsers() const;

    // Méthodes principales
    bool isValidSensor(const Sensor& sensor);
    bool isUserReliable(const User& user);
    vector<User> detectMaliciousUsers(const vector<User>& users);
};

#endif // SENSORVALIDATOR_H
