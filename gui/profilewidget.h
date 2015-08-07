#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;
class EducationsTab;
class ExperiencesTab;
class OtherInfoTab;

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

    /** Applica delle proprietà dei pulsanti del menu interno al profilo.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setProfileButtonProperties( QPushButton* );

    void setProfileButtonSelected( QPushButton* );
public:
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );

signals:

public slots:

};

#endif // PROFILEWIDGET_H
