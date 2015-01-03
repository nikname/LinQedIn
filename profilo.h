#ifndef PROFILO_H
#define PROFILO_H
#include <QDebug>
#include <QString>
#include <QDate>

class Profilo {
private:
    class InfoPersonali;
    InfoPersonali* personalInfo;
public:
    /** Costruttore a 4 parametro con 4 parametri di default.
     *
     * @param QString  Nome dell'utente.
     * @param QString  Cognome dell'utente.
     * @param QDate()  Data di nascita dell'utente.
     * @param QString  Stato civile dell'utente.
     */
    Profilo( const QString& = "",
             const QString& = "",
             const QDate& = QDate(),
             const QString& = "" );

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
    void setName( QString );

    /** Modifica il cognome dell'utente.
     *
     * @param QString  Cognome dell'utente.
     */
    void setSurname( QString );

    /** Modifica la data di nascita dell'utente.
     *
     * @param QDate  Data di nascita dell'utente.
     */
    void setBirthday( QDate );

    /** Modifica lo stato civile dell'utente.
     *
     * @param QString  Stato civile dell'utente.
     */
    void setMaritialStatus( QString );

    friend QDebug operator <<( QDebug, const Profilo& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni associate al profilo.
 *
 * @param QDebug  QDebug.
 * @param Profilo  Profilo dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Profilo& );

#endif
