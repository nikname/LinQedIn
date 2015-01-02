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

    Utente* getUser() const;

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

#endif // SMARTUTENTE_H
