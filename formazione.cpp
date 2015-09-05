#include <QList>
#include <QListIterator>
#include "formazione.h"
#include "titolo.h"

// CLASSE Formazione_rapp
class Formazione::Formazione_rapp {
public:
    QList<SmartTitolo> titlesList;
    int references;

    /** Costruttore ad 1 parametro con 1 parametro di default.
     *  Inizializza ad 1 il numero dei riferimenti.
     */
    Formazione_rapp( QList<SmartTitolo> l = QList<SmartTitolo>() ) :
        titlesList( l ),
        references( 1 ) // Gestito da Formazione
    {}

    /** Distruttore Formazione_rapp.
     *  Invoca il metodo clear() sulla lista dei titoli di studio dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Formazione_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Formazione_rapp* p_aux = static_cast<Formazione_rapp*>( p );
            p_aux->references--;
            if( !p_aux->references )
                p_aux->titlesList.clear();
        }
    }

    /** Metodo di utilità necessario per creare copie profonde di oggetti di tipo Formazione_rapp.
     *
     * @return Formazione_rapp *  Copia implicita della lista delle esperienze lavorative.
     */
    Formazione_rapp *clone() const {
        return new Formazione_rapp( titlesList );
    }
};

// COSTRUTTORE Formazione
Formazione::Formazione() :
    titles( new Formazione_rapp ),
    user_ref( 1 )
{}

// COSTRUTTORE di COPIA Formazione
Formazione::Formazione( const Formazione& ed ) :
    titles( ed.titles )
{
    user_ref++;
    titles->references++;
}

// DISTRUTTORE Formazione
Formazione::~Formazione() {
    titles->references--;
    if( titles->references == 0 )
        delete titles;
}

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

// METODO Formazione::Iteratore::hasNext
bool Formazione::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO Formazione::Iteratore::next
SmartTitolo Formazione::Iteratore::next() {
    return iterator->it.next();
}

// METODO Formazione::Iteratore::begin
Formazione::Iteratore Formazione::begin() const {
    Iteratore aux;
    aux.iterator = new Iteratore::Iteratore_rapp( titles->titlesList );
    return aux;
}

// METODO Formazione::Iteratore::addEducation( SmartTitolo )
void Formazione::addEducation( const SmartTitolo& t ) {
    titles->titlesList.append( t );
}

// METODO Formazione::Iteratore::removeEducation( SmartTitolo )
void Formazione::removeEducation( const SmartTitolo& t ) {
    titles->titlesList.removeOne( t );
}

// METODO getTitlesList Formazione
QVector<SmartTitolo> Formazione::getEducationsList() const {
    QVector<SmartTitolo> v;
    QListIterator<SmartTitolo> it( titles->titlesList );
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

// OPERATOR << Formazione
QDebug& operator <<( QDebug& qdbg, const Formazione& e ) {
    qdbg << "FORMAZIONE: " << "\n";
    QVector<SmartTitolo> ed = e.getEducationsList();
    if( ed.size() == 0 )
        qdbg << " ** Nessun titolo di studio! **" << "\n";
    else {
        for( int i = 0; i < ed.size(); i++ ) {
            qdbg << " Scuola: " << ed[i]->getSchool() << "\n";
            qdbg << " Data diploma: " <<
                    ed[i]->getDateAttended().toString( "yyyy" ) << "\n";
            qdbg << " Campo di studio: " << ed[i]->getFieldOfStudy() << "\n";
        }
    }
    return qdbg;
}
