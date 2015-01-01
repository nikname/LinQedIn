#include "esperienza.h"
#include <QList>

QString Esperienza::Lavoro::getCompanyName() const {
    return companyName;
}

QString Esperienza::Lavoro::getTitle() const {
    return title;
}

QString Esperienza::Lavoro::getLocation() const {
    return location;
}

QString Esperienza::Lavoro::getPeriod() const {
    // Da valutare QDate::getDate( int* year, int* month, int* day )
    QString out( begin.toString( "dd.MM.yyyy" ) + " - " + end.toString( "dd.MM.yyyy" ) );
    return out;
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
    qdbg << "ESPERIENZE:\n"
         << "Azienda: " << l.getCompanyName() << "\n"
         << "Ruolo: " << l.getTitle() << "\n"
         << "Luogo: " << l.getLocation() << "\n"
         << "Periodo: " << l.getPeriod() << "\n";
    return qdbg;
}

class Esperienza::EspLavorative {
public:
    QList<Lavoro> experiencesList;
};

Esperienza::Esperienza() : expiriences( new EspLavorative ) {}

void Esperienza::addExperience( const Lavoro& l ) {
    expiriences->experiencesList.append( l );
}

void Esperienza::removeExperience( const Lavoro& l ) {
    expiriences->experiencesList.removeAll( l );
}

/** Overloading dell'operatore di uguaglianza tra Esperienza::Lavoro.
 *  Necessario per QList::removeAll( const Lavoro& ) in
 *  void Esperienza::removeExperience( const Lavoro& ).
 *
 * @param Esperienza::Lavoro l1  Lavoro.
 * @param Esperienza::Lavoro l2  Lavoro.
 * @return bool  true se i due oggetti di tipo Lavoro coincidono; false altrimenti.
 */
bool operator ==( const Esperienza::Lavoro& l1, const Esperienza::Lavoro& l2 ) {
    return ( l1.getCompanyName() == l2.getCompanyName() ) &&
           ( l1.getLocation() == l2.getLocation() ) &&
           ( l1.getPeriod() == l2.getPeriod() ) &&
           ( l1.getTitle() == l2.getTitle() );
}

QDebug operator <<( QDebug qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE:\n";
    QListIterator<Esperienza::Lavoro> it( e.expiriences->experiencesList );
    while( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}


