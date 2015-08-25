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

    /** Inizializza la UI. */
    void initUI();

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

    /** */
    SmartUtente getUser();

    /** */
    void hideRemoveUserButton();
signals:
    /** */
    void removeUserSignal( const SmartUtente& );

    /** */
    void showUserSignal( const SmartUtente& );
public slots:
    /** */
    void removeUser();

    /** */
    void showUser();
};

#endif // USERPREVIEWWIDGET_H
