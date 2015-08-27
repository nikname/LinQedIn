#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linqedinwindow.h"

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public LinQedInWindow {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QPushButton *loginButton;

    QLabel *adminLabel;
    QLineEdit *adminPassword;
    QPushButton *openAdminLoginButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
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
private slots:
    /** */
    void loginUser();

    /** */
    void loginAdmin();

    /** */
    void openAdminLoginDialog();
};

#endif // MAINWINDOW_H
