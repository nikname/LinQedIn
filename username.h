#ifndef USERNAME_H
#define USERNAME_H
#include <iostream>
#include <QString>

using std::ostream;

class Username {
private:
    QString login;
public:
    /** Costruttore ad 1 parametro.
     *  È richiesta una email da utilizzare come login.
     *  Costruttore di default non disponibile.
     *
     * @param QString  Login dell'utente.
     */
    Username( QString );

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

/** Overloading dell'operatore di output.
 *  Mostra sullo standard output le informazioni collegate all'username.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Username  Username dell'utente.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator<< ( ostream&, Username );

#endif
