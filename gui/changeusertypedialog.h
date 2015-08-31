#ifndef CHANGEUSERTYPEDIALOG_H
#define CHANGEUSERTYPEDIALOG_H

#include <QDialog>
#include "linqedindialog.h"
#include "smartutente.h"

class QGroupBox;
class QLabel;
class QPushButton;
class QRadioButton;

class ChangeUserTypeDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QString username;
    QString type;

    QLabel *titleLabel;

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
     * @param QString  Username dell'utente interessato al cambio.
     * @param QString  Tipologia di account dell'utente interessato al cambio.
     * @param QWidegt  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ChangeUserTypeDialog( const QString&, const QString&, QWidget *parent = 0 );
signals:
    /** Notifica il parent la tipologia di account selezionata per l'utente della tabella selezionato.
     *
     * @param QString  Username dell'utente interessato al cambio.
     * @param QString  Tipologia selezionata.
     */
    void sendDetails( const QString&, const QString& );
public slots:
    /** */
    void changeUserType();
};

#endif // CHANGEUSERTYPEDIALOG_H
