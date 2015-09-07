#ifndef SEARCHRESULTSWIDGET_H
#define SEARCHRESULTSWIDGET_H

#include <QWidget>
#include "smartutente.h"

class UserPreviewWidget;

class SearchResultsWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartUtente> usersList;

    QVector<UserPreviewWidget*> userPreviewWidgetsList;

    /** Inizializza la UI.
     *
     * @param SmartUtente  Utente che esegue la ricerca.
     */
    void initUI( const SmartUtente&, const QString& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QVector<SmartUtente>  Utenti del client presenti sul database.
     * @param SmartUtente  Utente che esegue la ricerca.
     * @param QString  Stringa da cercare.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit SearchResultsWidget( QVector<SmartUtente>, const SmartUtente&,
                                  const QString&, QWidget *parent = 0 );
signals:
    /** Notifica il parent di quale utente visualizzare il profilo.
     *
     * @param SmartUtente  Utente del quale visualizzare il profilo.
     */
    void showUserSignal( const SmartUtente& );
public slots:

};

#endif // SEARCHRESULTSWIDGET_H
