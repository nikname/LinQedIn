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
    QPushButton *experiencesTabButton;
    QPushButton *educationsTabButton;
    QPushButton *otherInfoTabButton;

    EducationsTab *educationsTab;
    ExperiencesTab *experiencesTab;
    OtherInfoTab *otherInfoTab;
public:
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );

signals:

public slots:

};

#endif // PROFILEWIDGET_H
