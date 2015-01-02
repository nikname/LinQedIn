#include "database.h"
#include "smartutente.h"
#include <QList>
#include <QListIterator>

class Database::ListaUtenti {
public:
    QList<SmartUtente> users;
};

void Database::load() {

}

void Database::save() const {

}

Utente* Database::find( Username un ) const {
    Utente* u;
    QListIterator<SmartUtente> it( usersList->users );
    while( it.hasNext() ) {
        SmartUtente su = it.next();
        if( su.getUser()->getUsername().getLogin() == un.getLogin() )
            u = su.getUser();
    }
    return u;
}
