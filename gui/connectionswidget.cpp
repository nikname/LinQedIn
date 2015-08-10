#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "connectionswidget.h"
#include "utente.h"
#include "userpreviewwidget.h"

// COSTRUTTORE ConnectionsWidget
ConnectionsWidget::ConnectionsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    widgetsWrapper = new QWidget( this );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( widgetsWrapper );

    QWidget *usersGridWidget = new QWidget( widgetsWrapper );

    QGridLayout *usersGridLayout = new QGridLayout( usersGridWidget );

    contactsList = su->getContactsList();
    int j = 0;
    for( int i = 0; i < contactsList.size(); i++ ) {
        UserPreviewWidget *aux = new UserPreviewWidget( contactsList[i], widgetsWrapper );
        userPreviewWidget.append( aux );
        usersGridLayout->addWidget( aux, static_cast<int>( i/2 ), j );
        j = ( j + 1 ) % 2;
    }

    wrapperLayout->addWidget( usersGridWidget );

    layout->addWidget( widgetsWrapper );

    setLayout( layout );
}
