#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H
#include "utente_pagante.h"

class UtenteBusiness : public UtentePagante {
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Richiama il costruttore a 2 parametri di UtentePagante.
     *
     * @param Username u  Username dell'utente express.
     * @param Profilo p  Profilo dell'utente express.
     */
    UtenteBusiness( const Username& un = Username(),
                    const Profilo& p = Profilo() ) :
        UtentePagante( un, p ) {}

    /** Ricerca polimorfa, virtuale pura.
     *  Esegue la ricerca degli utenti nel database per utenti express.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    ~UtenteBusiness() {}
};

#endif
