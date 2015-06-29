#include "linqedin_client.h"

LinQedInClient::LinQedInClient( QString un ) : db( new Database ) {
    db->loadUsersList();
    if( db->contains( un ) ) {
        user = db->find( un );
    } else {
        // throw ...
        qDebug() << "[error] User not found!";
    }
}

void LinQedInClient::aggiornaProfilo() {
    // user->getProfile().setName();
    // user->getProfile().setSurname();
    // user->getProfile().setBirthday();
    // user->getProfile().setMaritialStatus();
}

void LinQedInClient::showProfilo() {
    // user->getUsername();
    // user->getProfile();
    // user->getNet();
    // user->getExperiences();
    // user->getEducations();
}

void LinQedInClient::insertRete( QString un ) {
    //user->getNet().addContact( un );
}

void LinQedInClient::removeRete( QString un ) {
    //user->getNet().removeContact( un );
}
