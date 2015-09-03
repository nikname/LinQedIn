#include "smartrete.h"
#include "rete.h"

// COSTRUTTORE SmartRete
SmartRete::SmartRete( Rete *n ) : net( n ) {
    if( net )
        net->user_ref++;
}

// COSTRUTTORE di COPIA SmartRete
SmartRete::SmartRete( const SmartRete& sr ) : net( sr.net ) {
    if( net )
        net->user_ref++;
}

// DISTRUTTORE SmartRete
SmartRete::~SmartRete() {
    if( net ) {
        net->user_ref--;
        if( net->user_ref == 0 )
            delete net;
    }
}

// OPERATORE = SmartRete
SmartRete& SmartRete::operator =( const SmartRete& sr ) {
    if( this != &sr ) {
        Rete* n = net;
        net = sr.net;
        if( net )
            net->user_ref++;
        if( n ) {
            n->user_ref--;
            delete n;
        }
    }
    return *this;
}

// OPERATORE * SmartRete
Rete& SmartRete::operator *() const {
    return *net;
}

// OPERATORE -> SmartRete
Rete* SmartRete::operator ->() const {
    return net;
}

// OPERATORE == SmartRete
bool SmartRete::operator ==( const SmartRete& sr ) {
    return net == sr.net;
}

// OPERATORE != SmartRete
bool SmartRete::operator !=( const SmartRete& sr ) {
    return net != sr.net;
}

// OPERATORE << SmartRete
QDebug operator <<( QDebug qdbg, const SmartRete& sr ) {
    qdbg << *sr;
    return qdbg;
}

