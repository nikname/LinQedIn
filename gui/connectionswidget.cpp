#include <QLabel>
#include <QVBoxLayout>
#include "connectionswidget.h"
#include "utente.h"
#include "usergridwidget.h"

// COSTRUTTORE ConnectionsWidget
ConnectionsWidget::ConnectionsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    widgetsWrapper = new QWidget( this );
    widgetsWrapper->setStyleSheet( "background: white" );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( widgetsWrapper );

    connectionsLabel = new QLabel( tr( "Connections" ), this );
    connectionsLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 )" );

    wrapperLayout->addWidget( connectionsLabel );

    contactsList = su->getContactsList();
    for( int i = 0; i < contactsList.size(); i++ ) {
        UserGridWidget *aux = new UserGridWidget( contactsList[i], widgetsWrapper );
        userGridWidget.append( aux );
        wrapperLayout->addWidget( aux );
    }

    layout->addWidget( widgetsWrapper );

    setLayout( layout );
}
