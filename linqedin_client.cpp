#include "linqedin_client.h"

LinQedInClient::LinQedInClient( QString un ) {
    db->loadUsersList();
    //user = db->findUser( un );
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
