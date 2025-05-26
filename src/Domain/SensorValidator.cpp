#include "SensorValidator.h"
#include "../Infrastructure/CSVReader.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <optional>
#include "User.h"
#include "Sensor.h"
#include "Measurement.h"

using namespace std;


// Constructeur
SensorValidator::SensorValidator() {}

// Getters
// bool SensorValidator::SetIsValidSensor( Sensor& sensor)  {
//     #ifdef MAP 
//     cout << "SensorValidator::getIsValidSensor()" << endl;
//     #endif
//   sensor.setStatus(); 
// return isValidSensor(sensor);
// }

// bool SensorValidator::SetIsUserReliable( Sensor& sensor)   {
//     #ifdef MAP 
//     cout << "SensorValidator::getIsUserReliable()" << endl;
//     #endif
//     //bool isUserReliable = user.getIsReliable();
//     //return isUserReliable;
// }

// std::vector<User> SensorValidator::getMaliciousUsers()  {
//     #ifdef MAP 
//     cout << "SensorValidator::getMaliciousUsers()" << endl;
//     #endif

//     return maliciousUsers;
// }


// Calcule la distance entre deux points pour les capteurs
static double distance(float lat1, float lon1, float lat2, float lon2) {
    const double R = 6371.0; // rayon Terre en km
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    double a = sin(dLat/2)*sin(dLat/2) +
               cos(lat1*M_PI/180.0)*cos(lat2*M_PI/180.0)*
               sin(dLon/2)*sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}


// Méthode : Vérifie si un capteur est valide (exemple simple basé sur une condition)
bool SensorValidator::isValidSensor( Sensor& sensor)  {
    #ifdef MAP 
    cout << "SensorValidator::isValidSensor()" << endl;
    #endif
    CSVReader reader;
    reader.loadSensors("../Data/sensors.csv"); // charge sensors et measurements

    Measurement mesureRecent = sensor.getMeasurements()[0];
    float lastvalue = mesureRecent.getValue();

    vector<float> ValeurVoisines;
    for(const auto& s : reader.getSensors()) {
        if (s.getId() != sensor.getId()) { // Exclure le capteur lui-même
            float dist = distance(sensor.getLatitude(), sensor.getLongitude(),
                                  s.getLatitude(), s.getLongitude());
            if (dist < 0.5) { // Seuil de proximité de 0.5 km
                for (const auto& m : s.getMeasurements()) {
                    ValeurVoisines.push_back(m.getValue());
                }
            }
        }
    }


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
