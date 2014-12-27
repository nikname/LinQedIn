#ifndef USERNAME_H
#define USERNAME_H
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Username {
private:
    string login;
public:
    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param string  Login dell'utente.
     */
    Username( string );

    /** Ritorna la login associata all'utente.
     *
     * @return string  Login associata all'utente.
     */
    string getLogin() const;

    /** Modifica la login associata all'utente.
     *
     * @param string  Login associata all'utente.
     */
    void changeLogin( string );
};

/** Overloading dell'operatore di output.
 *  Mostra sullo standard output tutte le informazioni collegate all'username.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Username  Username del quale si stampano le informazioni.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator<< ( ostream&, Username );

#endif
