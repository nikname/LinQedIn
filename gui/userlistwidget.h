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

    /** Notifica AdminWindow della rimozione di un utente dalla tabella.
     *
     * @param QString  Username dell'utente rimosso.
     */
    void removeUserSignal( const QString& );

    /** Notifica AdminWindow del cambio di tipologia dell'account di un utente.
     *
     * @param QString  Username dell'utente interessato dal cambio di tipologia dell'account.
     * @param QString  Nuova tipologia di account dell'utente.
     */
    void changeAccountTypeSignal( const QString&, const QString& );

    /** */
    void sendDetails( const QString&, const QString&, const QString&, const QString& );
private slots:
    /** Aggiunge le informazioni di un utente in una riga della tabella.
     *
     * @param QString  Username dell'utente.
     * @param QString  Nome dell'utente.
     * @param QString  Cognome dell'utente.
     * @param QString  Tipologia account dell'utente.
     */
    void addUser( const QString&, const QString&, const QString&, const QString& );

    /** Rimuove le informazioni di un utente da una riga della tabella. */
    void removeUser();

    /** Modifica la tipologia dell'account di un utente nella tabella.
     *
     * @param QString  Username dell'utente interessato dal cambio di tipologia.
     * @param QString  Nuova tipologia dell'account.
     */
    void changeAccountType( const QString&, const QString& );

    /** */
    void openChangeTypeDialog();

    /** */
    void clearSelections();
};

#endif // USERLIST_WIDGET_H
