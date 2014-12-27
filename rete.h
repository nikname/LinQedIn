#ifndef RETE_H
#define RETE_H
#include <iostream>
#include <vector>
#include <string>
#include "smart_utente.h"
#include "username.h"

using std::vector;
using std::ostream;
using std::string;

class Rete {
private:
    vector<SmartUtente> contacts;
public:
    /** Ritorna la lista dei contatti.
     *
     * @return vector<SmartUtente>  Lista dei contatti.
     */
    vector<SmartUtente> getContacts() const;

    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username del contatto da aggiungere.
     */
    void add( Username );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param Username  Username del contatto da rimuovere.
     */
    void remove( Username );
};
/*
ostream& operator<< ( ostream& os, Rete* r ) {
    string out = "CONTATTI: ";
    for( unsigned i = 0; i < (r->getContacts()).size(); i++ ) {
        if( i == (r->getContacts()).size()-1 )
            out += (r->getContacts())[i];
        else {
            out += ", ";
            out += ((r->getContacts())[i]);
        }
    }
    return os << out;
}*/

#endif
