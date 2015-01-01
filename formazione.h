#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>

class Formazione {
private:
    class TitoliStudio;
    TitoliStudio* titles;
public:
    /** Costruttore di default ridefinito. */
    Formazione();

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *
     * @param Education  Titolo di studio da aggiungere.
     */
    void addEducation( Formazione );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *
     * @param Education  Titoli di studio da rimuovere.
     */
    void removeEducation( Formazione );

    friend QDebug operator <<( QDebug, const Formazione& );
};

/** Ridefinizione operatore di output di QDebug.
 *  Stampa su standard output le informazioni di tutti i titoli di studio dell'utente.
 *
 * @param QDebug  QDebug.
 * @param Formazione  Elenco dei titoli di studio dell'utente.
 * @return QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Formazione& );

#endif // TITOLO_STUDIO_H
