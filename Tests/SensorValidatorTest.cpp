#include "SensorValidator.h"
#include "Sensor.h"
#include <iostream>
using namespace std;
#include <cstdlib>


int main(int argc, char* argv[])
{

    if (argc > 2)
    {
        cerr << ("Arguments trop nombreux ou Invalide ") << endl;
        return -1;
    }
    int caseTest = atoi(argv[argc]);
    if (caseTest == 1)
    {
        //Test1
        Sensor s("S1", -999.0, 999.0, "User1"); // clearly invalid coordinates
        SensorValidator validator;
        bool result = validator.isValidSensor(s);
        std::cout << "Test isValidSensor - Invalid coordinates: " << (result == false ? "PASS" : "FAIL") << "\n";
        
        return result;
    }
   

}