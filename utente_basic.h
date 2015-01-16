#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente_gratis.h"

class UtenteBasic : public UtenteGratis {
    // Viene ereditata la classe interna FuntoreRicerca.
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri della classe base diretta.
     *
     * @param Username un  Username dell'utente basic.
     * @param Profilo p  Profilo dell'utente basic.
     */
    UtenteBasic( const Username& un = Username(),
                 const Profilo& p = Profilo() )
        : UtenteGratis( un, p ) {}

    /** Ricerca polimorfa virtuale.
     *  Esegue la ricerca degli utenti nel database per utenti di tipo basic.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    /** Distruttore virtuale. */
    virtual ~UtenteBasic() {}
};

#endif
