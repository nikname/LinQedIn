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
    LinQedInAdmin *admin;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    QWidget *menuWidget;

    QPushButton *homeButton;
    QPushButton *backButton;
    QPushButton *openChangeTypeDialogButton;
    QPushButton *removeUserButton;
    QPushButton *openSearchDialogButton;
    QPushButton *saveDatabaseButton;
    QPushButton *addUserButton;

    QLabel *linqedinLabel;

    QPushButton *openSearchButton;

    UserListWidget *userListWidget;

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
    /** */
    void addUserTableSignal( const SmartUtente& );
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra di dialogo. */
    void about();

    /** */
    void openChangeTypeDialog();

    /** */

    /** Apre una nuova finestra per l'inserimento di un nuovo utente. */
    void openAddUserDialog();

    /** Aggiunge un nuovo utente.
     *
     * @param Qstring  Username dell'utente.
     * @param Qstring  Nome dell'utente.
     * @param Qstring  Cognome dell'utente.
     * @param Qstring  Tipologia account dell'utente.
     */
    void addUserSlot( const QString&, const QString&, const QString&, const QString& );

    /** Salva su file (XML) lo stato del database. */
    void saveDatabaseStatus();

    /** */
    void openSearchDialog();
};

#endif // ADMINWINDOW_H
