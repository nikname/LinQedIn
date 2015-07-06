#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

class QLineEdit;
class QGroupBox;
class QRadioButton;
class QDialogButtonBox;
class SmartUtente;

class AddUserDialog : public QDialog {
    Q_OBJECT
private:
    QLineEdit *username;
    QLineEdit *name;
    QLineEdit *surname;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *executiveRadioButton;
    QRadioButton *businessRadioButton;

    QDialogButtonBox *buttonBox;

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
     * @param SmartUtente  Utente da aggiungere.
     */
    void userToAddSignal( const SmartUtente& );
private slots:
    /** Emette il segnale userToAddSignal( SmartUtente ) con l'utente appena creato. */
    void addUser();
};

#endif // ADDUSERDIALOG_H
