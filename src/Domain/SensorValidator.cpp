#include "SensorValidator.h"
#include <cmath>
#include <iostream>

using namespace std;

// Constructeur
SensorValidator::SensorValidator() {}

// Getters
bool SensorValidator::getIsValidSensor() const {
    return isValidSensor;
}

bool SensorValidator::getIsUserReliable() const {
    return isUserReliable;
}

std::vector<User> SensorValidator::getMaliciousUsers() const {
    return maliciousUsers;
}

// Méthode : Vérifie si un capteur est valide (exemple simple basé sur une condition)
bool SensorValidator::isValidSensor(const Sensor& sensor) {

}

// Méthode : Vérifie si un utilisateur est fiable (exemple simple basé sur flag)
bool SensorValidator::isUserReliable(const User& user) {

}

// Méthode : Détecte les utilisateurs malveillants
vector<User> SensorValidator::detectMaliciousUsers(const vector<User>& users) {
    maliciousUsers.clear();  // Réinitialiser

    for (const auto& user : users) {
        if (!isUserReliable(user)) {
            maliciousUsers.push_back(user);
        }
    }

    return maliciousUsers;
}
