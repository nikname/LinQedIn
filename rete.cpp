#include "rete.h"

class Utente; // Dichiarazione incompleta

class SmartUtente {
public:
    Utente* user; // Puntatore polimorfo

    /* Costruttore ad 1 parametro.
     * Costruttore di default non disponibile.
     *
     * @param Utente* u  Utente da aggiungere alla lista dei contatti.
     */
    SmartUtente( Utente* u ) : user( u ) {}
};

class Rete::Contatti {
public:
    QList<SmartUtente> contactsList;
};

void Rete::addContact( Username u ) {
    // SmartUtente = SmartUtente( findOnDB( u ) )
    // contacts->contactsList.append( su );
}

void Rete::removeContact( Username u ) {
    //SmartUtente su( new Utente( u ) );
    //if( contacts->contactsList.contains( su ) )
    //    contacts->contactsList.removeOne();
}
/*
ostream& operator <<( ostream& os, Rete r ) {
    QString out = "";
    QListIterator<Rete::Contatti> it( r.contacts->contactsList );
    while( it.hasNext() ) {
        if( it.hasNext() ) {
            out.append( it.next() );
            out.append( ", " );
        } else out.append( it.next() );
    }
    return os << "CONTATTI: " << out;
}
*/

QDebug& operator <<( QDebug& qdbg, const Rete& r ) {
    qdbg << "CONTATTI: \n"
         << "Nome e cognome: \n";
    return qdbg;
}
