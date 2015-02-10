#include "smarttitolo.h"
#include "titolo.h"

// COSTRUTTORE SmartTitolo
SmartTitolo::SmartTitolo( Titolo* t ) : title( t ) {
    if( title )
        title->references++;
}

// COSTRUTTORE di COPIA SmartTitolo
SmartTitolo::SmartTitolo( const SmartTitolo& st ) : title( st.title ) {
    if( title )
        title->references++;
}

// DISTUTTORE SmartTitolo
SmartTitolo::~SmartTitolo() {
    if( title ) {
        title->references--;
        if( title->references == 0 )
            delete title;
    }
}

// OPERATORE = SmartTitolo
SmartTitolo& SmartTitolo::operator =( const SmartTitolo& st ) {
    if( this != &st ) {
        Titolo* t = title;
        title = st.title;
        if( title )
            title->references++;
        if( t ) {
            t->references--;
            delete t;
        }
    }
    return *this;
}

// OPERATORE * SmartTitolo
Titolo& SmartTitolo::operator *() const {
    return *title;
}

// OPERATORE -> SmartTitolo
Titolo* SmartTitolo::operator ->() const {
    return title;
}

// OPERATORE == SmartTitolo
bool SmartTitolo::operator ==( const SmartTitolo& st ) {
    return title == st.title;
}

// OPERATORE != SmartTitolo
bool SmartTitolo::operator !=( const SmartTitolo& st ) {
    return title != st.title;
}

// OPERATORE << SmartTitolo
QDebug operator <<( QDebug qdbg, const SmartTitolo& st ) {
    qdbg << *st;
    return qdbg;
}
