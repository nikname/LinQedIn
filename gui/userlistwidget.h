#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QItemSelection>
#include <QWidget>
#include "smartutente.h"

class LinQedInAdmin;
class QPushButton;
class QSortFilterProxyModel;
class QTableView;
class TableModel;

class UserListWidget : public QWidget {
    Q_OBJECT
private:
    QMap<QString, SmartUtente> usersList;

    TableModel *model;
    QSortFilterProxyModel *proxyModel;
    QTableView *tableView;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Realizza l'area della GUI nella quale viene visualizzata la lista degli utenti.
     *
     * @param QVector<SmartUtente>  Utenti da visualizzare nella tabella.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit UserListWidget( const QVector<SmartUtente>, QWidget *parent = 0 );
signals:
    /** */
    void selectionChanged( const QItemSelection& );
private slots:
    /** */
    void addUserTableSlot( const SmartUtente& );

    /** Aggiunge le informazioni di un utente in una riga della tabella.
     *
     * @param Qstring  Username dell'utente.
     * @param Qstring  Nome dell'utente.
     * @param Qstring  Cognome dell'utente.
     * @param Qstring  Tipologia account dell'utente.
     */
    void addUser( QString, QString, QString, QString );

    /** Rimuove le informazioni di un utente da una riga della tabella. */
    void removeUser();
};

#endif // USERLIST_WIDGET_H
