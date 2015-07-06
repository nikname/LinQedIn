#ifndef CHANGEUSERTYPEDIALOG_H
#define CHANGEUSERTYPEDIALOG_H

#include <QDialog>

class QGroupBox;
class QRadioButton;
class QDialogButtonBox;

class ChangeUserTypeDialog : public QDialog {
    Q_OBJECT
private:
    QString username;
    QString type;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *executiveRadioButton;
    QRadioButton *businessRadioButton;

    QDialogButtonBox *buttonBox;

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito a 3 parametri con 1 parametro di default.
     *  Come da buona pratica, delega la realizzazione della GUI ad un metodo ausiliario.
     *
     * @param QString  Username dell'utente interessato dal cambio di account.
     * @param QString  Tipologia dell'utente interessato dal cambio di account.
     * @param QWidegt  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ChangeUserTypeDialog( const QString&, const QString&, QWidget *parent = 0 );
signals:
    /** */
    void changeUserTypeSignal( const QString&, const QString& );
public slots:
    /** */
    void changeUserType();
};

#endif // CHANGEUSERTYPEDIALOG_H
