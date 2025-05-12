#include "../../Include/Domain/Provider.h"


Provider::Provider(const string& id, const vector<Cleaner>& cleanersList)
    : providerId(id), cleaners(cleanersList) {}

// Getters
string Provider::getProviderId() const {
    return providerId;
}

vector<Cleaner> Provider::getAirCleaners() const {
    return cleaners;
}

// Setters
void Provider::setProviderId(const string& id) {
    providerId = id;
}

void Provider::setCleaners(const vector<Cleaner>& cleanersList) {
    cleaners = cleanersList;
}

void Provider::addCleaner(const Cleaner& cleaner) {
    cleaners.push_back(cleaner);
}
