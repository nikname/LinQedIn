#ifndef JOBWIDGET_H
#define JOBWIDGET_H

#include <QWidget>
#include "smartlavoro.h"

class QLabel;
class QPushButton;

class JobWidget : public QWidget {
    Q_OBJECT
private:
    SmartLavoro job;

    QLabel *jobIconLabel;

    QLabel *companyNameLabel;
    QLabel *titleLabel;
    QLabel *periodLabel;

    QPushButton *removeJobButton;
    QPushButton *editJobButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton * );
public:
    /** */
    explicit JobWidget( const SmartLavoro&, QWidget *parent = 0 );

    /** */
    SmartLavoro getJob();
signals:
    /** */
    void removeJobSignal( const SmartLavoro& );

    /** */
    void updateJobInfoSignal( const SmartLavoro& );
public slots:
    /** */
    void openEditJobDialog();

    /** */
    void updateJobInfoSlot( const QString&, const QString&, int, int );

    /** */
    void removeJob();
};

#endif // JOBWIDGET_H
