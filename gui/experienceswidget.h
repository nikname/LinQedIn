#ifndef EXPERIENCESWIDGET_H
#define EXPERIENCESWIDGET_H

#include <QDate>
#include <QWidget>
#include "smartlavoro.h"
#include "smartutente.h"

class JobWidget;
class QLabel;
class QPushButton;

class ExperiencesWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartLavoro> jobsList;

    QLayout *jobWidgetsLayout;
    QVector<JobWidget *> jobWidgetsList;
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

    /** Aggiunge e mostra un JobWidget al layout degli altri widget.
     *
     * @param JobWidget  Widget da aggiungere
     */
    void addJobWidget( JobWidget * );

    /** Inserisce e mostra un JobWidget al layout degli altri widget in una determinata posizione.
     *
     * @param int  Posizione nella quale aggiungere il widget
     * @param JobWidget  Widget da aggiungere
     */
    void insertJobWidget( int, JobWidget * );
public:
    /** */
    explicit ExperiencesWidget( const SmartUtente&, QWidget *parent = 0 );

    /** */
    void hideToolsButtons();
signals:
    /** */
    void jobToAddSignal( const SmartLavoro& );

    /** */
    void jobToRemoveSignal( const SmartLavoro& );

    /** */
    void updateLastJobInfoSignal( const SmartLavoro& );
public slots:
    /** */
    void openAddJobDialog();

    /** */
    void addNewJobSlot( const QString&, const QString&, const QDate&, const QDate& );

    /** */
    void removeJobSlot( const SmartLavoro& );

    /** */
    void updateJobInfoSlot( const SmartLavoro& );
};

#endif // EXPERIENCESWIDGET_H
