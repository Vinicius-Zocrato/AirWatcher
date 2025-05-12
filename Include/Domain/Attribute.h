#ifndef Attribute_H
#define Attribute_H
#include <string>

using namespace std;

class Attribute {
    public:
        Attribute();
        ~Attribute();
        Attribute(string attributeID, string unit, string description);
    private:
        string attributeID;
        string unit;
        string description;
};
#endif // Attribute_H