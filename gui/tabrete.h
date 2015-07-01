#ifndef TABRETE_H
#define TABRETE_H

#include <QWidget>
#include "userlist_widget.h"
#include "database.h"

class TabRete : public QWidget {
    Q_OBJECT
private:
    UserListWidget *contactList;
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit TabRete( SmartUtente, Database*, QWidget *parent = 0 );
signals:
    /** */
    void updateContactsSignal( const QString& );

    void updateContactsListSignal( const SmartUtente& );
};

#endif // TABRETE_H
