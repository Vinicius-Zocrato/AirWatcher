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
    User(string userId, vector<Sensor> associatedSensors);
    ~User();
    vector<Sensor> getAssociatedSensors() const;
    void updateScore();
    void changeRealisable();
    string getUserId() const;
    void setUserId(const string &userId) { this->userId = userId; }
    void setAssociatedSensors(const vector<Sensor> &associatedSensors) { this->associatedSensors = associatedSensors; }
    void setScore(int score) { this->score = score; }
    void setIsReliable(bool isReliable) { this->isReliable = isReliable; }

private:
    string userId;
    int score;
    vector<Sensor> associatedSensors;
    bool isReliable;
};

#endif // USER_H