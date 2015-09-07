#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>
#include "linqedindialog.h"

class QLabel;
class QLineEdit;
class QPushButton;

class AdminLoginDialog : public LinQedInDialog {
    Q_OBJECT
private:
    QLineEdit *passwordEdit;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit AdminLoginDialog( QWidget *parent = 0 );
signals:
    /** Notifica il parent di aprire il client per l'amministratore. */
    void adminLoginSignal();
public slots:
    /** Controlla il contenuto dell'input utente. Nel caso il campo della password risulti vuoto
     *  (gli spazi ad inizio e fine non vengono considerati) disabilita il pulsante di conferma.
     *
     * @param QString  Contenuto dell'input utente.
     */
    void checkInput( const QString& );

    /** Chiude la finestra di dialogo ed emette il segnale adminLoginSingal(). Per semplicità, il
     *  controllo effettivo della password non viene eseguito.
     */
    void checkPassword();
};

#endif // ADMINLOGINDIALOG_H
