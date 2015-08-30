#include "linqedin_admin.h"
#include "utente_basic.h"
#include "utente_executive.h"
#include "utente_business.h"
#include <QDebug>

// COSTRUTTORE LinQedInAdmin
LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
}

// DISTRUTTORE LinQedInAdmin
LinQedInAdmin::~LinQedInAdmin() {
    delete db;
}

// METODO LinQedInAdmin::insertUser
bool LinQedInAdmin::insertUser( SmartUtente su ) {
    return db->insert( su );
}

// METODO LinQedInAdmin::findUser
SmartUtente LinQedInAdmin::findUser( QString u ) const {
    if( db->contains( u ) ) {
        QVectorIterator<SmartUtente> it( db->getUsersList() );
        while( it.hasNext() ) {
            SmartUtente aux = it.next();
            if( aux->getUsername() == u )
                return aux;
        }
    }
    return SmartUtente();
}

// METODO LinQedInAdmin::removeUser
bool LinQedInAdmin::removeUser( QString u ) {
    return db->remove( u );
}

// METODO LinQedInAdmin::changeSubscriptionType
void LinQedInAdmin::changeSubscriptionType( QString un, QString type ) {
    qDebug() << "#";
    if( db->contains( un ) ) {
        SmartUtente su = findUser( un );
        db->remove( un );
        if( type == "Basic" ) {
            db->insert( new UtenteBasic( *su ) );
        } else if( type == "Executive" ) {
            db->insert( new UtenteExecutive( *su ) );
        } else if( type == "Business" ) {
            db->insert( new UtenteBusiness( *su ) );
        } else {}
    }
    qDebug() << "#";
}

// METODO LinQedInAdmin::saveDatabase
void LinQedInAdmin::saveDatabase() const {
    db->saveUsersList();
}

// METODO LinQedInAdmin::getUserList
QVector<SmartUtente> LinQedInAdmin::getUsersList() const {
    return db->getUsersList();
}
