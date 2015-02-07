#include "esperienza.h"
#include <QList>
#include <QListIterator>

// CLASSE Esperienza_rapp
class Esperienza::Esperienza_rapp {
public:
    QList<Esperienza::Lavoro> experiencesList;

    /** Costruttore di default ridefinito. */
    Esperienza_rapp() :
        experiencesList( QList<Esperienza::Lavoro>() ) {}

    /** Distruttore Esperienza_rapp.
     *  Invoca il metodo clear() sulla lista delle esperienze lavorative dell'utente.
     */
    void operator delete( void* p ) {
        if( p ) {
            Esperienza_rapp* p_aux = static_cast<Esperienza_rapp*>( p );
            p_aux->experiencesList.clear();
        }
    }
};

// COSTRUTTORE Esperienza
Esperienza::Esperienza() :
    experiences( new Esperienza_rapp ),
    user_ref( 1 ) {}

// METODO getCompanyName Lavoro
QString Esperienza::Lavoro::getCompanyName() const {
    return companyName;
}

// METODO getTitle Lavoro
QString Esperienza::Lavoro::getTitle() const {
    return title;
}

// METODO getLocation Lavoro
QString Esperienza::Lavoro::getLocation() const {
    return location;
}

// METODO getBegin Lavoro
QDate Esperienza::Lavoro::getBegin() const {
    return begin;
}

// METODO getEnd Lavoro
QDate Esperienza::Lavoro::getEnd() const {
    return end;
}

// METODO setCompanyName Lavoro
void Esperienza::Lavoro::setCompanyName( QString azienda ) {
    companyName = azienda;
}

// METODO setTitle Lavoro
void Esperienza::Lavoro::setTitle( QString ruolo ) {
    title = ruolo;
}

// METODO setLocation Lavoro
void Esperienza::Lavoro::setLocation( QString posizione ) {
    location = posizione;
}

// METODO setBegin Lavoro
void Esperienza::Lavoro::setBegin( QDate inizio ) {
    begin = inizio;
}

// METODO setEnd Lavoro
void Esperienza::Lavoro::setEnd( QDate fine ) {
    end = fine;
}

// OPERATOR == Lavoro
bool Esperienza::Lavoro::operator ==( const Esperienza::Lavoro& l ) {
    return ( getCompanyName() == l.getCompanyName() ) &&
        ( getLocation() == l.getLocation() ) &&
        ( getBegin() == l.getBegin() ) &&
        ( getEnd() == l.getEnd() ) &&
        ( getTitle() == l.getTitle() );
}

// METODO addExperience Lavoro
void Esperienza::addExperience( const Lavoro& l ) {
    experiences->experiencesList.append( l );
}

// METODO removeExperience Lavoro
void Esperienza::removeExperience( const Lavoro& l ) {
    experiences->experiencesList.removeAll( l );
}

// METODO getExperiencesList Esperienza
QVector<Esperienza::Lavoro*> Esperienza::getExperiencesList() const {
    QVector<Esperienza::Lavoro*> v;
    //QListIterator<Esperienza::Lavoro*> it( experiences->experiencesList ); // QMutableListIterator ?
    //while( it.hasNext() )
        //v.push_back( it.next() );
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

// OPERATOR << Lavoro
QDebug operator <<( QDebug qdbg, const Esperienza::Lavoro& l ) {
    qdbg << "Azienda: " << l.getCompanyName() << "\n"
         << "Ruolo: " << l.getTitle() << "\n"
         << "Luogo: " << l.getLocation() << "\n"
         << "Inizio: " << l.getBegin() << "\n"
         << "Fine: " << l.getEnd() << "\n";
    return qdbg;
}

// OPERATOR << Esperienza
QDebug operator <<( QDebug qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE:\n";
    QListIterator<Esperienza::Lavoro> it( e.experiences->experiencesList );
    while( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}
