#include "formazione.h"
#include "titolo.h"
#include <QList>
#include <QListIterator>

// CLASSE Formazione_rapp
class Formazione::Formazione_rapp {
public:
    QList<SmartTitolo> titlesList; // Puntatore per permetterne la modifica

    /** Costruttore di default rifefinito.
     *  Inizializza il campo titlesList con una QList di SmartTitolo vuota.
     */
    Formazione_rapp() :
        titlesList( QList<SmartTitolo>() ) {}

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

// CLASSE Iteratore_rapp
class Formazione::Iteratore::Iteratore_rapp {
public:
    QListIterator<SmartTitolo> it;

    /** Costruttore ad 1 paramtro.
     *  Costruttore di default non disponibile.
     *
     * @param QList<SmartTitolo>  Lista di SmartTitolo sulla quale iterare.
     */
    Iteratore_rapp( QList<SmartTitolo> list ) : it( list ) {}
};

// METODO hasNext Iteratore
bool Formazione::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO next Iteratore
SmartTitolo Formazione::Iteratore::next() {
    return iterator->it.next();
}

// METODO begin Iteratore
Formazione::Iteratore Formazione::begin() const {
    Iteratore aux;
    aux.iterator = new Iteratore::Iteratore_rapp( titles->titlesList );
    return aux;
}

// COSTRUTTORE Formazione
Formazione::Formazione() :
    titles( new Formazione_rapp ),
    user_ref( 1 ) {}

// METODO addEducation Formazione
void Formazione::addEducation( SmartTitolo t ) {
    titles->titlesList.append( t );
}

// METODO removeEducation Formazione
void Formazione::removeEducation( SmartTitolo t ) {
    titles->titlesList.removeOne( t );
}

// METODO getTitlesList Formazione
QVector<SmartTitolo> Formazione::getEducationsList() const {
    QVector<SmartTitolo> v;
    QListIterator<SmartTitolo> it( titles->titlesList ); // QMutableListIterator ?
    while( it.hasNext() )
        v.push_back( SmartTitolo( it.next() ) );
    return v;
}

// METODO Formazione::setEducationsList
void Formazione::setEducationsList( QVector<SmartTitolo> v ) {
    if( titles ) {
        delete titles;
        titles = 0;
    }
    titles = new Formazione_rapp();
    for( int i = 0; i < v.size(); i++ )
        addEducation( v[i] );
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
