#include "linqedin_admin.h"

LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
}

void LinQedInAdmin::insertUser( Utente* u ) {
    db->insert( u );
}

void LinQedInAdmin::find( Username u ) const {

}

void LinQedInAdmin::remove( Username u ) {

}

void LinQedInAdmin::changeSubscriptionType( Username u ) {

}

void LinQedInAdmin::save() const {

}

Database* LinQedInAdmin::getDB() const {
    return db;
}
