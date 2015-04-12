#include "linqedin_admin.h"
#include <QDebug>

LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
}

bool LinQedInAdmin::insertUser( Utente* u ) {
    return db->insert( u );
}

SmartUtente LinQedInAdmin::findUser( QString u ) const {
    SmartUtente su = SmartUtente();
    if( db->contains( u ) ) {
        QVectorIterator<SmartUtente> it( db->getUsersList() );
        while( it.hasNext() ) {
            SmartUtente aux = it.next();
            if( aux->getUsername() == u )
                su = aux;
        }
    }
    return su;
}

void LinQedInAdmin::removeUser( QString u ) {

}

void LinQedInAdmin::changeSubscriptionType( QString u ) {

}

void LinQedInAdmin::saveDatabase() const {
    db->saveUsersList();
}
