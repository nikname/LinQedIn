#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QList>
#include "utente.h"

class Database {
private:
    class ListaUtenti;
    ListaUtenti* usersList;
public:
    /** Carica una lista di utenti da file. */
    void load();

    /** Salva la lista degli utenti su file. */
    void save() const;

    /** Dato un'username, ricerca l'utente nel database.
     *
     * @param Username  Username dell'utente da ricercare.
     * @return Utente*  Utente ricercato.
     */
    Utente* find( Username ) const;
};

#endif // DATABASE_H
