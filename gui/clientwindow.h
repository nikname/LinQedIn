#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QString>
#include "smartutente.h"

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

    ProfileWidget *profileWidget;

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

    /** Applica delle proprietà agli altri pulsanti dell'area del menu.
     *
     * @param QPushButton*  Pulsante al quale applicare le proprietà.
     */
    void setButtonProperties( QPushButton* );
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

    /** Esegue la ricerca di utenti nel database. */
    void searchUsers();

    /** */
    void updateContactsSlot( const QString& );
signals:
    /** */
    void updateContactsListSignal( const SmartUtente& );
};

#endif // CLIENTWINDOW_H
