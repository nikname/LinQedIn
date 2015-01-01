#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>
#include "username.h"

class Rete {
private:
    class Contatti; // Classe privata
    Contatti* contacts;
public:
    /** Costruttore di default ridefinito.
     *  Crea una lista vuota di contatti.
     */
    Rete();

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

    friend QDebug operator <<( QDebug, const Rete& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output nome e cognome dei contatti dell'utente separati da ",".
 *
 * @param QDebug  QDebug.
 * @param Rete  Lista dei contatti dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Rete& );

#endif
