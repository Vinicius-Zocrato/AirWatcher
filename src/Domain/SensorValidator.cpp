#include "SensorValidator.h"
#include <cmath>
#include <iostream>
#include "User.h"
#include "Sensor.h"
#include "Measurement.h"

using namespace std;


// Constructeur
SensorValidator::SensorValidator() {}

// Getters
bool SensorValidator::getIsValidSensor(const Sensor& sensor) const {
    #ifdef MAP 
    cout << "SensorValidator::getIsValidSensor()" << endl;
    #endif
    bool isValidSensor = sensor.getStatus();
    return isValidSensor;
}

bool SensorValidator::getIsUserReliable(const User& user) const {
    #ifdef MAP 
    cout << "SensorValidator::getIsUserReliable()" << endl;
    #endif
    bool isUserReliable = user.getIsReliable();
    return isUserReliable;
}

std::vector<User> SensorValidator::getMaliciousUsers() const {
    #ifdef MAP 
    cout << "SensorValidator::getMaliciousUsers()" << endl;
    #endif
    
    return maliciousUsers;
}

// Méthode : Vérifie si un capteur est valide (exemple simple basé sur une condition)
bool SensorValidator::isValidSensor(const Sensor& sensor) {
    #ifdef MAP 
    cout << "SensorValidator::isValidSensor()" << endl;
    #endif
    return sensor.getStatus();


}

// Méthode : Vérifie si un utilisateur est fiable (exemple simple basé sur flag)
bool SensorValidator::isUserReliable(const User& user) {
    #ifdef MAP 
    cout << "SensorValidator::isUserReliable()" << endl;
    #endif
    return user.getIsReliable();
}

// Méthode : Détecte les utilisateurs malveillants
vector<User> SensorValidator::detectMaliciousUsers(const vector<User>& users) {
    #ifdef MAP 
    cout << "SensorValidator::detectMaliciousUsers()" << endl;
    #endif


    maliciousUsers.clear();  // Réinitialiser

    for (const auto& user : users) {
        if (!isUserReliable(user)) {
            maliciousUsers.push_back(user);
        }
    }

    return maliciousUsers;
}
