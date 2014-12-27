#include "profilo.h"

using std::ostream;
using std::string;
using std::vector;

class Profilo::Info {
public:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;
    vector<Esperienza> experiences;
    vector<TitoloStudio> educations;
    vector<string> interests;

    /** Costruttore a 4 parametri con 2 parametri di default.
     *  Richiesti nome e cognome.
     *
     * @param string name  Nome dell'utente.
     * @param string surname  Cognome dell'utente.
     * @param Data  birthday  Data di nascita dell'utente.
     * @param string maritialStatus  Stato civile dell'utente.
     */
    Info( string nome = "", string cognome = "", Data compleanno = Data(), string statoCivile = "" ) :
        name( nome ), surname( cognome ), birthday( compleanno ), maritialStatus( statoCivile ) {}
};

Profilo::Profilo() {
    info = new Info();
}

Profilo::Profilo( string nome, string cognome, Data compleanno = Data(), string statoCivile = "" ) {
    info = new Info( nome, cognome, compleanno, statoCivile );
}

string Profilo::getName() const {
    return info->name;
}

string Profilo::getSurname() const {
    return info->surname;
}

Data Profilo::getBirthday() const {
    return info->birthday;
}

string Profilo::getMaritialStatus() const {
    return info->maritialStatus;
}

void Profilo::setName( string n ) {
    info->name = n;
}

void Profilo::setSurname( string s ) {
    info->surname = s;
}

void Profilo::setBirthday( Data b ) {
    info->birthday = b;
}

void Profilo::setMaritialStatus( string ms ) {
    info->maritialStatus = ms;
}

ostream& operator <<( ostream& os, Profilo p ) {
    return os << "UTENTE: " << p.info->name << " " << p.info->surname << "\n"
              << "DATA NASCITA: " << p.info->birthday << "\n"
              << "STATO CIVILE: " << p.info->maritialStatus;
}
