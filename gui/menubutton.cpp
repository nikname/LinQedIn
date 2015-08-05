#include "menubutton.h"

MenuButton::MenuButton( QString label, QWidget *parent ) :
    QPushButton( label, parent )
{
    this->setFixedHeight( 50 );
    this->setStyleSheet(
        "MenuButton {"
            "padding: 0 10px;"
            "border: 3px solid #069;"
            "outline: 0;"
        "}"
        "MenuButton:hover {"
            "padding: 0 10px;"
            "border-bottom-color: white;"
            "outline: 0;"
        "}"
    );
}
