#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>

class Formazione {
private:
    class TitoliStudio;
    TitoliStudio* titles;
public:
    class Titolo {
    private:
        QString school;
        QDate dateAttended;
        QString degree;
        QString fieldOfStudy;
        QString grade;
        QString activities;
    public:
        /** Costruttore a 6 parametri con parametri di default.
         *
         * @param QString scuola  Nome della scuola, collegio, università.
         * @param QDate dataDiploma  Data del conseguimento del diploma.
         * @param QString laurea  Titolo della laurea.
         * @param QString corsoDiStudio  Nome del corso di studio.
         * @param QString votazione  Giudizio finale.
         * @param QString attivita  Attività svolte con la scuola, collegio, università.
         */
        Titolo( const QString& scuola = "",
                const QDate& dataDiploma = QDate(),
                const QString& laurea = "",
                const QString& corsoDiStudio = "",
                const QString& votazione = "",
                const QString& attivita = "" ) :
            school( scuola ),
            dateAttended( dataDiploma ),
            degree( laurea ),
            fieldOfStudy( corsoDiStudio ),
            grade( votazione ),
            activities( attivita ) {}

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

        /** Ritorna le attività svolte nella scuola, collegio, università.
         *
         * @return QString  Attività svolte nella scuola, collegio, università.
         */
        QString getActivities() const;

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

        /** Imposta le attività svolte nella scuola, collegio, università.
         *
         * @param QString  Attività svolte nella scuola, collegio, università.
         */
        void setActivity( QString );
    };

    /** Costruttore di default ridefinito. */
    Formazione();

    /** Distruttore di Formazione.
     *  Invoca il distruttore di TitoliStudio.
     */
    ~Formazione();

    /** Ritorna il titolo di studio dell'utente in base all'indice.
     *
     * @param int  Indice del titolo di studio richiesto.
     * @return Titolo  Titolo della lista dei titoli di studio dell'utente.
     */
    Titolo getTitleByIndex( int ) const;

    /** Ritorna il numero di titoli di studio dell'utente.
     *
     * @return int  Numero di titoli di studio dell'utente.
     */
    int titlesNumber() const;

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *
     * @param Titolo  Titolo di studio da aggiungere.
     */
    void addEducation( const Titolo& );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *
     * @param Titolo  Titolo di studio da rimuovere.
     */
    void removeEducation( Titolo );

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

/** Overloading dell'operatore di uguaglianza di Titolo.
 *  Confronta due oggetti della classe Titolo.
 *
 * @param Formazione::Titolo  Oggetto Titolo da confrontare.
 * @param Formazione::Titolo  Oggetto Titolo da confrontare.
 * @return bool  true se i due oggetti sono uguali; false altrimenti.
 */
bool operator ==( const Formazione::Titolo&, const Formazione::Titolo& );

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni di tutti i titoli di studio dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Formazione  Elenco dei titoli di studio dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Formazione& );

#endif // TITOLO_STUDIO_H
