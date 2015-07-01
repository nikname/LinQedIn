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
    friend class AddUserDialog;
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

    /** Distruttore ridefinito. Ripulisce lo heap. */
    ~UserListWidget();

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
    /** */
    void updateUserListSignal( const QString& );

    void updateUserListSignal( const QString&, const QString& );

    void updateContactsSignal( const QString& );

    void updateContactsListSignal( const SmartUtente& );
private slots:
    /** Aggiorna la lista degli utenti con il nuovo contenuto del database.
     *
     * @param LinQedInAdmin*
     */
    void updateUserListSlot( LinQedInAdmin* );

    /** Aggiorna la lista degli utenti nella tabella rimuovendo un'utente da una riga.
     *
     * @param QModelIndex  Indice la quale riga corrispondente all'utente da rimuovere.
     */
    void updateUserListSlot( const QModelIndex& );

    /** */
    void openChangeAccountTypeSlot( const QModelIndex& );

    /** */
    void removeContactSlot( const QModelIndex& );

    void updateContactsListSlot( const SmartUtente& );
};

#endif // USERLIST_WIDGET_H
