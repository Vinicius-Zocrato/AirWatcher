#include <cassert>
#include "AirQualityAnalyzer.h"
#include "Sensor.h"

// int main() {
//     AirQualityAnalyzer analyzer;

//     // Cas 1 : liste vide -> la moyenne doit être 0.0
//     std::vector<Measurement> vide;
//     double avg = analyzer.computeAverage("O3", vide);
//     assert(avg == 0.0);

//     // Cas 2 : pas de capteurs à comparer -> capteurs similaires vides
//     Sensor cible("S1", 45.0, 5.0);
//     std::vector<Sensor> listeVide;
//     auto sim = analyzer.findMostSimilarSensors(cible, listeVide, 3);
//     assert(sim.empty());

//     return 0;
// }

#include "SensorValidator.h"
#include "Sensor.h"
#include <iostream>
using namespace std;
#include <cstdlib>


int main(int argc, char* argv[])
{

    AirQualityAnalyzer analyzer;

    if (argc > 2)
    {
        cerr << ("Arguments trop nombreux ou Invalide ") << endl;
        return -1;
    }
    int caseTest = atoi(argv[argc]);
    if (caseTest == 1)
    {
        //Test1
        
    }
   
    AirQualityAnalyzer analyzer;
    std::vector<Measurement> emptyMeasurements;
    double avg = analyzer.computeAvarege("O3", emptyMeasurements);
    std::cout << "Test computeAverage - Empty list: " << (avg == 0.0 ? "PASS" : "FAIL") << "\n";
}