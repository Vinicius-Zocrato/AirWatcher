#include <cassert>
#include "../Include/Infrastructure/CSVReader.h"



using namespace std;

int main(int argc, char* argv[]) {
    CSVReader reader;
    int arg = atoi(argv[1]);
    // Cas 1 : fichier existant
    if (arg == 1)
    {
        try {
                vector<Sensor> sensors = reader.loadSensors("sensors.csv");
                cout << "Loaded " << sensors.size() << " sensors." << endl;
            } catch (const exception &e) {
                cerr << "Error loading sensors.csv: " << e.what() << endl;
            }
    }
    else if (arg == 2)
    {
        /* code */
         // Cas 2 : fichier inexistant
    try {
        vector<User> users = reader.loadUsers("invalidfile.csv");
        cout << "Loaded " << users.size() << " users from invalidfile.csv (unexpected)." << endl;
    } catch (const exception &e) {
        cerr << "Error loading invalidfile.csv: " << e.what() << endl;
    }

    }
    else if (arg == 3)
    {
        /* code */
         // Cas 3 : tout charger via loadData
        try {
            reader.loadData();
            cout << "Global loadData executed." << endl;
            cout << "Sensors: " << reader.getSensors().size() << endl;
            cout << "Users: " << reader.getUsers().size() << endl;
            cout << "Measurements: " << reader.getMeasurements().size() << endl;
            cout << "Providers: " << reader.getProviders().size() << endl;
            cout << "Cleaners: " << reader.getCleaners().size() << endl;
            cout << "Attributes: " << reader.getAttributes().size() << endl;
        } catch (const exception &e) {
            cerr << "Error in loadData: " << e.what() << endl;
        }

    }
    
    
   

   

    return 0;
}
