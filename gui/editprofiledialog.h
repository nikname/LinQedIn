#ifndef EDITPROFILEDIALOG_H
#define EDITPROFILEDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class EditProfileDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLabel *titleLabel;

    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit EditProfileDialog( QWidget *parent = 0 );
signals:
    /** */
    void updateProfileInfoSignal( const QString&, const QString& );
public slots:
    /** */
    void checkInput( const QString& );

    /** */
    void updateProfileInfo();
};

#endif // EDITPROFILEDIALOG_H
