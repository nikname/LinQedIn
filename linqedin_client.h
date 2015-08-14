#ifndef LINQEDIN_CLIENT_H
#define LINQEDIN_CLIENT_H
#include "database.h"

class LinQedInClient {
    friend class ClientWindow;
private:
    SmartUtente user;
    Database* db;
public:
    /** Costruttore ad 1 parametro.
     *  Esegue l'accesso dell'utente all'applicazione.
     *  Costruttore di default non disponibile.
     *
     * @param QString  Username dell'utente che accede.
     */
    LinQedInClient( QString );

    /** Salva lo stato del database. */
    void saveDatabase();
};

#endif // LINQEDIN_CLIENT_H
