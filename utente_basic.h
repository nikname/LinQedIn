#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente_gratis.h"

class UtenteBasic : public UtenteGratis {
    // Classe concreta
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtenteBasic( const QString& un = "",
                 const QString& name = "",
                 const QString& surname = "" )
       : UtenteGratis( un, name, surname ) {}

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
