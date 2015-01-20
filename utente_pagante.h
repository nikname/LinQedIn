#ifndef UTENTE_PAGANTE_H
#define UTENTE_PAGANTE_H
#include "utente.h"

class UtentePagante : public Utente {
    // Classe astratta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri dalla classe base diretta.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtentePagante( const Username& un = Username(),
                   const Profilo& p = Profilo() )
        : Utente( un, p ) {}

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtentePagante() = 0;
};

#endif
