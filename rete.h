#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>

class SmartUtente;
class Database;
class Utente;

class Rete {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Rete.
    // Poichè un oggetto di tipo Rete può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno
    // ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.
    // Fornire un'iteratore sarebbe inutile.

    friend class Utente; // Necessaria per costruire e distruggere oggetti Utente.
private:
    class Rete_rapp;
    Rete_rapp* contacts;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Rete.

    /** Costruttore di default privato.
     *  Crea una lista vuota di contatti.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     *  Viene invocato solo dal costruttore di Utente.
     */
    Rete();
public:
    /** Aggiunge un contatto alla lista dei contatti dell'utente.
     *
     * @param SmartUtente  Utente da aggiungere.
     */
    void addContact( const SmartUtente& );

    /** Rimuove un contatto dalla lista dei contatti dell'utente.
     *
     * @param SmartUtente  Utente da rimuovere.
     */
    void removeContact( const SmartUtente& );

    /** Ritorna un QVector di SmartUtente contenente i contatti nella rete dell'utente.
     *
     * @return QVector<SmartUtente>  Vettore dei contatti nella rete dell'utente.
     */
    QVector<SmartUtente> getContactsList() const;

    /** Ridefinizione operatore delete.
     *  Se il campo user_ref è 0 invoca la delete standard su contacts,
     *  altrimenti si limita a decrementare il contatore di riferimenti.
     *
     * @param void*  Puntatore all'oggetto Rete.
     */
    void operator delete( void* );
};

#endif
