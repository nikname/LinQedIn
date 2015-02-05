#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente_gratis.h"

class UtenteBasic : public UtenteGratis {
    // Classe concreta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente basic.
     * @param Profilo p  Profilo dell'utente basic.
     */
    UtenteBasic( const QString& un = "",
                 const Profilo& p = Profilo() )
        : UtenteGratis( un, p ) {}

    /** Ricerca polimorfa virtuale.
     *  Esegue la ricerca degli utenti nel database per utenti di tipo basic.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteBasic() {}
};

#endif
