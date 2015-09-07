#ifndef ADDTITLEDIALOG_H
#define ADDTITLEDIALOG_H

#include <QDate>
#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class AddTitleDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *schoolEdit;
    QLineEdit *fieldOfStudyEdit;
    QLineEdit *dayAttendedEdit;
    QLineEdit *monthAttendedEdit;
    QLineEdit *yearAttendedEdit;

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
    explicit AddTitleDialog( QWidget *parent = 0 );
signals:
    /** */
    void addNewTitleSignal( const QString&, const QDate&, const QString& );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void addNewTitle();
};

#endif // ADDTITLEDIALOG_H
