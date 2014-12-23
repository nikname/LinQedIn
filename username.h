#ifndef USERNAME_H
#define USERNAME_H
#include <string>

using std::string;

class Username {
public:
    string login;
    /** Costruttore ad 1 parametro. Costruttore di default non disponibile.
     *
     * @param string  Login dell'utente da creare.
     */
    Username( string l ) : login( l ) {}
};

#endif
