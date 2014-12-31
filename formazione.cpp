#include "formazione.h"
#include <QList>

class Titolo {
public:
    QString school;
    QDate dateAttended;
    QString degree;
    QString fieldOfStudy;
    QString grade;
    QString activities;

    /** Costruttore a 6 parametri con 5 parametri di default.
     *  Costruttore di default non disponibile.
     *
     * @param QString scuola  Nome della scuola, collegio, università.
     * @param QDate dataDiploma  Data del conseguimento del diploma.
     * @param QString laurea  Titolo della laurea.
     * @param QString corsoDiStudio  Nome del corso di studio.
     * @param QString votazione  Giudizio finale.
     * @param QString attivita  Attività svolte con la scuola, collegio, università.
     */
    Titolo( QString scuola,
            QDate dataDiploma,
            QString laurea,
            QString corsoDiStudio,
            QString votazione,
            QString attivita ) :
        school( scuola ),
        dateAttended( dataDiploma ),
        degree( laurea ),
        fieldOfStudy( corsoDiStudio ),
        grade( votazione ),
        activities( attivita ) {}
};

QDebug operator <<( QDebug qdbg, const Titolo& t ) {
    qdbg << "Scuola: " << t.school << "\n"
         << "Data diploma: " << t.dateAttended.toString( "yyyy" ) << "\n"
         << "Laurea: " << t.degree << "\n"
         << "Campo di studio: " << t.fieldOfStudy << "\n"
         << "Votazione: " << t.grade << "\n"
         << "Attività svolte: " << t.activities << "\n";
}

class Formazione::TitoliStudio {
    QList<Titolo> titlesList;
};

Formazione::Formazione() : titles( new TitoliStudio ) {}

QDebug operator <<( QDebug qdbg, const Formazione& f ) {
    qdbg << "TITOLI DI STUDIO:\n";
    //TODO: aggiungere il resto
    return qdbg;
}
