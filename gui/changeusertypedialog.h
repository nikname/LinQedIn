#ifndef CHANGEUSERTYPEDIALOG_H
#define CHANGEUSERTYPEDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QRadioButton>
#include <QDialogButtonBox>

class ChangeUserTypeDialog : public QDialog {
    Q_OBJECT
private:
    QString username;
    QString type;

    QGroupBox *buttonGroup;
    QRadioButton *basicRadioButton;
    QRadioButton *expressRadioButton;
    QRadioButton *businessRadioButton;

    QDialogButtonBox *buttonBox;

    /** */
    void setupUI();
public:
    /** */
    explicit ChangeUserTypeDialog( const QString&, const QString&, QWidget *parent = 0 );
signals:
    /** */
    void changeAccountTypeSignal( const QString&, const QString& );
public slots:
    /** */
    void emitChangeAccountTypeSignal();
};

#endif // CHANGEUSERTYPEDIALOG_H
