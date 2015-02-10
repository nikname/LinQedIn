#ifndef SMARTLAVORO_H
#define SMARTLAVORO_H

#include <QDebug>

class Lavoro;

class SmartLavoro {
private:
    Lavoro* job;
public:
    /** Costruttore ad 1 parametro con 1 parametro di default.
     *
     * @param Lavoro*  Lavoro della lista delle esperienze lavorative dell'utente.
     */
    SmartLavoro( Lavoro* = 0 );

    /** Costruttore di copia.
     *  Utilizza la tecnica del reference counting, incrementando il campo reference di Lavoro.
     *
     * @param SmartLavoro  SmartLavoro dal quale creare di copia il nuovo SmartLavoro.
     */
    SmartLavoro( const SmartLavoro& );

    /** Distruttore di SmartLavoro.
     *  Richiama il distruttore di Lavoro.
     */
    ~SmartLavoro();

    /** Overloading dell'operatore di assegnazione.
     *  Tiene sotto controllo la memoria, distruggendo eventuali campi dati definiti.
     *  Aggiorna il valore del campo references di Lavoro.
     *
     * @param SmartLavoro  SmartLavoro da assegnare al nuovo SmartLavoro.
     */
    SmartLavoro& operator =( const SmartLavoro& );

    /** Overloading dell'operatore di referenziazione.
     *
     * @return Lavoro&  L'oggetto Lavoro al quale si riferisce l'oggetto SmartLavoro.
     */
    Lavoro& operator *() const;

    /** Overloading dell'operatore di accesso a membro.
     *
     * @return Lavoro*  Puntatore all'oggetto Lavoro al quale si riferisce l'oggetto SmartLavoro.
     */
    Lavoro* operator ->() const;

    /** Overloading dell'operatore di uguglianza tra SmartLavoro.
     *  Confronta due oggetti di tipo SmartLavoro.
     *
     * @param SmartLavoro  SmartLavoro da confrontare con l'oggetto di invocazione.
     * @return bool true se i due oggetti puntano allo stesso Lavoro; false altrimenti.
     */
    bool operator ==( const SmartLavoro& );

    /** Overloading dell'operatore di disuguaglianza tra SmartLavoro.
     *  Confronta due oggetti di tipo SmartLavoro.
     *
     * @param SmartLavoro  SmartLavoro da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti non puntano allo stesso Lavoro; false altrimenti.
     */
    bool operator !=( const SmartLavoro& );

    friend QDebug operator <<( QDebug, const SmartLavoro& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni associate all'esperienza lavorativa.
 *
 * @param QDebug  QDebug.
 * @param SmartLavoro  Elemento della lista delle esperienze lavorative.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const SmartLavoro& );

#endif // SMARTLAVORO_H
