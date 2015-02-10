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
    // Poichè un oggetto di tipo Rete può venire creato solo tramite una new da un oggetto di tipo
    // Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.
    // Viene fornita una classe Iteratore non necessaria.

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

    class Iteratore {
        friend class Rete;
    private:
        class Iteratore_rapp;
        Iteratore_rapp* iterator;
    public:
        /** Controlla se l'Iteratore è arrivao alla fine della lista.
         *
         * @return bool  true se esiste un prossimo elemento, false altrimenti.
         */
        bool hasNext() const;

        /** Ritorna l'elemento puntato ed avanza l'Iteratore.
         *
         * @return Utente*  Utente puntato dall'Iteratore.
         */
        Utente* next();
    };

    /** Ritorna un iteratore al primo elemento della rete dei contatti dell'utente.
     *
     * @return Iteratore  Iteratore al primo elemento della rete dei contatti dell'utente.
     */
    Iteratore begin() const;

    friend class Iteratore::Iteratore_rapp;
public:
    /** Aggiunge un contatto alla lista dei contatti dell'utente.
     *
     * @param Utente*  Utente da aggiungere.
     * @param Database*  Database sul quale ricercare l'username dell'utente da inserire.
     */
    void addContact( Utente*, Database* );

    /** Rimuove un contatto dalla lista dei contatti dell'utente.
     *
     * @param Utente*  Utente da rimuovere.
     * @param Database*  Database sul quale ricercare l'username dell'utente da rimuovere.
     */
    void removeContact( Utente*, Database* );

    /** Ritorna un QVector di SmartUtente contenente i contatti nella rete dell'utente.
     *
     * @return QVector<SmartUtente>  Vettore dei contatti nella rete dell'utente.
     */
    QVector<SmartUtente> getContactsList() const;

    /** Ridefinizione distruttore Rete.
     *  Se il campo user_ref è 0 invoca la delete standard su contacts,
     *  altrimenti si limita a decrementare il contatore di riferimenti.
     *
     * @param void*  Puntatore all'oggetto Rete.
     */
    void operator delete( void* );
};

#endif
