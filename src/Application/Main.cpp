#include <ConsoleUI.h>
#include <iostream>
using namespace std;

// Déclarations des handlers ConsoleUI
void handleAirQualityRequest();
void handleAirQualityAtPositionRequest();
void handleProviderImpactRequest();
void handleUserScoreRequest();
void handleMalfunctioningSensorsRequest();
void handleSimilarAreasRequest();
void handleAlgorithmEfficiencyRequest();
void loadData();

int main()
{
    loadData();
    int role = 0;
    cout << "Bienvenue dans AirWatcher !\n";
    cout << "Êtes-vous :\n1. Admin\n2. User\n3. Provider\nVotre choix : ";
    cin >> role;
    while (role < 1 || role > 3) {
        cout << "Choix invalide. Entrez 1 (Admin), 2 (User) ou 3 (Provider) : ";
        cin >> role;
    }

    int choice = 0;
    while (true) {
        if (role == 1) {
            cout << "\n--- Menu Admin ---\n";
            cout << "1. Calculer la qualité de l'air dans une zone\n";
            cout << "2. Calculer la qualité de l'air à une position\n";
            cout << "3. Classer les capteurs par similarité\n";
            cout << "4. Vérifier l'impact d'un produit fournisseur\n";
            cout << "5. Vérifier le score d'un utilisateur\n";
            cout << "6. Vérifier les capteurs défaillants\n";
            cout << "7. Identifier les zones à qualité similaire\n";
            cout << "8. Mesurer l'efficacité d'un algorithme\n";
            cout << "0. Quitter\n";
            cout << "Votre choix : ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: handleAirQualityRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 2: handleAirQualityAtPositionRequest(); break;
                // Fonction incomplète : findMostSimilarSensors non implémentée
                case 3: handleSensorSimilarityRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 4: handleProviderImpactRequest(); break;
                // Fonction complète
                case 5: handleUserScoreRequest(); break;
                // Fonction complète
                case 6: handleMalfunctioningSensorsRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 7: handleSimilarAreasRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 8: handleAlgorithmEfficiencyRequest(); break;
                default: cout << "Choix invalide.\n"; break;
            }
        } else if (role == 2) {
            cout << "\n--- Menu Utilisateur ---\n";
            cout << "1. Calculer la qualité de l'air dans une zone\n";
            cout << "2. Calculer la qualité de l'air à une position\n";
            cout << "3. Vérifier votre score\n";
            cout << "4. Identifier les zones à qualité similaire\n";
            cout << "0. Quitter\n";
            cout << "Votre choix : ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: handleAirQualityRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 2: handleAirQualityAtPositionRequest(); break;
                // Fonction complète
                case 3: handleUserScoreRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 4: handleSimilarAreasRequest(); break;
                default: cout << "Choix invalide.\n"; break;
            }
        } else if (role == 3) {
            cout << "\n--- Menu Fournisseur ---\n";
            cout << "1. Calculer la qualité de l'air dans une zone\n";
            cout << "2. Calculer la qualité de l'air à une position\n";
            cout << "3. Vérifier l'impact d'un de vos produits\n";
            cout << "4. Identifier les zones à qualité similaire\n";
            cout << "0. Quitter\n";
            cout << "Votre choix : ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: handleAirQualityRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 2: handleAirQualityAtPositionRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 3: handleProviderImpactRequest(); break;
                // Fonction incomplète : stub, à implémenter
                case 4: handleSimilarAreasRequest(); break;
                default: cout << "Choix invalide.\n"; break;
            }
        }
    }
    cout << "Merci d'avoir utilisé AirWatcher !\n";
    return 0;
}
