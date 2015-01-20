#ifndef UTENTE_GRATIS_H
#define UTENTE_GRATIS_H
#include "utente.h"

class UtenteGratis : public Utente {
    // Classe astratta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri della classe base diretta.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtenteGratis( const Username& un = Username(),
                  const Profilo& p = Profilo() )
        : Utente( un, p ) {}

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtenteGratis() = 0;
};

#endif
