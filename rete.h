#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>
#include "username.h"

class SmartUtente;
class Database;

class Rete {
    friend class Iteratore;
private:
    class Contatti;
    Contatti* contacts;
public:
    /** Costruttore di default ridefinito.
     *  Crea una lista vuota di contatti.
     */
    Rete();

    /** Distruttore di Rete.
     *  Invoca il distruttore di Contatti.
     */
    ~Rete();

    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username del contatto da aggiungere.
     */
    void addContact( const Username&, Database* );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param Username  Username del contatto da rimuovere.
     */
    void removeContact( const Username&, Database* );

    /** Ritorna la lista dei contatti (username) separati da ",".
     *
     * @return QString  Lista dei conatti (username) separati da ",".
     */
    QString getUsernamesList() const;

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
