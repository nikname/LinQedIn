#ifndef UTENTE_GRATIS_H
#define UTENTE_GRATIS_H
#include "utente.h"

class UtenteGratis : public Utente {
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Richiama il costruttore della classe base diretta passando i 2 parametri.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtenteGratis( const Username& un = Username(),
                  const Profilo& p = Profilo() )
        : Utente( un, p ) {}

    ~UtenteGratis() = 0;
};

#endif
