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

    /** */
    void hideToolsButtons();
signals:
    /** */
    void updatePersonalInfoSignal( const QDate&, const QString& );
public slots:
    /** */
    void openEditPersonalInfoDialog();

    /** */
    void updatePersonalInfo( const QDate&, const QString& );
};

#endif // OTHERINFOWIDGET_H
