#include "esperienza.h"
#include "lavoro.h"
#include <QList>
#include <QListIterator>

// CLASSE Esperienza_rapp
class Esperienza::Esperienza_rapp {
public:
    QList<Lavoro*> experiencesList;

    /** Costruttore di default ridefinito. */
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
QVector<Lavoro*> Esperienza::getExperiencesList() const {
    QVector<Lavoro*> v;
    QListIterator<Lavoro*> it( experiences->experiencesList ); // QMutableListIterator ?
    while( it.hasNext() )
        v.push_back( it.next() );
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
