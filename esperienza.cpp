#include "esperienza.h"
#include <QList>
#include <QListIterator>

QString Esperienza::Lavoro::getCompanyName() const {
    return companyName;
}

QString Esperienza::Lavoro::getTitle() const {
    return title;
}

QString Esperienza::Lavoro::getLocation() const {
    return location;
}

QDate Esperienza::Lavoro::getBegin() const {
    return begin;
}

QDate Esperienza::Lavoro::getEnd() const {
    return end;
}

void Esperienza::Lavoro::setCompanyName( QString azienda ) {
    companyName = azienda;
}

void Esperienza::Lavoro::setTitle( QString ruolo ) {
    title = ruolo;
}

void Esperienza::Lavoro::setLocation( QString posizione ) {
    location = posizione;
}

void Esperienza::Lavoro::setBegin( QDate inizio ) {
    begin = inizio;
}

void Esperienza::Lavoro::setEnd( QDate fine ) {
    end = fine;
}

QDebug operator <<( QDebug qdbg, const Esperienza::Lavoro& l ) {
    qdbg << "Azienda: " << l.getCompanyName() << "\n"
         << "Ruolo: " << l.getTitle() << "\n"
         << "Luogo: " << l.getLocation() << "\n"
         << "Periodo: " << l.getBegin() << "-" << l.getEnd() << "\n";
    return qdbg;
}

bool operator ==( const Esperienza::Lavoro& l1, const Esperienza::Lavoro& l2 ) {
    return ( l1.getCompanyName() == l2.getCompanyName() ) &&
           ( l1.getLocation() == l2.getLocation() ) &&
           ( l1.getBegin() == l2.getBegin() ) &&
           ( l1.getEnd() == l2.getEnd() ) &&
           ( l1.getTitle() == l2.getTitle() );
}

class Esperienza::EspLavorative {
public:
    QList<Esperienza::Lavoro> experiencesList;
};

Esperienza::Esperienza() : experiences( new EspLavorative ) {}

Esperienza::~Esperienza() {
    delete experiences;
}

Esperienza::Lavoro Esperienza::getJobByIndex( int index ) const {
    QListIterator<Lavoro> it( experiences->experiencesList );
    Lavoro j;
    if( index > experiencesNumber() )
        qDebug() << "No experience found at index" << index << "!";
    else {
        while( it.hasNext() )
            j = it.next();
    }
    return j;
}

int Esperienza::experiencesNumber() const {
    return experiences->experiencesList.length();
}

void Esperienza::addExperience( const Lavoro& l ) {
    experiences->experiencesList.append( l );
}

void Esperienza::removeExperience( const Lavoro& l ) {
    experiences->experiencesList.removeAll( l );
}

QDebug operator <<( QDebug qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE:\n";
    QListIterator<Esperienza::Lavoro> it( e.experiences->experiencesList );
    while( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}


