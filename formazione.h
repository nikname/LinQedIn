#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDate>
#include <QDebug>
#include <QString>
#include "smarttitolo.h"

class Formazione {

    // NOTE:
    // Nel metodo begin() non serve controllare se titles è valido in quanto se creo un oggetto
    // Formazione allora viene creato in automatico un oggetto Formazione_rapp.

    friend class Utente;
private:
    class Formazione_rapp;
    Formazione_rapp* titles;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Formazione.
public:
    /** Costruttore privato di default.
     *  Crea una lista vuota di titoli di studio.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     */
    Formazione();

    /** Costruttore di copia di Formazione.
     *  Incrementa il contatore di riferimenti all'oggetto Formazione di 1.
     *  Utilizza la tecnica del references counting per il campo dati di tipo Formazione_rapp.
     *
     * @param Formazione  Oggetto Formazione da copiare.
     */
    Formazione( const Formazione& );

    /** Decrementa il campo references di Formazione_rapp
     *  In caso il valore diventi 0 invoca il distruttore dell'oggetto.
     */
    ~Formazione();

    class Iteratore {
        friend class Formazione;
    private:
        class Iteratore_rapp;
        Iteratore_rapp* iterator;
    public:
        /** Controlla se l'Iteratore è arrivato alla fine della lista.
         *
         * @return bool  true se esiste un prossimo elemento, false altrimenti.
         */
        bool hasNext() const;

        /** Ritorna l'elemento puntato ed avanza l'Iteratore.
         *
         * @return SmartTitolo  Titolo di studio puntato dall'Iteratore.
         */
        SmartTitolo next();
    };

    friend class Iteratore::Iteratore_rapp; // Necessaria per avanzare sulla lista.

    /** Ritorna un iteratore al primo elemento della lista di titoli di studio.
     *
     * @return Iteratore  Iteratore al primo elemento della lista dei titoli di studio.
     */
    Iteratore begin() const;

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *
     * @param SmartTitolo  Titolo di studio da aggiungere.
     */
    void addEducation( const SmartTitolo& );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *
     * @param SmartTitolo  Titolo di studio da rimuovere.
     */
    void removeEducation( const SmartTitolo& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<SmartTitolo>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartTitolo> getEducationsList() const;

    /** Crea una nuova lista dei titoli di studio. Rimuove un'eventuale lista preesistente.
     *
     * @param  QVector<SmartTitolo>  Lista dei nuovi titoli di studio dell'utente.
     */
    void setEducationsList( QVector<SmartTitolo> );
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output la lista dei titoli di studio.
 * @param QDebug  QDebug.
 * @param Formazione  Lista dei titoli di studio.
 * @return QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Formazione& );

#endif // FORMAZIONE_H
