#ifndef SMARTRETE_H
#define SMARTRETE_H

#include <QDebug>

class Rete;

class SmartRete {
private:
    Rete *net;
public:
    /** Costruttore ad 1 parametro con 1 parametro di default.
     *
     * @param  Rete *  Rete dei contatti dell'Rete.
     */
    SmartRete( Rete * = 0 );

    /** Costruttore di copia.
     *  Utilizza la tecnica del references counting, incrementando il campo references di Rete.
     *
     * @param SmartRete  SmartRete dal quale creare di copia la nuova SmartRete.
     */
    SmartRete( const SmartRete& );

    /** Distruttore di SmartRete.
     *  Richiama il distruttore di Rete.
     */
    ~SmartRete();

    /** Overloading dell'operatore di assegnazione.
     *  Tiene sotto controllo la memoria, distruggendo eventuali campi dati definiti.
     *  Aggiorna il valore del campo references di Rete.
     *
     * @param SmartRete  SmartRete da assegnare al nuovo SmartRete.
     */
    SmartRete& operator =( const SmartRete& );

    /** Overloaging dell'operatore di referenziazione.
     *
     * @return Rete&  L'oggetto Rete al quale si riferisce l'oggetto SmartRete.
     */
    Rete& operator *() const;

    /** Overloading dell'operatore di accesso a membro.
     *
     * @return Rete*  Puntatore all'oggetto Rete al quale si riferisce l'oggetto SmartRete.
     */
    Rete* operator ->() const;

    /** Overloading dell'operatore di uguaglianza tra SmartRete.
     *  Confronta due oggetti di tipo SmartRete.
     *
     * @param SmartRete  SmartRete da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti puntano allo stesso Rete; false altrimenti.
     */
    bool operator ==( const SmartRete& );

    /** Overloading dell'operatore di disuguaglianza tra SmartRete.
     *  Confronta due oggetti di tipo SmartRete.
     *
     * @param SmartRete  SmartRete da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti non puntano allo stesso Rete; false altrimenti.
     */
    bool operator !=( const SmartRete& );

    friend QDebug operator <<( QDebug, const SmartRete& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output la lista degli username della rete dei contatti.
 *
 * @param QDebug  QDebug.
 * @param SmartRete  Rete dei contatti della quale stampare gli username.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const SmartRete& );

#endif // SMARTRETE_H
