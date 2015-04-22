#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QTabWidget>
#include "tablemodel.h"

class UserListWidget : public QTabWidget {
    Q_OBJECT
private:
    TableModel *table;

    void setupTabs();
public:
    explicit UserListWidget( QWidget *parent = 0 );
};

#endif // USERLIST_WIDGET_H
