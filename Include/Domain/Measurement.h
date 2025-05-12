#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <string>
#include "Attribute.h"

#using namespace std;

class Measurement {
    public:

    Measurement(const std::string& timestamp, const Attribute& attribute, float value)
        : timestamp(timestamp), attribute(attribute), value(value) {}
    Measurement(const Measurement& other)
        : timestamp(other.timestamp), attribute(other.attribute), value(other.value) {}
    Measurement();
    ~Measurement();
    private:
    String timestamp;
    Attribute attribute;
    float value;
};
#endif // MEASUREMENT_H