#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "smartutente.h"

class ConnectionsWidget;
class EducationsWidget;
class ExperiencesWidget;
class LinQedInClient;
class ProfileWidget;
class QAction;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QScrollArea;

class ClientWindow : public QMainWindow {
    Q_OBJECT
private:
    LinQedInClient *client;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    QWidget *mainWidget;
    QWidget *menuWidget;
    QLabel *linqedinLabel;
    QPushButton *profileButton;
    QPushButton *connectionsButton;
    QPushButton *educationsButton;
    QPushButton *experiencesButton;
    QPushButton *openSearchButton;
    QWidget *searchWidget;
    QPushButton *closeSearchButton;
    QLineEdit *searchText;
    QPushButton *searchButton;

    QScrollArea *scrollArea;
    QWidget *contentWidget;
    ProfileWidget *profileWidget;
    ConnectionsWidget *connectionsWidget;
    ExperiencesWidget *experiencesWidget;
    EducationsWidget *educationsWidget;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu.
     *  Associa le action al menu ed inserisce il menu nella barra del menu.
     */
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

    /** Applica delle proprietà ai pulsanti dell'area di ricerca.
     *
     * @param QPushButton*  Pulsante al quale applicare le proprietà.
     */
    void setSearchAreaButtonProperties( QPushButton* );
public:
    /** Costruttore esplicito a 2 parametri con 2 parametri di deafult.
     *
     * @param QString  Username dell'utente del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ClientWindow( QString = "", QWidget* = 0 );

    /** Distruttore ridefinito.
     *  Ripulise lo heap.
     */
    ~ClientWindow();
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra pop-up. */
    void about();

    /** Mostra il box di ricerca. */
    void openSearchBox();

    /** Chiude il box di ricerca. */
    void closeSearchBox();

    /** Mostra il profilo dell'utente. */
    void showProfile();

    /** Mostra la rete dei contatti dell'utente. */
    void showConnections();

    /** Mostra le esperienze lavorative dell'utente. */
    void showExperiences();

    /** Mostra i titoli di studio dell'utente. */
    void showEducations();

    /** */
    void updateUserInfoSlot( const QString&, const QString& );

    void updateContactsSlot( const QString& );
signals:
    void updateContactsListSignal( const SmartUtente& );
};

#endif // CLIENTWINDOW_H
