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

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton * );
protected:
    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** Costruttore a 2 parametri con 1 parametro di default.
     *
     * @param SmartLavoro  Esperienza lavorativa dalla quale creare il widget.
     * @param QWidget  Puntatore al QWidget parent. Se nullo si riferisce a quello top-level.
     */
    explicit JobWidget( const SmartLavoro&, QWidget *parent = 0 );

    /** Ritorna l'esperienza lavorativa associata al widget.
     *
     * @return SmartLavoro  Esperienza lavorativa associata al widget.
     */
    SmartLavoro getJob();

    /** Metodo di utilità. Nasconde i pulsanti per la modifica e rimozione. */
    void hideToolsButtons();
signals:
    /** Notifica il parent la necessità di rimuovere un'esperienza lavorativa.
     *
     * @param SmartLavoro  Esperienza lavorativa da rimuovere.
     */
    void removeJobSignal( const SmartLavoro& );

    /** Notifica il parent l'aggiornamento di un'sperienza lavorativa.
     *
     * @param SmartLavoro  Esperienza lavorativa da aggiornare.
     */
    void updateJobInfoSignal( const SmartLavoro& );
public slots:
    /** Apre la finesta di dialogo per la modifica dell'esperienza lavorativa associata al widget. */
    void openEditJobDialog();

    /** Aggiorna l'esperienza lavorativa associata ed il widget.
     *
     * @param QString  Nome dell'azienda.
     * @param QString  Ruolo svolto nell'azienda.
     * @param QDate  Anno di inizio.
     * @param QDate  Anno di fine.
     */
    void updateJobInfoSlot( const QString&, const QString&, const QDate&, const QDate& );

    /** Emette il sengale removeJobSignal( SmartLavoro ).
     *  Lo slot può essere rimosso esetendendo il segnale al parent.
     */
    void removeJob();
};

#endif // JOBWIDGET_H
