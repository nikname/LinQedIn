#include "profilo.h"

class Profilo::InfoPersonali {
public:
    QString name;
    QString surname;
    QDate birthday;
    QString maritialStatus;
    int references; // Numero riferimenti all'oggetto InfoPersonali.

    /** Costruttore a 4 parametri con 4 parametri di default.
     *  Inizializza il contatore di riferimenti a 0.
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
        maritialStatus( statoCivile ),
        references( 0 ) {}

    /** Overloading operatore di delete per InfoPersonali.
     *  Decrementa il contatore di riferimenti all'oggetto di tipo InfoPersonali.
     *  Nel caso references == 0 allora distrugge l'oggetto di tipo InfoPersonali.
     *
     * @param void*  Puntatore all'oggetto di tipo InfoPersonali da cancellare.
     */
    void operator delete( void* pi ) {
        if( pi ) {
            InfoPersonali* pi_aux = static_cast<InfoPersonali*>( pi );
            pi_aux->references--;
            if( pi_aux->references == 0 )
                ::delete pi_aux;
        }
    }
};

Profilo::Profilo( const QString& nome,
                  const QString& cognome,
                  const QDate& compleanno,
                  const QString& statoCivile ) :
    personalInfo( new InfoPersonali( nome, cognome, compleanno, statoCivile ) ) {
    // Aumenta il contatore di riferimenti all'oggetto InfoPersonali.
    // Poichè viene creato un nuovo oggetto InfoPersonali, equivale a fare references = 1.
    personalInfo->references++;
}

Profilo::~Profilo() {
    if( personalInfo )
        // Richiama la delete ridefinita di InfoPersonali.
        delete personalInfo;
}

Profilo::Profilo( const Profilo& p ) : personalInfo( p.personalInfo ) {
    // Memoria condivisa: aumenta il contatore di riferimenti all'oggetto InfoPersonali.
    personalInfo->references++;
}

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
        if( personalInfo )
            delete personalInfo;
        personalInfo = p.personalInfo;
        if( personalInfo)
            personalInfo->references++;
    }
    return *this;
}

QDebug operator <<( QDebug qdbg, const Profilo& p ) {
    qdbg << "UTENTE: " << p.personalInfo->name + " " + p.personalInfo->surname << "\n"
         << "DATA NASCITA: " << p.personalInfo->birthday.toString( "dd/MM/yyyy" ) << "\n"
         << "STATO CIVILE: " << p.personalInfo->maritialStatus << "\n";
    return qdbg;
}
