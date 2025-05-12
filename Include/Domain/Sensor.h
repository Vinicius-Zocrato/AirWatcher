#ifndef SENSOR_H   // Nome da macro de guarda deve ser único e não depender do nome do arquivo
#define SENSOR_H   // Definir a macro para indicar que o arquivo foi incluído

#include <vector>
#include <string>
#include "Measurement.h"
using namespace std;

class Sensor
{
private:
    string sensorID;
    float latitude;
    float longitude;
    bool status;
    vector<Measurement> Measurements;

public:
    Sensor();

    Sensor(string sensorID, float lat, float lon, bool status);

    ~Sensor();
};

#endif
