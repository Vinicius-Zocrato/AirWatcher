/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

vector<Cleaner> Provider::getAirCleaners() const
{
#ifdef MAP
    cout << "Appel du getAirCleanners de <Provider>" << endl;
#endif
    return this->cleaners;
}

string Provider::getProviderId() const
{
#ifdef MAP
    cout << "Appel du getAirCleanners de <Provider>" << endl;
#endif
    return this->providerId;
}

void Provider:: addCleaner(const Cleaner& cleaner)
{
#ifdef MAP
    cout << "Appel du addCleaner de <Provider>" << endl;
#endif
    
    cleaners.push_back(cleaner);
    return;
}

void Provider::setProviderId(const string& id)
{
#ifdef MAP
    cout << "Appel du setProvider de <Provider>" << endl;
#endif

    this->providerId = id;
}
void Provider::setCleaners(const vector<Cleaner>& cleanersList)
{
#ifdef MAP
    cout << "Appel du setCleaners de <Provider>" << endl;
#endif

    this->cleaners = cleanersList;

}



//-------------------------------------------- Constructeurs - destructeur



Provider::Provider(const string& id, const vector<Cleaner>& cleanersList)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif

    this->providerId = id;
    this->cleaners = cleanersList;

} //----- Fin de Provider



Provider::~Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

