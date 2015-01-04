#include "linqedin_admin.h"
#include "smartutente.h"

LinQedInAdmin::LinQedInAdmin() : db( new Database ) {
    db->loadUsersList();
}

void LinQedInAdmin::insert() {

}

void LinQedInAdmin::find( Username u ) const {

}

void LinQedInAdmin::remove( Username u ) {

}

void LinQedInAdmin::changeSubscriptionType( Username u ) {

}

void LinQedInAdmin::save() const {

}
