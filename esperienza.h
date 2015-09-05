#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDate>
#include <QDebug>
#include <QString>
#include "smartlavoro.h"

class Esperienza {

    // NOTE:
    // Nel metodo begin() non serve controllare se experiences è valido in quanto se creo un oggetto
    // Esperienza allora viene creato in automatico un oggetto Esperienza_rapp.

    friend class Utente;
private:
    class Esperienza_rapp;
    Esperienza_rapp* experiences;
    int user_ref; // Numero di utenti che si riferiscono all'oggetto Esperienza.

    /** Costruttore ad 1 parametro di utilità. Utilizzato per fare copie profonde.
     *  Viene utilizzato dal metodo clone().
     *
     * @param Esperienza_rapp *  Oggetto Esperienza_rapp del quale fare la copia.
     */
    Esperienza( Esperienza_rapp * );
public:
    /** Costruttore di default ridefinito.
     *  Crea una lista vuota di esperienze lavorative.
     *  Inizializza ad 1 il contatore di riferimenti user_ref.
     */
    Esperienza();

    /** Costruttore di copia di Esperienza.
     *  Incrementa il contatore di riferimenti all'oggetto Esperienza di 1.
     *  Utilizza la tecnica del references counting per il campo dati di tipo Esperienza_rapp.
     *
     * @param Esperienza  Oggetto Esperienza da copiare.
     */
    Esperienza( const Esperienza& );

    /** Decrementa il campo references di Esperienza_rapp
     *  In caso il valore diventi 0 invoca il distruttore dell'oggetto.
     */
    ~Esperienza();

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
    void addExperience( const SmartLavoro& );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *
     * @param SmartLavoro  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( const SmartLavoro& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *
     * @return QVector<SmartLavoro>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartLavoro> getExperiencesList() const;

    /** Crea una nuova lista delle esperienze lavorative. Rimuove un'eventuale lista preesistente.
     *
     * @param  QVector<SmartLavoro>  Lista delle nuove esperienze lavorative.
     */
    void setExperiencesList( QVector<SmartLavoro> );

    /** Operatore delete ridefinito.
     *  Decrementa user_ref di 1. Se user_ref vale 0 invoca il distuttore di Esperienza_rapp.
     */
    void operator delete( void* );

    /** Metodo di utilità necessario per creare copie profonde di oggetti di tipo Esperienza.
     *
     * @return Esperienza *  Copia profonda dell'oggetto stesso.
     */
    Esperienza *clone() const;
};

/** Overloading dell'operatore di output di QDebug.
 *  Stampa su standard output la lista delle esperienze lavorative.
 *
 * @param QDebug  QDebug.
 * @param Esperienza  Lista delle esperienze lavorative.
 * @return QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Esperienza& );

#endif // ESPERIENZA_H
