#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QTabWidget>

class UserListWidget : public QTabWidget {
    Q_OBJECT
private:


    void setupTabs();
public:
    explicit UserListWidget( QWidget *parent = 0 );
signals:

public slots:

};

#endif // USERLIST_WIDGET_H
