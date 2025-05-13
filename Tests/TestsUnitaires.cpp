#include "../Include/Domain/Measurement.h"
#include "../Include/Domain/Attribute.h"
#include "../Include/Domain/Sensor.h"
//#include "../Include/Domain/SensorValidator.h"
//#include "../Include/Domain/AirQualityAnalyzer.h"
#include "../Include/Domain/User.h"
#include "../Include/Presentation/ConsoleUI.h"
#include "../Include/Infrastructure/CSVReader.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

/*
bool Test1()
{
    // Sensor s("S1", -999.0, 999.0); // clearly invalid coordinates
    // SensorValidator validator;
    // bool result = validator.isValidSensor(s);
    // std::cout << "Test isValidSensor - Invalid coordinates: " << (result == false ? "PASS" : "FAIL") << "\n";
    // return result;
}
bool Test2()
{
    AirQualityAnalyzer analyzer;
    std::vector<Measurement> emptyMeasurements;
    //double avg = analyzer.computeAvarege("O3", emptyMeasurements);
    //std::cout << "Test computeAverage - Empty list: " << (avg == 0.0 ? "PASS" : "FAIL") << "\n";
}
bool Test3()
{
    // TODO: apprendre comment utiliser tm pour faire des tests sur les dates
    // Sensor s("S2", 45, 5);
    // s.addMeasurement({"2025-01-01 10:00:00", "S2", "NO2", 30});
    // auto res = s.getMeasurementsInPeriod(LocalDate("2026-01-01"),LocalDate("2026-02-01"));
    // std::cout << "Test getMeasurementsInPeriod - No data in period: " << (res.empty() ? "PASS" : "FAIL") << "\n";
}
bool Test4()
{
    
    // std::vector<Sensor> sensors = { Sensor("S1", 45, 5) };
    // User user("U1", sensors);
    // auto result = user.getAssociatedSensors();
    // std::cout << "Test getAssociatedSensors -  " << (result.empty() ? "FAIL" : "PASS") << "\n";
}
bool Test5()
{
    tm startTime = tm{0, 0, 0, 1, 0, 2025 - 1900};
    tm endTime = tm{0, 0, 0, 10, 0, 2025 - 1900};
    Cleaner cleaner = Cleaner("C1", 45.0, 5.0, startTime, endTime);

    // Create a tm structure for the test time
    tm testTime = {};
    testTime.tm_year = 2025 - 1900; // tm_year is years since 1900
    testTime.tm_mon = 0;            // January (0-based)
    testTime.tm_mday = 10;
    testTime.tm_hour = 0;
    testTime.tm_min = 0;
    testTime.tm_sec = 1;

    // Convert tm to time_t
    time_t testTimeT = std::mktime(&testTime);

    bool active = cleaner.isActiveAt(testTimeT);
    std::cout << "Test isActiveAt - Just after active range: " << (!active ? "PASS" : "FAIL") << "\n";
    return !active;
}
bool Test6()
{
    Sensor target("S1", 45, 5);
    std::vector<Sensor> emptyList;
    auto result = analyzer.findMostSimilarSensors(target, emptyList, 3);
    std::cout << "Test findMostSimilarSensors - Empty sensor list: " << (result.empty() ? "PASS" : "FAIL") << "\n";
}
bool Test7()
{
    CSVReader reader;
    auto result = reader.loadMeasurements("nonexistent.csv");
    std::cout << "Test loadMeasurements - Missing file: " << (result.empty() ? "PASS" : "FAIL") << "\n";
}
bool Test8() {
    Sensor s("S3", 45.0, 5.0);
    Attribute attr("O3", "ppm", "Ozone");
    s.addMeasurement(Measurement("2025-01-01 12:00:00", attr, 42.0));
    auto result = s.getMeasurementsByAttribute(attr);
    std::cout << "Test getMeasurementsByAttribute - One matching attribute: " << (!result.empty() ? "PASS" : "FAIL") << "\n";
    return !result.empty();
}

bool Test9() {
    Sensor s("S4", 0, 0);
    s.setStatus(false);
    bool result = !s.getStatus(); // suppose que tu as un getter getStatus()
    std::cout << "Test setStatus - Set to false: " << (result ? "PASS" : "FAIL") << "\n";
    return result;
}

bool Test10() {
    User u("U2", {});
    u.updateScore(20); // suppose que ça ajoute ou remplace
    std::cout << "Test updateScore: " << (u.getScore() == 20 ? "PASS" : "FAIL") << "\n";
    return u.getScore() == 20;
}

bool Test11() {
    User u("U3", {});
    u.changeReliable(true);
    std::cout << "Test changeReliable - Set true: " << (u.isReliable() ? "PASS" : "FAIL") << "\n";
    return u.isReliable();
}

bool Test12() {
    AirQualityAnalyzer analyzer;
    Sensor s("S5", 45, 5);
    Sensor t("S6", 45, 5);
    double sim = analyzer.calculateSimilarity(s, t);
    std::cout << "Test calculateSimilarity - Same location: " << (sim == 1.0 ? "PASS" : "FAIL") << "\n"; // ou une autre logique
    return true;
}

bool Test13() {
    AirQualityAnalyzer analyzer;
    double q = analyzer.calculateAirQuality("O3", {}, {});
    std::cout << "Test calculateAirQuality - Empty sensors and cleaners: " << (q == 0.0 ? "PASS" : "FAIL") << "\n";
    return q == 0.0;
}

bool Test14() {
    AirQualityAnalyzer analyzer;
    auto res = analyzer.rankSensorsByQuality({}, "O3");
    std::cout << "Test rankSensorsByQuality - Empty input: " << (res.empty() ? "PASS" : "FAIL") << "\n";
    return res.empty();
}

bool Test15() {
    SensorValidator validator;
    User u("U4", {});
    bool result = validator.isUserReliable(u);
    std::cout << "Test isUserReliable - No sensors: " << (!result ? "PASS" : "FAIL") << "\n";
    return !result;
}

bool Test16() {
    SensorValidator validator;
    auto users = validator.detectMaliciousUsers({});
    std::cout << "Test detectMaliciousUsers - Empty input: " << (users.empty() ? "PASS" : "FAIL") << "\n";
    return users.empty();
}

bool Test17() {
    CSVReader reader;
    auto sensors = reader.loadSensors("nonexistent.csv");
    std::cout << "Test loadSensors - File missing: " << (sensors.empty() ? "PASS" : "FAIL") << "\n";
    return sensors.empty();
}

bool Test18() {
    CSVReader reader;
    auto users = reader.loadUsers("nonexistent.csv");
    std::cout << "Test loadUsers - File missing: " << (users.empty() ? "PASS" : "FAIL") << "\n";
    return users.empty();
}

bool Test19() {
    CSVReader reader;
    auto provs = reader.loadProviders("nonexistent.csv");
    std::cout << "Test loadProviders - File missing: " << (provs.empty() ? "PASS" : "FAIL") << "\n";
    return provs.empty();
}

bool Test20() {
    CSVReader reader;
    auto cleaners = reader.loadAirCleaners("nonexistent.csv");
    std::cout << "Test loadAirCleaners - File missing: " << (cleaners.empty() ? "PASS" : "FAIL") << "\n";
    return cleaners.empty();
}*/

bool test21(){
    cout<<"Runing Tests 21\n";
    CSVReader reader;
    reader.loadData();

    for (size_t i = 0; i < reader.getAttributes().size(); i++)
    {
        reader.getAttributes()[i].toString();
    }

    cout<<endl<<endl;

    return true;
}

bool test22(){
    cout<<"Runing Tests 22\n";
    CSVReader reader;
    reader.loadData();

    for (size_t i = 0; i < reader.getCleaners().size(); i++)
    {
        reader.getCleaners()[i].toString();
    }

    cout<<endl<<endl;

    return true;
}

int main() {
    //Test1(); Test2(); Test3(); Test4(); Test5(); 
    test21(); test22();
    //Test6(); Test7(); Test8(); Test9(); Test10();
    //Test11(); Test12(); Test13(); Test14(); Test15();
    //Test16(); Test17(); Test18(); Test19(); Test20();
    return 0;
}
