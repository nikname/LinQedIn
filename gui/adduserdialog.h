#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include "smartutente.h"

class AddUserDialog : public QDialog {
    Q_OBJECT
private:
    QLineEdit *username;
    QLineEdit *name;
    QLineEdit *surname;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *expressRadioButton;
    QRadioButton *businessRadioButton;

    QDialogButtonBox *buttonBox;

    /** */
    void setupUI();
public:
    /** */
    explicit AddUserDialog( QWidget *parent = 0 );
signals:
    /** */
    void addUserSignal( const SmartUtente& );
private slots:
    /** */
    void emitAddUserSignal();
};

#endif // ADDUSERDIALOG_H
