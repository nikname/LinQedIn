#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "smarttitolo.h"

class QLabel;

class TitleWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *schoolLabel;
    QLabel *dateAttendedLabel;
    QLabel *degreeLabel;
    QLabel *fieldOfStudyLabel;
    QLabel *gradeLabel;
public:
    /** */
    explicit TitleWidget( const SmartTitolo&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // TITLEWIDGET_H
