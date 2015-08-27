#ifndef CONNECTIONSWIDGET_H
#define CONNECTIONSWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class UserPreviewWidget;

class ConnectionsWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartUtente> contactsList;

    QLayout *userPreviewWidgetsLayout;
    QVector<UserPreviewWidget*> userPreviewWidgetsList;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ConnectionsWidget( const SmartUtente&, QWidget *parent = 0 );

    /** */
    void hideToolsButtons();
signals:
    /** */
    void contactToRemoveSignal( const SmartUtente& );

    /** */
    void showContactSignal( const SmartUtente& );
public slots:
    /** */
    void removeUserSlot( const SmartUtente& );
};

#endif // CONNECTIONSWIDGET_H
