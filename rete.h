#ifndef RETE_H
#define RETE_H
#include <QDebug>
#include <QString>

class SmartUtente;

class Rete {
    friend class Utente;
private:
    class Rete_rapp;
    Rete_rapp* contacts;
    int user_ref;
public:
    /** Costruttore di default.
     *  Crea una lista vuota di contatti. Inizializza ad 1 il contatore di riferimenti.
     */
    Rete();

    /** Costruttore di copia di Rete.
     *  Incrementa il contatore di riferimenti di 1. Utilizza la tecnica del references
     *  counting per il campo dati di tipo Rete_rapp.
     *
     * @param Rete  Oggetto Rete da copiare.
     */
    Rete( const Rete& );

    /** Decrementa il campo references di Rete_rapp
     *  In caso il valore diventi 0 invoca il distruttore dell'oggetto.
     */
    ~Rete();

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

    /** Controlla se un utente è presente tra i contatti.
     *
     * @param SmartUtente  Utente da cercare tra i contatti dell'utente.
     * @return bool  true se è presente; false altrimenti.
     */
    bool isContact( const SmartUtente& ) const;

    /** Ritorna la lista dei contatti nella rete dell'utente.
     *
     * @return QVector<SmartUtente>  Vettore dei contatti nella rete dell'utente.
     */
    QVector<SmartUtente> getContactsList() const;
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output la lista di nomi e cognomi della rete dei contatti.
 *
 * @param QDebug  QDebug.
 * @param Rete  Rete dei contatti della quale stampare nome e cognome.
 * @return QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Rete& );

#endif
