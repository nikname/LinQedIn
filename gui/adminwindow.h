#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

class AdminSearchWidget;
class LinQedInAdmin;
class QAction;
class QLabel;
class QMenu;
class QPushButton;
class SmartUtente;
class UserListWidget;

class AdminWindow : public QMainWindow {
    Q_OBJECT
    friend class AddUserDialog;
private:
    bool stateChanged;
    LinQedInAdmin *admin;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    QWidget *menuWidget;

    QPushButton *homeButton;
    QPushButton *backButton;

    QLabel *linqedinLabel;

    QPushButton *openSearchButton;

    UserListWidget *userListWidget;
    QPushButton *openSearchDialogButton;
    QPushButton *saveDatabaseButton;
    QPushButton *addUserButton;

    /** Inizializza la GUI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu. Associa le action al menu ed inserisce il menu nella barra del menu. */
    void createMenus();

    /** Applica delle proprietà agli altri pulsanti dell'area del menu.
     *
     * @param QPushButton*  Pulsante al quale applicare le proprietà.
     */
    void setButtonProperties( QPushButton* );
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminWindow( QWidget *parent = 0 );

    /** Distruttore ridefinito. Ripulise lo heap. */
    ~AdminWindow();
protected:
    /** Override. Nel caso lo stato del database fosse cambiato, apre una finestra di dialogo
     *  nella quale chiede all'amministratore se salvare il contenuto del database su file (XML).
     *
     * @param QCloseEvent*
     */
    void closeEvent( QCloseEvent* );
signals:
    /** Notifica che lo stato del database è stato modificato e non ancora salvato. */
    void databaseStatusChangedSignal();
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra di dialogo. */
    void about();

    /** */
    void openSearchDialog();

    /** Apre una nuova finestra per l'inserimento di un nuovo utente. */
    void openAddUserDialog();

    /** Salva su file (XML) lo stato del database. */
    void saveDatabaseStatus();

    /** Quando avviene una modifica allo stato del database */
    void databaseStatusChangedSlot();
};

#endif // ADMINWINDOW_H
