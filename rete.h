#ifndef RETE_H
#define RETE_H
#include <iostream>
#include <string>
#include "username.h"

using std::ostream;
using std::string;

class Rete {
    friend class Utente; // necessario per addContact( Username ) e removeContact( Username )
private:
    class SmartUtente;
    SmartUtente* first;

    /** Aggiunge un contatto alla lista dei contatti.
     *  Metodo privato invocato da Utente::addContact( Username ).
     *
     * @param Username  Username del contatto da aggiungere.
     */
    void add( Username );

    /** Rimuove un contatto dalla lista dei contatti.
     *  Metodo privato invocato da Utente::removeContact( Username ).
     *
     * @param Username  Username del contatto da rimuovere.
     */
    void remove( Username );
public:
    /** Codstruttore di default. */
    Rete();

    friend ostream& operator <<( ostream&, Rete );
};

/** Overloading dell'operatore <<.
 *  Stampa su standard output la lista dei contatti dell'utente.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Rete  Rete dei contatti dell'utente.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Rete );

#endif
