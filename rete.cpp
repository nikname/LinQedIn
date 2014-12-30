#include "rete.h"

using std::ostream;

class Utente; // Dichiarazione incompleta

class Rete::Contatti {
    friend ostream& operator <<( ostream&, Rete );
public:
    Utente* user; // Puntatore polimorfo

    /* Costruttore ad 1 parametro.
     * Costruttore di default non disponibile.
     *
     * @param Utente* u  Utente da aggiungere alla lista dei contatti.
     */
    Contatti( Utente* u ) : user( u ) {}
};

void Rete::addContact( Username u ) {
    // Contatto su = Contatto( findOnDB( u ) )
    // contactsList.append( su );
}

void Rete::removeContact( Username u ) {
    Contatti su( new Utente( u ) );
    if( contactsList.contains( su ) )
        contactsList.removeOne();
}

ostream& operator <<( ostream& os, Rete r ) {
    QString out = "";
    QListIterator<Rete::Contatti> it( r.contactsList );
    while( it.hasNext() ) {
        if( it.hasNext() ) {
            out.append( it.next() );
            out.append( ", " );
        } else out.append( it.next() );
    }
    return os << "CONTATTI: " << out;
}
