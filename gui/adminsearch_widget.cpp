#include "gui/adminsearch_widget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>

// COSTRUTTORE AdminSearchWidget
AdminSearchWidget::AdminSearchWidget( QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *searchLabel = new QLabel( tr( "Search user" ) );

    search = new QLineEdit();

    checkbox = new QWidget;

    QVBoxLayout *checkboxLayout = new QVBoxLayout;

    checkboxEntry1 = new QCheckBox( "Basic" );
    checkboxEntry2 = new QCheckBox( "Express" );
    checkboxEntry3 = new QCheckBox( "Business" );

    checkboxLayout->addWidget( checkboxEntry1 );
    checkboxLayout->addWidget( checkboxEntry2 );
    checkboxLayout->addWidget( checkboxEntry3 );

    checkbox->setLayout( checkboxLayout );

    searchButton = new QPushButton( tr( "Search" ) );
    connect( searchButton, SIGNAL( clicked() ), this, SLOT( searchUsers() ) );
    searchButton->setStyleSheet(
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );

    resetButton = new QPushButton( tr( "Reset" ) );
    resetButton->setStyleSheet(
        "QPushButton { border: 2px solid #FF1744; border-radius: 5px;"
            "background: #FF1744; color: white; }"
        "QPushButton:pressed { border: 2px solid #FF5252; background: #FF5252; }"
    );

    QWidget *bottomFiller = new QWidget();
    bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    layout->addWidget( searchLabel );
    layout->addWidget( search );
    layout->addWidget( checkbox );
    layout->addWidget( searchButton );
    layout->addWidget( resetButton );
    layout->addWidget( bottomFiller );

    setLayout( layout );

    setStyleSheet(
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QCheckBox { color: white; }"
    );
}

// SLOT AdminSearchWidget::searchUsers()
void AdminSearchWidget::searchUsers() {

}
