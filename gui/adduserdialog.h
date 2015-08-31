#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include "linqedindialog.h"
#include "smartutente.h"

class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;

class AddUserDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *usernameEdit;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *executiveRadioButton;
    QRadioButton *businessRadioButton;

    QPushButton *acceptButton;
    QPushButton *rejectButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AddUserDialog( QWidget *parent = 0 );
signals:
    /** Notifica che un utente deve essere aggiunto alla lista degli utenti del database.
     *
     * @param QString  Username dell'utente da aggiungere.
     * @param QString  Nome dell'utente da aggiungere.
     * @param QString  Cognome dell'utente da aggiungere.
     * @param QString  Tipologia dell'utente da aggiungere.
     */
    void sendUserDetails( const QString&, const QString&, const QString&, const QString& );
private slots:
    /** */
    void checkInput( const QString& );

    /** */
    void addUser();
};

#endif // ADDUSERDIALOG_H
