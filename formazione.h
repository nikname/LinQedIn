#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>

class Formazione {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Formazione.
    // Poichè un oggetto di tipo Formazione può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.

    friend class Utente; // Necessario per costruire e distruggere oggetti Formazione
private:
    class Formazione_rapp;
    Formazione_rapp* titles;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Formazione.

    /** Costruttore privato di default.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     *  Viene invocato solo dal costruttore di Utente.
     */
    Formazione();
public:
    class Titolo {
    private:
        QString school;
        QDate dateAttended;
        QString degree;
        QString fieldOfStudy;
        QString grade;
    public:
        /** Costruttore a 5 parametri con 5 parametri di default.
         *
         * @param QString scuola  Nome della scuola, collegio, università.
         * @param QDate dataDiploma  Data del conseguimento del diploma.
         * @param QString laurea  Titolo della laurea.
         * @param QString corsoDiStudio  Nome del corso di studio.
         * @param QString votazione  Giudizio finale.
         */
        Titolo( const QString& scuola = "",
                const QDate& dataDiploma = QDate(),
                const QString& laurea = "",
                const QString& corsoDiStudio = "",
                const QString& votazione = "" ) :
            school( scuola ),
            dateAttended( dataDiploma ),
            degree( laurea ),
            fieldOfStudy( corsoDiStudio ),
            grade( votazione ) {}

        /** Ritorna il nome della scuola, collegio, università.
         *
         * @return QString  Nome della scuola, collegio, università.
         */
        QString getSchool() const;

        /** Ritorna la data del conseguimento del titolo di studio.
         *
         * @return QDate  Data del conseguimento del titolo di studio.
         */
        QDate getDateAttended() const;

        /** Ritorna il tipo di titolo di studio.
         *
         * @return QString  Tipo di titolo di studio.
         */
        QString getDegree() const;

        /** Ritorna il campo di studio.
         *
         * @return QString  Campo di studio.
         */
        QString getFieldOfStudy() const;

        /** Ritorna il giudizio finale.
         *
         * @return QString  Giudizio Finale.
         */
        QString getGrade() const;

        /** Modifica il nome della scuola, collegio, università.
         *
         * @param QString  Nome della scuola, collegio, università.
         */
        void setSchool( QString );

        /** Imposta la data del conseguimento del titolo di studio.
         *
         * @param QDate  Data del conseguimento del titolo di studio.
         */
        void setDateAttended( QDate );

        /** Imposta il tipo di titolo di studio.
         *
         * @param QString  Tipo del titolo di studio.
         */
        void setDegree( QString );

        /** Imposta il campo di studio.
         *
         * @param QString  Campo di studio.
         */
        void setFieldOfStudy( QString );

        /** Imposta il giudizio finale.
         *
         * @param QString  Giudizio finale.
         */
        void setGrade( QString );

        /** Overloading dell'operatore di uguaglianza di Titolo.
         *  Confronta l'oggetto di invocazione con un oggetto della classe Titolo.
         *
         * @param Formazione::Titolo  Oggetto Titolo da confrontare.
         * @return bool  true se i due oggetti sono uguali; false altrimenti.
         */
        bool operator ==( const Formazione::Titolo& );
    };

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *
     * @param Titolo  Titolo di studio da aggiungere.
     */
    void addEducation( const Titolo& );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *
     * @param Titolo  Titolo di studio da rimuovere.
     */
    void removeEducation( const Titolo& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<Titolo*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Titolo*> getTitlesList() const;

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distruttore di Formazione_rapp.
     */
    void operator delete( void* );

    friend QDebug operator <<( QDebug, const Formazione& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate al titolo di studio.
 *
 * @param QDebug  QDebug.
 * @param Formazione::Titolo  Titolo di studio.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Formazione::Titolo& );

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni di tutti i titoli di studio dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Formazione  Elenco dei titoli di studio dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Formazione& );

#endif // TITOLO_STUDIO_H
