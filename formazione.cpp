#include "formazione.h"
#include "titolo.h"
#include <QList>
#include <QListIterator>

// CLASSE Formazione_rapp
class Formazione::Formazione_rapp {
public:
    QList<Titolo*> titlesList; // Memoria condivisa per permettere la modifica

    /** Costruttore di default rifefinito.
     *  Inizializza il campo titlesList con una QList di Titolo vuota.
     */
    Formazione_rapp() :
        titlesList( QList<Titolo*>() ) {}

    QList<Titolo*> getTitles() const {
        return titlesList;
    }

    /** Distruttore Formazione_rapp.
     *  Invoca il metodo clear() sulla lista dei titoli di studio dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Formazione_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Formazione_rapp* p_aux = static_cast<Formazione_rapp*>( p );
            if( !p_aux->titlesList.isEmpty() )
                p_aux->titlesList.clear();
        }
    }
};

// COSTRUTTORE Iteratore
Formazione::Iteratore::Iteratore() : iterator( new Iteratore_rapp ) {}

// CLASSE Iteratore_rapp
class Formazione::Iteratore_rapp {
public:
    QListIterator<Titolo*> it;
    Iteratore_rapp( QList<Titolo*> list ) : it( list ) {}
};

Formazione::Iteratore::Iteratore_rapp* Formazione::Iteratore::begin() const {
    return new Iteratore_rapp( titles->titlesList );
}

// COSTRUTTORE Formazione
Formazione::Formazione() :
    titles( new Formazione_rapp ),
    user_ref( 1 ) {}

// METODO addEducation Formazione
void Formazione::addEducation( Titolo* t ) {
    titles->titlesList.append( t );
}

// METODO removeEducation Formazione
void Formazione::removeEducation( Titolo* t ) {
    titles->titlesList.removeOne( t );
}

// METODO getTitlesList Formazione
QVector<Titolo*> Formazione::getTitlesList() const {
    QVector<Titolo*> v;
    QListIterator<Titolo*> it( titles->titlesList ); // QMutableListIterator ?
    while( it.hasNext() )
        v.push_back( it.next() );
    return v;
}

// OPERATOR delete Formazione
void Formazione::operator delete( void* p ) {
    if( p ) {
        Formazione* p_aux = static_cast<Formazione*>( p );
        p_aux->user_ref--;
        if( p_aux->user_ref == 0 )
            delete p_aux->titles;
    }
}
