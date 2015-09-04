#ifndef ADDJOBDIALOG_H
#define ADDJOBDIALOG_H

#include <QDate>
#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class AddJobDialog : public LinQedInDialog {
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
    explicit AddJobDialog( QWidget *parent = 0 );
signals:
    /** */
    void addNewJobSignal( const QString&, const QString&, const QDate&, const QDate& );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void addNewJob();
};

#endif // ADDJOBDIALOG_H
