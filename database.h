#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QXmlStreamReader>
#include "utente.h"

class LinQedInAdmin;

class Database {

    // NOTE:
    // Deve esistere un unico oggetto Database.

    friend class LinQedInAdmin; // Necessario per poter aggiungere utenti al database.
private:
    class Database_rapp;
    Database_rapp* dbUsers;

    /** Scorre un elemento user nel file xml.
     *  Crea e salva un oggetto Utente nella lista degli utenti del database.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     */
    void parseUser( QXmlStreamReader& );

    /** Scorre un elemento profile nel file xml.
     *  Ricrea le informazioni legate al profilo dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Utente del quale si devono ricreare le informazioni.
     */
    void parseProfile( QXmlStreamReader&, Utente* );

    /** Scorre un elemento net nel file xml.
     *  Ricrea la rete dei contatti dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Utente del quale si vuole ricreare la rete dei contatti.
     */
    void parseNet( QXmlStreamReader&, Utente* );

    /** Scorre un elemento education nel file xml.
     *  Crea ed aggiunge un oggetto Titolo nella lista dei titoli di studio dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Utente del quale si vogliono aggiungere i titoli di studio.
     */
    void parseEducation( QXmlStreamReader&, Utente* );

    /** Scorre un oggetto experience nel file xml.
     *  Crea ed aggiunge un oggetto Lavoro nella lista delle esperienze lavorative dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Utente del quale si vogliono aggiungere le esperienze lavorative.
     */
    void parseExperience( QXmlStreamReader&, Utente* );

    /** Inserisce un nuovo utente nella lista degli utenti del database.
     *
     * @param Utente*  Utende da inserire nella lista degli utenti del database.
     */
    void insert( Utente* );
public:
    /** Costruttore di default ridefinito.
     *  Popola il database*/
    Database();

    /** Distruttore di Database.
     *  Richiama il distruttore di Database_rapp.
     */
    ~Database();

    /** Cerca se nel database è presente un oggetto con la chiave cercata.
     *
     * @param QString  Username da cercare tra le chiavi.
     * @return bool  true se l'username è presente tra le chiavi, false altrimenti.
     */
    bool contains( const QString& ) const;

    /** Carica una lista di utenti da file (XML). */
    void loadUsersList();

    /** Salva la lista degli utenti su file (XML). */
    void saveUsersList() const;

    /** Ritorna un vettore contenente gli utenti del database.
     *
     * @return QVector<SmartUtente>  Vettore degli utenti del database.
     */
    QVector<SmartUtente> getDbUsersList() const;

    friend QDebug operator <<( QDebug, Database* ); // *** JUST FOR DEBUG ***
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output l'username degli utenti del database.
 *
 * @param QDebug  QDebug.
 * @param Database*  Database.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, Database* );

#endif // DATABASE_H
