#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H
#include "utente_pagante.h"

class Profilo;
class Rete;
class Formazione;
class Esperienza;

class UtenteBusiness : public UtentePagante {
protected:
    /** Costruttore a 5 parametri. Necessario per le copie profonde. Invocato dal metodo clone().
     *
     * @param QString  Username dell'utente.
     * @param Profilo  Informazioni personali dell'utente.
     * @param Rete *  Rete dei contatti dell'utente.
     * @param Formazione *  Lista dei titoli di studio dell'utente.
     * @param Esperienza *  Esperienze lavorative dell'utente.
     */
    UtenteBusiness( const QString& un, const Profilo& p, Rete *n, Formazione *ed, Esperienza *ex ) :
        UtentePagante( un, p, n, ed, ex ) {}
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri della classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtenteBusiness( const QString& un = "", const QString& name = "", const QString& surname = "" )
          : UtentePagante( un, name, surname ) {}

    /** Costruttore di copia ridefinito.
     *  Invoca il costruttore di copia della classe base.
     *
     * @param Utente  Riferimento polimorfo all'oggetto utente da creare di copia.
     */
    UtenteBusiness( const Utente& );

    /** Distruttore virtuale.
     *  Invoca il distruttore della classe base diretta. */
    virtual ~UtenteBusiness() {}

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
     *  Ritorna una lista di utenti con le informazioni accessibili da utenti di tipo UtenteBusiness."
     *
     * @param QVector<SmartUtente>  Lista di utenti sulla quale cercare.
     */
    virtual QVector<SmartUtente> searchUsers( QVector<SmartUtente> ) const;
};

#endif
