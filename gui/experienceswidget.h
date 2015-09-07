#ifndef EXPERIENCESWIDGET_H
#define EXPERIENCESWIDGET_H

#include <QDate>
#include <QWidget>
#include "smartlavoro.h"
#include "smartutente.h"

class JobWidget;
class QLabel;
class QPushButton;

class ExperiencesWidget : public QWidget {
    Q_OBJECT
private:
    QVector<SmartLavoro> jobsList;

    QLayout *jobWidgetsLayout;
    QVector<JobWidget *> jobWidgetsList;
    QPushButton *addJobButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Aggiunge e mostra un JobWidget al layout degli altri widget.
     *
     * @param JobWidget  Widget da aggiungere
     */
    void addJobWidget( JobWidget * );

    /** Inserisce e mostra un JobWidget al layout degli altri widget in una determinata posizione.
     *
     * @param int  Posizione nella quale aggiungere il widget
     * @param JobWidget  Widget da aggiungere
     */
    void insertJobWidget( int, JobWidget * );
protected:
    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** Costruttore a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale visualizzare le esperienze lavorative.
     * @param QWidget  Puntatore al QWidget parent. Se nullo si riferisce a quello top-level.
     */
    explicit ExperiencesWidget( const SmartUtente&, QWidget *parent = 0 );

    /** Metodo di utilità necessario per nascondere i pulsanti di modifica e rimozione titoli. */
    void hideToolsButtons() const;
signals:
    /** Notifica il parent dell'aggiunta di una nuova esperienza lavorativa. Aggiunge una nuova
     *  istanza di JobWidget alla GUI.
     * @param SmartLavoro  Esperienza lavorativa da aggiungere.
     */
    void jobToAddSignal( const SmartLavoro& );

    /** Notifica il parent della rimozione di una esperienza lavorativa. Rimuove l'istanza di
     *  JobWidget corrispondente dalla GUI.
     *
     * @param SmartLavoro  Esperienza lavorativa da aggiungere.
     */
    void jobToRemoveSignal( const SmartLavoro& );

    /** In caso di modifica dell'ultima esperienza lavorativa, notifica il parent di aggiornare
     *  l'informazione presente nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa con le informazioni aggiornate.
     */
    void updateLastJobInfoSignal( const SmartLavoro& );
public slots:
    /** Apre la finesta di dialogo per l'aggiunta di una esperienza lavorativa. */
    void openAddJobDialog();

    /** Aggiunge un nuovo JobWidget alla GUI. L'aggiunta effettiva dell'esperienza lavorativa
     *  all'utente è lasciata al parent tramite l'emissione del segnale jobToAddSignal( SmartLavoro ).
     *
     * @param QString  Nome dell'azienda.
     * @param QString  Ruolo ricoperto all'interno.
     * @param QDate  Anno di inizio.
     * @param QDate  Anno di fine.
     */
    void addNewJobSlot( const QString&, const QString&, const QDate&, const QDate& );

    /** Rimuove un JobWidget dalla GUI. La rimozione effettiva dell'esperienza lavorativa dall'utente
     *  è lasciata al parent tramite tramite l'emissione del segnale jobToRemove( SmartLavoro ).
     *
     * @param SmartLavoro  Esperienza lavorativa da rimuovere.
     */
    void removeJobSlot( const SmartLavoro& );

    /** Nel caso l'esperienza lavorativa aggiornata sia l'ultima, notifica il parent la necessità di
     *  aggiornare le informazioni presenti nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa da aggiornare.
     */
    void updateJobInfoSlot( const SmartLavoro& );
};

#endif // EXPERIENCESWIDGET_H
