#include "smartlavoro.h"
#include "lavoro.h"

// COSTRUTTORE SmartLavoro
SmartLavoro::SmartLavoro( Lavoro* j ) : job( j ) {
    if( job )
        job->references++;
}

// COSTRUTTORE di COPIA SmartLavoro
SmartLavoro::SmartLavoro( const SmartLavoro& sj ) : job( sj.job ) {
    if( job )
        job->references++;
}

// DISTRUTTORE SmartLavoro
SmartLavoro::~SmartLavoro() {
    if( job ) {
        job->references--;
        if( job->references == 0 )
            delete job;
    }
}

// OPERATORE = SmartLavoro
SmartLavoro& SmartLavoro::operator =( const SmartLavoro& sj ) {
    if( this != &sj ) {
        Lavoro* j = job;
        job = sj.job;
        if( job )
            job->references++;
        if( j ) {
            j->references--;
            delete j;
        }
    }
    return *this;
}

// OPERATORE * SmartLavoro
Lavoro& SmartLavoro::operator *() const {
    return *job;
}

// OPERATORE -> SmartLavoro
Lavoro* SmartLavoro::operator ->() const {
    return job;
}

// OPERATORE == SmartLavoro
bool SmartLavoro::operator ==( const SmartLavoro& sj ) {
    return job == sj.job;
}

// OPERATORE != SmartLavoro
bool SmartLavoro::operator !=( const SmartLavoro& sj ) {
    return job != sj.job;
}

// OPERATORE << SmartLavoro
QDebug operator <<( QDebug qdbg, const SmartLavoro& sj ) {
    qdbg << *sj;
    return qdbg;
}
