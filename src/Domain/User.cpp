#include "../../Include/Domain/User.h"
#include "../../Include/Domain/Sensor.h"

User::User()
    : userId(""), score(0), isReliable(true)
{
}

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