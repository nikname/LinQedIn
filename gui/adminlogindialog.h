#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class AdminLoginDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *passwordEdit;

    QPushButton *rejectButton;
    QPushButton *acceptButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminLoginDialog( QWidget *parent = 0 );
signals:
    /** */
    void adminLoginSignal();
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void checkPassword();
};

#endif // ADMINLOGINDIALOG_H
