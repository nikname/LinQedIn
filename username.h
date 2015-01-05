#ifndef USERNAME_H
#define USERNAME_H
#include <QDebug>
#include <QString>

class Username {
private:
    QString login;
public:
    /** Costruttore ad 1 parametro.
     *  È richiesta una email da utilizzare come login.
     *  Costruttore di default non disponibile.
     *
     * @param QString l  Login dell'utente.
     */
    Username( const QString& l = "" ) : login( l ) {}

    /** Ritorna la login associata all'utente.
     *
     * @return QString  Login associata all'utente.
     */
    QString getLogin() const;

    /** Modifica la login associata all'utente.
     *
     * @param QString  Login associata all'utente.
     */
    void changeLogin( QString );
};

/** Overloading dell'operatore di output di QDebug.
 *  Mostra sullo standard output le informazioni collegate all'username.
 *
 * @param QDebug  QDebug.
 * @param Username  Username dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Username& );

#endif
