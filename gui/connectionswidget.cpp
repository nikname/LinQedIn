#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "connectionswidget.h"
#include "utente.h"
#include "userpreviewwidget.h"

// COSTRUTTORE ConnectionsWidget
ConnectionsWidget::ConnectionsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent ),
    contactsList( su->getContactsList() )
{
    initUI();
    setupUI();
}

// METODO ConnectionsWidget::initUI
void ConnectionsWidget::initUI() {
    userPreviewWidgetsLayout = new QGridLayout( this );

    for( int i = 0; i < contactsList.size(); i++ )
        userPreviewWidgetsList.append( new UserPreviewWidget( contactsList[i], this ) );
}

// METODO ConnectionsWidget::setupUI
void ConnectionsWidget::setupUI() {
    userPreviewWidgetsLayout->setMargin( 0 );

    int j = 0;
    for( int i = 0; i < userPreviewWidgetsList.size(); i++ ) {
        QGridLayout *aux = dynamic_cast<QGridLayout *>( userPreviewWidgetsLayout );
        aux->addWidget( userPreviewWidgetsList[i], static_cast<int>( i / 2 ), j );
        connect( userPreviewWidgetsList[i], SIGNAL( removeUserSignal( SmartUtente ) ),
                 this, SLOT( removeUserSlot( SmartUtente ) ) );
        j = ( j + 1 ) % 2;
    }
}

// SLOT ConnectionsWidget::removeUserSlot
void ConnectionsWidget::removeUserSlot( const SmartUtente& su ) {
    int pos = contactsList.indexOf( su );
    if( pos > -1 )
        contactsList.remove( pos );

    for( int i = 0; i < userPreviewWidgetsList.size(); i++ ) {
        if( userPreviewWidgetsList[i]->getUser() == su ) {
            QGridLayout *layout = dynamic_cast<QGridLayout *>( userPreviewWidgetsLayout );
            layout->removeWidget( userPreviewWidgetsList[i] );

            UserPreviewWidget *aux = userPreviewWidgetsList.takeAt( i );
            delete aux;

            for( i; i < userPreviewWidgetsList.size(); i++ ) {
                layout->removeWidget( userPreviewWidgetsList[i] );
                layout->addWidget( userPreviewWidgetsList[i], static_cast<int>( i / 2 ), i % 2 );
            }
        }
    }

    emit contactToRemoveSignal( su );
}
