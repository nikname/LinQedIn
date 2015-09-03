#ifndef UTENTE_EXPRESS_H
#define UTENTE_EXPRESS_H
#include "utente_pagante.h"

class UtenteExecutive : public UtentePagante {
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtenteExecutive( const QString& un = "", const QString& name = "", const QString& surname = "" )
         : UtentePagante( un, name, surname ) {}

    /** Costruttore di copia ridefinito.
     *  Invoca il costruttore di copia della classe base.
     *
     * @param Utente  Riferimento polimorfo all'oggetto utente da creare di copia.
     */
    UtenteExecutive( const Utente& );

    /** Ritorna le informazioni di un utente per utenti con tipologia di account Executive che
     *  eseguono la ricerca.
     *
     * @param SmartUtente  Utente del quale si vogliono ottenere le informazioni.
     * @return SmartUtente  Utente con le sole informazioni visualizzabili.
     */
    virtual SmartUtente getUserInfo( const SmartUtente& ) const;

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteExecutive() {}

    /** Ritorna la tipologia dell'account sotto forma di stringa.
     *  Il metodo viene ridefinito in ogni sottoclasse concreta in modo che all'invocazione su di
     *  un qualsiasi utente ritorni la tipologia corretta.
     *
     * @return QString  Tipologia dell'account.
     */
    virtual QString getAccountType() const;
};

#endif
