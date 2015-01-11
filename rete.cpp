#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

class Rete::Contatti {
public:
    QList<SmartUtente> contactsList;
};

Rete::Rete() : contacts( new Contatti ) {}

void Rete::addContact( Username un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        SmartUtente su( user );
        contacts->contactsList.append( su );
    }
}

void Rete::removeContact( Username un, Database* db ) {
    Utente* user = db->findUser( un );
    //if( user ) {
        //SmartUtente su( user );
        //contacts->contactsList.removeOne( su );
    //}
}

QString Rete::getContactsList() const {
    QString users = "";
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() ) {
        Utente* u = it.next().getUser();
        users.append( u->getProfile().getName() );
        users.append( u->getProfile().getSurname() );
        if( it.hasNext() )
            users.append( ", " );
    }
    return users;
}

QString Rete::getUsernamesList() const {
    QString usernames = "";
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() ) {
        Utente* u = it.next().getUser();
        usernames.append( u->getUsername().getLogin() );
        if( it.hasNext() )
            usernames.append( ", ");
    }
    return usernames;
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
