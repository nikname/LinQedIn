#include "profilo.h"

// CLASSE Profilo::InfoPersonali
class Profilo::InfoPersonali {
public:
    QString name;
    QString surname;
    QDate birthday;
    QString maritialStatus;

    /** Costruttore a 4 parametri con 4 parametri di default.
     *
     * @param QString  Nome dell'utente.
     * @param QString  Cognome dell'utente.
     * @param QDate  Data di nascita dell'utente.
     * @param QString  Stato civile dell'utente.
     */
    InfoPersonali( const QString& n = "",
                   const QString& s = "",
                   const QDate& b = QDate(),
                   const QString& ms = "" ) :
        name( n ),
        surname( s ),
        birthday( b ),
        maritialStatus( ms )
    {}

    /** Costruttore ad 1 parametro.
     *  Inizializza i campi dati di personalInfo a partire da un'oggetto di tipo InfoPersonali.
     *
     * @param InfoPersonali*  Puntatore all'oggetto di tipo InfoPersonali da copiare.
     */
    InfoPersonali( InfoPersonali* pi ) :
        name( pi->name ),
        surname( pi->surname ),
        birthday( pi->birthday ),
        maritialStatus( pi->maritialStatus )
    {}
};

// COSTRUTTORE Profilo( QString, QString, QDate, QString )
Profilo::Profilo( const QString& n, const QString& s, const QDate& b, const QString& ms ) :
    personalInfo( new InfoPersonali( n, s, b, ms ) )
{}

// DISTRUTTORE Profilo
Profilo::~Profilo() {
    if( personalInfo )
        delete personalInfo;
}

// COSTRTUTTORE di COPIA Profilo
Profilo::Profilo( const Profilo& p ) :
    personalInfo( new InfoPersonali( p.personalInfo ) )
{}

// METODO Profilo::getName
QString Profilo::getName() const {
    return personalInfo->name;
}

// METODO Profilo::getSurname
QString Profilo::getSurname() const {
    return personalInfo->surname;
}

// METODO Profilo::getBirtyday
QDate Profilo::getBirthday() const {
    return personalInfo->birthday;
}

// METODO Profilo::getMaritialStatus
QString Profilo::getMaritialStatus() const {
    return personalInfo->maritialStatus;
}

// METODO Profilo::setName( QString )
void Profilo::setName( const QString& n ) {
    personalInfo->name = n;
}

// METODO Profilo::setSurname( QString )
void Profilo::setSurname( const QString& s ) {
    personalInfo->surname = s;
}

// METODO Profilo::setBirthday( QDate )
void Profilo::setBirthday( const QDate& b ) {
    personalInfo->birthday = b;
}

// METODO Profilo::setMaritialStatus( QString )
void Profilo::setMaritialStatus( const QString& ms ) {
    personalInfo->maritialStatus = ms;
}

// OPERATORE di ASSEGNAZIONE Profilo
Profilo& Profilo::operator =( const Profilo& p ) {
    if( this != &p ) {
        personalInfo->name = p.getName();
        personalInfo->surname = p.getSurname();
        personalInfo->birthday = p.getBirthday();
        personalInfo->maritialStatus = p.getMaritialStatus();
    }
    return *this;
}

// OVERLOADING
QDebug& operator <<( QDebug& qdbg, const Profilo& p ) {
    qdbg << "UTENTE: " << p.personalInfo->name + " " + p.personalInfo->surname << "\n"
         << "DATA NASCITA: " << p.personalInfo->birthday.toString( "dd/MM/yyyy" ) << "\n"
         << "STATO CIVILE: " << p.personalInfo->maritialStatus << "\n";
    return qdbg;
}
