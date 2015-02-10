#include "esperienza.h"
#include "lavoro.h"
#include <QList>
#include <QListIterator>

// CLASSE Esperienza_rapp
class Esperienza::Esperienza_rapp {
public:
    QList<Lavoro*> experiencesList; // Puntatore per permetterne la modifica

    /** Costruttore di default ridefinito.
     *  Inizializza il campo experiencesList con una QList di Lavoro* vuota.
     */
    Esperienza_rapp() :
        experiencesList( QList<Lavoro*>() ) {}

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
    QListIterator<Lavoro*> it;

    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param QList<Lavoro*>  Lista di Lavoro* sulla quale iterare.
     */
    Iteratore_rapp( QList<Lavoro*> list ) : it( list ) {}
};

// METODO hasNext Iteratore
bool Esperienza::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO next Iteratore
Lavoro* Esperienza::Iteratore::next() {
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
void Esperienza::addExperience( Lavoro* l ) {
    experiences->experiencesList.append( l );
}

// METODO removeExperience Esperienza
void Esperienza::removeExperience( Lavoro* l ) {
    experiences->experiencesList.removeAll( l );
}

// METODO getExperiencesList Esperienza
QVector<SmartLavoro> Esperienza::getExperiencesList() const {
    QVector<SmartLavoro> v;
    QListIterator<Lavoro*> it( experiences->experiencesList ); // QMutableListIterator ?
    while( it.hasNext() )
        v.push_back( SmartLavoro( it.next() ) );
    return v;
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
