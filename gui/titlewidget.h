#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "smarttitolo.h"

class QLabel;
class QPushButton;

class TitleWidget : public QWidget {
    Q_OBJECT
private:
    SmartTitolo title;

    QLabel *titleIconLabel;

    QLabel *schoolLabel;
    QLabel *dateAttendedLabel;
    QLabel *fieldOfStudyLabel;

    QPushButton *removeTitleButton;
    QPushButton *editTitleButton;

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
     * @param SmartTitolo  Titolo di studio dal quale creare il widget.
     * @param QWidget  Puntatore al QWidget parent. Se nullo si riferisce a quello top-level.
     */
    explicit TitleWidget( const SmartTitolo&, QWidget *parent = 0 );

    /** Ritorna il titolo di studio associato al widget.
     *
     * @return SmartTitolo  Titolo di studio associato al widget.
     */
    SmartTitolo getTitle();

    /** Metodo di utilità. Nasconde i pulsanti per la modifica e rimozione. */
    void hideToolsButtons();
signals:
    /** Notifica il parent la necessità di rimuovere un titolo di studio.
     *
     * @param SmartTitolo  Titolo di studio da rimuovere.
     */
    void removeTitleSignal( const SmartTitolo& );

    /** Notifica il parent l'aggiornamento di un titolo di studio.
     *
     * @param SmartTitolo  Titolo di studio da aggiornare.
     */
    void updateTitleInfoSignal( const SmartTitolo& );
public slots:
    /** Apre la finesta di dialogo per la modifica del titolo di studio associato al widget. */
    void openEditTitleDialog();

    /** Aggiorna il titolo di studio associato ed il widget.
     *
     * @param QString  Nome della scuola o università.
     * @param QDate  Data di conseguimento diploma o laurea.
     * @param QString  Campo di studio.
     */
    void updateTitleInfoSlot( const QString&, const QDate&, const QString& );

    /** Emette il sengale removeTitleSignal( SmartTitolo ).
     *  Lo slot può essere rimosso esetendendo il segnale al parent.
     */
    void removeTitle();
};

#endif // TITLEWIDGET_H
