#ifndef UTENTE_H
#define UTENTE_H
#include <iostream>
#include <QString>
#include <QDate>
#include "username.h"
#include "profilo.h"
#include "rete.h"
#include "formazione.h"
#include "esperienza.h"

using std::ostream;

class Utente {
private:
    Username username;
    Profilo profile;
    Rete net;
    Formazione educations;
    Esperienza experiences;
public:
    /** Costruttore ad 2 parametri con 1 parametro di default.
     *  Associa un'username e delle informazioni personali all'utente.
     *  Invoca i costruttori di default per net, educations ed experiences.
     *  Costruttore di default non disponibile.
     *
     * @param Username  Username dell'utente.
     * @param Profilo  Profilo dell'utente.
     */
    Utente( const Username&,
            const Profilo& = Profilo() );

    /** Distruttore virtuale di Utente. */
    virtual ~Utente();

    /** Ritorna l'username dell'utente.
     *
     * @return Username  Username dell'utente.
     */
    Username getUsername() const;

    /** Ritorna il profilo dell'utente.
     *
     * @return Profilo  Profilo dell'utente.
     */
    Profilo getProfile() const;

    /** Ritorna la rete dei contatti dell'utente.
     *
     * @return Rete  Rete dei contatti dell'utente.
     */
    Rete getNet() const;

    /** Ritorna la lista dei titoli di studio posseduti dall'utente.
     *
     * @return Formazione*  Lista dei titoli di studio posseduti dall'utente.
     */
    Formazione* getEucations() const;

    /** Ritorna la lista delle esperienze lavorative dell'utente.
     *
     * @return Esperienza*  Lista delle esperienze lavorative possedute dall'utente.
     */
    Esperienza* getExperiences() const;
};

/** Oveloading operatore di output.
 *  Stampa su standard output tutte le informazioni associate all'utente, quali: username,
 *  profilo, rete di contatti, titoli di studio posseduti ed esperienze lavorative.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Utente  Utente del quale vengono stampate le informazioni.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Utente );

#endif
