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
    void initUI( const SmartUtente& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ConnectionsWidget( const SmartUtente&, QWidget *parent = 0 );

    /** Metodo di utilità. Per ogni anteprima utente rimuove il pulsante di rimozione contatto. */
    void hideToolsButtons() const;
signals:
    /** Notifica il parent quale contatto è da rimuovere.
     *
     * @param SmartUtente  Contatto da rimuovere.
     */
    void contactToRemoveSignal( const SmartUtente& );

    /** Notifica il parent di quale utente visualizzare il profilo.
     *
     * @param SmartUtente  Utente del quale visualizzare il profilo.
     */
    void showContactSignal( const SmartUtente& );
public slots:
    /** Rimuove un contatto dalla lista dei contatti. Aggiorna la GUI.
     *
     * @param SmartUtente  Contatto da rimuovere.
     */
    void removeUserSlot( const SmartUtente& );
};

#endif // CONNECTIONSWIDGET_H
