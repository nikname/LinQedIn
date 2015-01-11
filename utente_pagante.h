#ifndef UTENTE_PAGANTE_H
#define UTENTE_PAGANTE_H
#include "utente.h"

class UtentePagante : public Utente {
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Richiama il costruttore dalla classe base diretta passando i 2 parametri.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtentePagante( const Username& un = Username(),
                   const Profilo& p = Profilo() )
        : Utente( un, p ) {}

    ~UtentePagante() = 0;
};

#endif
