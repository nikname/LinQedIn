#ifndef SMARTTITOLO_H
#define SMARTTITOLO_H

#include <QDebug>

class Titolo;

class SmartTitolo {
private:
    Titolo* title;
public:
    /** Costruttore ad 1 parametro con 1 parametro di default.
     *
     * @param Titolo*  Titolo della lista dei titoli di studio dell'utente.
     */
    SmartTitolo( Titolo* = 0 );

    /** Costruttore di copia.
     *  Utilizza la tecnica del reference counting, incrementando il campo reference di Titolo.
     *
     * @param SmartTitolo  SmartTitolo dal quale creare di copia il nuovo SmartTitolo.
     */
    SmartTitolo( const SmartTitolo& );

    /** Distruttore di SmartTitolo.
     *  Richiama il distruttore di Titolo.
     */
    ~SmartTitolo();

    /** Overloading dell'operatore di assegnazione.
     *  Tiene sotto controllo la memoria, distruggendo eventuali campi dati definiti.
     *  Aggiorna il valore del campo references di Titolo.
     *
     * @param SmartTitolo  SmartTitolo da assegnare al nuovo SmartTitolo.
     */
    SmartTitolo& operator =( const SmartTitolo& );

    /** Overloading dell'operatore di referenziazione.
     *
     * @return Titolo&  L'oggetto Titolo al quale si riferisce l'oggetto SmartTitolo.
     */
    Titolo& operator *() const;

    /** Overloading dell'operatore di accesso a membro.
     *
     * @return Titolo*  Puntatore all'oggetto Titolo al quale si riferisce l'oggetto SmartTitolo.
     */
    Titolo* operator ->() const;

    /** Overloading dell'operatore di uguaglianza tra SmartTitolo.
     *  Confronta due oggetti di tipo SmartTitolo.
     *
     * @param SmartTitolo  SmartTitolo da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti puntano allo stesso Titolo; false altrimenti.
     */
    bool operator ==( const SmartTitolo& );

    /** Overloading dell'operatore di disuguaglianza tra SmartTitolo.
     *  Confronta due oggetti di tipo SmartTitolo.
     *
     * @param SmartTitolo  SmartTitolo da confrontare con l'oggetto di invocazione.
     * @return bool  true se i due oggetti non puntano allo stesso Titolo; false altrimenti.
     */
    bool operator !=( const SmartTitolo& );

    friend QDebug operator <<( QDebug, const SmartTitolo& );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output le informazioni associate al titolo di studio.
 *
 * @param QDebug  QDebug.
 * @param SmartTitolo  Elemento della lista di titoli di studio.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const SmartTitolo& );

#endif // SMARTTITOLO_H
