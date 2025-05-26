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
    // Appeler la fonction cible ici si besoin
    time_t end = time(nullptr);
    std::cout << "Durée d'exécution : " << (end - start) << " secondes." << std::endl;
}

#endif // CONSOLEUI_H