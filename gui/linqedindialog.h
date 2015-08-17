#ifndef LINQEDINDIALOG_H
#define LINQEDINDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LinQedInDialog : public QDialog {
    Q_OBJECT
protected:
    QLabel *titleLabel;

    QPushButton *rejectButton;
    QPushButton *acceptButton;

    /** Disabilita un pulsante. Applica proprietà specifiche in base allo stato del pulsante.
     *
     * @param QPushButton  Pulsante interessato dal cambio di stato (abilitato/disabilitato).
     * @param bool  true se il pulsante deve essere disabilitato; false altrimenti.
     */
    void setButtonDisabled( QPushButton *, bool );

    /** Abilita un pulsante. Applica proprietà specifiche in base allo stato del pulsante.
     *
     * @param QPushButton  Pulsante interessato dal cambio di stato (abilitato/disabilitato).
     * @param bool  true se il pulsante deve essere abilitato; false altrimenti.
     */
    void setButtonEnabled( QPushButton *, bool );

    /** */
    void setButtonEnabledProperties( QPushButton * );

    /** */
    void setButtonDisabledProperties( QPushButton * );

    /** */
    void setLineEditProperties( QLineEdit * );

    /** Override.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit LinQedInDialog( QWidget *parent = 0 );

    /** */
    ~LinQedInDialog() = 0;
};

#endif // LINQEDINDIALOG_H
