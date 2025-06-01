#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
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
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
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

void handleSensorSimilarityRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    string targetId;
    int y1, m1, d1, h1, min1, s1, y2, m2, d2, h2, min2, s2;
    cout << "ID du capteur de référence : "; cin >> targetId;
    cout << "Date début reference (YYYY MM DD HH mm ss) : "; cin >> y1 >> m1 >> d1 >> h1 >> min1 >> s1;
    cout << "Date fin reference(YYYY MM DD HH mm ss) : "; cin >> y2 >> m2 >> d2 >> h2 >> min2 >> s2;
    tm t1 = {}; t1.tm_year = y1-1900; t1.tm_mon = m1-1; t1.tm_mday = d1; t1.tm_hour = h1; t1.tm_min = min1; t1.tm_sec = s1;
    tm t2 = {}; t2.tm_year = y2-1900; t2.tm_mon = m2-1; t2.tm_mday = d2; t2.tm_hour = h2; t2.tm_min = min2; t2.tm_sec = s2;
    Sensor it = analyzer.findSensorById(targetId);
    if (it.getId() == "") {
        cout << "Capteur non trouvé.\n";
        return;
    }
    analyzer.findMostSimilarSensors(it, t1, t2);
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

void handleAirQualityAtPositionRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    float latitude, longitude;
    int y, m, d, h, min, s;
    cout << "Latitude : "; cin >> latitude;
    cout << "Longitude : "; cin >> longitude;
    cout << "Date (YYYY MM DD HH mm ss) : "; cin >> y >> m >> d >> h >> min >> s;
    tm t = {}; t.tm_year = y-1900; t.tm_mon = m-1; t.tm_mday = d; t.tm_hour = h; t.tm_min = min; t.tm_sec = s;
    cout << "[TODO] Calcul de la qualité de l'air à la position donnée non implémenté.\n";
}

void handleProviderImpactRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    string cleanerId;
    cout << "ID du produit (cleaner) : "; cin >> cleanerId;
    cout << "[TODO] Vérification de l'impact du produit non implémentée.\n";
}

void handleUserScoreRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    string userId;
    cout << "Votre ID utilisateur : "; cin >> userId;
    const auto& users = reader.getUsers();
    auto it = std::find_if(users.begin(), users.end(), [&](const User& u){ return u.getUserId() == userId; });
    if (it == users.end()) {
        cout << "Utilisateur non trouvé.\n";
        return;
    }
    cout << "Votre score : " << it->getScore() << endl;
}

void handleMalfunctioningSensorsRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    const auto& sensors = reader.getSensors();
    cout << "Capteurs défaillants :\n";
    for (const auto& s : sensors) {
        Sensor copy = s;
        if (!validator.isValidSensor(copy)) {
            s.toString();
        }
    }
}

void handleSimilarAreasRequest() {
    if (!dataLoaded) { cout << "[ERREUR] Chargez les données d'abord.\n"; return; }
    cout << "[TODO] Identification des zones à qualité similaire non implémentée.\n";
}

void handleAlgorithmEfficiencyRequest() {
    cout << "Quel algorithme voulez-vous mesurer ?\n";
    cout << "1. Calculer la qualité de l'air dans une zone\n";
    cout << "2. Calculer la qualité de l'air à une position\n";
    cout << "3. Classer les capteurs par similarité\n";
    cout << "4. Vérifier l'impact d'un produit fournisseur\n";
    cout << "5. Vérifier le score d'un utilisateur\n";
    cout << "6. Vérifier les capteurs défaillants\n";
    cout << "7. Identifier les zones à qualité similaire\n";
    cout << "Votre choix : ";
    int algo = 0;
    cin >> algo;
    time_t start = time(nullptr);
    switch (algo) {
        case 1: handleAirQualityRequest(); break;
        case 2: handleAirQualityAtPositionRequest(); break;
        case 3: handleSensorSimilarityRequest(); break;
        case 4: handleProviderImpactRequest(); break;
        case 5: handleUserScoreRequest(); break;
        case 6: handleMalfunctioningSensorsRequest(); break;
        case 7: handleSimilarAreasRequest(); break;
        default: cout << "Choix invalide.\n"; break;
    }
    time_t end = time(nullptr);
    cout << "Durée d'exécution : " << (end - start) << " secondes." << endl;
}

// Fonctions manquantes à implémenter (résumé) :
// - handleAirQualityAtPositionRequest (calcul réel)
// - handleProviderImpactRequest (calcul réel)
// - handleSimilarAreasRequest (identification réelle)
// - handleAlgorithmEfficiencyRequest (mesure réelle)
// - analyzer.findMostSimilarSensors (logique de similarité)
// - Toute logique avancée pour la position, l'impact produit, zones similaires
#endif // CONSOLEUI_H