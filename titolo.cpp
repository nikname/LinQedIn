#include "titolo.h"

// METODO getSchool Titolo
QString Titolo::getSchool() const {
    return school;
}

// METODO getDateAttended Titolo
QDate Titolo::getDateAttended() const {
    return dateAttended;
}

// METODO getDegree Titolo
QString Titolo::getDegree() const {
    return degree;
}

// METODO getFieldOfStudy Titolo
QString Titolo::getFieldOfStudy() const {
    return fieldOfStudy;
}

// METODO getGrade Titolo
QString Titolo::getGrade() const {
    return grade;
}

// METODO setSchool Titolo
void Titolo::setSchool( QString scuola ) {
    school = scuola;
}

// METODO setDateAttended Titolo
void Titolo::setDateAttended( QDate dataDiploma ) {
    dateAttended = dataDiploma;
}

// METODO setDegree Titolo
void Titolo::setDegree( QString laurea ) {
    degree = laurea;
}

// METODO setFieldOfStudy Titolo
void Titolo::setFieldOfStudy( QString campoDiStudio ) {
    fieldOfStudy = campoDiStudio;
}

// METODO setGrade Titolo
void Titolo::setGrade( QString valutazione ) {
    grade = valutazione;
}

// OPERATOR == Titolo
bool Titolo::operator ==( const Titolo& t ) {
    return ( getSchool() == t.getSchool() ) &&
        ( getDateAttended() == t.getDateAttended() ) &&
        ( getDegree() == t.getDegree() ) &&
        ( getFieldOfStudy() == t.getFieldOfStudy() ) &&
        ( getGrade() == t.getGrade() );
}

// OPERATOR << Titolo
QDebug operator <<( QDebug qdbg, const Titolo& t ) {
    qdbg << "Scuola: " << t.getSchool() << "\n"
         << "Data diploma: " << t.getDateAttended().toString( "yyyy" ) << "\n"
         << "Laurea: " << t.getDegree() << "\n"
         << "Campo di studio: " << t.getFieldOfStudy() << "\n"
         << "Votazione: " << t.getGrade() << "\n";
    return qdbg;
}
