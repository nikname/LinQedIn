#include "lavoro.h"

// METODO getCompanyName Lavoro
QString Lavoro::getCompanyName() const {
    return companyName;
}

// METODO getTitle Lavoro
QString Lavoro::getTitle() const {
    return title;
}

// METODO getLocation Lavoro
QString Lavoro::getLocation() const {
    return location;
}

// METODO getBegin Lavoro
QDate Lavoro::getBegin() const {
    return begin;
}

// METODO getEnd Lavoro
QDate Lavoro::getEnd() const {
    return end;
}

// METODO setCompanyName Lavoro
void Lavoro::setCompanyName( QString azienda ) {
    companyName = azienda;
}

// METODO setTitle Lavoro
void Lavoro::setTitle( QString ruolo ) {
    title = ruolo;
}

// METODO setLocation Lavoro
void Lavoro::setLocation( QString posizione ) {
    location = posizione;
}

// METODO setBegin Lavoro
void Lavoro::setBegin( QDate inizio ) {
    begin = inizio;
}

// METODO setEnd Lavoro
void Lavoro::setEnd( QDate fine ) {
    end = fine;
}

// OPERATOR == Lavoro
bool Lavoro::operator ==( const Lavoro& l ) {
    return ( getCompanyName() == l.getCompanyName() ) &&
        ( getLocation() == l.getLocation() ) &&
        ( getBegin() == l.getBegin() ) &&
        ( getEnd() == l.getEnd() ) &&
        ( getTitle() == l.getTitle() );
}

// OPERATOR << Lavoro
QDebug operator <<( QDebug qdbg, const Lavoro& l ) {
    qdbg << "Azienda: " << l.getCompanyName() << "\n"
         << "Ruolo: " << l.getTitle() << "\n"
         << "Luogo: " << l.getLocation() << "\n"
         << "Inizio: " << l.getBegin() << "\n"
         << "Fine: " << l.getEnd() << "\n";
    return qdbg;
}
