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

    /** Inizializza la UI.
     *
     * @param SmartLavoro  Esperienza lavorativa.
     */
    void initUI( const SmartLavoro& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton * );
public:
    /** */
    explicit JobWidget( const SmartLavoro&, QWidget *parent = 0 );
signals:
    /** */
    void updateExperiencesSignal();
public slots:
    /** */
    void openEditJobDialog();

    /** */
    void updateJobInfoSlot( const QString&, const QString&, int, int );
};

#endif // JOBWIDGET_H
