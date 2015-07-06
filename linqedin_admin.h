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
    /** Distruttore ridefinito.
     *  Ripulisce lo heap.
     */
    ~LinQedInAdmin();

    /** Inserisce un nuovo utente nel database.
     *
     * @param SmartUtente  Utente da inserire nel database.
     * @return bool  true se l'utente viene inserito correttamente; false altrimenti.
     */
    bool insertUser( SmartUtente );

    /** Ricerca un'utente nel database.
     *
     * @param QString  Username dell'utente da ricercare.
     * @return SmartUtente  Utente cercato. Se non presente
     */
    SmartUtente findUser( QString ) const;

    /** Rimuove un'utente nel database.
     *
     * @param QString  Username dell'utente da rimuovere.
     * @return bool  true se l'utente viene rimosso con successo; false altrimenti (può essere dovuto
     * a problemi di rimozione o per il semplice fatto che l'utente da rimuovere non esiste).
     */
    bool removeUser( QString );

    /** Cambia tipologia di account.
     *
     * @param QString  Username dell'utente interessato dal cambio tipologia.
     * @param QString  Nuova tipologia di account ("Basic", "Executive", "Business").
     */
    void changeSubscriptionType( QString, QString );

    /** Salva la lista degli utenti del database.
     *  Invoca il metodo Database::saveUsersList().
     */
    void saveDatabase() const;

    /** Ritorna un vettore contenente gli utenti del database.
     *  Richiama il metodo Database::getUserList.
     *
     * @return QVector<SmartUtente>  Vettore degli utenti del database.
     */
    QVector<SmartUtente> getUsersList() const;
};

#endif // LINQEDIN_ADMIN_H
