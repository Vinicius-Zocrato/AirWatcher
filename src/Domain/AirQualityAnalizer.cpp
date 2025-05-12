#include "../../Include/Domain/AirQualityAnalizer.h"
#include <algorithm>


double AirQualityAnalizer::calculateAirQuality() {
    // TODO
    return 0.0;
}

double AirQualityAnalizer::calculateSimilarity(const std::vector<Measurement>& m1,
    const std::vector<Measurement>& m2) {
    // TODO
    return 0.0;
}

std::vector<Sensor> AirQualityAnalizer::findMostSimilarSensors(Sensor target,
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

double AirQualityAnalizer::computeAverage() {
    // TODO
    return 0.0;
}

std::vector<Sensor> AirQualityAnalizer::rankSensorByQuality() {
    // TODO
    return {};
}