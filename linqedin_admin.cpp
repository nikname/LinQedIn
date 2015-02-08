#include "linqedin_admin.h"

LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
}

void LinQedInAdmin::insertUser( Utente* u ) {
    qDebug() << u;
    db->insert( u );
}

void LinQedInAdmin::find( QString u ) const {

}

void LinQedInAdmin::remove( QString u ) {

}

void LinQedInAdmin::changeSubscriptionType( QString u ) {

}

void LinQedInAdmin::save() const {

}

Database* LinQedInAdmin::getDB() const {
    return db;
}
