#include "../../Include/Domain/User.h"
#include "../../Include/Domain/Sensor.h"


User::User()
    : userId(""), score(0), isReliable(true) {
    
}

User::~User() {
}

vector<Sensor> User::getAssociatedSensors() const {
    return associatedSensors;
}


void User::updateScore() {
    score += 1;
}

void User::changeRealisable() {
    isReliable = !isReliable;
}

bool User::getIsReliable() const {
    return isReliable;
}

int User::getScore() const{
    return score;
}

string User::getUserId()const{
    return userId;
}

void User::toString() const {
    std::cout << "User ID: " << userId
              << ", Score: " << score
              << ", IsReliable: " << (isReliable ? "true" : "false")
              << std::endl;
    std::cout << "Associated Sensors (" << associatedSensors.size() << "):" << std::endl;
    for (const auto& sensor : associatedSensors) {
        sensor.toString();
    }
}
