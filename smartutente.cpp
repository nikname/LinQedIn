#include "smartutente.h"

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
