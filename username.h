#ifndef USERNAME_H
#define USERNAME_H
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Username {
private:
    string login;
    string email;
public:
    /** Costruttore ad 2 parametri con 1 parametro di default.
     *  Costruttore di default non disponibile.
     *
     * @param string l  Login dell'utente.
     * @param string e  Email dell'utente.
     */
    Username( string l, string e = "" ) : login( l ), email( e ) {}

    /** Ritorna la login associata all'utente.
     *
     * @return string  Login associata all'utente.
     */
    string getLogin() const {
        return login;
    }

    /** Ritorna l'email associata all'utente.
     *
     * @return string  Email associata all'utente.
     */
    string getEmail() const {
        return email;
    }

    /** Modifica l'email associata all'utente.
     *
     * @param string e  Email associata all'utente.
     */
    void setEmail( string e ) {
        email = e;
    }
};

/** Overloading dell'operatore di output.
 *  Mostra sullo standard output tutte le informazioni collegate all'username.
 *
 * @param ostream& os  ostream passato per riferimento.
 * @param Username un  Username del quale si stampano le informazioni.
 * @return ostream&  ostream passato per riferimento.
 */
ostream& operator<< ( ostream& os, Username un ) {
    return os << "LOGIN: " << un.getLogin() << "\nEMAIL: " << un.getEmail();
}

#endif
