#ifndef JOBWIDGET_H
#define JOBWIDGET_H

#include <QWidget>
#include "smartlavoro.h"

class QLabel;

class JobWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *companyNameLabel;
    QLabel *titleLabel;
    QLabel *locationLabel;
    QLabel *periodLabel;
public:
    /** */
    explicit JobWidget( const SmartLavoro&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // JOBWIDGET_H
