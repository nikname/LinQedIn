#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDebug>
#include <QString>
#include <QDate>

class Esperienza {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Esperienza.
    // Poichè un oggetto di tipo Esperienza può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.

    friend class Utente; // Necessario per costruire e distruggere oggetti Esperienza
private:
    class Esperienza_rapp;
    Esperienza_rapp* experiences;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Esperienza.

    /** Costruttore di default ridefinito. */
    Esperienza();
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

        /** Overloading dell'operatore di uguaglianza di Lavoro.
         *  Confronta l'oggetto di invocazione con un oggetto della classe Lavoro.
         *
         * @param Esperienza::Lavoro  Oggetto di tipo Lavoro da confrontare.
         * @return bool  true se i due oggetti sono uguali; false altrimenti.
         */
        bool operator ==( const Esperienza::Lavoro& );
    };

    /** Aggiunge un'esperienza alle esperienze lavorative.
     *
     * @param Lavoro  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( const Lavoro& );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *
     * @param Lavoro  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( const Lavoro& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<Lavoro*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Lavoro*> getExperiencesList() const;

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distuttore di Esperienza_rapp.
     */
    void operator delete( void* );

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

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte esperienza lavorative dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Esperienza  Esperienze lavorative.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Esperienza& );

#endif // ESPERIENZA_H
