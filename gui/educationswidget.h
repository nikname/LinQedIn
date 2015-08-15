#ifndef EDUCATIONSWIDGET_H
#define EDUCATIONSWIDGET_H

#include <QWidget>
#include "smartutente.h"
#include "smarttitolo.h"

class QLabel;
class QPushButton;
class TitleWidget;

class EducationsWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartTitolo> titlesList;

    QVector<TitleWidget*> titleWidgetsList;
    QPushButton *addTitleButton;

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
    explicit EducationsWidget( const SmartUtente&, QWidget *parent = 0 );
signals:
    /** */
    void updateEducationsSignal();
public slots:

};

#endif // EDUCATIONSWIDGET_H
