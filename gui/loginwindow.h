#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMenuBar>
#include "linqedinwindow.h"

class QLabel;
class QLineEdit;
class QPushButton;

class LoginWindow : public LinQedInWindow {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QPushButton *loginButton;

    QPushButton *openAdminLoginButton;

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

    /** Disabilita un pulsante. Applica proprietà specifiche in base allo stato del pulsante.
     *
     * @param QPushButton  Pulsante interessato dal cambio di stato (abilitato/disabilitato).
     * @param bool  true se il pulsante deve essere disabilitato; false altrimenti.
     */
    void setButtonDisabled( QPushButton *, bool );

    /** Abilita un pulsante. Applica proprietà specifiche in base allo stato del pulsante.
     *
     * @param QPushButton  Pulsante interessato dal cambio di stato (abilitato/disabilitato).
     * @param bool  true se il pulsante deve essere abilitato; false altrimenti.
     */
    void setButtonEnabled( QPushButton *, bool );

    /** */
    void setButtonEnabledProperties( QPushButton * );

    /** */
    void setButtonDisabledProperties( QPushButton * );
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di dafault.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *  Mostra la GUI.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit LoginWindow( QWidget *parent = 0 );

    /** Distruttore ridefinito.
     *  Ripulisce lo heap.
     */
    ~LoginWindow();
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void loginUser();

    /** */
    void loginAdmin();

    /** */
    void openAdminLoginDialog();
};

#endif // LOGINWINDOW_H
