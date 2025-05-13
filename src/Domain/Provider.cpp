#include "../../Include/Domain/Provider.h"
#include<iostream>

Provider::Provider(const string& id, const vector<Cleaner>& cleanersList)
    : providerId(id), cleaners(cleanersList) {}

Provider::Provider(const string& id){
    this->providerId = id;
}
// Getters
string Provider::getProviderId() const {
    return providerId;
}

vector<Cleaner> Provider::getAirCleaners() const {
    return cleaners;
}

void Provider::addCleaner(const Cleaner& cleaner) {
    cleaners.push_back(cleaner);
}

void Provider::toString() const {
    std::cout << "Provider ID: " << providerId << std::endl;
    std::cout << "Cleaners:" << std::endl;
    for (const auto& cleaner : cleaners) {
        cleaner.toString();
    }
}