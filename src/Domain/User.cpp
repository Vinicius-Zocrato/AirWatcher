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

bool User::getIsReliable() const {
    return isReliable;
}