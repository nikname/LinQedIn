#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QXmlStreamReader>
#include "utente.h"

class Database {
private:
    class ListaUtenti;
    ListaUtenti* usersList;

    /** Scorre un elemento Utente nel file xml.
     *  Crea e salva un oggetto Utente nella lista degli utenti del database.
     *
     * @param QXmlStreamReader  Lettore di file xml passato per riferimento.
     */
    void parseUser( QXmlStreamReader& );
public:

    Database();

    /** Carica una lista di utenti da file. */
    void loadUsersList();

    /** Salva la lista degli utenti su file. */
    void saveUsersList() const;

    /** Dato un'username, ricerca l'utente nel database.
     *
     * @param Username  Username dell'utente da ricercare.
     * @return Utente*  Utente ricercato.
     */
    Utente* find( Username ) const;
};

#endif // DATABASE_H
