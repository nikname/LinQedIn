#ifndef USERGRIDWIDGET_H
#define USERGRIDWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;

class UserGridWidget : public QWidget {
    Q_OBJECT
private:
    QWidget *widgetsWrapper;

    QLabel *profilePicLabel;

    QLabel *userLabel;
    QLabel *lastJobLabel;

    QWidget *toolWidget;
    QPushButton *viewContactButton;
    QPushButton *removeContactButton;
public:
    /** */
    explicit UserGridWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // USERGRIDWIDGET_H
