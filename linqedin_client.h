#ifndef LINQEDIN_CLIENT_H
#define LINQEDIN_CLIENT_H
#include "utente.h"
#include "database.h"

class LinQedInClient {
private:
    Utente* user;
    Database* db;
public:
    /** Costruttore ad 1 parametro.
     *  Esegue l'accesso dell'utente all'applicazione.
     *  Costruttore di default non disponibile.
     *
     * @param Username  Username dell'utente che accede.
     */
    LinQedInClient( Username );

    /** Permette di aggiornare le informazioni del profilo. */
    void aggiornaProfilo();

    /** Visualizza le informazioni del profilo. */
    void showProfilo();

    /** Aggiunge un contatto nella rete dell'utente.
     *
     * @param Username  Username dell'utente da aggiungere alla lista dei contatti.
     */
    void insertRete( Username );

    /** Rimuove un contatto dalla lista dei contatti.
     *
     * @param Username  Username dell'utente da rimuovere dalla lista dei contatti.
     */
    void removeRete( Username );
};

#endif // LINQEDIN_CLIENT_H
