#include "lavoro.h"

// METODO Lavoro::getCompanyName
QString Lavoro::getCompanyName() const {
    return companyName;
}

// METODO Lavoro::getTitle
QString Lavoro::getTitle() const {
    return title;
}

// METODO Lavoro::getBegin
QDate Lavoro::getBegin() const {
    return begin;
}

// METODO Lavoro::getEnd
QDate Lavoro::getEnd() const {
    return end;
}

// METODO Lavoro::setCompanyName( QString )
void Lavoro::setCompanyName( const QString& cn ) {
    companyName = cn;
}

// METODO Lavoro::setTitle( QString )
void Lavoro::setTitle( const QString& t ) {
    title = t;
}

// METODO Lavoro::setBegin( QDate )
void Lavoro::setBegin( const QDate& b ) {
    begin = b;
}

// METODO Lavoro::setEnd( QDate )
void Lavoro::setEnd( const QDate& e ) {
    end = e;
}

// OPERATORE uguaglianza Lavoro
bool Lavoro::operator ==( const Lavoro& l ) {
    return ( getCompanyName() == l.getCompanyName() ) &&
        ( getBegin() == l.getBegin() ) &&
        ( getEnd() == l.getEnd() ) &&
        ( getTitle() == l.getTitle() );
}

// OVERLOADING
QDebug& operator <<( QDebug&qdbg, const Lavoro& l ) {
    qdbg << "Azienda: " << l.getCompanyName() << "\n"
         << "Ruolo: " << l.getTitle() << "\n"
         << "Inizio: " << l.getBegin() << "\n"
         << "Fine: " << l.getEnd() << "\n";
    return qdbg;
}
