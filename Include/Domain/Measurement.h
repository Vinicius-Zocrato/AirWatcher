#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <string>
#include "Attribute.h"

using namespace std;

class Measurement
{
public:
    Measurement(const std::string &timestamp, const Attribute &attribute, float value, const string &sensorID)
        : timestamp(timestamp), attribute(attribute), value(value), sensorID(sensorID) {}
    Measurement(const Measurement &other)
        : timestamp(other.timestamp), attribute(other.attribute), value(other.value), sensorID(other.sensorID) {}
    Measurement();
    ~Measurement();

private:
    string timestamp;
    Attribute attribute;
    float value;
    string sensorID;
};
#endif // MEASUREMENT_H