#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "usersearchwidget.h"
#include "tabprofilo.h"
#include "tabrete.h"

class LinQedInClient;

class ClientWindow : public QMainWindow {
    Q_OBJECT
private:
    LinQedInClient *client;

    UserSearchWidget *userSearchWidget;
    QTabWidget *tabWidget;
    TabProfilo *tabProfilo;
    TabRete *tabRete;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    /** Inizializza la GUI. */
    void initializeGUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu.
     *  Associa le action al menu ed inserisce il menu nella barra del menu.
     */
    void createMenus();
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

    /** */
    void updateUserInfoSlot( const QString&, const QString& );

    void updateContactsSlot( const QString& );
};

#endif // CLIENTWINDOW_H
