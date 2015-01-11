#ifndef SMARTUTENTE_H
#define SMARTUTENTE_H

#include <QDebug>

class Utente;

class SmartUtente {
private:
    Utente* user; // Puntatore polimorfo
public:
    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param Utente* u  Elemento della lista utenti.
     */
    SmartUtente( Utente* u ) : user( u ) {}

    /** Distruttore di SmartUtente.
     *  Richiama il distruttore di Utente.
     */
    ~SmartUtente();

    /** Ritorna l'utente puntato dallo SmartUtente.
     *
     * @return Utente*  Utente puntato.
     */
    Utente* getUser() const;

    /** Modifica l'utente puntato dallo SmartUtente.
     *
     * @param Utente*  Utente che sarà puntato dallo SmartUtente.
     */
    void setUser( Utente* );

    friend QDebug operator <<( QDebug, const SmartUtente& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output nome e cognome dell'utente.
 *
 * @param QDebug  QDebug.
 * @param SmartUtente  Elemento della lista utenti.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const SmartUtente& );

/** Overloadine dell'operatore di uguaglianza tra SmartUtente.
 *  Confronta due oggetti di tipo SmartUtente.
 *
 * @param SmartUtente  Oggetto di tipo SmartUtente da confrontare.
 * @param SmartUtente  Oggetto di tipo SmartUtente da confrontare.
 * @return bool  true se i due oggetti puntano allo stesso utente; false altrimenti.
 */
bool operator ==( const SmartUtente&, const SmartUtente& );

#endif // SMARTUTENTE_H
