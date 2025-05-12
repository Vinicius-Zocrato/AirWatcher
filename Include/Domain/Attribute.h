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
};


#endif // Attribute_H