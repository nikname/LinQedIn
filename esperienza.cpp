#include <QList>
#include <QListIterator>
#include "esperienza.h"
#include "lavoro.h"

// CLASSE Esperienza_rapp
class Esperienza::Esperienza_rapp {
public:
    QList<SmartLavoro> experiencesList;
    int references;

    /** Costruttore ad 1 parametro con 1 parametro di default.
     *  Inizializza ad 1 il numero di riferimenti.
     */
    Esperienza_rapp( QList<SmartLavoro> l = QList<SmartLavoro>() ) :
        experiencesList( l ),
        references( 1 ) // Gestito da Esperienza
    {}

    /** Distruttore Esperienza_rapp.
     *  Invoca il metodo clear() sulla lista delle esperienze lavorative dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Esperienza_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Esperienza_rapp* p_aux = static_cast<Esperienza_rapp*>( p );
            p_aux->references--;
            if( !p_aux->references )
                p_aux->experiencesList.clear();
        }
    }

    /** Metodo di utilità necessario per creare copie profonde di oggetti di tipo Esperienza_rapp.
     *
     * @return Esperienza_rapp *  Copia implicita della lista delle esperienze lavorative.
     */
    Esperienza_rapp *clone() const {
        return new Esperienza_rapp( experiencesList );
    }
};

// COSTRUTTORE Esperienza
Esperienza::Esperienza() :
    experiences( new Esperienza_rapp ),
    user_ref( 1 )
{}

// COSTRUTTORE Esperienza( Esperienza_rapp * )
Esperienza::Esperienza( Esperienza::Esperienza_rapp * rapp ) :
    experiences( rapp ),
    user_ref( 1 )
{}

// COSTRUTTORE di COPIA Esperienza
Esperienza::Esperienza( const Esperienza& n ) :
    experiences( n.experiences )
{
    user_ref++;
    experiences->references++;
}

// DISTRUTTORE Esperienza
Esperienza::~Esperienza() {
    experiences->references--;
    if( experiences->references == 0 )
        delete experiences;
}

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

// METODO Esperienza::Iteratore::hasNext
bool Esperienza::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO Esperienza::Iteratore::next
SmartLavoro Esperienza::Iteratore::next() {
    return iterator->it.next();
}

// METODO Esperienza::Iteratore::begin
Esperienza::Iteratore Esperienza::begin() const {
    Iteratore aux;
    aux.iterator = new Iteratore::Iteratore_rapp( experiences->experiencesList );
    return aux;
}

// METODO Esperienza::addExperience( SmartLavoro )
void Esperienza::addExperience( const SmartLavoro& l ) {
    experiences->experiencesList.append( l );
}

// METODO Esperienza::removeExperience( SmartLavoro )
void Esperienza::removeExperience( const SmartLavoro& l ) {
    experiences->experiencesList.removeAll( l );
}

// METODO Esperienza::getExperiencesList
QVector<SmartLavoro> Esperienza::getExperiencesList() const {
    QVector<SmartLavoro> v;
    QListIterator<SmartLavoro> it( experiences->experiencesList );
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

// OPERATORE delete Esperienza
void Esperienza::operator delete( void* p ) {
    if( p ) {
        Esperienza* p_aux = static_cast<Esperienza*>( p );
        p_aux->user_ref--;
        if( p_aux->user_ref == 0 )
            delete p_aux->experiences;
    }
}

// METODO Esperienza::clone
Esperienza *Esperienza::clone() const {
    return new Esperienza( experiences->clone() );
}

// OVERLOADING
QDebug& operator <<( QDebug& qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE: " << "\n";
    QVector<SmartLavoro> ex = e.getExperiencesList();
    if( ex.size() == 0 )
        qdbg << " ** Nessuna esperienza lavorativa! **" << "\n";
    else {
        for( int i = 0; i < ex.size(); i++ ) {
            qdbg << " Azienda: " << ex[i]->getCompanyName() << "\n";
            qdbg << " Ruolo: " << ex[i]->getTitle() << "\n";
            qdbg << " Inizio: " << ex[i]->getBegin().toString( "dd/MM/yyyy" ) << "\n";
            qdbg << " Fine: " << ex[i]->getEnd().toString( "dd/MM/yyyy" ) << "\n";
        }
    }
    return qdbg;
}
