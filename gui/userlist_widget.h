#ifndef USERLIST_WIDGET_H
#define USERLIST_WIDGET_H

#include <QWidget>

class TableModel;
class LinQedInAdmin;

class UserListWidget : public QWidget {
    Q_OBJECT
private:
    TableModel *table;
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Realizza l'area della GUI nella quale viene visualizzata la lista degli utenti.
     *
     * @param LinQedInAdmin  Puntatore all'oggetto LinQedInAdmin.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit UserListWidget( LinQedInAdmin *adminClient, QWidget *parent = 0 );

    /** Mostra le informazioni di un utente in una riga della tabella.
     *
     * @param Qstring  Username dell'utente.
     * @param Qstring  Nome dell'utente.
     * @param Qstring  Cognome dell'utente.
     * @param Qstring  Tipologia account dell'utente.
     */
    void addUser( QString, QString, QString, QString );

    /** */
    void loadUserList();
};

#endif // USERLIST_WIDGET_H
