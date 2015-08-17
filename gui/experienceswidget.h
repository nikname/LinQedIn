#ifndef EXPERIENCESWIDGET_H
#define EXPERIENCESWIDGET_H

#include <QWidget>
#include "smartlavoro.h"
#include "smartutente.h"

class JobWidget;
class QPushButton;
class QLabel;

class ExperiencesWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartLavoro> jobsList;

    QVector<JobWidget*> jobWidgetsList;
    QPushButton *addJobButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** */
    explicit ExperiencesWidget( const SmartUtente&, QWidget *parent = 0 );
signals:
    /** */
    void jobToAddSignal( const SmartLavoro& );
public slots:
    /** */
    void openAddJobDialog();
    /** */
    void addNewJobSlot( const QString&, const QString&, int, int );
};

#endif // EXPERIENCESWIDGET_H
