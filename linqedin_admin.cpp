#include "linqedin_admin.h"
#include <QDebug>

// COSTRUTTORE LinQedInAdmin
LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
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
void LinQedInAdmin::changeSubscriptionType( QString u ) {

}

// METODO LinQedInAdmin::saveDatabase
void LinQedInAdmin::saveDatabase() const {
    db->saveUsersList();
}

// METODO LinQedInAdmin::getUserList
QVector<SmartUtente> LinQedInAdmin::getUsersList() const {
    return db->getUsersList();
}
