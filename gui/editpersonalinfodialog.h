#ifndef EDITPERSONALINFODIALOG_H
#define EDITPERSONALINFODIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class EditPersonalInfoDialog : public LinQedInDialog {
    Q_OBJECT
    friend class OtherInfoWidget;
private:
    QLabel *titleLabel;

    QLabel *birthdayLabel;
    QLineEdit *dayEdit;
    QLineEdit *monthEdit;
    QLineEdit *yearEdit;

    QLineEdit *maritialStatusEdit;

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
    explicit EditPersonalInfoDialog( QWidget *parent = 0 );
signals:
    /** */
    void sendDetails( const QDate&, const QString& );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void editPersonalInfo();
};

#endif // EDITPERSONALINFODIALOG_H
