#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

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

    /** Carica la tabella con le informazioni degli utenti presenti nel database. */
    void loadUserList();
signals:

private slots:
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

    /** Mostra una finestra di dialogo necessaria al cambio di tipologia di account di un utente.
     *
     * @param QModelIndex  Indice della tabella selezionato. La riga identifica l'utente interessato
     * dal cambio di tipologia di account.
     */
    void openChangeUserTypeSlot( const QModelIndex& );
};

#endif // USERLIST_WIDGET_H
