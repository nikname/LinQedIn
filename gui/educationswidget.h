#ifndef EDUCATIONSWIDGET_H
#define EDUCATIONSWIDGET_H

#include <QDate>
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
protected:
    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** Costruttore a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale visualizzare i titoli di studio.
     * @param QWidget  Puntatore al QWidget parent. Se nullo si riferisce a quello top-level.
     */
    explicit EducationsWidget( const SmartUtente&, QWidget *parent = 0 );

    /** Metodo di utilità necessario per nascondere i pulsanti di modifica e rimozione titoli. */
    void hideToolsButtons() const;
signals:
    /** Notifica il parent dell'aggiunta di un nuovo titolo di studio. Aggiunge una nuova istanza
     *  di TitleWidget alla GUI.
     * @param SmartTitolo  Titolo di studio da aggiungere.
     */
    void titleToAddSignal( const SmartTitolo& );

    /** Notifica il parent della rimozione di un titolo di studio. Rimuove l'istanza di TitleWidget
     *  corrispondente dalla GUI.
     *
     * @param SmartTitolo  Titolo di studio da aggiungere.
     */
    void titleToRemoveSignal( const SmartTitolo& );

    /** In caso di modifica dell'ultimo titolo di studio, notifica il parent di aggiornare
     *  l'informazione presente nell'header del profilo.
     *
     * @param SmartTitolo  Titolo di studio con le informazioni aggiornate.
     */
    void updateLastTitleInfoSignal( const SmartTitolo& );
public slots:
    /** Apre la finesta di dialogo per l'aggiunta di un titolo di studio. */
    void openAddTitleDialog();

    /** Aggiunge un nuovo TitleWidget alla GUI. L'aggiunta effettiva del titolo di studio all'utente
     *  è lasciata al parent tramite l'emissione del segnale titleToAddSignal( SmartTitolo ).
     *
     * @param QString  Nome della scuola o università.
     * @param QDate  Data di conseguimento diploma o laurea.
     * @param QString  Campo di studio.
     */
    void addNewTitleSlot( const QString&, const QDate&, const QString& );

    /** Rimuove un TitleWidget dalla GUI. La rimozione effettiva del titolo di studio dall'utente
     *  è lasciata al parent tramite tramite l'emissione del segnale titleToRemove( SmartTitolo ).
     *
     * @param SmartTitolo  Titolo di studio da rimuovere.
     */
    void removeTitleSlot( const SmartTitolo& );

    /** Nel caso il titolo di studio aggiornato sia l'ultimo, notifica il parent la necessità di
     *  aggiornare le informazioni presenti nell'header del profilo.
     *
     * @param SmartTitolo  Titolo di studio aggiornato.
     */
    void updateTitleInfoSlot( const SmartTitolo& );
};

#endif // EDUCATIONSWIDGET_H
