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
    LinQedInClient( const QString& );

    /** Salva tutte le informazioni dell'utente sul database. */
    void saveUserInfo();

    /** Salva le informazioni del profilo dell'utente sul database. */
    void saveProfile();

    /** Salva la lista dei contatti dell'utente sul database. */
    void saveNet();

    /** Salva la lista delle esperienze lavorative dell'utente sul database. */
    void saveExperiences();

    /** Salva la lista dei titoli di studio dell'utente sul database. */
    void saveEducations();
};

#endif // LINQEDIN_CLIENT_H
