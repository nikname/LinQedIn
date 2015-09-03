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

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteExecutive() {}

    /** Metodo virtuale di utilità necessario per creare copie profonde di oggetti di tipo Utente.
     *  Restituisce una copia profonda di se stesso.
     *
     * @param Utente *  Copia profonda dell'oggetto Utente.
     */
    virtual Utente *clone() const;

    /** Ritorna la tipologia dell'account sotto forma di stringa.
     *  Il metodo viene ridefinito in ogni sottoclasse concreta in modo che all'invocazione su di
     *  un qualsiasi utente ritorni la tipologia corretta.
     *
     * @return QString  Tipologia dell'account.
     */
    virtual QString getAccountType() const;

    /** Ricerca polimorfa, virtuale pura.
     *  Ritorna una lista di utenti con le informazioni accessibili da utenti di tipo UtenteExecutive."
     *
     * @param QVector<SmartUtente>  Lista di utenti sulla quale cercare.
     */
    virtual QVector<SmartUtente> searchUsers( QVector<SmartUtente> ) const;
};

#endif
