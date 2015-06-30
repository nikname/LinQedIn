#ifndef TABRETE_H
#define TABRETE_H

#include <QWidget>
#include "userlist_widget.h"

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
    explicit TabRete( SmartUtente, QWidget *parent = 0 );
signals:

public slots:

};

#endif // TABRETE_H
