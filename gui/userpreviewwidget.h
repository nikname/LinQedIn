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
public:
    /** */
    explicit UserPreviewWidget( const SmartUtente&, QWidget *parent = 0 );
signals:

public slots:

};

#endif // USERPREVIEWWIDGET_H
