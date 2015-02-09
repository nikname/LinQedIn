#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>

class Titolo;

class Formazione {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Formazione.
    // Poichè un oggetto di tipo Formazione può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.

    friend class Utente; // Necessario per costruire e distruggere oggetti Formazione
private:
    class Formazione_rapp;
    Formazione_rapp* titles;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Formazione.

    /** Costruttore privato di default.
     *  Crea una lista vuota di titoli di studio.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     *  Viene invocato solo dal costruttore di Utente.
     */
    Formazione();
public:
    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *
     * @param Titolo*  Titolo di studio da aggiungere.
     */
    void addEducation( Titolo* );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *
     * @param Titolo*  Titolo di studio da rimuovere.
     */
    void removeEducation( Titolo* );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<Titolo*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Titolo*> getTitlesList() const;

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distruttore di Formazione_rapp.
     */
    void operator delete( void* );
};

#endif // FORMAZIONE_H
