#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"
#include "smartlavoro.h"
#include "smarttitolo.h"

class ConnectionsWidget;
class EducationsWidget;
class ExperiencesWidget;
class QLabel;
class QPushButton;

class ProfileWidget : public QWidget {
    Q_OBJECT
private:
    SmartUtente user;

    QLabel *profilePicLabel;

    QWidget *profileSummary;
    QLabel *nameSurnameLabel;
    QLabel *lastExperienceLabel;
    QLabel *lastEducationLabel;
    QLabel *connectionsNumber;
    QPushButton *editProfileButton;

    QVector<QPushButton *> tabButtons;
    QPushButton *backgroundTabButton;
    QPushButton *connectionsTabButton;
    QPushButton *otherInfoTabButton;

    QPushButton *addContactButton;
    QPushButton *removeContactButton;

    QWidget *backgroundTab;
    QLabel *experiencesLabel;
    ExperiencesWidget *experiencesWidget;
    QLabel *educationsLabel;
    EducationsWidget *educationsWidget;

    ConnectionsWidget *connectionsTab;

    QWidget *otherInfoTab;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Applica delle proprietà dei pulsanti del menu interno al profilo.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setProfileButtonProperties( QPushButton* );

    /** Modifica la GUI mostrando quale pulsante del menu interno al profilo è stato selezionato.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setProfileButtonSelected( QPushButton* );
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale mostrare le informazioni.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

private slots:
    /** Mostra la scheda della panoramica dell'utente. */
    void showBackgroundTab();

    /** Mostra la scheda dei contatti dell'utente. */
    void showConnectionsTab();

    /** Mostra la scheda delle altre informazioni dell'utente. */
    void showOtherInfoTab();

    /** */
    void openEditProfileDialog();

    /** */
    void updateProfileInfoSlot( const QString&, const QString& );

    /** */
    void jobToAddSlot( const SmartLavoro& );

    /** */
    void titleToAddSlot( const SmartTitolo& );
};

#endif // PROFILEWIDGET_H
