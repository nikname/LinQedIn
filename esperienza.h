#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDebug>
#include <QString>
#include <QDate>

class Esperienza {
private:
    class EspLavorative;
    EspLavorative* expiriences;
public:
    class Lavoro {
    private:
        QString companyName;
        QString title;
        QString location;
        QDate begin;
        QDate end;
    public:
        /** Costruttore a 5 parametri con parametri di default.
         *
         * @param QString azienda  Nome dell'azienda.
         * @param QString ruolo  Ruolo o posizione all'interno dell'azienda.
         * @param QString posizione  Luogo in cui si trova l'azienda.
         * @param QDate inizio  Data di inizio di tale occupazione.
         * @param QDate fine  Data di fine di tale occupazione.
         */
        Lavoro( const QString& azienda = "",
                const QString& ruolo = "",
                const QString& posizione = "",
                const QDate& inizio = QDate(),
                const QDate& fine = QDate() ) :
            companyName( azienda ),
            title( ruolo ),
            location( posizione ),
            begin( inizio ),
            end( fine ) {}

        /** Ritorna il nome dell'azienda.
         *
         * @return QString  Nome dell'azienda.
         */
        QString getCompanyName() const;

        /** Ritorna il ruolo o posizione all'interno dell'azienda.
         *
         * @param QString  Ruolo o posizione all'interno dell'azienda.
         */
        QString getTitle() const;

        /** Ritorna il luogo in cui si trova l'azienda.
         *
         * @return QString  Luogo in cui si trova l'azienda.
         */
        QString getLocation() const;

        /** Ritorna la data nella quale l'utente ha iniziato l'esperienza lavorativa.
         *
         * @return QDate  Data nella quale l'utente ha iniziato l'esperienza lavorativa.
         */
        QDate getBegin() const;

        /** Ritorna la data nella quale l'utente ha terminato l'esperienza lavorativa.
         *
         * @return QDate  Data nellq quale l'utente ha terminato l'esperienza lavorativa.
         */
        QDate getEnd() const;

        /** Modifica il nome dell'azienda.
         *
         * @param QString  Nome dell'azienda.
         */
        void setCompanyName( QString );

        /** Imposta il ruolo o posizione all'interno dell'azienda.
         *
         * @param QString  Ruolo o posizione all'interno dell'azienda.
         */
        void setTitle( QString );

        /** Imposta il luogo nel quale si trova l'azienda.
         *
         * @param QString  Luogo nel quale si trova l'azienda.
         */
        void setLocation( QString );

        /** Imposta la data di inizio di tale occupazione.
         *
         * @param QDate  Data di inizio di tale occupazione.
         */
        void setBegin( QDate );

        /** Imposta la data di fine di tale occupazione.
         *
         * @param QDate  Data di fine di tale occupazione.
         */
        void setEnd( QDate );
    };

    /** Costruttore di default ridefinito. */
    Esperienza();

    /** Ritorna l'esperienza dell'utente in base all'indice.
     *
     * @param int  Indice dell'esperienza dell'utente richiesta.
     * @return Lavoro  Esperienza della lista delle esperienze dell'utente.
     */
    Lavoro getJobByIndex( int ) const;

    /** Ritorna il numero di esperienze dell'utente.
     *
     * @return int  Numero delle esperienze dell'utente.
     */
    int experiencesNumber() const;

    /** Aggiunge un'esperienza alle esperienze lavorative.
     *
     * @param Lavoro  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( const Lavoro& );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *
     * @param Lavoro*  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( const Lavoro& );

    friend QDebug operator <<( QDebug, const Esperienza& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate ad una esperienza lavorativa.
 *
 * @param QDebug  QDebug.
 * @param Esperienza::Lavoro  Esperienza lavorativa.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Esperienza::Lavoro& );

/** Overloading dell'operatore di uguaglianza di Lavoro.
 *  Confronta due oggetti della classe Lavoro.
 *
 * @param Esperienza::Lavoro  Oggetto di tipo Lavoro da confrontare.
 * @param Esperienza::Lavoro  Oggetto di tipo Lavoro da confrontare.
 * @return bool  true se i due oggetti sono uguali; false altrimenti.
 */
bool operator ==( const Esperienza::Lavoro&, const Esperienza::Lavoro& );

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte esperienza lavorative dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Esperienza  Esperienze lavorative.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Esperienza& );

#endif // ESPERIENZA_H
