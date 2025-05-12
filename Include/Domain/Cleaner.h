#ifndef Cleaner_H
#define Cleaner_H

#include <string>
#include <vector>

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
    string TimeStampStart;
    string TimeStampStop;
};

#endif // Cleaner_H