#ifndef SMARTUTENTE_H
#define SMARTUTENTE_H

#include <QDebug>

class Utente;

class SmartUtente {
private:
    Utente* user; // Puntatore polimorfo
public:
    /** Costruttore ad 1 parametro.
     *
     * @param Utente* u  Elemento della lista utenti.
     */
    SmartUtente( Utente* = 0 );

    /** Costruttore di copia.
     *  Utilizza la tecnica del references counting, incrementando il campo references di Utente.
     *
     * @param SmartUtente  SmartUtente dal quale creare di copia il nuovo SmartUtente.
     */
    SmartUtente( const SmartUtente& );

    /** Distruttore di SmartUtente.
     *  Richiama il distruttore di Utente.
     */
    ~SmartUtente();

    /** Overloading dell'operatore di assegnazione.
     *  Tiene sotto controllo la memoria, distruggendo eventuali campi dati definiti.
     *  Aggiorna il valore del campo references di Utente.
     *
     * @param SmartUtente  SmartUtente da assegnare al nuovo SmartUtente.
     */
    SmartUtente& operator =( const SmartUtente& );

    /** Overloaging dell'operatore di referenziazione.
     *
     * @return Utente&  L'oggetto Utente al quale si riferisce l'oggetto SmartUtente.
     */
    Utente& operator *() const;

    /** Overloading dell'operatore di accesso a membro.
     *
     * @return Utente*  Puntatore all'oggetto Utente al quale si riferisce l'oggetto SmartUtente.
     */
    Utente* operator ->() const;

    /** Overloading dell'operatore di uguaglianza tra SmartUtente.
     *  Confronta due oggetti di tipo SmartUtente.
     *
     * @param SmartUtente  SmartUtente da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti puntano allo stesso utente; false altrimenti.
     */
    bool operator ==( const SmartUtente& );

    /** Overloading dell'operatore di disuguaglianza tra SmartUtente.
     *  Confronta due oggetti di tipo SmartUtente.
     *
     * @param SmartUtente  SmartUtente da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti non puntano allo stesso utente; false altrimenti.
     */
    bool operator !=( const SmartUtente& );

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
