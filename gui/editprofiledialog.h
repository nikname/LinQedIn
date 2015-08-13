#ifndef EDITPROFILEDIALOG_H
#define EDITPROFILEDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class EditProfileDialog : public QDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;

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
    /** Costruttore esplicito a 3 parametri con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit EditProfileDialog( QWidget *parent = 0 );
signals:

public slots:

};

#endif // EDITPROFILEDIALOG_H
