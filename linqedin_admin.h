#ifndef LINQEDIN_ADMIN_H
#define LINQEDIN_ADMIN_H
#include <QDebug>
#include "database.h"

class LinQedInAdmin {
private:
    Database* db;
public:
    /** Costruttore di default ridefinito. */
    LinQedInAdmin();

    /** Inserisce un nuovo utente nel database.
     *
     * @param Utente*  Utente da inserire nel database.
     */
    void insertUser( Utente* );

    void find( QString ) const;

    void remove( QString );

    // cambia tra Basic, Business, Executive!
    void changeSubscriptionType( QString );

    void save() const;

    Database* getDB() const;
};

#endif // LINQEDIN_ADMIN_H
