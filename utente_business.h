#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H
#include "utente_pagante.h"

class UtenteBusiness : public UtentePagante {
    // Classe concreta
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtenteBusiness( const QString& un = "",
                    const QString& name = "",
                    const QString& surname = "" )
          : UtentePagante( un, name, surname ) {}

    /** Ricerca polimorfa virtuale.
     *  Esegue la ricerca degli utenti nel database per utenti business.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteBusiness() {}
};

#endif
