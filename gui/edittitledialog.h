#ifndef EDITTITLEDIALOG_H
#define EDITTITLEDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class EditTitleDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *schoolEdit;
    QLineEdit *dayAttendedEdit;
    QLineEdit *monthAttendedEdit;
    QLineEdit *yearAttendedEdit;
    QLineEdit *fieldOfStudyEdit;

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
    explicit EditTitleDialog( QWidget *parent = 0 );
signals:
    /** */
    void updateTitleInfoSignal( const QString&, const QDate&, const QString& );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void updateTitleInfo();
};

#endif // EDITTITLEDIALOG_H
