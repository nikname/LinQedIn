#include "usersearchwidget.h"

// COSTRUTTORE UserSearchWidget
UserSearchWidget::UserSearchWidget( QWidget *parent ) :
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

    typeCheckbox = new QWidget( this );

    QVBoxLayout *typeCheckboxLayout = new QVBoxLayout( typeCheckbox );
    typeCheckboxLayout->setContentsMargins( 10, 5, 10, 5 );

    typeLabel = new QLabel( tr( "Type" ), typeCheckbox );

    typeCheckboxBasic = new QCheckBox( "Basic", typeCheckbox );
    typeCheckboxBasic->setChecked( true );
    typeCheckboxExecutive = new QCheckBox( "Executive", typeCheckbox );
    typeCheckboxExecutive->setChecked( true );
    typeCheckboxBusiness = new QCheckBox( "Business", typeCheckbox );
    typeCheckboxBusiness->setChecked( true );

    typeCheckboxLayout->addWidget( typeLabel );
    typeCheckboxLayout->addWidget( typeCheckboxBasic );
    typeCheckboxLayout->addWidget( typeCheckboxExecutive );
    typeCheckboxLayout->addWidget( typeCheckboxBusiness );

    typeCheckbox->setLayout( typeCheckboxLayout );
    typeCheckbox->setStyleSheet( "margin: 0" );
    typeCheckbox->setVisible( false );

    fieldCheckbox = new QWidget( this );

    QVBoxLayout *fieldCheckboxLayout = new QVBoxLayout( fieldCheckbox );
    fieldCheckboxLayout->setContentsMargins( 10, 5, 10, 5 );

    fieldLabel = new QLabel( tr( "Field" ), fieldCheckbox );

    fieldCheckboxUsername = new QCheckBox( tr( "Username" ), fieldCheckbox );
    fieldCheckboxUsername->setChecked( true );
    fieldCheckboxName = new QCheckBox( tr( "Name" ), fieldCheckbox );
    fieldCheckboxSurname = new QCheckBox( tr( "Surname" ), fieldCheckbox );

    fieldCheckboxLayout->addWidget( fieldLabel );
    fieldCheckboxLayout->addWidget( fieldCheckboxUsername );
    fieldCheckboxLayout->addWidget( fieldCheckboxName );
    fieldCheckboxLayout->addWidget( fieldCheckboxSurname );

    fieldCheckbox->setLayout( fieldCheckboxLayout );
    fieldCheckbox->setStyleSheet( "margin: 0" );
    fieldCheckbox->setVisible( false );

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
    layout->addWidget( typeCheckbox );
    layout->addWidget( fieldCheckbox );
    layout->addWidget( resetButton );
    layout->addWidget( bottomFiller );

    setLayout( layout );

    setStyleSheet(
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QCheckBox { color: white; }"
    );
}

// SLOT UserSearchWidget::showAdvancedSettings()
void UserSearchWidget::showAdvancedSettings() {
    searchSettingsButton->setVisible( false );
    hideSearchSettingsButton->setVisible( true );
    typeCheckbox->setVisible( true );
    fieldCheckbox->setVisible( true );
}

// SLOT UserSearchWidget::hideAdvancedSettings()
void UserSearchWidget::hideAdvancedSettings() {
    searchSettingsButton->setVisible( true );
    hideSearchSettingsButton->setVisible( false );
    typeCheckbox->setVisible( false );
    fieldCheckbox->setVisible( false );
}

// SLOT UserSearchWidget::searchUsers()
void UserSearchWidget::searchUsers() {

}
