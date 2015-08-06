#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;

class ProfileWidget : public QWidget {
    Q_OBJECT
private:
    QWidget *header;

    QWidget *profilePicWidget;
    QLabel *profilePicLabel;

    QWidget *profileSummary;
    QLabel *nameSurnameLabel;
    QLabel *lastEducationLabel;
    QLabel *lastExperienceLabel;
public:
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );

signals:

public slots:

};

#endif // PROFILEWIDGET_H
