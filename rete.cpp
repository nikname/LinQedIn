#include "rete.h"
#include <QListIterator>

class Utente;

class SmartUtente {
public:
    Utente* user; // Puntatore polimorfo

    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param Utente* u  Utente da aggiungere alla lista dei contatti.
     */
    SmartUtente( Utente* u ) : user( u ) {}
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output nome e cognome del contatto.
 *
 * @param QDebug  QDebug.
 * @param Utente  Utente nella lista dei contatti.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug qdbg, const SmartUtente& su ) {
    qdbg << su.user;
    return qdbg;
}

class Rete::Contatti {
public:
    QList<SmartUtente> contactsList;
};

Rete::Rete() : contacts( new Contatti ) {}

void Rete::addContact( Username u ) {
    // SmartUtente su( findOnDB( u ) );
    // contacts->contactsList.append( su );
}

void Rete::removeContact( Username u ) {
    // SmartUtente su( findOnDB( u ) );
    // contacts->contactsList.removeOne( su );
}

QDebug operator <<( QDebug qdbg, const Rete& r ) {
    qdbg << "CONTATTI: \n";
    QListIterator<SmartUtente> it( r.contacts->contactsList );
    while( it.hasNext() ) {
        qdbg << it.next();
        if( it.hasNext() )
            qdbg << ", ";
    }
    qdbg << "\n";
    return qdbg;
}
