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
    // Constructeurs
    Provider() = default;
    Provider(const string& id, const vector<Cleaner>& cleanersList);

    // Getters
    string getProviderId() const;
    vector<Cleaner> getAirCleaners() const;

    // Setters
    void setProviderId(const string& id);
    void setCleaners(const vector<Cleaner>& cleanersList);

    // Méthode pour ajouter un cleaner
    void addCleaner(const Cleaner& cleaner);
};

#endif // PROVIDER_H
