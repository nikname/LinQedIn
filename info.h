#ifndef INFO_H
#define INFO_H
#include <iostream>
#include <string>
#include <vector>
#include "esperienza.h"
#include "data.h"
#include "titolo_studio.h"

using std::string;
using std::vector;
using std::ostream;

class Info {
private:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;
    vector<Esperienza> experiences;
    vector<TitoloStudio> educations;
    vector<string> interests;
public:
    /** Costruttore a 4 parametri con 4 parametri di default.
     *
     * @param string name  Nome dell'utente.
     * @param string surname  Cognome dell'utente.
     * @param Data  birthday  Data di nascita dell'utente.
     * @param string maritialStatus  Stato civile dell'utente.
     */
    Info( string nome = "", string cognome = "", Data dataNascita = Data(), string statoCivile = "" ) :
        name( nome ), surname( cognome ), birthday( dataNascita ), maritialStatus( statoCivile ) {}

    string getName() const {
        return name;
    }

    string getSurname() const {
        return surname;
    }

    Data getBirthday() const {
        return birthday;
    }

    string getMaritialStatus() const {
        return maritialStatus;
    }

    string getExperiences() const;

    string getEducations() const;

    string getInterests() const;

    void setName( string n ) {
        name = n;
    }

    void setSurname( string s ) {
        surname = s;
    }

    void setBirthday( Data b ) {
        birthday = b;
    }

    void setMaritialStatus( string ms ) {
        maritialStatus = ms;
    }

    void addExperiences( string );

    void addEducations( string );

    void addInterests( string );

    string toString() const {
        string info = "UTENTE: ";
        info += getName();
        info += " ";
        info += getSurname();
        if( !( (getBirthday().toString()).empty() ) ) {
            info += "\nDATA NASCITA: ";
            info += getBirthday().toString();
        }
        if( !( getMaritialStatus().empty() ) ) {
            info += "\nSTATO CIVILE: ";
            info += getMaritialStatus();
        }
        return info;
    }
};

ostream& operator<< ( ostream& os, Info* i ) {
    return os << "UTENTE: " << i->getName() << " " << i->getSurname()
              << "\nDATA NASCITA: " << i->getBirthday()
              << "\nSTATO CIVILE: " <<i->getMaritialStatus();
}

#endif
