#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"

class ProfileWidget : public QWidget {
    Q_OBJECT
public:
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );

signals:

public slots:

};

#endif // PROFILEWIDGET_H
