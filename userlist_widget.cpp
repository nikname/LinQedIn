#include "userlist_widget.h"
#include <QTableWidget>

UserListWidget::UserListWidget( LinQedInAdmin *adminClient, QWidget *parent ) :
    QTabWidget( parent )
{
    table = new TableModel( adminClient, this );

    setupTabs();
}

void UserListWidget::setupTabs() {
    QStringList tabs;
    tabs << "Tutti" << "Basic" << "Business" << "Express";

    for( int i = 0; i < tabs.size(); i++ ) {
        QString str = tabs.at( i );

        QTableWidget *tableWidget = new QTableWidget;
        tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
        tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );

        tableWidget->setSortingEnabled( true );

        addTab( tableWidget, str );
    }
}
