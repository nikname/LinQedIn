#ifndef LAVORO_H
#define LAVORO_H
#include <QDate>
#include <QDebug>
#include <QString>

class Lavoro {
    friend class SmartLavoro;
private:
    QString companyName;
    QString title;
    QDate begin;
    QDate end;
    int references;
public:
    /** Costruttore a 4 parametri con 4 parametri di default.
     *  Inizializza il contatore di riferimenti ad 1.
     *
     * @param QString  Nome dell'azienda.
     * @param QString  Ruolo o posizione all'interno dell'azienda.
     * @param QDate  Data di inizio di tale occupazione.
     * @param QDate  Data di fine di tale occupazione.
     */
    Lavoro( const QString& c = "",
            const QString& t = "",
            const QDate& b = QDate(),
            const QDate& e = QDate() ) :
        companyName( c ),
        title( t ),
        begin( b ),
        end( e ),
        references( 1 )
    {}

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
    void setCompanyName( const QString& );

    /** Imposta il ruolo o posizione all'interno dell'azienda.
     *
     * @param QString  Ruolo o posizione all'interno dell'azienda.
     */
    void setTitle( const QString& );

    /** Imposta la data di inizio di tale occupazione.
     *
     * @param QDate  Data di inizio di tale occupazione.
     */
    void setBegin( const QDate& );

    /** Imposta la data di fine di tale occupazione.
     *
     * @param QDate  Data di fine di tale occupazione.
     */
    void setEnd( const QDate& );

    /** Overloading dell'operatore di uguaglianza di Lavoro.
     *  Confronta l'oggetto di invocazione con un oggetto della classe Lavoro.
     *
     * @param Lavoro  Oggetto di tipo Lavoro da confrontare.
     * @return bool  true se i due oggetti sono uguali; false altrimenti.
     */
    bool operator ==( const Lavoro& );

    friend QDebug& operator <<( QDebug&, const Lavoro& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate ad una esperienza lavorativa.
 *
 * @param QDebug  QDebug.
 * @param Lavoro  Esperienza lavorativa.
 * @param QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Lavoro& );

#endif // LAVORO_H
