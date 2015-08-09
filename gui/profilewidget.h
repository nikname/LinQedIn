#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;
class ExperiencesWidget;
class EducationsWidget;

class ProfileWidget : public QWidget {
    Q_OBJECT
private:
    QWidget *header;

    QWidget *profilePicWidget;
    QLabel *profilePicLabel;

    QWidget *profileSummary;
    QLabel *nameSurnameLabel;
    QLabel *lastExperienceLabel;
    QLabel *lastEducationLabel;
    QLabel *connectionsNumber;

    QWidget *infoTabs;

    QWidget *infoTabsButtonsWidget;
    QPushButton *backgroundTabButton;
    QPushButton *connectionsTabButton;
    QPushButton *otherInfoTabButton;
    QPushButton *addContactButton;

    QWidget *backgroundTab;
    ExperiencesWidget *experiencesWidget;
    QWidget *educationsWidget;

    QWidget *connectionsTab;
    QWidget *otherInfoTab;

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
};

#endif // PROFILEWIDGET_H
