#ifndef EDUCATIONSWIDGET_H
#define EDUCATIONSWIDGET_H

#include <QWidget>
#include "smartutente.h"
#include "smarttitolo.h"

class QLabel;
class TitleWidget;

class EducationsWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartTitolo> educationsList;

    QWidget *widgetsWrapper;
    QLabel *educationsLabel;
    QVector<TitleWidget*> titlesWidget;
public:
    /** */
    explicit EducationsWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // EDUCATIONSWIDGET_H
