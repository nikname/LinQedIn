#ifndef UTENTE_GRATIS_H
#define UTENTE_GRATIS_H
#include "utente.h"

class UtenteGratis : public Utente {
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtenteGratis( const QString& un = "",
                  const QString& name = "",
                  const QString& surname = "" )
        : Utente( un, name, surname ) {}

    /** Costruttore di copia ridefinito.
     *  Invoca il costruttore di copia della classe base.
     *
     * @param Utente  Riferimento polimorfo all'oggetto utente da creare di copia.
     */
    UtenteGratis( const Utente& );

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtenteGratis() = 0;
};

#endif
