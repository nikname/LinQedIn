#ifndef PROFILO_H
#define PROFILO_H
#include <string>
#include "info.h"

class Profilo {
private:
    Info* info;
public:
    /** Costruttore di default. Associa al profilo dei campi informazione vuoti. */
    Profilo() : info( new Info() ) {}
    /** Costruttore ad 1 parametro.
     *
     * @param Info  Informazioni del profilo dell'utente.
     */
    Profilo( Info* i ) : info( i ) {}
    /** Modifica le informazioni del profilo. */
    void setInfo( Info* i ) {
        //TODO: ridefinizione di operator= (?)
        info->setName( i->getName() );
        info->setSurname( i->getSurname() );
        info->setBirthday( i->getBirthday() );
        info->setMaritialStatus( i->getMaritialStatus() );
    }
    /** Ritorna le informazioni associate al profilo dell'utente.
     *
     * @return Info*  Le informazioni del profilo associato all'utente.
     */
    Info* getInfo() const {
        return info;
    }
};

#endif
