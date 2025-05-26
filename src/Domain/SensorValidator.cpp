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

// Moyenne
static float mean(const vector<float>& v) {
    if (v.empty()) return 0.0f;
    return std::accumulate(v.begin(), v.end(), 0.0f) / v.size();
}

// Ecart-type
static float ecartType(const vector<float>& v) {
    if (v.size() < 2) return 0.0f;
    float m = mean(v);
    float sum = 0.0f;
    for (float x : v) sum += (x - m) * (x - m);
    return sqrt(sum / (v.size() - 1));
}



// Méthode : Vérifie si un capteur est valide (exemple simple basé sur une condition)
bool SensorValidator::isValidSensor( Sensor& sensor) { {
    #ifdef MAP 
    cout << "SensorValidator::isValidSensor()" << endl;
    #endif
    CSVReader reader;
    reader.loadSensors("../Data/sensors.csv"); // charge sensors et measurements

    // Récupere la dernière mesure du capteur
    Measurement mesureRecent = sensor.getMeasurements()[0];
    float lastvalue = mesureRecent.getValue();

    //On va tester cette dernoière valeur par rapport aux valeurs voisines
    vector<float> ValeurVoisines;
    vector<Sensor> sensors = reader.getSensors();
    for (size_t i = 0; i < sensors.size(); i++) {
        Sensor& s = sensors[i];
        if (s.getId() != sensor.getId()) { // Exclure le capteur lui-même
            float dist = distance(sensor.getLatitude(), sensor.getLongitude(), s.getLatitude(), s.getLongitude());
            if (dist < 0.5) { // Seuil de proximité de 0.5 km
                Measurement measurements = s.getMeasurements()[0]; // On prend la première mesure pour simplifier
                if (measurements.getAttribute().getAttributeID() == mesureRecent.getAttribute().getAttributeID()) { // Vérifie si l'attribut est le même
                ValeurVoisines.push_back(measurements.getValue()); //Ajoute de cette valeur à la liste des valeurs voisines
                }
            }
        }
    }

    if (ValeurVoisines.size() < 2) return true; // Non déterminable, on considère valide car peut pas montrer le contraire
    // Calcul de la moyenne des valeurs voisines
    float moyenneVoisins = mean(ValeurVoisines);
    float ecartTypeVoisins = ecartType(ValeurVoisines);
    float borneBasse = moyenneVoisins - 2 * ecartTypeVoisins;
    float borneHaute = moyenneVoisins + 2 * ecartTypeVoisins;

    // Vérification si la dernière valeur est en dehors des bornes
    if (lastvalue < borneBasse || lastvalue > borneHaute) {
        sensor.setStatus(false); // Capteur invalide
        return false;
    } else {
        sensor.setStatus(true); // Capteur valide
    }
    //Verification de la dernière valeur par rapport a l'historique 
    vector<float> valeursMesures;
    vector<Measurement> mesures = sensor.getMeasurements();
    for (size_t i = 0; i < mesures.size(); ++i) {
    float valeur = mesures[i].getValue();
    valeursMesures.push_back(valeur);
}
    float moyenneHisto = mean(valeursMesures);
    float ecartHisto = ecartType(valeursMesures);
    float borneHistoMin = moyenneHisto - 3 * ecartHisto;
    float borneHistoMax = moyenneHisto + 3 * ecartHisto;

    // Vérification si la dernière valeur est en dehors des bornes de l'historique
    if (lastvalue < borneHistoMin || lastvalue > borneHistoMax) {
        sensor.setStatus(false); // Capteur invalide
        return false;
    } else {
        sensor.setStatus(true); // Capteur valide
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
