#include "rete.h"
#include "smartutente.h"
#include <QList>
#include <QListIterator>

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
