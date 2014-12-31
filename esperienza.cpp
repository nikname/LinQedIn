#include "esperienza.h"

QString Esperienza::getCompanyName() const {
    return companyName;
}

QString Esperienza::getTitle() const {
    return title;
}

QString Esperienza::getLocation() const {
    return location;
}

QString Esperienza::getPeriod() const {
    // Da valutare QDate::getDate( int* year, int* month, int* day )
    QString out( begin.toString( "dd.MM.yyyy" ) + " - " + end.toString( "dd.MM.yyyy" ) );
    return out;
}

QString Esperienza::getDescription() const {
    return description;
}

QDebug& operator <<( QDebug& qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE:\n"
        << "Azienda: " << e.getCompanyName() << "\n"
        << "Ruolo: " << e.getTitle() << "\n"
        << "Luogo: " << e.getLocation() << "\n"
        << "Periodo: " << e.getPeriod() << "\n"
        << "Descrizione: " << e.getDescription() << "\n";
    return qdbg;
}


