#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

class AdminSearchWidget;
class LinQedInAdmin;
class QAction;
class QMenu;
class QPushButton;
class SmartUtente;
class UserListWidget;

class AdminWindow : public QMainWindow {
    Q_OBJECT
    friend class AddUserDialog;
private:
    LinQedInAdmin *admin;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    AdminSearchWidget *searchWidget;
    UserListWidget *userListWidget;
    QPushButton *addUserButton;

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu. Associa le action al menu ed inserisce il menu nella barra del menu. */
    void createMenus();
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminWindow( QWidget *parent = 0 );

    /** Distruttore ridefinito. Ripulise lo heap. */
    ~AdminWindow();
signals:
    /** Notifica userListWidget che la lista degli utenti del database è stata aggiornata.
     *  Si preoccupa di aggiornare la lista degli utenti sulla tabella del client.
     *
     * @param LinQedInAdmin*  Necessario per poter recuperare la nuova lista degli utenti.
     */
    void updateUsersListSignal( LinQedInAdmin*, const QString& );
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra di dialogo. */
    void about();

    /** Apre una nuova finestra per l'inserimento di un nuovo utente. */
    void openAddUserDialog();

    /** Inserisce un nuovo utente nel database quando viene emesso il segnale AddUserDialog::
     *  addUserSignal( SmartUtente ). Mostra il nuovo utente inserito e salva il database.
     *
     * @param SmartUtente  Utente da inserire.
     */
    void addUserSlot( const SmartUtente& );

    /** Quando userListWidget notifica la rimozione di un utente dal database, rimuove un utente dal
     *  database ed emette il segnale updateUserListSignal( LinQedInAdmin* ).
     *
     * @param QString  Username dell'utente da rimuovere dal database degli utenti.
     */
    void updateListUserRemovedSlot( const QString& );

    /** Quando userListWidget notifica la modifica della tipologia di account di un utente, modifica
     *  la tipologia dell'utente ed emette il segnale updateUserListSignal( LinQedInAdmin* )
     *
     * @param QString  Username dell'utente interessato dal cambio di tipologia.
     * @param QString  Nuova tipologia dell'account dell'utente.
     */
    void updateListUserTypeSlot( const QString&, const QString& );
};

#endif // ADMINWINDOW_H
