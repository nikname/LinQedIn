#ifndef CHANGEUSERTYPEDIALOG_H
#define CHANGEUSERTYPEDIALOG_H

#include <QDialog>
#include "linqedindialog.h"
#include "smartutente.h"

class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;

class ChangeUserTypeDialog : public LinQedInDialog {
    Q_OBJECT
private:
    SmartUtente user;

    QLabel *titleLabel;

    QLineEdit *usernameEdit;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *executiveRadioButton;
    QRadioButton *businessRadioButton;

    QPushButton *rejectButton;
    QPushButton *acceptButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito a 3 parametri con 1 parametro di default.
     *  Come da buona pratica, delega la realizzazione della GUI ad un metodo ausiliario.
     *
     * @param SmartUtente  Utente interessato dal cambio di tipologia di account.
     * @param QWidegt  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ChangeUserTypeDialog( const SmartUtente&, QWidget *parent = 0 );
signals:
    /** */
    void changeUserTypeSignal( const QString&, const QString& );
public slots:
    /** */
    void changeUserType();
};

#endif // CHANGEUSERTYPEDIALOG_H
