#include "profilo.h"

using std::ostream;
using std::string;

// PROFILO - INFOPERSONALI

class Profilo::InfoPersonali {
public:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;

    /** Costruttore a 4 parametri.
     *
     * @param string name  Nome dell'utente.
     * @param string surname  Cognome dell'utente.
     * @param Data  birthday  Data di nascita dell'utente.
     * @param string maritialStatus  Stato civile dell'utente.
     */
    InfoPersonali( const string& nome,
                   const string& cognome,
                   const Data& compleanno,
                   const string& statoCivile ) :
        name( nome ),
        surname( cognome ),
        birthday( compleanno ),
        maritialStatus( statoCivile ) {}
};

// PROFILO

Profilo::Profilo( const string& nome,
                  const string& cognome,
                  const Data& compleanno,
                  const string& statoCivile ) :
    personalInfo( new InfoPersonali( nome, cognome, compleanno, statoCivile ) ) {}

string Profilo::getName() const {
    return personalInfo->name;
}

string Profilo::getSurname() const {
    return personalInfo->surname;
}

Data Profilo::getBirthday() const {
    return personalInfo->birthday;
}

string Profilo::getMaritialStatus() const {
    return personalInfo->maritialStatus;
}

void Profilo::setName( string n ) {
    personalInfo->name = n;
}

void Profilo::setSurname( string s ) {
    personalInfo->surname = s;
}

void Profilo::setBirthday( Data b ) {
    personalInfo->birthday = b;
}

void Profilo::setMaritialStatus( string ms ) {
    personalInfo->maritialStatus = ms;
}

// Altro

ostream& operator <<( ostream& os, Profilo p ) {
    return os << "UTENTE: " << p.personalInfo->name << " "
                            << p.personalInfo->surname << "\n"
              << "DATA NASCITA: " << p.personalInfo->birthday << "\n"
              << "STATO CIVILE: " << p.personalInfo->maritialStatus;
}
