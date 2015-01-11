#ifndef UTENTE_EXPRESS_H
#define UTENTE_EXPRESS_H
#include "utente_pagante.h"

class UtenteExpress : public UtentePagante {
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Richiama il costruttore della classe base diretta.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    UtenteExpress( const Username& un = Username(),
                   const Profilo& p = Profilo() ) :
        UtentePagante( un, p ) {}

    /** Ricerca polimorfa, virtuale pura.
     *  Esegue la ricerca degli utenti nel database per utenti express.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    ~UtenteExpress() {}
};

#endif
