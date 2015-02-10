#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "titolo.h"

class Formazione {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Formazione.
    // Poichè un oggetto di tipo Formazione può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.
    // Nelle classi innestate si può accedere solo a campi dati statici della classe contenitrice!
    // La classe Iteratore non ha bisogno di un costruttore ridefinito. L'Iteratore viene construito
    // con il metodo begin() sull'oggetto Formazione di invocazione.
    // Nel metodo begin() non serve controllare se titles è valido in quanto se creo un oggetto
    // Formazione allora viene creato in automatico un oggetto Formazione_rapp.

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
         * @return Titolo*  Titolo di studio puntato dall'Iteratore.
         */
        Titolo* next();
    };

    friend class Iteratore::Iteratore_rapp; // Necessaria per avanzare sulla lista.

    /** Ritorna un iteratore al primo elemento della lista di titoli di studio.
     *
     * @return Iteratore  Iteratore al primo elemento della lista dei titoli di studio.
     */
    Iteratore begin() const;

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
