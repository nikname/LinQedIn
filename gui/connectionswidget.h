#ifndef CONNECTIONSWIDGET_H
#define CONNECTIONSWIDGET_H

#include <QWidget>
#include "smartutente.h"

class Database;

class ConnectionsWidget : public QWidget {
    Q_OBJECT
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ConnectionsWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // CONNECTIONSWIDGET_H
