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

    /** Scorre un elemento Utente nel file xml.
     *  Crea e salva un oggetto Utente nella lista degli utenti del database.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     */
    void parseUser( QXmlStreamReader& );

    /** Inserisce un nuovo utente nella lista degli utenti del database.
     *
     * @param Utente*  Utende da inserire nella lista degli utenti del database.
     */
    void insert( Utente* );
public:
    /** Costruttore di default ridefinito. */
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

    QVector<SmartUtente> getDbUsersList() const;

    friend QDebug operator <<( QDebug, Database* ); // *** JUST FOR DEBUG ***
};

#endif // DATABASE_H
