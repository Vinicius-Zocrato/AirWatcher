#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "../../Include/Infrastructure/CSVReader.h"
#include "../../Include/Domain/AirQualityAnalyzer.h"
#include "../../Include/Domain/SensorValidator.h"
using namespace std;

static CSVReader reader;
static bool dataLoaded = false;
static AirQualityAnalyzer analyzer;
static SensorValidator validator;

void loadData() {
    reader.loadData();
    dataLoaded = true;
    cout << "[INFO] Données chargées avec succès.\n";
}

void displaySensors() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    const auto& sensors = reader.getSensors();
    for (const auto& s : sensors) s.toString();
}

void displayMeasurements() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    const auto& measurements = reader.getMeasurements();
    for (const auto& m : measurements) m.toString();
}

void displayMenu() {
    std::cout << "1. Charger les données" << std::endl;
    std::cout << "2. Calculer la qualité de l'air dans une zone" << std::endl;
    std::cout << "3. Afficher les capteurs" << std::endl;
    std::cout << "4. Afficher les mesures" << std::endl;
    std::cout << "5. Trouver les capteurs similaires" << std::endl;
    std::cout << "6. Détecter les utilisateurs malveillants" << std::endl;
    std::cout << "7. Quitter" << std::endl;
}

void handleAirQualityRequest() {

}

void handleSensorSimilarityRequest() {

}

void handleMaliciousUserDetection() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    auto users = reader.getUsers();
    auto mal = validator.detectMaliciousUsers(users);
    if (mal.empty()) cout << "Aucun utilisateur malveillant détecté.\n";
    else {
        cout << "Utilisateurs malveillants :\n";
        for (const auto& u : mal) u.toString();
    }
}

void measureRunTime(string algorithme) {
    std::cout << "Measuring runtime for: " << algorithme << std::endl;
    time_t start = time(nullptr);
    callFunctionByName(algorithme);
    time_t end = time(nullptr);
    std::cout << "Durée d'exécution : " << (end - start) << " secondes." << std::endl;
}

void callFunctionByName(const std::string& functionName) {
    if (functionName == "detectMaliciousUsers") {
        auto users = reader.getUsers();
        auto mal = validator.detectMaliciousUsers(users);
        if (mal.empty()) cout << "Aucun utilisateur malveillant détecté.\n";
        else {
            cout << "Utilisateurs malveillants :\n";
            for (const auto& u : mal) u.toString();
        }
    }
    else if (functionName == "calculateAirQuality") {
        double radius;
        float latitude, longitude;
        int y1, m1, d1, h1, min1, s1, y2, m2, d2, h2, min2, s2;
        cout << "Rayon (km) : "; cin >> radius;
        cout << "Latitude : "; cin >> latitude;
        cout << "Longitude : "; cin >> longitude;
        cout << "Date début (YYYY MM DD HH mm ss) : "; cin >> y1 >> m1 >> d1 >> h1 >> min1 >> s1;
        cout << "Date fin (YYYY MM DD HH mm ss) : "; cin >> y2 >> m2 >> d2 >> h2 >> min2 >> s2;
        tm t1 = {}; t1.tm_year = y1-1900; t1.tm_mon = m1-1; t1.tm_mday = d1; t1.tm_hour = h1; t1.tm_min = min1; t1.tm_sec = s1;
        tm t2 = {}; t2.tm_year = y2-1900; t2.tm_mon = m2-1; t2.tm_mday = d2; t2.tm_hour = h2; t2.tm_min = min2; t2.tm_sec = s2;
        analyzer.calculateAirQuality(radius, latitude, longitude, t1, t2);
    }
    // else if (functionName == "findMostSimilarSensors") {
    //     string targetId;
    //     cout << "ID du capteur de référence : "; cin >> targetId;
    //     auto sensors = reader.getSensors();
    //     auto it = std::find_if(sensors.begin(), sensors.end(), [&](const Sensor& s){ return s.getId() == targetId; });
    //     if (it == sensors.end()) {
    //         cout << "Capteur non trouvé.\n";
    //         return;
    //     }
    //     Sensor target = *it;
    //     vector<Sensor> others;
    //     for (const auto& s : sensors) if (s.getId() != targetId) others.push_back(s);
    //     auto similars = analyzer.findMostSimilarSensors(target, others);
    //     cout << "Capteurs les plus similaires :\n";
    //     for (const auto& s : similars) s.toString();
    // }
    else {
        cout << "Fonction inconnue : " << functionName << endl;
    }
}

#endif // CONSOLEUI_H