#ifndef LINQEDIN_CLIENT_H
#define LINQEDIN_CLIENT_H
#include "database.h"

class LinQedInClient {
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

    /** Permette di aggiornare le informazioni del profilo. */
    void aggiornaProfilo();

    /** Visualizza le informazioni del profilo. */
    void showProfilo();

    /** Aggiunge un contatto nella rete dell'utente.
     *
     * @param QString  Username dell'utente da aggiungere alla lista dei contatti.
     */
    void insertRete( QString );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param QString  Username dell'utente da rimuovere dalla lista dei contatti.
     */
    void removeRete( QString );
};

#endif // LINQEDIN_CLIENT_H
