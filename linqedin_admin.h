#ifndef LINQEDIN_ADMIN_H
#define LINQEDIN_ADMIN_H
#include "database.h"
#include <QDebug>

class LinQedInAdmin {
private:
    Database* db;
public:
    /** Costruttore di default ridefinito. */
    LinQedInAdmin();

    void insert();

    void find( Username ) const;

    void remove( Username );

    // cambia tra Basic, Business, Executive!
    void changeSubscriptionType( Username );

    void save() const;
};

#endif // LINQEDIN_ADMIN_H
