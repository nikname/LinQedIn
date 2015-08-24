#ifndef EDUCATIONSWIDGET_H
#define EDUCATIONSWIDGET_H

#include <QWidget>
#include "smarttitolo.h"
#include "smartutente.h"

class QLabel;
class QPushButton;
class TitleWidget;

class EducationsWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartTitolo> titlesList;

    QLayout *titleWidgetsLayout;
    QVector<TitleWidget *> titleWidgetsList;
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

    /** Aggiunge e mostra un TitleWidget al layout degli altri widget.
     *
     * @param TitleWidget  Widget da aggiungere
     */
    void addTitleWidget( TitleWidget * );

    /** Inserisce e mostra un TitleWidget al layout degli altri widget in una determinata posizione.
     *
     * @param int  Posizione nella quale aggiungere il widget
     * @param TitleWidget  Widget da aggiungere
     */
    void insertTitleWidget( int, TitleWidget * );
public:
    /** */
    explicit EducationsWidget( const SmartUtente&, QWidget *parent = 0 );

    /** */
    void hideToolsButtons();
signals:
    /** */
    void titleToAddSignal( const SmartTitolo& );

    /** */
    void titleToRemoveSignal( const SmartTitolo& );

    /** */
    void updateLastTitleInfoSignal( const SmartTitolo& );
public slots:
    /** */
    void openAddTitleDialog();

    /** */
    void addNewTitleSlot( const QString&, int, int, int, const QString& );

    /** */
    void removeTitleSlot( const SmartTitolo& );

    /** */
    void updateTitleInfoSlot( const SmartTitolo& );
};

#endif // EDUCATIONSWIDGET_H
