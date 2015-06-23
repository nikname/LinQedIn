#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QXmlStreamReader>
#include "utente.h"

class LinQedInAdmin;

class Database {

    // NOTE:
    // Il metodo Database::insert( Utente* ) è accessibile solo da oggetti di tipo
    // LinQedInAdmin. In questo modo solo l'utente amministratore può aggiungere nuovi
    // utenti al database. Oggetti di tipo LinQedInClient non possono aggiungere nuovi
    // utenti al database.
    // Da prendere il considerazione il fatto di rendere privato il costruttore di
    // Database e rendere anche la classe LinQedInClient amica. In questo modo però anche
    // quest'ultima potrebbe aggiungere nuovi utenti.

    friend class LinQedInAdmin; // Necessario per poter aggiungere utenti al database.
private:
    class Database_rapp;
    Database_rapp* database_rapp;

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
     *  Crea ed aggiunge un oggetto Lavoro nella lista delle esperienze lavorative
     *  dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Utente del quale si vogliono aggiungere le esperienze lavorative.
     */
    void parseExperience( QXmlStreamReader&, Utente* );

    /** Scorre un elemento <date> nel file xml.
     *  Crea un oggetto di tipo QDate e lo aggiunge in base all'oggetto adeguato.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param Utente*  Oggetto del quale si vuole aggiungere una data.
     */
    void parseDate( QXmlStreamReader&, Utente* );

    /** Inserisce un nuovo utente nella lista degli utenti del database.
     *  Accessibile solo da oggetti di tipo LinQedInAdmin.
     *
     * @param SmartUtente  Utende da inserire nella lista degli utenti del database.
     * @return bool  true se l'utente viene inserito correttamente; false altrimenti.
     */
    bool insert( SmartUtente );

    /** Rimuove un utente dalla lista degli utenti del database.
     *  Accessibile solo da oggetti di tipo LinQedInAdmin.
     *
     * @param QString  Username dell'utente da rimuovere dalla lista degli utenti del database.
     * @return bool  true se l'utente viene rimosso correttamente; false altrimenti.
     */
    bool remove( QString );
public:
    /** Costruttore di default ridefinito.
     *  Carica la lista degli utenti da file (XML).
     */
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

    /** Carica la lista degli utenti da file (XML). */
    void loadUsersList();

    /** Salva la lista degli utenti su file (XML). */
    void saveUsersList() const;

    /** Ritorna un vettore contenente gli utenti del database.
     *
     * @return QVector<SmartUtente>  Vettore degli utenti del database.
     */
    QVector<SmartUtente> getUsersList() const;

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
