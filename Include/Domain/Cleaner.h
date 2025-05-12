#ifndef Cleaner_H
#define Cleaner_H

#include <string>
#include <vector>
#include <ctime>

using namespace std;


class Cleaner {
public:
    Cleaner();
    ~Cleaner();
    bool isActiveAt();
    double estimatedImpact();



private:
    string CleanerId;
    float Latitude;
    float Longitude;
    tm TimeStampStart;
    tm TimeStampStop;
};

#endif // Cleaner_H