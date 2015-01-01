#include "esperienza.h"
#include <QList>

class Lavoro {
public:
    QString companyName;
    QString title;
    QString location;
    QDate begin;
    QDate end;

    /** Costruttore a 5 parametri.
     *  Costruttore di default non disponibile.
     *
     * @param QString azienda  Nome dell'azienda.
     * @param QString qualifica  Ruolo o posizione all'interno dell'azienda.
     * @param QString posizione  Luogo in cui si trova l'azienda.
     * @param QDate inizio  Data di inizio di tale occupazione.
     * @param QDate fine  Data di fine di tale occupazione.
     */
    Lavoro( QString azienda,
            QString qualifica,
            QString posizione,
            QDate inizio,
            QDate fine ) :
        companyName( azienda ),
        title( qualifica ),
        location( posizione ),
        begin( inizio ),
        end( fine ) {}
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate ad una esperienza lavorativa.
 *
 * @param QDebug  QDebug.
 * @param Lavoro  Esperienza lavorativa.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug qdbg, const Lavoro& l ) {
    qdbg << "ESPERIENZE:\n"
         << "Azienda: " << l.companyName << "\n"
         << "Ruolo: " << l.title << "\n"
         << "Luogo: " << l.location << "\n"
         << "Periodo: " << l.begin.toString( "DD.MM.yyyy")
                           + " - " +
                           l.end.toString( "DD.MM.yyyy" ) << "\n";
    return qdbg;
}

class Esperienza::EspLavorative {
public:
    QList<Lavoro> experiencesList;
};

Esperienza::Esperienza() : expiriences( new EspLavorative ) {}

QDebug operator <<( QDebug qdbg, const Esperienza& e ) {
    qdbg << "ESPERIENZE:\n";
    QListIterator<Lavoro> it( e.expiriences->experiencesList );
    while( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}


