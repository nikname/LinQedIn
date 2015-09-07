#ifndef OTHERINFOWIDGET_H
#define OTHERINFOWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;

class OtherInfoWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *personalInfoLabel;

    QPushButton *editPersonalInfoButton;

    QLabel *birthdayLabel;
    QLabel *userBirthday;
    QLabel *maritialStatusLabel;
    QLabel *userMaritialStatus;

    QLabel *accountInfoLabel;

    QLabel *usernameLabel;
    QLabel *userUsername;
    QLabel *accountTypeLabel;
    QLabel *userAccountType;

    /** Inizializza la UI.
     *
     * @param SmartUtente  Utente dal qual inizializzare i campi dati.
     */
    void initUI( const SmartUtente& su );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** */
    void setToolButtonProperties( QPushButton * );

    /** */
    void setSectionLabelProperties( QLabel * );

    /** */
    void setTitleLabelProperties( QLabel * );
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit OtherInfoWidget( const SmartUtente&, QWidget *parent = 0 );

    /** Nasconde i pulsanti di modifica. */
    void hideToolsButtons() const;
signals:
    /** Notifica al parent le notifiche delle informazioni aggiuntive sul profilo ed aggiorna la GUI.
     *  Dei valori vuoti sono ammessi e servono per cancellare le informazioni.
     *
     * @param QDate  Nuova data di nascita dell'utente.
     * @param QString  Nuovo stato civile dell'utente.
     */
    void updatePersonalInfoSignal( const QDate&, const QString& );
public slots:
    /** Apre la finestra di modifica delle informazioni personali. */
    void openEditPersonalInfoDialog();

    /** Aggiorna la GUI con le nuove informazioni.
     *
     * @param QDate  Nuova data di nascita.
     * @param QString  Nuovo stato civile.
     */
    void updatePersonalInfo( const QDate&, const QString& );
};

#endif // OTHERINFOWIDGET_H
