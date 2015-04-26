#include "userlist_widget.h"
#include <QTableWidget>

UserListWidget::UserListWidget( LinQedInAdmin *adminClient, QWidget *parent ) :
    QTabWidget( parent )
{
    table = new TableModel( adminClient );
}
