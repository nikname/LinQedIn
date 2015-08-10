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
    QVector<SmartTitolo> titlesList;

    QVector<TitleWidget*> titleWidgetsList;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** */
    explicit EducationsWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // EDUCATIONSWIDGET_H
