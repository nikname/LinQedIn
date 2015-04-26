#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include "gui/adminsearch_widget.h"
#include "gui/userlist_widget.h"

class LinQedInAdmin;

class AdminWindow : public QMainWindow {
    Q_OBJECT
private:
    LinQedInAdmin *adminClient;

    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    AdminSearchWidget *searchWidget;
    UserListWidget *userListWidget;

    /** Inizializza la GUI. */
    void initializeGUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu.
     *  Associa le action al menu ed inserisce il menu nella barra del menu.
     */
    void createMenus();
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *  Mostra la GUI del client per l'amministratore.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminWindow( QWidget *parent = 0 );

    /** Distruttore ridefinito.
     *  Ripulise lo heap.
     */
    ~AdminWindow();
private slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra pop-up. */
    void about();
};

#endif // ADMINWINDOW_H
