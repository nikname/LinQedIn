#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>

class SmartUtente;
class Database;
//class Utente;

class Rete {
    friend class Utente;
private:
    class Contatti;
    Contatti* contacts;
    int references;
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
     * @param QString  Username del contatto da aggiungere.
     */
    void addContact( const QString&, Database* );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param QString  Username del contatto da rimuovere.
     */
    void removeContact( const QString&, Database* );

    /** Ritorna un QVector di QString contenente la login dei contatti nella rete dell'utente.
     *
     * @return QVector<QString>  Login dei contatti nella rete dell'utente.
     */
    QVector<QString> getContactsList() const;

    /** Ridefinizione distruttore Rete.
     *  Se il campo references è 0 invoca la delete standard su contacts,
     *  altrimenti si limita a decrementare il contatore di riferimenti.
     *
     * @param void*  Puntatore all'oggetto Rete.
     */
    void operator delete( void* );

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
