#include "adminsearch_widget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

AdminSearchWidget::AdminSearchWidget( QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *searchLabel = new QLabel( tr( "Search user" ) );

    search = new QLineEdit();

    QPushButton *searchButton = new QPushButton( tr( "Search" ) );

    QWidget *bottomFiller = new QWidget();
    bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    layout->addWidget( searchLabel );
    layout->addWidget( search );
    layout->addWidget( searchButton );
    layout->addWidget( bottomFiller );

    setLayout( layout );

    setStyleSheet(
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );
}
