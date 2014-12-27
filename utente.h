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
     * @param Username  Username dell'utente.
     * @param Profilo  Profilo dell'utente.
     * @param Rete*  Rete di utenti che compongono i contatti dell'utente.
     */
    Utente( Username, Profilo = Profilo(), Rete* = new Rete() );

    /** Distruttore virtuale di Utente.
     *  Ripulisce lo heap deallocando net.
     */
    virtual ~Utente();

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
     * @return Rete*  Rete dei contatti dell'utente.
     */
    Rete* getNet() const;

    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username dell'utente da aggiungere alla lista dei contatti.
     */
    void addContact( Username );

    /** Rimuove (se esiste) un contatto dalla lista dei contatti.
     *
     * @param Username  Username dell'utente da rimuovere dalla lista dei contatti.
     */
    void removeContact( Username );
};

/** Oveloading operatore di output.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Utente  Utente del quale vengono stampate le informazioni.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Utente );

#endif
