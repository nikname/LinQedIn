#include "tabrete.h"
#include "utente.h"
#include <QVBoxLayout>

// COSTRUTTORE TabRete
TabRete::TabRete( SmartUtente su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *tabLayout = new QVBoxLayout( this );

    contactList = new UserListWidget( su->getContactsList(), this );

    tabLayout->addWidget( contactList );

    setLayout( tabLayout );
}
