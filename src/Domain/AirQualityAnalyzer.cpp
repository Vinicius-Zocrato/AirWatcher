#include "../../Include/Domain/AirQualityAnalyzer.h"
#include <algorithm>
#include <string_view>
#include <array>
#include <iomanip>
#include <cmath>
#include <math.h>

AirQualityAnalyzer::AirQualityAnalyzer(vector<Sensor> sensors){
    this->sensors = sensors;
}

AirQualityAnalyzer::AirQualityAnalyzer()
{

}

bool inCircle(double xc, double yc, double xP, double yP, double r){
    double distance = std::hypot(xP - xc, yP - yc);
    return distance <= r;
}

bool inPeriod(tm init, tm fin, tm t){
    tm initCopy = init;
    tm finCopy  = fin;
    tm tCopy    = t;

    time_t timeInit = mktime(&initCopy);
    time_t timeFin  = mktime(&finCopy);
    time_t timeT    = mktime(&tCopy);

    if (timeInit == -1 || timeFin == -1 || timeT == -1) {
        return false;
    }

    return (timeInit <= timeT && timeT <= timeFin);
}

int categoriaO3(double o3) {
    if (o3 <= 54)   return 0;
    if (o3 <= 104)  return 1;
    if (o3 <= 129)  return 2;
    if (o3 <= 179)  return 3;
    if (o3 <= 239)  return 4;
                   return 5;
}

int categoriaSO2(double so2) {
    if (so2 <= 79)   return 0;
    if (so2 <= 159)  return 1;
    if (so2 <= 199)  return 2;
    if (so2 <= 299)  return 3;
    if (so2 <= 499)  return 4;
                     return 5;
}

int categoriaNO2(double no2) {
    if (no2 <= 54)   return 0;
    if (no2 <= 109)  return 1;
    if (no2 <= 134)  return 2;
    if (no2 <= 199)  return 3;
    if (no2 <= 399)  return 4;
                     return 5;
}

int categoriaPM10(double pm10) {
    if (pm10 <= 13)  return 0;
    if (pm10 <= 27)  return 1;
    if (pm10 <= 34)  return 2;
    if (pm10 <= 49)  return 3;
    if (pm10 <= 79)  return 4;
                     return 5;
}

void airQuality(double o3, double so2, double no2, double pm10) {

    int cO3  = categoriaO3(o3);
    int cSO2 = categoriaSO2(so2);
    int cNO2 = categoriaNO2(no2);
    int cPM  = categoriaPM10(pm10);

    static constexpr std::array<std::string_view,6> labels = {
        "Tres bon",
        "Bon",
        "Moyen",
        "Mediocre",
        "Mauvais",
        "Tres mauvais"
    };

    cout<<"O3 indice: "<<o3<<" - Niveau: "<<labels[cO3]<<endl;
    cout<<"SO2 indice: "<<so2<<" - Niveau: "<<labels[cSO2]<<endl;
    cout<<"NO2 indice: "<<no2<<" - Niveau: "<<labels[cNO2]<<endl;
    cout<<"PM10 indice: "<<pm10<<" - Niveau: "<<labels[cPM]<<endl;

}

std::vector<double> calculateAirqualityMean(std::vector<Sensor> sensors, tm init, tm fin){

    double O3 = 0, SO2 = 0, NO2 = 0, PM10 = 0;
    int O3_n = 0, SO2_n = 0, NO2_n = 0, PM10_n = 0;

    static constexpr std::array<std::string_view,4> keys = {
        "O3", "SO2", "NO2", "PM10"
    };

    for (size_t i = 0; i < sensors.size(); i++)
    {
        for (size_t j = 0; j < sensors[i].getMeasurements().size(); j++)
        {
            Measurement measurement = sensors[i].getMeasurements()[j];
            if(inPeriod(init, fin, measurement.getTimeStamp())){
                if (auto it = std::find(keys.begin(), keys.end(), measurement.getAttribute().getAttributeID()); it != keys.end()){
                    switch (distance(keys.begin(), it))
                    {
                    case 0:
                        O3 += measurement.getValue();
                        O3_n += 1;
                        break;
                    
                    case 1:
                        SO2 += measurement.getValue();
                        SO2_n += 1;
                        break;

                    case 2:
                        NO2 += measurement.getValue();
                        NO2_n += 1;
                        break;

                    case 3:
                        PM10 += measurement.getValue();
                        PM10_n += 1;
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }

    std::vector<double> means;
    means.push_back(O3/O3_n);
    means.push_back(SO2/SO2_n);
    means.push_back(NO2/NO2_n);
    means.push_back(PM10/PM10_n);
    return means;
}

void AirQualityAnalyzer::calculateAirQuality(double radius, float latitude, float longitude, tm init, tm fin){

    std::vector<Sensor> sensors_in_circle;

    for(size_t i=0; i<sensors.size(); i++){
        if(inCircle(longitude, latitude, sensors[i].getLongitude(), sensors[i].getLatitude(), radius)){
            sensors_in_circle.push_back(sensors[i]);
        }
    }

    std::vector<double> means = calculateAirqualityMean(sensors_in_circle, init, fin);
    
    cout<<"utilized sensors"<<endl;
    for (size_t i = 0; i < sensors_in_circle.size(); i++)
    {
        cout<<sensors_in_circle[i].getId()<<" ";
    }
    cout<<endl;
    

    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &init);

    cout<<"Air quality analisys results for latitude: "<<latitude
    <<", longitude: "<<longitude<<", time: "<<std::put_time(&init, "%Y-%m-%d %H:%M:%S")
    <<" to "<<std::put_time(&fin, "%Y-%m-%d %H:%M:%S")<<endl;
    airQuality(means[0], means[1], means[2], means[3]);

}

double AirQualityAnalyzer::calculateSimilarity(const std::vector<Measurement>& m1,
    const std::vector<Measurement>& m2) {
    // TODO
    
    return 0.0;
}

/*

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
*/

double AirQualityAnalyzer::computeAverage() {
    // TODO
    return 0.0;
}

void AirQualityAnalyzer::rankSensorByQuality(string attribute, tm init, tm fin) {
    // TODO

    std::vector<double> sensorsMeans, aux;
    static constexpr std::array<std::string_view,4> keys = {
        "O3", "SO2", "NO2", "PM10"
    };

    auto it = std::find(keys.begin(), keys.end(), attribute);
    int attrIndex = std::distance(keys.begin(), it);

    for (size_t i = 0; i < sensors.size(); i++) {
        aux = calculateAirqualityMean(std::vector<Sensor>{sensors[i]}, init, fin);

        switch (attrIndex) {
            case 0: // O3
                sensorsMeans.push_back(aux[0]);
                break;

            case 1: // SO2
                sensorsMeans.push_back(aux[1]);
                break;

            case 2: // NO2
                sensorsMeans.push_back(aux[2]);
                break;

            case 3: // PM10
                sensorsMeans.push_back(aux[3]);
                break;

            default:
                std::cerr << "Índice fora do esperado: " << attrIndex << std::endl;
                break;
        }
    }

    cout<<"Sensors ranked by Qualitity, using attribute: "<<attribute
    << ", time: "<<std::put_time(&init, "%Y-%m-%d %H:%M:%S")
    <<" to "<<std::put_time(&fin, "%Y-%m-%d %H:%M:%S")<<endl;
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