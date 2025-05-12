#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class Sensor; // Déclaration anticipée de la classe Sensor si elle est définie ailleurs

class User
{
public:
    User();
    ~User();
    vector<Sensor> getAssociatedSensors() const;
    void updateScore();
    void changeRealisable();
    string getUserId() const;

private:
    string userId;
    int score;
    vector<Sensor> associatedSensors;
    bool isReliable;
};

#endif // USER_H