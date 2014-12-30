#include "profilo.h"

using std::ostream;

class Profilo::InfoPersonali {
public:
    QString name;
    QString surname;
    QDate birthday;
    QString maritialStatus;

    /** Costruttore a 4 parametri.
     *
     * @param QString name  Nome dell'utente.
     * @param QString surname  Cognome dell'utente.
     * @param QDate  birthday  Data di nascita dell'utente.
     * @param QString maritialStatus  Stato civile dell'utente.
     */
    InfoPersonali( const QString& nome,
                   const QString& cognome,
                   const QDate& compleanno,
                   const QString& statoCivile ) :
        name( nome ),
        surname( cognome ),
        birthday( compleanno ),
        maritialStatus( statoCivile ) {}
};

Profilo::Profilo( const QString& nome,
                  const QString& cognome,
                  const QDate& compleanno,
                  const QString& statoCivile ) :
    personalInfo( new InfoPersonali( nome, cognome, compleanno, statoCivile ) ) {}

QString Profilo::getName() const {
    return personalInfo->name;
}

QString Profilo::getSurname() const {
    return personalInfo->surname;
}

QDate Profilo::getBirthday() const {
    return personalInfo->birthday;
}

QString Profilo::getMaritialStatus() const {
    return personalInfo->maritialStatus;
}

void Profilo::setName( QString n ) {
    personalInfo->name = n;
}

void Profilo::setSurname( QString s ) {
    personalInfo->surname = s;
}

void Profilo::setBirthday( QDate b ) {
    personalInfo->birthday = b;
}

void Profilo::setMaritialStatus( QString ms ) {
    personalInfo->maritialStatus = ms;
}


ostream& operator <<( ostream& os, Profilo p ) {
    return os << "UTENTE: " << p.personalInfo->name << " "
                            << p.personalInfo->surname << "\n"
              << "DATA NASCITA: " << p.personalInfo->birthday << "\n"
              << "STATO CIVILE: " << p.personalInfo->maritialStatus;
}
