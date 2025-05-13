#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <string>
#include <ctime>
#include "Attribute.h"

using namespace std;

class Measurement {
    public:
        Measurement(const tm& timestamp, const Attribute& attribute, float value)
            : timestamp(timestamp), attribute(attribute), value(value) {}
        Measurement(const Measurement& other)
            : timestamp(other.timestamp), attribute(other.attribute), value(other.value) {}
        Measurement();
        ~Measurement();
        tm getTimeStamp()const;
        Attribute getAttribute()const;
        float getValue()const;
        void toString()const;

    private:
        tm timestamp;
        Attribute attribute;
        float value;
};
#endif // MEASUREMENT_H