
// AirQualityAnalyzer::AirQualityAnalyzer(vector<Sensor> sensors){
//     this->sensors = sensors;
// }

// bool inCircle(double xc, double yc, double xP, double yP, double r){
//     double distance = std::hypot(xP - xc, yP - yc);
//     return distance <= r;
// }

// bool inPeriod(tm init, tm fin, tm t){
//     tm initCopy = init;
//     tm finCopy  = fin;
//     tm tCopy    = t;

//     time_t timeInit = mktime(&initCopy);
//     time_t timeFin  = mktime(&finCopy);
//     time_t timeT    = mktime(&tCopy);

//     if (timeInit == -1 || timeFin == -1 || timeT == -1) {
//         return false;
//     }

//     return (timeInit <= timeT && timeT <= timeFin);
// }

// int categoriaO3(double o3) {
//     if (o3 <= 54)   return 0;
//     if (o3 <= 104)  return 1;
//     if (o3 <= 129)  return 2;
//     if (o3 <= 179)  return 3;
//     if (o3 <= 239)  return 4;
//                    return 5;
// }

// int categoriaSO2(double so2) {
//     if (so2 <= 79)   return 0;
//     if (so2 <= 159)  return 1;
//     if (so2 <= 199)  return 2;
//     if (so2 <= 299)  return 3;
//     if (so2 <= 499)  return 4;
//                      return 5;
// }

// int categoriaNO2(double no2) {
//     if (no2 <= 54)   return 0;
//     if (no2 <= 109)  return 1;
//     if (no2 <= 134)  return 2;
//     if (no2 <= 199)  return 3;
//     if (no2 <= 399)  return 4;
//                      return 5;
// }

// int categoriaPM10(double pm10) {
//     if (pm10 <= 13)  return 0;
//     if (pm10 <= 27)  return 1;
//     if (pm10 <= 34)  return 2;
//     if (pm10 <= 49)  return 3;
//     if (pm10 <= 79)  return 4;
//                      return 5;
// }

// void airQuality(double o3, double so2, double no2, double pm10) {

//     int cO3  = categoriaO3(o3);
//     int cSO2 = categoriaSO2(so2);
//     int cNO2 = categoriaNO2(no2);
//     int cPM  = categoriaPM10(pm10);

//     static constexpr std::array<std::string_view,6> labels = {
//         "Tres bon",
//         "Bon",
//         "Moyen",
//         "Mediocre",
//         "Mauvais",
//         "Tres mauvais"
//     };

//     cout<<"O3 indice: "<<o3<<" - Niveau: "<<labels[cO3]<<endl;
//     cout<<"SO2 indice: "<<so2<<" - Niveau: "<<labels[cSO2]<<endl;
//     cout<<"NO2 indice: "<<no2<<" - Niveau: "<<labels[cNO2]<<endl;
//     cout<<"PM10 indice: "<<pm10<<" - Niveau: "<<labels[cPM]<<endl;

// }

// void AirQualityAnalyzer::calculateAirQuality(double radius, float latitude, float longitude, tm init, tm fin){

//     std::vector<Sensor> sensors_in_circle;

//     for(size_t i=0; i<sensors.size(); i++){
//         if(inCircle(longitude, latitude, sensors[i].getLongitude(), sensors[i].getLatitude(), radius)){
//             sensors_in_circle.push_back(sensors[i]);
//         }
//     }


//     double O3 = 0, SO2 = 0, NO2 = 0, PM10 = 0;
//     int O3_n = 0, SO2_n = 0, NO2_n = 0, PM10_n = 0;
    

//     std::vector<Measurement> measurements_in_period;

//     static constexpr std::array<std::string_view,4> keys = {
//         "O3", "SO2", "NO2", "PM10"
//     };

//     for (size_t i = 0; i < sensors_in_circle.size(); i++)
//     {
//         for (size_t j = 0; j < sensors_in_circle[i].getMeasurements().size(); j++)
//         {
//             Measurement measurement = sensors_in_circle[i].getMeasurements()[j];
//             if(inPeriod(init, fin, measurement.getTimeStamp())){
//                 if (auto it = std::find(keys.begin(), keys.end(), measurement.getAttribute().getAttibruteID()); it != keys.end()){
//                     switch (distance(keys.begin(), it))
//                     {
//                     case 0:
//                         O3 += measurement.getValue();
//                         O3_n += 1;
//                         break;
                    
//                     case 1:
//                         SO2 += measurement.getValue();
//                         SO2_n += 1;
//                         break;

//                     case 2:
//                         NO2 += measurement.getValue();
//                         NO2_n += 1;
//                         break;

//                     case 3:
//                         PM10 += measurement.getValue();
//                         PM10_n += 1;
//                         break;

//                     default:
//                         break;
//                     }
//                 }
//             }
//         }
//     }

//     cout<<"utilized sensors"<<endl;
//     for (size_t i = 0; i < sensors_in_circle.size(); i++)
//     {
//         cout<<sensors_in_circle[i].getId()<<" ";
//     }
//     cout<<endl;
    

//     char buf[20];
//     std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &init);

//     cout<<"Air quality analisys results for latitude: "<<latitude
//     <<", longitude: "<<longitude<<", time: "<<std::put_time(&init, "%Y-%m-%d %H:%M:%S")
//     <<" to "<<std::put_time(&fin, "%Y-%m-%d %H:%M:%S")<<endl;
//     airQuality(O3/O3_n, SO2/SO2_n, NO2/NO2_n, PM10/PM10_n);

// }


// //Makefile

// # Makefile (à la racine du projet)
// CXX      := g++
// CXXFLAGS := -std=c++17 -Wall -IInclude -w

// # Répertoires de code
// SRC_DIRS := \
//     ../src/Domain \
//     ../src/Infrastructure \
//     ../src/Presentation

// # Fichiers que nous NE voulons PAS compiler
// EXCLUDE  := \
//     ../src/Domain/SensorValidator.cpp

// # Recherche tous les .cpp, puis supprime ceux qui sont dans EXCLUDE
// ALL_SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))
// SRCS     := $(filter-out $(EXCLUDE),$(ALL_SRCS)) TestsUnitaires.cpp

// # Convertit la liste de .cpp en liste de .o
// OBJS     := $(SRCS:.cpp=.o)

// # Exécutable de tests
// TARGET   := run_tests

// .PHONY: all clean

// all: $(TARGET)

// # Lie tous les .o dans l'exécutable
// $(TARGET): $(OBJS)
// 	$(CXX) $(CXXFLAGS) $^ -o $@

// # Règle générique pour compiler .cpp en .o
// %.o: %.cpp
// 	$(CXX) $(CXXFLAGS) -c $< -o $@

// clean:
// 	del /Q "..\\src\\Domain\\Attribute.o" "..\\src\\Domain\\AirQualityAnalyzer.o" "..\\src\\Domain\\Measurement.o" "..\\src\\Domain\\Sensor.o" "..\\src\\Domain\\User.o" "..\\src\\Domain\\Cleaner.o" "..\\src\\Domain\\Provider.o" "..\\src\\Infrastructure\\CSVReader.o" "..\\src\\Presentation\\ConsoleUI.o" "..\\Tests\\TestsUnitaires.o" "run_tests.exe"
