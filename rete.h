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
    /** */
    vector<SmartUtente> getContacts() const {
        return contacts;
    }

    /** */
    void add( Username );

    /** */
    void remove( Username );
};

ostream& operator<< ( ostream& os, Rete* r ) {
    string out = "CONTATTI: ";
    /*for( unsigned i = 0; i < (r->getContacts()).size(); i++ ) {
        if( i == (r->getContacts()).size()-1 )
            out += (r->getContacts())[i];
        else {
            out += ", ";
            out += ((r->getContacts())[i]);
        }
    }*/
    return os << out;
}

#endif
