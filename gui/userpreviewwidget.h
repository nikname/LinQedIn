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

    QWidget *toolWidget;
    QPushButton *viewContactButton;
    QPushButton *removeContactButton;

    /** Applica delle proprietà ai pulsanti degli strumenti della preview.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setToolButtonProperties( QPushButton* );
public:
    /** */
    explicit UserPreviewWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // USERPREVIEWWIDGET_H
