#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QXmlStreamReader>
#include "smartutente.h"

class LinQedInAdmin;

class Database {
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
     * @param SmartUtente  Utente del quale si devono ricreare le informazioni.
     */
    void parseProfile( QXmlStreamReader&, const SmartUtente& );

    /** Scorre un elemento net nel file xml.
     *  Ricrea la rete dei contatti dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param SmartUtente  Utente del quale si vuole ricreare la rete dei contatti.
     */
    void parseNet( QXmlStreamReader&, const SmartUtente& );

    /** Scorre un elemento education nel file xml.
     *  Crea ed aggiunge un oggetto Titolo nella lista dei titoli di studio dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param SmartUtente  Utente del quale si vogliono aggiungere i titoli di studio.
     */
    void parseEducation( QXmlStreamReader&, const SmartUtente& );

    /** Scorre un oggetto experience nel file xml.
     *  Crea ed aggiunge un oggetto Lavoro nella lista delle esperienze lavorative
     *  dell'utente.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @param SmartUtente  Utente del quale si vogliono aggiungere le esperienze lavorative.
     */
    void parseExperience( QXmlStreamReader&, const SmartUtente& );

    /** Scorre un elemento <date> nel file xml.
     *  Crea un oggetto di tipo QDate.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     * @return QDate  Oggetto QDate creato con i valori letti da file (XML)
     */
    QDate parseDate( QXmlStreamReader& );

    /** Ricrea la lista dei contatti per ogni utente da file (XML).
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     */
    void loadUsersNet( QXmlStreamReader& );

    /** Inserisce un nuovo utente nella lista degli utenti del database.
     *  Accessibile solo da oggetti di tipo LinQedInAdmin.
     *
     * @param SmartUtente  Utende da inserire nella lista degli utenti del database.
     * @return bool  true se l'utente viene inserito correttamente; false altrimenti.
     */
    bool insert( const SmartUtente& );

    /** Rimuove un utente dalla lista degli utenti del database.
     *  Accessibile solo da oggetti di tipo LinQedInAdmin.
     *
     * @param QString  Username dell'utente da rimuovere dalla lista degli utenti del database.
     * @return bool  true se l'utente viene rimosso correttamente; false altrimenti.
     */
    bool remove( const QString& );
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

    /** Ritorna lo SmartUtente in base all'username.
     *  L'username fornito deve essere presente come chiave nel database.
     *
     * @param QString  Username dell'utente cercato.
     * @return SmartUtente  Utente cercato.
     */
    SmartUtente find( const QString& );

    /** Carica la lista degli utenti da file (XML). */
    void loadUsersList();

    /** Salva la lista degli utenti su file (XML). */
    void saveUsersList() const;

    /** Ritorna un vettore contenente gli utenti del database.
     *
     * @return QVector<SmartUtente>  Vettore degli utenti del database.
     */
    QVector<SmartUtente> getUsersList() const;

    friend QDebug& operator <<( QDebug&, const Database& );
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output l'username degli utenti del database.
 *
 * @param QDebug  QDebug.
 * @param Database  Database.
 * @param QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Database& );

#endif // DATABASE_H
