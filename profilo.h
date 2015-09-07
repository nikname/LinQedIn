#ifndef PROFILO_H
#define PROFILO_H
#include <QDate>
#include <QDebug>
#include <QString>

class Profilo {
private:
    class InfoPersonali;
    InfoPersonali* personalInfo;
public:
    /** Costruttore a 4 parametro con 4 parametri di default.
     *
     * @param QString  Nome dell'utente.
     * @param QString  Cognome dell'utente.
     * @param QDate  Data di nascita dell'utente.
     * @param QString  Stato civile dell'utente.
     */
    Profilo( const QString& = "",
             const QString& = "",
             const QDate& = QDate(),
             const QString& = "" );

    /** Distruttore di Profilo.
     *  Richiama il distruttore di InfoPersonali.
     */
    ~Profilo();

    /** Ridefinizione costruttore di copia.
     *  Esegue una copia profonda di personalInfo. Nessuna condivisione di memoria.
     *
     * @param Profilo  Oggetto della classe Profilo dal quale creare il nuovo oggetto.
     */
    Profilo( const Profilo& );

    /** Ritorna il nome dell'utente.
     *
     * @return QString  Nome dell'utente.
     */
    QString getName() const;

    /** Ritorna il cognome dell'utente.
     *
     * @return QString  Cognome dell'utente.
     */
    QString getSurname() const;

    /** Ritorna la data di nascita dell'utente.
     *
     * @return QDate  Data di nascita dell'utente.
     */
    QDate getBirthday() const;

    /** Ritorna lo stato civile dell'utente.
     *
     * @return QString  Stato civile dell'utente.
     */
    QString getMaritialStatus() const;

    /** Modifica il nome dell'utente.
     *
     * @param QString  Nome dell'utente.
     */
    void setName( const QString& );

    /** Modifica il cognome dell'utente.
     *
     * @param QString  Cognome dell'utente.
     */
    void setSurname( const QString& );

    /** Modifica la data di nascita dell'utente.
     *
     * @param QDate  Data di nascita dell'utente.
     */
    void setBirthday( const QDate& );

    /** Modifica lo stato civile dell'utente.
     *
     * @param QString  Stato civile dell'utente.
     */
    void setMaritialStatus( const QString& );

    /** Ridefinizione dell'operatore di assegnazione tra oggetti Profilo.
     *  Effettua una copia profonda.
     *
     * @param Profilo  Oggetto di tipo Profilo dal quale ne verrà creato uno nuovo.
     * @return Profilo  Oggetto Profilo creato ritornato per riferimento.
     */
    Profilo& operator =( const Profilo& );

    friend QDebug& operator <<( QDebug&, const Profilo& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni del profilo.
 *
 * @param QDebug  QDebug.
 * @param Profilo  Profilo dell'utente.
 * @return QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Profilo& );

#endif
