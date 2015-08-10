#ifndef JOBWIDGET_H
#define JOBWIDGET_H

#include <QWidget>
#include "smartlavoro.h"

class QLabel;

class JobWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *jobIconLabel;

    QLabel *companyNameLabel;
    QLabel *titleLabel;
    QLabel *periodLabel;

    /** Inizializza la UI.
     *
     * @param SmartLavoro  Esperienza lavorativa.
     */
    void initUI( const SmartLavoro& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** */
    explicit JobWidget( const SmartLavoro&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // JOBWIDGET_H
