#ifndef Attribute_H
#define Attribute_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Attribute {
    public:
        Attribute();
        ~Attribute();
        Attribute(string attributeID, string unit, string description);
        void toString() const;

    private:
        string attributeID;
        string unit;
        string description;
class Attribute
{
public:
    Attribute();
    ~Attribute();
    void setAttributeID(const string &attributeID) { this->attributeID = attributeID; }
    void setUnit(const string &unit) { this->unit = unit; }
    void setDescription(const string &description) { this->description = description; }

private:
    string attributeID;
    string unit;
    string description;
};

istream &operator>>(istream &is, Attribute &attr)
{
    string line;
    if (getline(is, line))
    {
        stringstream ss(line);
        string attributeID, unit, description;
        getline(ss, attributeID, ';');
        attr.setAttributeID(attributeID);
        ss.ignore(1);
        getline(ss, unit, ';');
        attr.setUnit(unit);
        ss.ignore(1);
        getline(ss, description, ';');
        attr.setDescription(description);
    }
    return is;
}
#endif // Attribute_H