#include "../../Include/Domain/User.h"
#include "../../Include/Domain/Sensor.h"

User::User()
    : userId(""), score(0), isReliable(true)
{
}

<<<<<<< HEAD
// Destructeur
User::~User()
{
}

// Renvoie la liste des capteurs associés
vector<Sensor> User::getAssociatedSensors() const
{
    return associatedSensors;
}

void User::updateScore()
{
    // Exemple : augmenter le score de 1
=======
User::~User() {
}

vector<Sensor> User::getAssociatedSensors() const {
    return associatedSensors;
}


void User::updateScore() {
>>>>>>> 7315d89dcce92ce9c7fd458bc2ee1139c85479a0
    score += 1;
}

void User::changeRealisable()
{
    isReliable = !isReliable;
}

string User::getUserId() const
{
    return userId;
}