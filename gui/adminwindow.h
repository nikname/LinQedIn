#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QItemSelection>
#include "linqedinwindow.h"
#include "smartutente.h"

class AdminSearchWidget;
class LinQedInAdmin;
class QAction;
class QLabel;
class QMenu;
class QPushButton;
class SmartUtente;
class UserListWidget;

class AdminWindow : public LinQedInWindow {
    Q_OBJECT
    friend class AddUserDialog;
private:
    bool statusChanged;
    bool filterActive;

    LinQedInAdmin *admin;

    QAction *logoutAct;

    QWidget *menuWidget;

    QWidget *tableToolsWidget;
    QPushButton *homeButton;
    QPushButton *openSearchDialogButton;
    QPushButton *saveDatabaseButton;
    QPushButton *addUserButton;

    QWidget *searchResultsWidget;
    QPushButton *backButton;

    QWidget *userToolsWidget;
    QPushButton *closeUserToolsButton;
    QPushButton *openChangeTypeDialogButton;
    QPushButton *removeUserButton;

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
    /** Notifica UserListWidget dell'aggiunta di un nuovo utente nel database.
     *
     * @param QString  Username dell'utente aggiunto.
     * @param QString  Nome dell'utetne aggiunto.
     * @param QString  Cognome dell'utente aggiunto.
     * @param QString  Tipologia dell'account dell'utente aggiunto.
     */
    void addUserSignal( const QString&, const QString&, const QString&, const QString& );

    /** Ripristina la tabella degli utenti alla lista di tutti gli utenti del client. */
    void restoreTableSignal();
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

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

    /** Rimuove un utente dal database.
     *
     * @param QString  Userneme dell'utente da rimuovere.
     */
    void removeUserSlot( const QString& );

    /** Esegue l'effettivo cambio di tipologia di account dell'utente.
     *  Imposta il flag stateChanged a true.
     *
     * @param QString  Username dell'utente interessato dal cambio di tipologia.
     * @param QString  Nuova tipologia di account.
     */
    void changeAccountTypeSlot( const QString&, const QString& );

    /** Eseguito quando viene selezionata una cella nella tabella degli utenti. Se la cella è
     *  valida allora mostra il menu delle azioni sull'utente selezionato. Altrimenti, in base
     *  al valore del flag filterActive mostra il menu generale o il menu dei risultati della
     *  ricerca.
     *
     * @param QItemSelection  Indice della tabella selezionato.
     */
    void updateMenuToolsButtons( const QItemSelection& = QItemSelection() );

    /** Salva su file (XML) lo stato del database. */
    void saveDatabaseStatus();

    /** Apre la finestra di dialogo per la ricerca degli utenti. */
    void openSearchDialog();

    /** Mostra il menu da visualizzare quando si effettua una ricerca. */
    void showSearchResultsMenu();

    /** Ripristina il contenuto della tabella all'elenco di tutti gli utenti del database.
     *  Ripristina il valore del flag filterActive a false.
     */
    void backToTable();
};

#endif // ADMINWINDOW_H
