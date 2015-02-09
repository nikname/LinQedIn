#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDebug>
#include <QString>
#include <QDate>

class Lavoro;

class Esperienza {

    // NOTE:
    // Solo creando un oggetto Utente è possibile creare un oggetto Esperienza.
    // Poichè un oggetto di tipo Esperienza può venire creato solo tramite una new da un oggetto di
    // tipo Utente, allora non sono necessari costruttore di copia e distruttore (nemmeno ridefiniti).
    // L'aumento del contatore user_ref è lasciato al costruttore di copia di Utente.

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
    /** Aggiunge un'esperienza alle esperienze lavorative.
     *
     * @param Lavoro*  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( Lavoro* );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *
     * @param Lavoro*  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( Lavoro* );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<Lavoro*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Lavoro*> getExperiencesList() const;

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distuttore di Esperienza_rapp.
     */
    void operator delete( void* );
};

#endif // ESPERIENZA_H
