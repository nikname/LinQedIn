#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente_gratis.h"

class UtenteBasic : public UtenteGratis {
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

    /** Ricerca polimorfa, virtuale pura.
     *  Esegue la ricerca degli utenti nel database per utenti basic.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    /** Definizione distruttore virtuale. */
    ~UtenteBasic() {}
};

#endif
