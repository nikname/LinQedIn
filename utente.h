#ifndef UTENTE_H
#define UTENTE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "username.h"
#include "profilo.h"
#include "rete.h"
#include "formazione.h"
#include "esperienza.h"
#include "smartutente.h"

class Utente {
    // Classe astratta
protected:
    Username username;
    Profilo profile;
    Rete* net;
    Formazione* educations;
    Esperienza* experiences;
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *
     * @param Username un  Username dell'utente da creare.
     * @param Profilo p  Profilo dell'utente da creare.
     */
    Utente( const Username& un = Username(),
            const Profilo& p = Profilo() ) :
        username( un ),
        profile( p ),
        net( new Rete ),
        educations( new Formazione ),
        experiences( new Esperienza ) {}

    /** Distruttore virtuale puro.
     *  Invoca i distruttori di tutti i campi dati. */
    virtual ~Utente() = 0;

    /** Ritorna l'Username dell'utente.
     *
     * @return Username  Username dell'utente.
     */
    Username getUsername();

    /** Ritorna il Profilo dell'utente.
     *
     * @return Profilo  Profilo dell'utente.
     */
    Profilo getProfile();

    /** Ritorna un puntatore alla rete dei contatti dell'utente.
     *
     * @return Rete*  Rete dei contatti dell'utente.
     */
    Rete* getNet();

    /** Ritorna un puntatore ai titoli di studio posseduti dall'utente.
     *
     * @return Formazione*  Titoli di studio posseduti dall'utente.
     */
    Formazione* getEducations();

    /** Ritorna un puntatore alle esperienze lavorative possedute dall'utente.
     *
     * @return Esperienza*  Esperienze lavorative possedute dall'utente.
     */
    Esperienza* getExperiences();

    /** Ricerca polimorfa, virtuale pura.
     *  Esegue la ricerca degli utenti nel database in base alla tipologia di account.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const = 0;
protected:
    class FuntoreRicerca {
    public:
        int searchType;

        /** Costruttore ad 1 parametro con 1 parametro di default.
         *  Imposta il tipo di ricerca che l'utente può effettuare nel database.
         *
         * @param int type  Tipo di ricerca.
         */
        FuntoreRicerca( int type = 0 ) : searchType( type ) {}

        /** Overloading dell'operatore di "chiamata a funzione".
         *  Invoca il funtore passando come parametro un oggetto SmartUtente, del quale si
         *  vogliono ottenere le informazioni.
         *  L'effetto di questo varia in base al tipo di utente che lo invoca.
         *
         * @param SmartUtente  SmartUtente del quale si vogliono ottenere le informazioni.
         */
        void operator ()( const SmartUtente& ) const;
    };
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param QDebug  QDebug.
 * @param Utente*  Puntatore all'oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, Utente* );

#endif
