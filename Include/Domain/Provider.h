#ifndef PROVIDER_H
#define PROVIDER_H

#include <string>
#include <vector>
#include "Cleaner.h"

using namespace std;

class Provider {
private:
    string providerId;
    vector <Cleaner> cleaners;

public:
    
    Provider();
    Provider(const string& id, const vector<Cleaner>& cleanersList);
    Provider(const string& id);

    string getProviderId() const;
    vector<Cleaner> getAirCleaners() const;
    void toString() const;

    void addCleaner(const Cleaner& cleaner);

};

#endif // PROVIDER_H
