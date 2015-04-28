#include "gui/userlist_widget.h"
#include "gui/tablemodel.h"
#include <QDebug>
#include <QTableWidget>
#include <QTableView>
#include <QVBoxLayout>
#include "utente.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( LinQedInAdmin *adminClient, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout;

    table = new TableModel( adminClient );

    QTableView *tableView = new QTableView;
    tableView->setModel( table );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    loadUserList();

    layout->addWidget( tableView );

    setLayout( layout );
}

// METODO UserListWidget::addUser
void UserListWidget::addUser( QString username, QString name, QString surname, QString type ) {
    table->insertRows( 0, 1, QModelIndex() );
/**
    QModelIndex index = table->index( 0, 0 );
    table->setData( index, username, Qt::EditRole );
    index = table->index( 0, 1 );
    table->setData( index, name, Qt::EditRole );
    index = table->index( 0, 2 );
    table->setData( index, surname, Qt::EditRole );
    index = table->index( 0, 3 );
    table->setData( index, type, Qt::EditRole );
*/
}

// METODO UserListWidget::loadUserList
void UserListWidget::loadUserList() {
    QVector<SmartUtente> userList = table->getList();

    if( userList.isEmpty() )
        qDebug() << "No user found!";
    else {
        QVectorIterator<SmartUtente> it( userList );
        while( it.hasNext() ) {
            SmartUtente aux = it.next();
            addUser( aux->getUsername(), aux->getName(), aux->getSurname(), "" );
        }
    }
}

