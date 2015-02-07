#ifndef UTENTE_EXPRESS_H
#define UTENTE_EXPRESS_H
#include "utente_pagante.h"

class UtenteExpress : public UtentePagante {
    // Classe concreta
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Invoca il costruttore a 2 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente express.
     * @param Profilo p  Profilo dell'utente express.
     */
    UtenteExpress( const QString& un = "",
                   const QString& name = "",
                   const QString& surname = "" )
         : UtentePagante( un, name, surname ) {}

    /** Ricerca polimorfa virtuale.
     *  Esegue la ricerca degli utenti nel database per utenti express.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const;

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteExpress() {}
};

#endif
