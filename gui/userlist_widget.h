#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QWidget>
#include "smartutente.h"

class LinQedInAdmin;
class QPushButton;
class QTableView;
class TableModel;

class UserListWidget : public QWidget {
    Q_OBJECT
private:
    TableModel *table;
    QTableView *tableView;
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

    /** Nasconde una colonna dalla tabella.
     *  Necessario per realizzare una tabella in base alle esigenze.
     *
     * @param int  Indice colonna da nascondere.
     */
    void hideColumn( int );
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

    /** Notifica il parent l'username del contatto da rimuovere.
     *
     * @param QString  Username del contatto da rimuovere.
     */
    void updateListContactRemovedSignal( const QString& );

    /** Notifica al parent l'username del contatto da rimuovere dai contatti dell'utente del client.
     *
     * @param SmartUtente  Username del contatto da rimuovere.
     */
    void updateContactsListSignal( const SmartUtente& );
private slots:
    /** Aggiorna la lista degli utenti con il nuovo contenuto del database.
     *
     * @param LinQedInAdmin*
     */
    void updateUserListSlot( LinQedInAdmin* );

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

    /**  */
    void contactToRemoveSlot( const QModelIndex& );

    void updateContactsListSlot( const SmartUtente& );
};

#endif // USERLIST_WIDGET_H
