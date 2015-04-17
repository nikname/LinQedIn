#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di dafault.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *  Mostra la GUI.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit MainWindow( QWidget *parent = 0 );

    /** Distruttore ridefinito.
     *  Ripulisce lo heap.
     */
    ~MainWindow();
private:
    QMenu *menu;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;

    QLabel *titleLabel;

    QVBoxLayout *userArea;
    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QPushButton *loginButton;

    QHBoxLayout *adminArea;
    QLabel *adminLabel;
    QHBoxLayout *adminLogin;
    QLineEdit *adminPassword;
    QPushButton *adminLoginButton;

    /** Inizializza la GUI. */
    void initializeGUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu.
     *  Associa le action al menu ed inserisce il menu nella barra del menu.
     */
    void createMenus();

    /** Crea l'area per il login dell'utente. */
    void createUserArea();

    /** Crea l'area per il login dell'amministratore. */
    void createAdminArea();
private slots:
    /** */
    void loginUser();

    /** */
    void loginAdmin();

    /** Mostra le informazioni dell'applicazione su di una finestra pop-up. */
    void about();
};

#endif // MAINWINDOW_H
