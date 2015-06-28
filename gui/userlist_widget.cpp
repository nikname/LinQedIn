#include "gui/userlist_widget.h"
#include "gui/tablemodel.h"
#include <QDebug>
#include <QTableWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QHeaderView>
#include "utente.h"
#include "linqedin_admin.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( const QVector<SmartUtente> v, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout;

    table = new TableModel( v );

    QTableView *tableView = new QTableView;
    tableView->setModel( table );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setStyleSheet( "background: white" );

    loadUserList();

    layout->addWidget( tableView );

    setLayout( layout );
}

// METODO UserListWidget::addUser
void UserListWidget::addItem( QString username, QString name, QString surname, QString type ) {
    QModelIndex index = table->index( 0, 0 );
    table->setData( index, username, Qt::EditRole );
    index = table->index( 0, 1 );
    table->setData( index, name, Qt::EditRole );
    index = table->index( 0, 2 );
    table->setData( index, surname, Qt::EditRole );
    index = table->index( 0, 3 );
    table->setData( index, type, Qt::EditRole );
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
            addItem( aux->getUsername(), aux->getName(), aux->getSurname(), aux->getAccountType() );
        }
    }
}

// SLOT UserListWidget::updateUserListSlot
void UserListWidget::updateUserListSlot( LinQedInAdmin* admin ) {
    table->setList( admin->getUsersList() );
}
