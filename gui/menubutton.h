#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>

class MenuButton : public QPushButton {
    Q_OBJECT
public:
    explicit MenuButton( QString label, QWidget *parent = 0 );
signals:

public slots:

};

#endif // MENUBUTTON_H
