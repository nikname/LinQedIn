#ifndef UTENTE_H
#define UTENTE_H
#include "profilo.h"
#include "rete.h"
#include "username.h"

class Utente {
private:
    Profilo profile;
    Rete* net;
    Username username;
public:
    /** Costruttore ad 1 parametro. Costruttore di default non disponibile.
     *
     * @param u  Username del contatto da aggiungere alla rete.
     */
    Utente( Username u ) : username( u ) {}
    /** Distruttore virtuale di Utente. */
    virtual ~Utente() {}
    /** Ritorna il profilo dell'utente.
     *
     * @return Profilo  Il profilo dell'utente.
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
    /** Ritorna l'username dell'utente.
     *
     * @return Username  L'username dell'utente.
     */
    Username getUsername() {
        return username;
    }
    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username dell'utente da aggiungere alla lista dei contatti dell'oggetto Utente di invocazione.
     */
    void addContact( Username u ) {
        //TODO: controlla la presenza dell'utente nel database
        net->add( u );
    }
    /** Rimuove (se esiste) un contatto dalla lista dei contatti.
     *
     * @param Username  Username dell'utente da rimuovere dalla lista dei contatti dell'oggetto Utente di invocazione.
     */
    void removeContact( Username u ) {
        net->remove( u );
    }
};

#endif
