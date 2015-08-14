#ifndef EDITJOBDIALOG_H
#define EDITJOBDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class EditJobDialog : public QDialog {
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

    /** */
    void setButtonProperties( QPushButton * );

    /** */
    void setLineEditProperties( QLineEdit * );

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
    explicit EditJobDialog( QWidget *parent = 0 );
signals:

public slots:

};

#endif // EDITJOBDIALOG_H
