#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "smarttitolo.h"

class QLabel;
class QPushButton;

class TitleWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *titleIconLabel;

    QLabel *schoolLabel;
    QLabel *dateAttendedLabel;
    QLabel *fieldOfStudyLabel;

    QPushButton *removeTitleButton;
    QPushButton *editTitleButton;

    /** Inizializza la UI.
     *
     * @param SmartTitolo  Titolo di studio.
     */
    void initUI( const SmartTitolo& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton * );
public:
    /** */
    explicit TitleWidget( const SmartTitolo&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // TITLEWIDGET_H
