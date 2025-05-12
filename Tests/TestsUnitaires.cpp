#include "../Include/Domain/Measurement.h"
#include "../Include/Domain/Attribute.h"
#include "../Include/Domain/Sensor.h"
#include "../Include/Domain/SensorValidator.h"
#include "../Include/Domain/AirQualityAnalyzer.h"
#include "../Include/Domain/User.h"
#include "../Include/Presentation/ConsoleUI.h"
#include "../Include/Infrastructure/CSVReader.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

bool Test1()
{
    Sensor s("S", -999.0, 999.0); // clearly invalid coordinates
    SensorValidator validator;
    bool result = validator.isValidSensor(s);
    std::cout << "Test isValidSensor - Invalid coordinates: " << (result == false ? "PASS" : "FAIL") << "\n";
    return result;
}
bool Test2()
{
    AirQualityAnalyzer analyzer;
    std::vector<Measurement> emptyMeasurements;
    double avg = analyzer.computeAverage("O3", emptyMeasurements);
    std::cout << "Test computeAverage - Empty list: " << (avg == 0.0 ? "PASS" : "FAIL") << "\n";
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
    User user("U1", {"S99"});
    std::vector<Sensor> sensors = { Sensor("S1", 45, 5) };
    auto result = user.getAssociatedSensors(sensors);
    std::cout << "Test getAssociatedSensors - No match found: " << (result.empty() ? "PASS" : "FAIL") << "\n";
}
bool Test5()
{
    AirCleaner cleaner("C1", 45, 5, "2025-01-01 00:00:00", "2025-01-10 00:00:00");
    auto testTime = parseDateTime("2025-01-10 00:00:01"); // just after
    bool active = cleaner.isActiveAt(testTime);
    std::cout << "Test isActiveAt - Just after active range: " << (!active ? "PASS" : "FAIL") << "\n";
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
}

int main() {
    Test1(); Test2(); Test3(); Test4(); Test5();
    Test6(); Test7(); Test8(); Test9(); Test10();
    Test11(); Test12(); Test13(); Test14(); Test15();
    Test16(); Test17(); Test18(); Test19(); Test20();
    return 0;
}
