#include "smartutente.h"
#include "utente.h"

SmartUtente::~SmartUtente() {
    delete user;
}

Utente* SmartUtente::getUser() const {
    return user;
}

void SmartUtente::setUser( Utente* u ) {
    user = u;
}

QDebug operator <<( QDebug qdbg, const SmartUtente& su ) {
    qdbg << su.getUser();
    return qdbg;
}

bool operator ==( const SmartUtente& sm1, const SmartUtente& sm2 ) {
    return sm1.getUser() == sm2.getUser();
}
