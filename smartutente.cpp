#include "smartutente.h"
#include "utente.h"

// COSTRUTTORE SmartUtente
SmartUtente::SmartUtente( Utente* u ) : user( u ) {
    if( user )
        user->references++;
}

// COSTRUTTORE di COPIA SmartUtente
SmartUtente::SmartUtente( const SmartUtente& su ) : user( su.user ) {
    if( user )
        user->references++;
}

// DISTRUTTORE SmartUtente
SmartUtente::~SmartUtente() {
    if( user ) {
        user->references--;
        if( user->references == 0 )
            delete user;
    }
}

// OPERATORE = SmartUtente
SmartUtente& SmartUtente::operator =( const SmartUtente& su ) {
    if( this != &su ) {
        Utente* u = user;
        user = su.user;
        if( user )
            user->references++;
        if( u ) {
            u->references--;
            delete u;
        }
    }
    return *this;
}

// OPERATORE * SmartUtente
Utente& SmartUtente::operator *() const {
    return *user;
}

// OPERATORE -> SmartUtente
Utente* SmartUtente::operator ->() const {
    return user;
}

// OPERATORE == SmartUtente
bool SmartUtente::operator ==( const SmartUtente& su ) {
    return user == su.user;
}

// OPERATORE != SmartUtente
bool SmartUtente::operator !=( const SmartUtente& su ) {
    return user != su.user;
}

// OPERATORE << SmartUtente
QDebug operator <<( QDebug qdbg, const SmartUtente& su ) {
    qdbg << *su;
    return qdbg;
}
