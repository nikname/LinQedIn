#include "linqedin_client.h"

// COSTRUTTORE LinQedInClient
LinQedInClient::LinQedInClient( const QString& un ) : db( new Database ) {
    db->loadUsersList();
    if( db->contains( un ) ) {
        user = db->find( un );
    } else {
        throw QString( "User not found!" );
    }
}

// METODO LinQedInClient::saveUserInfo
void LinQedInClient::saveUserInfo() {
    db->saveUsersList();
}

// METODO LinQedInClient::saveProfile
void LinQedInClient::saveProfile() {
    db->saveUsersList();
}

// METODO LinQedInClient::saveNet
void LinQedInClient::saveNet() {
    db->saveUsersList();
}

// METODO LinQedInClient::saveExperiences
void LinQedInClient::saveExperiences() {
    db->saveUsersList();
}

// METODO LinQedInClient::saveEducations
void LinQedInClient::saveEducations() {
    db->saveUsersList();
}
