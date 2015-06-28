#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "smartutente.h"

class TableModel;
class LinQedInAdmin;

class UserListWidget : public QWidget {
    Q_OBJECT
    friend class AddUserDialog;
private:
    TableModel *table;
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
private slots:
    /** Aggiorna la lista degli utenti con il nuovo contenuto del database. */
    void updateUserListSlot( LinQedInAdmin* );

    void updateUserListSlot( int );
signals:
    /** */
    void updateUserListSignal( const QString& );
};

#endif // USERLIST_WIDGET_H
