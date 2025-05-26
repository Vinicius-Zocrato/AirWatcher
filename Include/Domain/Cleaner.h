#ifndef Cleaner_H
#define Cleaner_H

#include <string>
#include <vector>
#include <ctime>

using namespace std;


class Cleaner {
public:
    Cleaner();
    Cleaner(string CleanerId, float Latitude, float Longitude, tm TimeStampStart, tm TimeStampStop);
    ~Cleaner();
    bool isActiveAt(time_t time);
    double estimatedImpact();
    string getCleanerID();
    float getLatitude();
    float getLongitude();
    tm getTimeStampStart();
    tm getTimeStampStop();
    void toString() const;


private:
    string CleanerId;
    float Latitude;
    float Longitude;
    tm TimeStampStart;
    tm TimeStampStop;
};

#endif // Cleaner_H