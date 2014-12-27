#ifndef RETE_H
#define RETE_H
#include <iostream>
#include <string>
#include "username.h"

using std::ostream;
using std::string;

class Rete {
private:
    class SmartUtente;
    SmartUtente* first;
public:
    class Iteratore {
        friend class Rete;
    private:
        Rete::SmartUtente* punt;
    public:
        /** Controlla se i due iteratori puntano allo stesso SmartUtente.
         *
         * @param Iteratore  Iteratore sulla lista dei contatti.
         * @return bool  true se puntano allo stesso SmartUtente, false altrimenti.
         */
        bool operator ==( Iteratore ) const;

        /** Controlla se i due iteratori puntano a SmartUtenti diversi.
         *
         * @param Iteratore  Iteratore sulla lista dei contatti.
         * @return bool  true se puntano ad istanze di SmartUtente diverse, false altrimenti.
         */
        bool operator !=( Iteratore ) const;

        /** Incremento prefisso. Avanza l'iteratore sulla lista dei contatti.
         *
         * @return Iteratore&  Iteratore sull'elemento successivo (se esiste).
         */
        Iteratore& operator ++();

        /** Incremento postfisso. Ritorna un'iteratore sull'elemento successivo.
         *
         * @param int  Parametro fittizio per distinguere incremento prefisso e postfisso.
         * @return Iteratore&  Iteratore sull'elemento successivo (se esiste).
         */
        Iteratore& operator ++( int );
    };

    /** Codstruttore di default. */
    Rete();

    /** Aggiunge un contatto alla lista dei contatti.
     *
     * @param Username  Username del contatto da aggiungere.
     */
    void add( Username );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param Username  Username del contatto da rimuovere.
     */
    void remove( Username );

    /** Ritorna una lista dei contatti separati da ",".
     *
     * @return string  Lista dei contatti separati da ",".
     */
    string getContactsList() const;

    /** Ritorna un'iteratore al primo elemento della lista.
     *
     * @return Iteratore  Iteratore al primo elemento della lista.
     */
    Iteratore begin() const;

    /** Ritorna un'iteratore all'ultimo elemento della lista (vuoto).
     *
     * @return Iteratore  Iteratore all'ultimo elemento della lista.
     */
    Iteratore end() const;

    /** Ritorna l'username dell'utente nella posizione dell'iteratore nella lista.
     *
     * @param Iteratore  Iteratore ad un elemento della lista.
     * @return Username  Username dell'utente nella posizione dell'iteratore.
     */
    Username operator []( Iteratore ) const;

    friend ostream& operator <<( ostream&, Rete* );
};

/** Overloading dell'operatore <<.
 *  Stampa su standard output la lista dei contatti dell'utente.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Rete*  Rete dei contatti dell'utente.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Rete* );

#endif
