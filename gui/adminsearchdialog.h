#ifndef ADMINSEARCHDIALOG_H
#define ADMINSEARCHDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QWidget;

class AdminSearchDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *searchEdit;

    QWidget *typeCheckboxWidget;
    QLabel *typeLabel;
    QCheckBox *typeCheckboxBasic;
    QCheckBox *typeCheckboxExecutive;
    QCheckBox *typeCheckboxBusiness;

    QWidget *fieldCheckboxWidget;
    QLabel *fieldLabel;
    QCheckBox *fieldCheckboxUsername;
    QCheckBox *fieldCheckboxName;
    QCheckBox *fieldCheckboxSurname;

    QPushButton *rejectButton;
    QPushButton *acceptButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
protected:
    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminSearchDialog( QWidget *parent = 0 );
signals:
    /** Notifica AdminSearchWindow i parametri della ricerca.
     *
     * @param QString  Stringa da ricercare.
     * @param QList<QString>  Lista dei campi nei quali ricercare la stringa.
     * @param QList<QString>  Lista delle tipologie di account da filtrare.
     */
    void sendSearchParams( const QString&, QList<QString>, QList<QString> );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void searchUsers();
};

#endif // ADMINSEARCHDIALOG_H
