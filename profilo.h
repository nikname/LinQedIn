#ifndef PROFILO_H
#define PROFILO_H
#include <string>
#include "info.h"

class Profilo {
private:
    Info info;
public:
    /** Costruttore ad 1 parametro. Costruttore di default non disponibile.
     *
     * @param Info  Informazioni del profilo dell'utente.
     */
    Profilo( Info i ) : info( i ) {}
    /** Modifica le informazioni del profilo. */
    void modifyProfile();
    /** Ritorna le informazioni associate al profilo dell'utente.
     *
     * @return Info*  Le informazioni del profilo associato all'utente.
     */
    Info* getProfile() const;
};

#endif
