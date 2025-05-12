#ifndef Attribute_H
#define Attribute_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Attribute
{
    
public:
    Attribute(string attributeID, string unit, string description);
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


#endif // Attribute_H