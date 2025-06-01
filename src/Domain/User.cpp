#include "../../Include/Domain/User.h"
#include "../../Include/Domain/Sensor.h"


User::User()
    : userId(""), score(0), isReliable(true) {
    
}

User::~User() {
}

User::User(string id, vector<Sensor> sensors)
: userId(""), score(0), isReliable(true){
    this->userId = id;
    this->associatedSensors = sensors;
}

User::User(string id)
: userId(""), score(0), isReliable(true){
    this->userId = id;
}

vector<Sensor> User::getAssociatedSensors() const {
    return associatedSensors;
}

<<<<<<< HEAD
void  User::insertSensor(const Sensor& sensor){
    this->associatedSensors.push_back(sensor);
=======
void  User::insertAssociatedSensor(const Sensor& sensor){
     this->associatedSensors.push_back(sensor);
>>>>>>> ad66455e705e212a825e132b7dac19b13124d8dc
}

void User::updateScore(double delta = 1.0) {
    score += static_cast<int>(delta);
    if (score < 0) {
        score = 0; // Ensure score does not go negative
    }
}

void User::setIsReliable(bool reliability) {
<<<<<<< HEAD
    isReliable = reliability;
=======
     this->isReliable = reliability;
>>>>>>> ad66455e705e212a825e132b7dac19b13124d8dc
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
