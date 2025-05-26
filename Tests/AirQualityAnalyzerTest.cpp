// #include <cassert>
// #include "AirQualityAnalyzer.h"
// #include "Sensor.h"
// #include "SensorValidator.h"
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// int main(int argc, char* argv[])
// {
//     AirQualityAnalyzer analyzer;

//     if (argc != 2)
//     {
//         cerr << "Usage : ./program <testNumber>" << endl;
//         return -1;
//     }

//     int caseTest = atoi(argv[1]);
//     if (caseTest == 1)
//     {
//         // Test de la méthode calculateSimilarity

//         // Création d'attributs fictifs
//         Attribute attrO3();
//         Attribute attrNO2();

//         // Timestamp arbitraire
//         tm t = {};
//         t.tm_year = 125; // 2025
//         t.tm_mon = 4;    // Mai
//         t.tm_mday = 26;

//         // Création de mesures pour capteur A
//         vector<Measurement> m1 = {
//             Measurement(t, attrO3, 50.0f, "A"),
//             Measurement(t, attrNO2, 30.0f, "A")
//         };

//         // Création de mesures pour capteur B
//         vector<Measurement> m2 = {
//             Measurement(t, attrO3, 48.0f, "B"),
//             Measurement(t, attrNO2, 32.0f, "B")
//         };

//         // Calcul de similarité
//         double similarity = analyzer.calculateSimilarity(m1, m2);

//         cout << "Similarity entre A et B : " << similarity << endl;

//         // Test unitaire simple : on s'attend à une similarité proche de 1
//         assert(similarity > 0.95 && similarity <= 1.0);
//         cout << "Test 1 passé avec succès." << endl;
//     }

//     return 0;
// }
