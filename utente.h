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
private:
    Username username;
    Profilo profile;
    Rete net;
    Formazione educations;
    Esperienza experiences;
public:
    /** Costruttore ad 2 parametri con 2 parametri di default.
     *  Associa un'username e delle informazioni personali (nome e cognome) all'utente.
     *  Invoca i costruttori di default per net, educations ed experiences.
     *
     * @param Username un  Username dell'utente.
     * @param Profilo p  Profilo dell'utente.
     */
    Utente( const Username& un = Username(),
            const Profilo& p = Profilo() ) :
        username( un ),
        profile( p ) {}

    /** Distruttore virtuale puro. */
    virtual ~Utente() = 0;

    /** Ritorna l'username dell'utente.
     *
     * @return Username  Username dell'utente.
     */
    Username getUsername() const;

    /** Ritorna il profilo dell'utente.
     *
     * @return Profilo  Profilo dell'utente.
     */
    Profilo getProfile() const;

    /** Ritorna la rete dei contatti dell'utente.
     *
     * @return Rete  Rete dei contatti dell'utente.
     */
    Rete getNet() const;

    /** Ritorna i titoli di studio posseduti dall'utente.
     *
     * @return Formazione  Titoli di studio posseduti dall'utente.
     */
    Formazione getEducations() const;

    /** Ritorna le esperienze lavorative possedute dall'utente.
     *
     * @return Esperienza  Esperienze lavorative possedute dall'utente.
     */
    Esperienza getExperiences() const;

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
         * @param int x  Tipo di ricerca.
         */
        FuntoreRicerca( int x = 0 ) : searchType( x ) {}

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
 *  Stampa su standard output nome e cognome dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Utente*  Puntatore all'oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, Utente* );

#endif
