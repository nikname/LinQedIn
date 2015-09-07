#include "titolo.h"

// METODO Titolo::getSchool
QString Titolo::getSchool() const {
    return school;
}

// METODO Titolo::getDateAttended
QDate Titolo::getDateAttended() const {
    return dateAttended;
}

// METODO Titolo::getFieldOfStudy
QString Titolo::getFieldOfStudy() const {
    return fieldOfStudy;
}

// METODO Titolo::setSchool( QString )
void Titolo::setSchool( const QString& s ) {
    school = s;
}

// METODO Titolo::setDateAttended( QString )
void Titolo::setDateAttended( const QDate& da ) {
    dateAttended = da;
}

// METODO Titolo::setFieldOfStudy( QString )
void Titolo::setFieldOfStudy( const QString& fos ) {
    fieldOfStudy = fos;
}

// OPERATOR == Titolo
bool Titolo::operator ==( const Titolo& t ) {
    return ( getSchool() == t.getSchool() ) &&
        ( getDateAttended() == t.getDateAttended() ) &&
        ( getFieldOfStudy() == t.getFieldOfStudy() );
}

// OVERLOADING
QDebug& operator <<( QDebug& qdbg, const Titolo& t ) {
    qdbg << "Scuola: " << t.getSchool() << "\n"
         << "Data diploma: " << t.getDateAttended().toString( "yyyy" ) << "\n"
         << "Campo di studio: " << t.getFieldOfStudy() << "\n";
    return qdbg;
}
