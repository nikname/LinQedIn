#ifndef PROFILO_H
#define PROFILO_H
#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::vector;

class Info; //Dichiarazione incompleta

class Profilo {
private:
    Info* info; //Information hiding!
public:
    /** Costruttore di default. Associa al profilo dei campi informazione vuoti. */
    Profilo();
    /** Costruttore ad 1 parametro.
     *
     * @param Info* i  Informazioni del profilo dell'utente.
     */
    Profilo( Info* );
    /** Modifica le informazioni del profilo. */
    void setInfo( Info* );
    /** Ritorna le informazioni associate al profilo dell'utente.
     *
     * @return Info*  Le informazioni del profilo associato all'utente.
     */
    Info* getInfo() const;
};

ostream& operator<< ( ostream&, Profilo );

#endif
