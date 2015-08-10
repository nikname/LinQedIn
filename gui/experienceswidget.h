#ifndef EXPERIENCESWIDGET_H
#define EXPERIENCESWIDGET_H

#include <QWidget>
#include "smartlavoro.h"
#include "smartutente.h"

class JobWidget;
class QLabel;

class ExperiencesWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartLavoro> jobsList;

    QVector<JobWidget*> jobWidgetsList;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** */
    explicit ExperiencesWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // EXPERIENCESWIDGET_H
