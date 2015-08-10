#ifndef EXPERIENCESWIDGET_H
#define EXPERIENCESWIDGET_H

#include <QWidget>
#include "smartutente.h"
#include "smartlavoro.h"

class QLabel;
class JobWidget;

class ExperiencesWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartLavoro> experiencesList;

    QWidget *widgetsWrapper;
    QVector<JobWidget*> jobsWidget;
public:
    /** */
    explicit ExperiencesWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // EXPERIENCESWIDGET_H
