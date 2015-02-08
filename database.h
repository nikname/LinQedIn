#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QXmlStreamReader>
#include "utente.h"

class LinQedInAdmin;

class Database {
    friend class LinQedInAdmin;
private:
    class ListaUtenti;
    ListaUtenti* usersList;

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
     *  Richiama il distruttore di ListaUtenti.
     */
    ~Database();

    /** Dato un'username, ricerca l'utente nel database.
     *
     * @param QString  Username dell'utente da ricercare.
     * @return SmartUtente  Utente ricercato.
     */
    SmartUtente findUser( const QString& ) const;

    /** Carica una lista di utenti da file (XML). */
    void loadUsersList();

    /** Salva la lista degli utenti su file (XML). */
    void saveUsersList() const;

    /** Ritorna il numero di utenti presenti nel database.
     *
     * @return int  Numero di utenti presenti nel database.
     */
    int usersNumber() const; // *** JUST FOR DEBUG ***

    friend QDebug operator <<( QDebug, Database* ); // *** JUST FOR DEBUG ***
};

#endif // DATABASE_H
