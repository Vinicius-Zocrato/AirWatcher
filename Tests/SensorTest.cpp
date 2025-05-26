// #include <cassert>
// #include "Sensor.h"

// int main(int argc, char *argv[]) {
//     // Cas nominal : création d’un capteur valide
//     Sensor cap("S1", 45.0, 5.0);
//     assert(cap.getId() == "S1");
//     assert(cap.getLatitude() == 45.0);
//     assert(cap.getLongitude() == 5.0);

//     // Ajout d’une mesure et récupération
//     Measurement m("2025-01-01 10:00:00", "S1", "O3", 50.0);
//     cap.addMeasurement(m);
//     auto ms = cap.getMeasurements();
//     assert(ms.size() == 1);
//     assert(ms[0].getAttribute() == "O3");  // L’attribut de la mesure ajoutée

//     // Cas limite : aucune mesure dans la période spécifiée
//     // On utilise une date éloignée pour être sûr de ne rien avoir
//     auto subset = cap.getMeasurementsInPeriod(LocalDate("2026-01-01"), 
//                                               LocalDate("2026-02-01"));
//     assert(subset.empty());  // doit être vide car aucune mesure en 2026

//     return 0;
// }
