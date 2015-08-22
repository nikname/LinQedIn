#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "smarttitolo.h"

class QLabel;
class QPushButton;

class TitleWidget : public QWidget {
    Q_OBJECT
private:
    SmartTitolo title;

    QLabel *titleIconLabel;

    QLabel *schoolLabel;
    QLabel *dateAttendedLabel;
    QLabel *fieldOfStudyLabel;

    QPushButton *removeTitleButton;
    QPushButton *editTitleButton;

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
    explicit TitleWidget( const SmartTitolo&, QWidget *parent = 0 );

    /** */
    SmartTitolo getTitle();
signals:
    /** */
    void removeTitleSignal( const SmartTitolo& );
public slots:
    /** */
    void openEditTitleDialog();

    /** */
    void updateTitleInfoSlot( const QString&, int, int, int, const QString& );

    /** */
    void removeTitle();
};

#endif // TITLEWIDGET_H
