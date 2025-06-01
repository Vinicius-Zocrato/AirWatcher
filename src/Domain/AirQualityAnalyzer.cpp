#include "../../Include/Domain/AirQualityAnalyzer.h"
#include <algorithm>
#include <array>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <unordered_map>

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

    static const array<string,6> labels = {
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

    static const array<string,4> keys = {
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

    if (O3_n == 0 && SO2_n == 0 && NO2_n == 0 && PM10_n == 0) {
        std::cout << "[AVERTISSEMENT] Aucune mesure trouvée dans l'intervalle de temps spécifié.\n";
        return {};
    }

    std::vector<double> means;
    means.push_back(O3/O3_n);
    means.push_back(SO2/SO2_n);
    means.push_back(NO2/NO2_n);
    means.push_back(PM10/PM10_n);
    return means;
}

std::vector<double> calculateAirqualitySensor(Sensor& sensor, tm init, tm fin) {
    double O3 = 0, SO2 = 0, NO2 = 0, PM10 = 0;
    int O3_n = 0, SO2_n = 0, NO2_n = 0, PM10_n = 0;

    static const std::unordered_map<std::string, int> attrIndex = {
        {"O3", 0},
        {"SO2", 1},
        {"NO2", 2},
        {"PM10", 3}
    };

    for (Measurement& measurement : sensor.getMeasurements()) {
        if (inPeriod(init, fin, measurement.getTimeStamp())) {
            std::string attr = measurement.getAttribute().getAttributeID();
            auto it = attrIndex.find(attr);
            if (it != attrIndex.end()) {
                switch (it->second) {
                    case 0: O3 += measurement.getValue(); O3_n++; break;
                    case 1: SO2 += measurement.getValue(); SO2_n++; break;
                    case 2: NO2 += measurement.getValue(); NO2_n++; break;
                    case 3: PM10 += measurement.getValue(); PM10_n++; break;
                }
            }
        }
    }

    if (O3_n == 0 && SO2_n == 0 && NO2_n == 0 && PM10_n == 0) {
        std::cout << "[AVERTISSEMENT] Aucune mesure trouvée dans l'intervalle de temps spécifié.\n";
        return {};
    }

    return {
        O3_n ? O3 / O3_n : 0.0,
        SO2_n ? SO2 / SO2_n : 0.0,
        NO2_n ? NO2 / NO2_n : 0.0,
        PM10_n ? PM10 / PM10_n : 0.0
    };
}

void AirQualityAnalyzer::calculateAirQuality(double radius, float latitude, float longitude, tm init, tm fin){

    std::vector<Sensor> sensors_in_circle;

    for(size_t i=0; i<sensors.size(); i++){
        if(inCircle(longitude, latitude, sensors[i].getLongitude(), sensors[i].getLatitude(), radius)){
            sensors_in_circle.push_back(sensors[i]);
        }
    }

    if (sensors_in_circle.empty()) {
        std::cout << "[AVERTISSEMENT] Aucun capteur trouvé dans la zone spécifiée.\n";
        return;
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

double AirQualityAnalyzer::calculateSimilarity(Sensor sensor1, Sensor sensor2, tm init, tm fin) const{
    
    std::vector<double> meansSensor1 = calculateAirqualitySensor(sensor1, init, fin);
    std::vector<double> meansSensor2 = calculateAirqualitySensor(sensor2, init, fin);

    double sumSquares = 0.0;
    for (size_t i = 0; i < meansSensor1.size(); ++i) {
        double diff = meansSensor1[i] - meansSensor2[i];
        sumSquares += diff * diff;
    }
    
    return std::sqrt(sumSquares);
}

double AirQualityAnalyzer::computeAverage() {
    // TODO
    return 0.0;
}

void AirQualityAnalyzer::rankSensorByQuality(string attribute, tm init, tm fin) {

    std::vector<pair<string, double>> rankedSensors;
    std::vector<double> aux;

    static const std::unordered_map<std::string, int> attrIndex = {
        {"O3", 0}, {"SO2", 1}, {"NO2", 2}, {"PM10", 3}
    };

    auto it = attrIndex.find(attribute);
    int attrIdx = it->second;


    for (size_t i = 0; i < sensors.size(); i++) {
         std::vector<double> means = calculateAirqualitySensor(sensors[i], init, fin);

        if (means.size() > attrIdx && means[attrIdx] > 0.0) { // evita sensores sem dados
            rankedSensors.emplace_back(sensors[i].getId(), means[attrIdx]);
        }
    }


    std::sort(rankedSensors.begin(), rankedSensors.end(),
    [](const auto& a, const auto& b) {
        return a.second < b.second; //less is better
    });


    cout<<"Sensors ranked by Qualitity, using attribute: "<<attribute
    << ", time: "<<std::put_time(&init, "%Y-%m-%d %H:%M:%S")
    <<" to "<<std::put_time(&fin, "%Y-%m-%d %H:%M:%S")<<endl;

    for (size_t i = 0; i < rankedSensors.size(); i++)
    {
        std::cout << i + 1 << ". Sensor ID: " << rankedSensors[i].first
        << ", Moyenne: " << rankedSensors[i].second << '\n';
    }

}


void AirQualityAnalyzer::findMostSimilarSensors(Sensor target, tm init, tm fin){

    std::vector<Sensor> result;
    
    std::vector<double> refMeans = calculateAirqualitySensor(target, init, fin);
    
    double refMagnitude = 0.0;
    for (double v : refMeans) {
        refMagnitude += v * v;
    }
    refMagnitude = std::sqrt(refMagnitude);

    for (const Sensor& sensor : sensors) {
        if (sensor.getId() == target.getId()) continue;

        double similarity = calculateSimilarity(target, sensor, init, fin);

        if (similarity <= 0.2 * refMagnitude) { //0.2 = REF-Similiarity
            result.push_back(sensor);
        }
    }

    cout<<"Sensors most similars with the Sensor: "<<target.getId()
    << ", time: "<<std::put_time(&init, "%Y-%m-%d %H:%M:%S")
    <<" to "<<std::put_time(&fin, "%Y-%m-%d %H:%M:%S")<<endl;
    airQuality(refMeans[0], refMeans[1], refMeans[2], refMeans[3]);

    cout<<"------------------\n";

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << i + 1 << ". Sensor ID: " << result[i].getId() << '\n';
        std::vector<double> refMeans = calculateAirqualitySensor(result[i], init, fin);
        airQuality(refMeans[0], refMeans[1], refMeans[2], refMeans[3]);
    }

}

Sensor AirQualityAnalyzer::findSensorById(string const capteurId) const
{
    for( size_t i = 0 ; i < sensors.size(); i++)
    {
        if (sensors[i].getId() ==  capteurId) 
        {
            return sensors[i];
        }
    }
    
    return Sensor();
}

vector<Sensor> AirQualityAnalyzer::getSensors() const{
    return sensors;
}