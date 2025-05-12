#include "../../Include/Domain/AirQualityAnalyzer.h"
#include <algorithm>


double AirQualityAnalyzer::calculateAirQuality() {
    // TODO
    return 0.0;
}

AirQualityAnalyzer::AirQualityAnalyzer()
{

}

<<<<<<< HEAD
AirQualityAnalyzer::AirQualityAnalyzer(vector<Sensor> sensors)
{
    this->sensors = sensors;
}

double AirQualityAnalyzer::calculateSimilarity() {
=======
double AirQualityAnalyzer::calculateSimilarity(const std::vector<Measurement>& m1,
    const std::vector<Measurement>& m2) {
>>>>>>> 7ce9f34f43e2eeb7c786dc2d42ab3e0e306e3221
    // TODO
    return 0.0;
}

std::vector<Sensor> AirQualityAnalyzer::findMostSimilarSensors(Sensor target,
vector<Sensor> others, int topN) {

    std::vector<std::pair<Sensor, double>> scoredSensors;

    // Récupère les mesures du capteur de référence
    std::vector<Measurement> targetMeasurements = target.getMeasurements();

    for (const Sensor& other : others) {
        if (other.getId() == target.getId()) continue;

        // Récupère les mesures du capteur comparé
        std::vector<Measurement> otherMeasurements = other.getMeasurements();

        // Calcule la similarité entre les deux capteurs
        double similarityScore = calculateSimilarity(targetMeasurements, otherMeasurements);

        scoredSensors.emplace_back(other, similarityScore);
    }

    // Trie par score croissant (plus petit = plus similaire)
    std::sort(scoredSensors.begin(), scoredSensors.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });

    // Prend les top N capteurs
    std::vector<Sensor> result;
    for (int i = 0; i < topN && i < scoredSensors.size(); ++i) {
        result.push_back(scoredSensors[i].first);
    }

    return result;
}

double AirQualityAnalyzer::computeAverage() {
    // TODO
    return 0.0;
}

std::vector<Sensor> AirQualityAnalyzer::rankSensorByQuality() {
    // TODO
    return {};
}

Sensor AirQualityAnalyzer::findSensorById(string const capteurId) const
{
    for( int i = 0 ; i < sensors.size(); i++)
    {
        if (sensors[i].getId() ==  capteurId) 
        {
            return sensors[i];
        }
    }
}