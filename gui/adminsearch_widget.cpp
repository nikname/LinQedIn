#include "gui/adminsearch_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>

// COSTRUTTORE AdminSearchWidget
AdminSearchWidget::AdminSearchWidget( QWidget *parent ) :
    QWidget( parent )
{
    layout = new QVBoxLayout( this );

    searchLabel = new QLabel( tr( "Search user" ) );

    search = new QLineEdit( this );

    searchWidget = new QWidget( this );

    QHBoxLayout *searchWidgetLayout = new QHBoxLayout( searchWidget );
    searchWidgetLayout->setMargin( 0 );

    searchButton = new QPushButton( tr( "Search" ), searchWidget );
    searchButton->setStyleSheet(
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );
    connect( searchButton, SIGNAL( clicked() ), this, SLOT( searchUsers() ) );

    searchSettingsButton = new QPushButton( searchWidget );
    searchSettingsButton->setIcon( QIcon( QPixmap( ":/icons/icon/settings.png" ) ) );
    searchSettingsButton->setMaximumWidth( 24 );
    searchSettingsButton->setStyleSheet( "border: none" );
    connect( searchSettingsButton, SIGNAL( clicked() ), this, SLOT( showAdvancedSettings() ) );

    hideSearchSettingsButton = new QPushButton( searchWidget );
    hideSearchSettingsButton->setIcon( QIcon( QPixmap( ":/icons/icon/chevron-up.png" ) ) );
    hideSearchSettingsButton->setMaximumWidth( 24 );
    hideSearchSettingsButton->setStyleSheet( "border: none" );
    hideSearchSettingsButton->setVisible( false );
    connect( hideSearchSettingsButton, SIGNAL( clicked() ), this, SLOT( hideAdvancedSettings() ) );

    checkbox = new QWidget( this );

    QVBoxLayout *checkboxLayout = new QVBoxLayout( checkbox );

    checkboxEntry1 = new QCheckBox( "Basic", checkbox );
    checkboxEntry2 = new QCheckBox( "Express", checkbox );
    checkboxEntry3 = new QCheckBox( "Business", checkbox );

    checkboxLayout->addWidget( checkboxEntry1 );
    checkboxLayout->addWidget( checkboxEntry2 );
    checkboxLayout->addWidget( checkboxEntry3 );

    checkbox->setLayout( checkboxLayout );
    checkbox->setVisible( false );

    searchWidgetLayout->addWidget( searchButton );
    searchWidgetLayout->addWidget( searchSettingsButton );
    searchWidgetLayout->addWidget( hideSearchSettingsButton );

    searchWidget->setLayout( searchWidgetLayout );

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
    layout->addWidget( searchWidget );
    layout->addWidget( checkbox );
    layout->addWidget( resetButton );
    layout->addWidget( bottomFiller );

    setLayout( layout );

    setStyleSheet(
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QCheckBox { color: white; }"
    );
}

// SLOT AdminSearchWidget::showAdvancedSettings()
void AdminSearchWidget::showAdvancedSettings() {
    searchSettingsButton->setVisible( false );
    hideSearchSettingsButton->setVisible( true );
    checkbox->setVisible( true );
}

// SLOT AdminSearchWidget::hideAdvancedSettings()
void AdminSearchWidget::hideAdvancedSettings() {
    searchSettingsButton->setVisible( true );
    hideSearchSettingsButton->setVisible( false );
    checkbox->setVisible( false );
}

// SLOT AdminSearchWidget::searchUsers()
void AdminSearchWidget::searchUsers() {

}
