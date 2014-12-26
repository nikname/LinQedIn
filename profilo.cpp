#include "profilo.h"
#include "esperienza.h"
#include "data.h"
#include "titolo_studio.h"

using std::ostream;
using std::string;
using std::vector;

class Info {
public:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;
    vector<Esperienza> experiences;
    vector<TitoloStudio> educations;
    vector<string> interests;

    /** Costruttore a 4 parametri con 4 parametri di default.
     *
     * @param string name  Nome dell'utente.
     * @param string surname  Cognome dell'utente.
     * @param Data  birthday  Data di nascita dell'utente.
     * @param string maritialStatus  Stato civile dell'utente.
     */
    Info( string nome = "", string cognome = "", Data dataNascita = Data(), string statoCivile = "" ) :
        name( nome ), surname( cognome ), birthday( dataNascita ), maritialStatus( statoCivile ) {}
};

/** Overloading dell'operatore <<. Stampa su standard output le informazioni collegate all'utente.
 *
 * @param ostream& os  ostream passato per riferimento.
 * @param Info* i  Informazioni collegate all'utente.
 * @return ostream&  ostream passato per riferimento.
 */
ostream& operator<< ( ostream& os, Info* i ) {
    return os << "UTENTE: " << i->name << " " << i->surname
              << "\nDATA NASCITA: " << i->birthday
              << "\nSTATO CIVILE: " <<i->maritialStatus;
}

Profilo::Profilo() {
    info = new Info();
}

Profilo::Profilo( Info* i ) {
    setInfo( i );
}

void Profilo::setInfo( Info* i ) {
    info->name = i->name;
    info->surname = i->surname;
    info->birthday = i->birthday;
    info->maritialStatus = i->maritialStatus;
}

Info* Profilo::getInfo() const {
    return info;
}

ostream& operator<< ( ostream& os, Profilo p ) {
    return os << p.getInfo();
}
