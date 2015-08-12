#ifndef USERPREVIEWWIDGET_H
#define USERPREVIEWWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;

class UserPreviewWidget : public QWidget {
    Q_OBJECT
private:
    QLabel *profilePicLabel;

    QLabel *userLabel;
    QLabel *lastJobLabel;
    QPushButton *contactInfoButton;
    QPushButton *removeContactButton;

    /** Inizializza la UI.
     *
     * @param  SmartUtente  Utente del quale visualizzare l'anteprima.
     */
    void initUI( const SmartUtente& );

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton * );

    /** Reimplementazione.
     *
     * @param QPaintEvent
     */
    void paintEvent( QPaintEvent * );
public:
    /** */
    explicit UserPreviewWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // USERPREVIEWWIDGET_H
