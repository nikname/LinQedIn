#ifndef UTENTE_H
#define UTENTE_H
#include <iostream>
#include <string>
#include "username.h"
#include "profilo.h"
#include "rete.h"

using std::ostream;
using std::string;

class Utente {
private:
    Username username;
    Profilo profile;
    Rete* net;
public:
    /** Costruttore ad 3 parametri con 2 parametri di default.
     *  Costruttore di default non disponibile.
     *
     * @param Username u  Username del contatto.
     * @param Profilo p  Profilo dell'utente.
     * @param Rete* r  Rete di utenti che compongono i contatti dell'utente.
     */
    Utente( Username u, Profilo p = Profilo(), Rete* r = new Rete() )
        : username( u ), profile( p ), net( r ) {}

    /** Distruttore virtuale di Utente. */
    virtual ~Utente() {}

    /** Ritorna l'username dell'utente.
     *
     * @return Username  Username dell'utente.
     */
    Username getUsername() {
        return username;
    }

    /** Ritorna il profilo dell'utente.
     *
     * @return Profilo  Profilo dell'utente.
     */
    Profilo getProfile() {
        return profile;
    }

    /** Ritorna la rete dei contatti dell'utente.
     *
     * @return Rete*  Rete dei contatti dell'utente.
     */
    Rete* getNet() {
        return net;
    }

    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username dell'utente da aggiungere alla lista dei contatti.
     */
    void addContact( Username u ) {
        //TODO: controlla la presenza dell'utente nel database
        net->add( u );
    }

    /** Rimuove (se esiste) un contatto dalla lista dei contatti.
     *
     * @param Username  Username dell'utente da rimuovere dalla lista dei contatti.
     */
    void removeContact( Username u ) {
        net->remove( u );
    }
};

/** Oveloading operatore di output.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param ostream& os  ostream passato per riferimento.
 * @param Utente u  Utente del quale vengono stampate le informazioni.
 * @return ostream&  ostream passato per riferimento.
 */
ostream& operator<< ( ostream& os, Utente u ) {
    return os << "*** PROFILO UTENTE ***\n"
              << u.getUsername() << "\n"
              << u.getProfile() << "\n"
              << u.getNet();
}

#endif
