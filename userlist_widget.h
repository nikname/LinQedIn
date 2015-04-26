#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QTabWidget>
#include "tablemodel.h"

class UserListWidget : public QTabWidget {
    Q_OBJECT
private:
    TableModel *table;
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Realizza l'area della GUI nella quale viene visualizzata la lista degli utenti.
     *
     * @param LinQedInAdmin  Puntatore all'oggetto LinQedInAdmin.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit UserListWidget( LinQedInAdmin *adminClient, QWidget *parent = 0 );
};

#endif // USERLIST_WIDGET_H
