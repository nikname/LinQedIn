#include "utente.h"

// COSTRUTTORE DI COPIA di Utente
Utente::Utente( const Utente& u ) :
    username( u.username ),
    profile( u.profile ),
    net( u.net ),
    educations( u.educations ),
    experiences( u.experiences )
{
    net->user_ref++;
    educations->user_ref++;
    experiences->user_ref++;
}

// DISTRUTTORE Utente
Utente::~Utente() {
    net->user_ref--;
    if( net->user_ref == 0 )
        delete net;
    educations->user_ref--;
    if( educations->user_ref == 0 )
        delete educations;
    experiences->user_ref--;
    if( experiences->user_ref == 0 )
        delete experiences;
}

// METODO getUsername Utente
QString Utente::getUsername() const {
    return username;
}

// METODO setLogin Utente
void Utente::setUsername( const QString& l ) {
    //TODO: controlla che non sia già utilizzato
    //try {
    //    if( db.findUser( l ) )
    //        throw new Exception( "Username non disponibile!" );
    //} catch( Exception e ) {
    //    qDebug() << e;
    //}
    username = l;
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
void Utente::addContact( Utente* u, Database* db ) {
    net->addContact( u, db );
}

// METODO removeContact Utente
void Utente::removeContact( Utente* u, Database* db ) {
    net->removeContact( u, db );
}

// METODO getContactsList Utente
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}

// METODO addEducation Utente
void Utente::addEducation( Formazione::Titolo* t ) {
    educations->addEducation( t );
}

// METODO removeEducation Utente
void Utente::removeEducation( Formazione::Titolo* t ) {
    educations->removeEducation( t );
}

// METODO getEducationsList Utente
QVector<Formazione::Titolo*> Utente::getTitlesList() const {
    return educations->getTitlesList();
}

// METODO addExperience Utente
void Utente::addExperience( Esperienza::Lavoro* l ) {
    experiences->addExperience( l );
}

// METODO removeExperience Utente
void Utente::removeExperience( Esperienza::Lavoro* l ) {
    experiences->removeExperience( l );
}

QVector<Esperienza::Lavoro*> Utente::getExperiencesList() const {
    return experiences->getExperiencesList();
}

// OPERATOR () Utente
void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {}

// OPERATOR << Utente
QDebug operator <<( QDebug qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***" << "\n";
    qdbg << "USERNAME: " << u.getUsername() << "\n";
    qdbg << "PROFILO:" << "\n";
    qdbg << " Nome: " << u.getName() << "\n";
    qdbg << " Cognome: " << u.getSurname() << "\n";
    qdbg << " Data di nascita: " << u.getBirthday().toString( "dd/MM/yyyy" ) << "\n";
    qdbg << " Stato civile: " << u.getMaritialStatus() << "\n";
    qdbg << "CONTATTI: " << "\n";
    QVector<SmartUtente> c = u.getContactsList();
    if( c.size() == 0 )
        qdbg << " ** Nessun contatto! **" << "\n";
    else {
        for( int i = 0; i < c.size(); i++ )
            qdbg << " " << c[i]->getUsername() << "\n";
    }
    qdbg << "FORMAZIONE: " << "\n";
    QVector<Formazione::Titolo*> ed = u.getTitlesList();
    if( ed.size() == 0 )
        qdbg << " ** Nessun titolo di studio! **" << "\n";
    else {
        for( int i = 0; i < ed.size(); i++ ) {
            qdbg << " Scuola: " << ed[i]->getSchool() << "\n";
            qdbg << " Data diploma: " << ed[i]->getDateAttended().toString( "yyyy" ) << "\n";
            qdbg << " Laurea: " << ed[i]->getDegree() << "\n";
            qdbg << " Campo di studio: " << ed[i]->getFieldOfStudy() << "\n";
            qdbg << " Votazione: " << ed[i]->getGrade() << "\n";
        }
    }
    qdbg << "ESPERIENZE: " << "\n";
    QVector<Esperienza::Lavoro*> ex = u.getExperiencesList();
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
    return qdbg;
}
