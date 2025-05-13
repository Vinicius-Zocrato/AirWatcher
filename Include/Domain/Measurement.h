#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <string>
#include <ctime>
#include "Attribute.h"

using namespace std;

class Measurement {
    public:
        Measurement(tm timestamp, Attribute attribute, float value, string sensorID);
        Measurement();
        ~Measurement();
        tm getTimeStamp()const;
        Attribute getAttribute()const;
        float getValue()const;
        string getSensorID()const;
        void toString()const;

    private:
        tm timestamp;
        Attribute attribute;
        float value;
        string sensorID;
};
#endif // MEASUREMENT_H