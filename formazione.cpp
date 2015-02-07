#include "formazione.h"
#include <QList>
#include <QListIterator>

// CLASSE Formazione_rapp
class Formazione::Formazione_rapp {
public:
    QList<Formazione::Titolo> titlesList;

    /** Costruttore di default rifefinito. */
    Formazione_rapp() :
        titlesList( new QList<Formazione::Titolo>() ) {}

    /** Distruttore Formazione_rapp.
     *  Invoca il metodo clear() sulla lista dei titoli di studio dell'utente.
     */
    void operator delete() {
        titlesList.clear();
    }
};

// COSTRUTTORE Formazione
Formazione::Formazione() :
    titles( new Formazione_rapp ),
    user_ref( 1 ) {}

// METODO getSchool Titolo
QString Formazione::Titolo::getSchool() const {
    return school;
}

// METODO getDateAttended Titolo
QDate Formazione::Titolo::getDateAttended() const {
    return dateAttended;
}

// METODO getDegree Titolo
QString Formazione::Titolo::getDegree() const {
    return degree;
}

// METODO getFieldOfStudy Titolo
QString Formazione::Titolo::getFieldOfStudy() const {
    return fieldOfStudy;
}

// METODO getGrade Titolo
QString Formazione::Titolo::getGrade() const {
    return grade;
}

// METODO setSchool Titolo
void Formazione::Titolo::setSchool( QString scuola ) {
    school = scuola;
}

// METODO setDateAttended Titolo
void Formazione::Titolo::setDateAttended( QDate dataDiploma ) {
    dateAttended = dataDiploma;
}

// METODO setDegree Titolo
void Formazione::Titolo::setDegree( QString laurea ) {
    degree = laurea;
}

// METODO setFieldOfStudy Titolo
void Formazione::Titolo::setFieldOfStudy( QString campoDiStudio ) {
    fieldOfStudy = campoDiStudio;
}

// METODO setGrade Titolo
void Formazione::Titolo::setGrade( QString valutazione ) {
    grade = valutazione;
}

// OPERATOR == Titolo
bool Formazione::Titolo::operator ==( const Formazione::Titolo& t ) {
    return ( getSchool() == t.getSchool() ) &&
        ( getDateAttended() == t.getDateAttended() ) &&
        ( getDegree() == t.getDegree() ) &&
        ( getFieldOfStudy() == t.getFieldOfStudy() ) &&
        ( getGrade() == t.getGrade() );
}

// COSTRUTTORE Iteratore
Formazione::Iteratore::Iteratore() : punt( begin() ) {}

// OPERATOR == Iteratore
bool Formazione::Iteratore::operator ==( Iteratore it ) const {
    return punt == it.punt;
}

// OPERATOR == Iteratore
bool Formazione::Iteratore::operator !=( Iteratore it ) const {
    return punt != it.punt;
}

Formazione::Iteratore Formazione::Iteratore::operator ++() {

}

// METODO addEducation Formazione
void Formazione::addEducation( const Titolo& t ) {
    titles->titlesList.append( t );
}

// METODO removeEducation Formazione
void Formazione::removeEducation( Titolo t ) {
    titles->titlesList.removeOne( t );
}

// OPERATOR delete Formazione
void Formazione::operator delete() {
    user_ref--;
    if( user_ref == 0 )
        delete titles;
}

// OPERATOR << Titolo
QDebug operator <<( QDebug qdbg, const Formazione::Titolo& t ) {
    qdbg << "Scuola: " << t.getSchool() << "\n"
         << "Data diploma: " << t.getDateAttended().toString( "yyyy" ) << "\n"
         << "Laurea: " << t.getDegree() << "\n"
         << "Campo di studio: " << t.getFieldOfStudy() << "\n"
         << "Votazione: " << t.getGrade() << "\n";
    return qdbg;
}

// OPERATOR << Formazione
QDebug operator <<( QDebug qdbg, const Formazione& f ) {
    qdbg << "TITOLI DI STUDIO:\n";
    QListIterator<Formazione::Titolo> it( f.titles->titlesList );
    while ( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}
