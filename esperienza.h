#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "smartlavoro.h"

class Esperienza {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Esperienza.
    // Poichè un oggetto di tipo Esperienza può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.
    // Nelle classi innestate si può accedere solo a campi dati statici della classe contenitrice!
    // La classe Iteratore non ha bisogno di un costruttore ridefinito. L'Iteratore viene construito
    // con il metodo begin() sull'oggetto Esperienza di invocazione.
    // Nel metodo begin() non serve controllare se experiences è valido in quanto se creo un oggetto
    // Esperienza allora viene creato in automatico un oggetto Esperienza_rapp.

    friend class Utente; // Necessario per costruire e distruggere oggetti Esperienza
private:
    class Esperienza_rapp;
    Esperienza_rapp* experiences;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Esperienza.

    /** Costruttore di default ridefinito.
     *  Crea una lista vuota di esperienze lavorative.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     *  Viene invocato solo dal costruttore di Utente.
     */
    Esperienza();
public:
    class Iteratore {
        friend class Esperienza;
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
         * @return SmartLavoro  Esperienza lavorativa puntata dall'Iteratore.
         */
        SmartLavoro next();
    };

    friend class Iteratore::Iteratore_rapp; // Necessaria per avanzare sulla lista.

    /** Ritorna un iteratore al primo elemento della lista di esperienze lavorative.
     *
     * @return Iteratore  Iteratore al primo elemento della lista di esperienze lavorative.
     */
    Iteratore begin() const;

    /** Aggiunge un'esperienza alle esperienze lavorative.
     *
     * @param SmartLavoro  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( SmartLavoro );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *
     * @param SmartLavoro  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( SmartLavoro );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<SmartLavoro>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartLavoro> getExperiencesList() const;

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distuttore di Esperienza_rapp.
     */
    void operator delete( void* );
};

#endif // ESPERIENZA_H
