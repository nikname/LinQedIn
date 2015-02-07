#ifndef UTENTE_PAGANTE_H
#define UTENTE_PAGANTE_H
#include "utente.h"

class UtentePagante : public Utente {
    // Classe astratta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri dalla classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
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
