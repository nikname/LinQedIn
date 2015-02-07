#ifndef UTENTE_GRATIS_H
#define UTENTE_GRATIS_H
#include "utente.h"

class UtenteGratis : public Utente {
    // Classe astratta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtenteGratis( const QString& un = "",
                  const QString& name = "",
                  const QString& surname = "" )
        : Utente( un, name, surname ) {}

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtenteGratis() = 0;
};

#endif
