#include <QLabel>
#include <QPushButton>
#include "otherinfowidget.h"
#include "profilewidget.h"
#include "utente.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent ),
    user( su )
{
    initUI();
    setupUI();
}

// DISTRUTTORE ProfileWidget
ProfileWidget::~ProfileWidget() {}

// METODO ProfileWidget::initUI
void ProfileWidget::initUI() {
    profilePicLabel = new QLabel( this );

    profileSummary = new QWidget( this );
    nameSurnameLabel = new QLabel(
                "<h1>" + user->getName() + " " + user->getSurname() + "</h1>", this );

    otherInfoTabButton = new QPushButton( tr( "Other info" ), this );

    tabButtons.append( otherInfoTabButton );

    otherInfoTab = new OtherInfoWidget( user, this );
}

// METODO ProfileWidget::setupUI
void ProfileWidget::setupUI() {
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle-100.png" ) );
    profilePicLabel->setMargin( 20 );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );

    setProfileButtonProperties( otherInfoTabButton );
    setProfileButtonSelected( otherInfoTabButton );
}

// METODO ProfileWidget::setProfileButtonProperties( QPushButton* )
void ProfileWidget::setProfileButtonProperties( QPushButton *button ) {
    button->setFixedHeight( 40 );
    button->setStyleSheet(
        "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
            "color: rgba(0,0,0,0.54); outline: 0; }"
        "QPushButton:hover { border-bottom-color: #069; }"
    );
}

// METODO ProfileWidget::setProfileButtonSelected( QPushButton* )
void ProfileWidget::setProfileButtonSelected( QPushButton *button ) {
    for( int i = 0; i < tabButtons.size(); i++ ) {
        QPushButton *aux = tabButtons[i];
        if( aux ) {
            if( aux == button ) {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                        "color: rgba(0,0,0,0.87); border-bottom-color: #069; outline: 0; }"
                );
            } else {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                        "color: rgba(0,0,0,0.54); outline: 0; }"
                    "QPushButton:hover { border-bottom-color: #069; }"
                );
            }
        } else { } // throw ...
    }
}
