#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "smarttitolo.h"

class QLabel;

class TitleWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *titleIconLabel;

    QLabel *schoolLabel;
    QLabel *dateAttendedLabel;
    QLabel *degreeLabel;
    QLabel *fieldOfStudyLabel;
    QLabel *gradeLabel;

    /** Inizializza la UI.
     *
     * @param SmartTitolo  Titolo di studio.
     */
    void initUI( const SmartTitolo& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** */
    explicit TitleWidget( const SmartTitolo&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // TITLEWIDGET_H
