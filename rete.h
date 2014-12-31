#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>
#include <QList>
#include "username.h"

class Rete {
private:
    class Contatti; // Classe privata
    Contatti* contacts;
public:
    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username del contatto da aggiungere.
     */
    void addContact( Username );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param Username  Username del contatto da rimuovere.
     */
    void removeContact( Username );

    //friend ostream& operator <<( ostream&, Rete );
};

/** Overloading dell'operatore di output.
 *  Stampa su standard output nome e cognome dei contatti dell'utente separati da ",".
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Rete  Lista dei contatti dell'utente.
 * @return ostream&  ostream per riferimento.
 */
//ostream& operator <<( ostream&, Rete );

QDebug& operator <<( QDebug&, const Rete& );

#endif
