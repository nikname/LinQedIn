#include "esperienza.h"
#include "lavoro.h"
#include <QList>
#include <QListIterator>

// CLASSE Esperienza_rapp
class Esperienza::Esperienza_rapp {
public:
    QList<SmartLavoro> experiencesList; // Puntatore per permetterne la modifica

    /** Costruttore di default ridefinito.
     *  Inizializza il campo experiencesList con una QList di SmartLavoro vuota.
     */
    Esperienza_rapp() :
        experiencesList( QList<SmartLavoro>() ) {}

    /** Distruttore Esperienza_rapp.
     *  Invoca il metodo clear() sulla lista delle esperienze lavorative dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Esperienza_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Esperienza_rapp* p_aux = static_cast<Esperienza_rapp*>( p );
            if( !p_aux->experiencesList.isEmpty() )
                p_aux->experiencesList.clear();
        }
    }
};

// CLASSE Iteratore_rapp
class Esperienza::Iteratore::Iteratore_rapp {
public:
    QListIterator<SmartLavoro> it;

    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param QList<SmartLavoro>  Lista di SmartLavoro sulla quale iterare.
     */
    Iteratore_rapp( QList<SmartLavoro> list ) : it( list ) {}
};

// METODO hasNext Iteratore
bool Esperienza::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO next Iteratore
SmartLavoro Esperienza::Iteratore::next() {
    return iterator->it.next();
}

// METODO begin Iteratore
Esperienza::Iteratore Esperienza::begin() const {
    Iteratore aux;
    aux.iterator = new Iteratore::Iteratore_rapp( experiences->experiencesList );
    return aux;
}

// COSTRUTTORE Esperienza
Esperienza::Esperienza() :
    experiences( new Esperienza_rapp ),
    user_ref( 1 ) {}

// METODO addExperience Esperienza
void Esperienza::addExperience( SmartLavoro l ) {
    experiences->experiencesList.append( l );
}

// METODO removeExperience Esperienza
void Esperienza::removeExperience( SmartLavoro l ) {
    experiences->experiencesList.removeAll( l );
}

// METODO getExperiencesList Esperienza
QVector<SmartLavoro> Esperienza::getExperiencesList() const {
    QVector<SmartLavoro> v;
    QListIterator<SmartLavoro> it( experiences->experiencesList ); // QMutableListIterator ?
    while( it.hasNext() )
        v.push_back( SmartLavoro( it.next() ) );
    return v;
}

// METODO Esperienza::setExperiencesList
void Esperienza::setExperiencesList( QVector<SmartLavoro> v ) {
    if( experiences ) {
        delete experiences;
        experiences = 0;
    }
    experiences = new Esperienza_rapp();
    for( int i = 0; i < v.size(); i ++ )
        addExperience( v[i] );
}

// OPERATOR delete Esperienza
void Esperienza::operator delete( void* p ) {
    if( p ) {
        Esperienza* p_aux = static_cast<Esperienza*>( p );
        p_aux->user_ref--;
        if( p_aux->user_ref == 0 )
            delete p_aux->experiences;
    }
}
