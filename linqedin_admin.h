#ifndef LINQEDIN_ADMIN_H
#define LINQEDIN_ADMIN_H
#include "database.h"

class AdminWindow;

class LinQedInAdmin {

    // NOTE:
    // Un oggetto di tipo LinQedInAdmin può essere creato solo da oggetti di tipo AdminWindow.

    friend class AdminWindow;
private:
    Database* db;

    /** Costruttore di default ridefinito.
     *  Ricostruisce il database con la lista degli utenti.
     */
    LinQedInAdmin();
public:
    /** Inserisce un nuovo utente nel database.
     *
     * @param Utente*  Utente da inserire nel database.
     * @return bool  true se l'utente viene inserito correttamente; false altrimenti.
     */
    bool insertUser( Utente* );

    /** Ricerca un'utente nel database.
     *
     * @param QString  Username dell'utente da ricercare.
     * @return SmartUtente  Utente cercato. Se non presente
     */
    SmartUtente findUser( QString ) const;

    /** Rimuove un'utente nel database.
     *
     * @param QString  Username dell'utente da rimuovere.
     */
    void removeUser( QString );

    /** Cambia tipologia di account.
     *
     * @param QString  Username dell'utente interessato dal cambio tipologia.
     */
    void changeSubscriptionType( QString );

    /** Salva la lista degli utenti del database.
     *  Invoca il metodo Database::saveUsersList().
     */
    void saveDatabase() const;
};

#endif // LINQEDIN_ADMIN_H
