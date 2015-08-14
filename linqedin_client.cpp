#include "linqedin_client.h"

// COSTRUTTORE LinQedInClient
LinQedInClient::LinQedInClient( QString un ) : db( new Database ) {
    db->loadUsersList();
    if( db->contains( un ) ) {
        user = db->find( un );
    } else {
        // throw ...
        qDebug() << "[error] User not found!";
    }
}

// METODO LinQedInClient::saveDatabase
void LinQedInClient::saveDatabase() {
    db->saveUsersList();
}
