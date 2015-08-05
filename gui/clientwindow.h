#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "menubutton.h"
#include "smartutente.h"

class LinQedInClient;
class QLabel;
class QLineEdit;

class ClientWindow : public QMainWindow {
    Q_OBJECT
private:
    LinQedInClient *client;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    QWidget *menuWidget;
    QLabel *linqedinLabel;
    MenuButton *profileButton;
    MenuButton *connectionsButton;
    MenuButton *educationsButton;
    MenuButton *experiencesButton;
    QPushButton *openSearchButton;
    QWidget *searchWidget;
    QPushButton *closeSearchButton;
    QLineEdit *searchText;
    QPushButton *searchButton;

    QWidget *contentWidget;

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu.
     *  Associa le action al menu ed inserisce il menu nella barra del menu.
     */
    void createMenus();

    /** Modifica la GUI indicando quale bottone del menu è stato selezionato.
     *
     * @param QPushButton*  Bottone selezionato.
     */
    void setButtonSelected( QPushButton* );
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

    /** */
    void updateUserInfoSlot( const QString&, const QString& );

    void updateContactsSlot( const QString& );
signals:
    void updateContactsListSignal( const SmartUtente& );
};

#endif // CLIENTWINDOW_H
