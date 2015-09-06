#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QString>
#include "linqedinwindow.h"
#include "smartutente.h"

class LinQedInClient;
class ProfileWidget;
class QAction;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QScrollArea;
class SearchResultsWidget;

class ClientWindow : public LinQedInWindow {
    Q_OBJECT
private:
    LinQedInClient *client;

    QAction *logoutAct;

    QWidget *menuWidget;

    QPushButton *homeButton;
    QPushButton *backButton;

    QLabel *linqedinLabel;

    QVector<QPushButton *> sectionButtons;
    QPushButton *profileButton;

    QPushButton *openSearchButton;

    QWidget *searchWidget;
    QPushButton *closeSearchButton;
    QLineEdit *searchText;
    QPushButton *searchButton;

    QScrollArea *scrollArea;
    QLayout *contentLayout;
    SearchResultsWidget *searchResultsWidget;
    ProfileWidget *profileWidget;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu. Associa le action al menu ed inserisce il menu nella barra del menu. */
    void createMenus();

    /** Applica delle proprietà ai pulsanti del menu utente.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setMenuButtonProperties( QPushButton* );

    /** Modifica la GUI indicando quale bottone del menu è stato selezionato.
     *
     * @param QPushButton*  Bottone selezionato.
     */
    void setMenuButtonSelected( QPushButton* );
protected:
    /** Override. Salva su file (XML) i dati dell'utente.
     *
     * @param QCloseEvent*
     */
    void closeEvent( QCloseEvent* );
public:
    /** Costruttore esplicito a 2 parametri con 2 parametri di deafult.
     *
     * @param QString  Username dell'utente del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ClientWindow( const QString& = "", QWidget* = 0 );

    /** Distruttore ridefinito.
     *  Ripulise lo heap.
     */
    virtual ~ClientWindow();
signals:
    /** */
    void updateContactsListSignal( const SmartUtente& );

    /** */
    void showUserSignal( const SmartUtente& );
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra il box di ricerca. */
    void openSearchBox();

    /** Chiude il box di ricerca. */
    void closeSearchBox();

    /** */
    void backFromProfileView();

    /** Mostra il profilo dell'utente. */
    void showPersonalProfile();

    /** Esegue la ricerca di utenti nel database. */
    void searchUsers();

    /**
     * Visualizza il profilo dell'utente selezionato.
     *
     * @param SmartUtente  Utente del quale visualizzare il profilo.
     *
     * PS: Poichè la lista dei contatti dell'utente del client viene distrutta assime al widget
     * dei contatti, anche l'oggetto SmartUtente del quale mostrare il profilo viene distrutto.
     * Per questo motivo viene il contatto passato per riferimento. Questo verrà distrutto in
     * seguito alla distruzione dell'oggetto ProfileWidget.
     */
    void showUserSlot( SmartUtente );

    /** */
    void addContactSlot( const SmartUtente& ); // o SmartUtente ?

    /** */
    void removeContactSlot( const SmartUtente& );

    /** */
    void updateContactsSlot( const QString& );
};

#endif // CLIENTWINDOW_H
