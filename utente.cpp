#include "utente.h"
#include "rete.h"
#include "smartutente.h"
#include "formazione.h"
#include "titolo.h"
#include "esperienza.h"
#include "lavoro.h"
#include "database.h"

// COSTRUTTORE Utente
Utente::Utente( const QString& un, const QString& name, const QString& surname ) :
    username( un ),
    profile( name, surname ),
    net( new Rete() ),
    educations( new Formazione ),
    experiences( new Esperienza ),
    references( 1 )
{}

// COSTRUTTORE DI COPIA Utente
Utente::Utente( const Utente& u ) :
    username( u.username ),
    profile( u.profile ),
    net( u.net ),
    educations( u.educations ),
    experiences( u.experiences )
{
    educations->user_ref++;
    experiences->user_ref++;
}

// DISTRUTTORE Utente
Utente::~Utente() {
    if( educations ) {
        educations->user_ref--;
        if( educations->user_ref == 0 )
            delete educations;
    }
    if( experiences ) {
        experiences->user_ref--;
        if( experiences->user_ref == 0 )
            delete experiences;
    }
}

// OPERATOR () Utente::FuntoreRicerca
SmartUtente Utente::FuntoreRicerca::operator ()( const SmartUtente& su ) const {
    SmartUtente aux( su );
    switch( searchType ) {
    case 1:
        delete aux->net;
        aux->net = 0;
        delete aux->educations;
        aux->educations = 0;
        delete aux->experiences;
        aux->experiences = 0;
        break;
    case 2:
        delete aux->net;
        aux->net = 0;
        break;
    case 3:
        break;
    default:
        break;
    }
    return aux;
}

// METODO getUsername Utente
QString Utente::getUsername() const {
    return username;
}

// METODO getName Utente
QString Utente::getName() const {
    return profile.getName();
}

// METODO getSurname Utente
QString Utente::getSurname() const {
    return profile.getSurname();
}

// METODO getBirthday Utente
QDate Utente::getBirthday() const {
    return profile.getBirthday();
}

// METODO getMaritialStatus Utente
QString Utente::getMaritialStatus() const {
    return profile.getMaritialStatus();
}

// METODO setName Utente
void Utente::setName( const QString& n ) {
    profile.setName( n );
}

// METODO setSurname Utente
void Utente::setSurname( const QString& s ) {
    profile.setSurname( s );
}

// METODO setBirthday Utente
void Utente::setBirthday( const QDate& b ) {
    profile.setBirthday( b );
}

// METODO setMaritialStatus Utente
void Utente::setMaritialStatus( const QString& ms ) {
    profile.setMaritialStatus( ms );
}

// METODO addContact Utente
void Utente::addContact( const SmartUtente& su ) {
    net->addContact( su );
}

// METODO removeContact Utente
void Utente::removeContact( const SmartUtente& su ) {
    net->removeContact( su );
}

// METODO Utente::isContact
bool Utente::isContact( const SmartUtente& su ) {
    return net->isContact( su );
}

// METODO Utente::isContactsListSet
bool Utente::isContactsListSet() {
    return &*net;
}

// METODO Utente::unsetContactsList
void Utente::unsetContactsList() {

}

// METODO getContactsList Utente
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}

// METODO addEducation Utente
void Utente::addEducation( SmartTitolo t ) {
    educations->addEducation( t );
}

// METODO removeEducation Utente
void Utente::removeEducation( SmartTitolo t ) {
    educations->removeEducation( t );
}

// METODO getEducationsList Utente
QVector<SmartTitolo> Utente::getEducationsList() const {
    return educations->getEducationsList();
}

// METODO Utente::setEducationsList
void Utente::setEducationsList( QVector<SmartTitolo> v ) {
    educations->setEducationsList( v );
}

// METODO Utente::unsetEducationsList
void Utente::unsetEducationsList() {
    if( educations ) {
        educations->user_ref--;
        if( !educations ) {
            delete educations;
            educations = 0;
        }
    }
}

// METODO Utente::isEducationsListSet
bool Utente::isEducationsListSet() {
    return educations;
}

// METODO getEducationsIterator
Formazione::Iteratore Utente::getEducationsIterator() const {
    return educations->begin();
}

// METODO addExperience Utente
void Utente::addExperience( SmartLavoro l ) {
    experiences->addExperience( l );
}

// METODO removeExperience Utente
void Utente::removeExperience( SmartLavoro l ) {
    experiences->removeExperience( l );
}

// METODO getExperiencesList Utente
QVector<SmartLavoro> Utente::getExperiencesList() const {
    return experiences->getExperiencesList();
}

// METODO Utente::setExperiencesList
void Utente::setExperiencesList( QVector<SmartLavoro> v ) {
    experiences->setExperiencesList( v );
}

// METODO Utente::isExperiencesListSet
bool Utente::isExperiencesListSet() {
    return experiences;
}

// METODO Utente::unsetExperiencesList
void Utente::unsetExperiencesList() {
    if( experiences ) {
        experiences->user_ref--;
        if( !experiences ) {
            delete experiences;
            experiences = 0;
        }
    }
}

// METODO getExperiecesIterator Utente
Esperienza::Iteratore Utente::getExperiencesIterator() const {
    return experiences->begin();
}

// OPERATOR << Utente
QDebug operator <<( QDebug qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***" << "\n";
    qdbg << "USERNAME: " << u.getUsername() << "\n";
    qdbg << "PROFILO:" << "\n";
    qdbg << " Nome: " << u.getName() << "\n";
    qdbg << " Cognome: " << u.getSurname() << "\n";
    qdbg << " Data di nascita: " << u.getBirthday().toString( "dd/MM/yyyy" ) << "\n";
    qdbg << " Stato civile: " << u.getMaritialStatus() << "\n";
    qdbg << u.net;
    if( u.educations ) {
        qdbg << "FORMAZIONE: " << "\n";
        QVector<SmartTitolo> ed = u.getEducationsList();
        if( ed.size() == 0 )
            qdbg << " ** Nessun titolo di studio! **" << "\n";
        else {
            for( int i = 0; i < ed.size(); i++ ) {
                qdbg << " Scuola: " << ed[i]->getSchool() << "\n";
                qdbg << " Data diploma: " <<
                        ed[i]->getDateAttended().toString( "yyyy" ) << "\n";
                qdbg << " Laurea: " << ed[i]->getDegree() << "\n";
                qdbg << " Campo di studio: " << ed[i]->getFieldOfStudy() << "\n";
                qdbg << " Votazione: " << ed[i]->getGrade() << "\n";
            }
        }
    }
    if( u.experiences ) {
        qdbg << "ESPERIENZE: " << "\n";
        QVector<SmartLavoro> ex = u.getExperiencesList();
        if( ex.size() == 0 )
            qdbg << " ** Nessuna esperienza lavorativa! **" << "\n";
        else {
            for( int i = 0; i < ex.size(); i++ ) {
                qdbg << " Azienda: " << ex[i]->getCompanyName() << "\n";
                qdbg << " Ruolo: " << ex[i]->getTitle() << "\n";
                qdbg << " Luogo: " << ex[i]->getLocation() << "\n";
                qdbg << " Inizio: " << ex[i]->getBegin().toString( "dd/MM/yyyy" ) << "\n";
                qdbg << " Fine: " << ex[i]->getEnd().toString( "dd/MM/yyyy" ) << "\n";
            }
        }
    }
    return qdbg;
}
