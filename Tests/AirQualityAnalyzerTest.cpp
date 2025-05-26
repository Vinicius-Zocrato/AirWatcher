// #include <cassert>
// #include "AirQualityAnalyzer.h"
// #include "Sensor.h"

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
