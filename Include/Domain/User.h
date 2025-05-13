#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class Sensor; // Déclaration anticipée de la classe Sensor si elle est définie ailleurs

class User {
public:
    User();
    User(string userId, vector<Sensor> associatedSensors);
    ~User();

    void updateScore();
    void changeRealisable();
    
    bool getIsReliable() const;
    string getUserId() const;
    int getScore() const;
    vector<Sensor> getAssociatedSensors() const;

    void toString() const;



private:
    string userId;
    int score;
    vector<Sensor> associatedSensors;
    bool isReliable;
};

#endif // USER_H