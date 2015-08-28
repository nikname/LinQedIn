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
    QVector<SmartUtente> usersList;

    TableModel *model;
    QTableView *tableView;
    QSortFilterProxyModel *proxyModel;

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

    /** Aggiunge le informazioni di un utente in una riga della tabella.
     *
     * @param Qstring  Username dell'utente.
     * @param Qstring  Nome dell'utente.
     * @param Qstring  Cognome dell'utente.
     * @param Qstring  Tipologia account dell'utente.
     */
    void addItem( QString, QString, QString, QString );

    /** Carica la tabella con le informazioni degli utenti presenti nel database. */
    void loadUserList();
signals:
    /** Notifica al parent l'username dell'utente da rimuovere dal database.
     *
     * @param QString  Username dell'utente.
     */
    void updateListUserRemovedSignal( const QString& );

    /** Notifica al parent la nuova tipologia dell'account di un utente.
     *
     * @param QString  Username dell'utente.
     * @param QString  Nuova tipologia dell'account.
     */
    void updateListUserTypeSignal( const QString&, const QString& );

    /** */
    void updateTableRowSignal( const SmartUtente& );
private slots:
    /** Aggiorna la lista degli utenti con il nuovo contenuto del database.
     *
     * @param LinQedInAdmin*  Oggetto che ha accesso al contenuto del database.
     */
    void updateUserListSlot( LinQedInAdmin*, const QString& );

    /** Emette il segnale updateListUserRemovedSignal( QModelIndex ) per notificare al parent
     *  l'username dell'utente da rimuovere.
     *
     * @param QModelIndex  Indice della tabella selezionato. La riga identifica l'utente da rimuovere.
     */
    void userToRemoveSlot( const QModelIndex& );

    /** Mostra una finestra di dialogo necessaria al cambio di tipologia di account di un utente.
     *
     * @param QModelIndex  Indice della tabella selezionato. La riga identifica l'utente interessato
     * dal cambio di tipologia di account.
     */
    void openChangeUserTypeSlot( const QModelIndex& );
};

#endif // USERLIST_WIDGET_H
