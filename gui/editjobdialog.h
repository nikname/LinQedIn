#ifndef EDITJOBDIALOG_H
#define EDITJOBDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class EditJobDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *companyNameEdit;
    QLineEdit *titleEdit;
    QLineEdit *beginEdit;
    QLineEdit *endEdit;

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
    explicit EditJobDialog( QWidget *parent = 0 );
signals:
    /** */
    void updateJobInfoSignal( const QString&, const QString&, int, int );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void updateJobInfo();
};

#endif // EDITJOBDIALOG_H
