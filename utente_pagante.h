#ifndef UTENTE_PAGANTE_H
#define UTENTE_PAGANTE_H
#include "utente.h"

class Profilo;
class Rete;
class Formazione;
class Esperienza;

class UtentePagante : public Utente {
protected:
    /** Costruttore a 5 parametri. Necessario per le copie profonde.
     *
     * @param QString  Username dell'utente.
     * @param Profilo  Informazioni personali dell'utente.
     * @param Rete *  Rete dei contatti dell'utente.
     * @param Formazione *  Lista dei titoli di studio dell'utente.
     * @param Esperienza *  Esperienze lavorative dell'utente.
     */
    UtentePagante( const QString& un, const Profilo& p, Rete *n, Formazione *ed, Esperienza *ex ) :
        Utente( un, p, n, ed, ex ) {}
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Invoca il costruttore a 3 parametri dalla classe base diretta.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    UtentePagante( const QString& un = "", const QString& name = "", const QString& surname = "" )
         : Utente( un, name, surname ) {}

    /** Costruttore di copia ridefinito.
     *  Invoca il costruttore di copia della classe base.
     *
     * @param Utente  Riferimento polimorfo all'oggetto utente da creare di copia.
     */
    UtentePagante( const Utente& );

    /** Distruttore virtuale puro.
     *  Invoca il distruttore della classe base diretta. */
    ~UtentePagante() = 0;
};

#endif
