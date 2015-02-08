#ifndef UTENTE_PAGANTE_H
#define UTENTE_PAGANTE_H
#include "utente.h"

class UtentePagante : public Utente {
    // Classe astratta
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri dalla classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtentePagante( const QString& un = "",
                   const QString& name = "",
                   const QString& surname = "" )
         : Utente( un, name, surname ) {}

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtentePagante() = 0;
};

#endif
