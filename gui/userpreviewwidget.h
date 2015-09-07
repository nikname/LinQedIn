#ifndef USERPREVIEWWIDGET_H
#define USERPREVIEWWIDGET_H

#include <QWidget>
#include "smartutente.h"

class QLabel;
class QPushButton;

class UserPreviewWidget : public QWidget {
    Q_OBJECT
private:
    SmartUtente user;

    QLabel *profilePicLabel;

    QLabel *userLabel;
    QLabel *lastJobLabel;
    QPushButton *userInfoButton;
    QPushButton *removeUserButton;

    /** Inizializza la UI in base alle informazioni visualizzabili.
     *
     * @param QList<QString>  Lista delle informazioni visualizzabili.
     */
    void initUI( QList<QString> );

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
    /** Costruttore ad 3 parametri con 2 parametri di default.
     *
     * @param SmartUtente  Utente del quale mostrare l'anteprima.
     * @param QList<QString>  Lista delle informazioni visualizzabili in base dall'utente.
     * @param QWidget  Puntatore al QWidget parent. Se nullo si riferisce a quello top-level.
     */
    explicit UserPreviewWidget( const SmartUtente&, QList<QString> = QList<QString>(),
                                QWidget *parent = 0 );

    /** Ritorna l'utente associato all'anteprima.
     *
     * @return SmartUtente  Utente dell'anteprima.
     */
    SmartUtente getUser();

    /** Metodo di utilità. Nasconde il pulsante di rimozione contatto. */
    void hideRemoveUserButton() const;
signals:
    /** Notifica il parent quale contatto è da rimuovere.
     *
     * @param SmartUtente  Contatto da riumuovere.
     */
    void removeUserSignal( const SmartUtente& );

    /** Notifica il parent di quale utente mostrare il profilo.
     *
     * @param SmartUtente  Utente del quale visualizzare il profilo.
     */
    void showUserSignal( const SmartUtente& );
public slots:
    /** Emette il segnale removeUserSignal( SmartUtente ). */
    void removeUser();

    /** Emette il sengale showUserSignal( SmartUtente ). */
    void showUser();
};

#endif // USERPREVIEWWIDGET_H
