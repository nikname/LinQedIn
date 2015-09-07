#ifndef TITOLO_H
#define TITOLO_H
#include <QDate>
#include <QDebug>
#include <QString>

class Titolo {
    friend class SmartTitolo;
private:
    QString school;
    QDate dateAttended;
    QString fieldOfStudy;
    int references;
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Inizializza il contatore di riferimenti ad 1.
     *
     * @param QString  Nome della scuola, collegio, università.
     * @param QDate  Data del conseguimento del diploma.
     * @param QString  Nome del corso di studio.
     */
    Titolo( const QString& s = "",
            const QDate& da = QDate(),
            const QString& fos = "" ) :
        school( s ),
        dateAttended( da ),
        fieldOfStudy( fos ),
        references( 1 )
    {}

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

    /** Ritorna il campo di studio.
     *
     * @return QString  Campo di studio.
     */
    QString getFieldOfStudy() const;

    /** Modifica il nome della scuola, collegio, università.
     *
     * @param QString  Nome della scuola, collegio, università.
     */
    void setSchool( const QString& );

    /** Imposta la data del conseguimento del titolo di studio.
     *
     * @param QDate  Data del conseguimento del titolo di studio.
     */
    void setDateAttended( const QDate& );

    /** Imposta il campo di studio.
     *
     * @param QString  Campo di studio.
     */
    void setFieldOfStudy( const QString& );

    /** Overloading dell'operatore di uguaglianza di Titolo.
     *  Confronta l'oggetto di invocazione con un oggetto della classe Titolo.
     *
     * @param Titolo  Oggetto Titolo da confrontare.
     * @return bool  true se i due oggetti sono uguali; false altrimenti.
     */
    bool operator ==( const Titolo& );

    friend QDebug& operator <<( QDebug&, const Titolo& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate al titolo di studio.
 *
 * @param QDebug  QDebug.
 * @param Titolo  Titolo di studio.
 * @param QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Titolo& );

#endif // TITOLO_H
