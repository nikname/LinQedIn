#include "profilo.h"

class Profilo::InfoPersonali {
public:
    QString name;
    QString surname;
    QDate birthday;
    QString maritialStatus;

    /** Costruttore a 4 parametri con 4 parametri di default.
     *
     * @param QString name  Nome dell'utente.
     * @param QString surname  Cognome dell'utente.
     * @param QDate  birthday  Data di nascita dell'utente.
     * @param QString maritialStatus  Stato civile dell'utente.
     */
    InfoPersonali( const QString& nome = "",
                   const QString& cognome = "",
                   const QDate& compleanno = QDate(),
                   const QString& statoCivile = "" ) :
        name( nome ),
        surname( cognome ),
        birthday( compleanno ),
        maritialStatus( statoCivile ) {}

    /** Costruttore ad 1 parametro.
     *  Inizializza i campi dati di personalInfo a partire da un'oggetto di tipo InfoPersonali.
     *
     * @param InfoPersonali*  Puntatore all'oggetto di tipo InfoPersonali da copiare.
     */
    InfoPersonali( InfoPersonali* pi ) :
        name( pi->name ),
        surname( pi->surname ),
        birthday( pi->birthday ),
        maritialStatus( pi->maritialStatus ) {}
};

Profilo::Profilo( const QString& nome,
                  const QString& cognome,
                  const QDate& compleanno,
                  const QString& statoCivile ) :
    personalInfo( new InfoPersonali( nome, cognome, compleanno, statoCivile ) ) {}

Profilo::~Profilo() {
    if( personalInfo )
        delete personalInfo;
}

Profilo::Profilo( const Profilo& p ) :
    personalInfo( new InfoPersonali( p.personalInfo ) ) {}

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

Profilo& Profilo::operator =( const Profilo& p ) {
    if( this != &p ) {
        personalInfo->name = p.getName();
        personalInfo->surname = p.getSurname();
        personalInfo->birthday = p.getBirthday();
        personalInfo->maritialStatus = p.getMaritialStatus();
    }
    return *this;
}

QDebug operator <<( QDebug qdbg, const Profilo& p ) {
    qdbg << "UTENTE: " << p.personalInfo->name + " " + p.personalInfo->surname << "\n"
         << "DATA NASCITA: " << p.personalInfo->birthday.toString( "dd/MM/yyyy" ) << "\n"
         << "STATO CIVILE: " << p.personalInfo->maritialStatus << "\n";
    return qdbg;
}
