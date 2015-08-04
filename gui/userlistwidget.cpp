#include <QDebug>
#include <QHeaderView>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>

#include "changeusertypedialog.h"
#include "gui/tablemodel.h"
#include "gui/userlistwidget.h"
#include "linqedin_admin.h"
#include "utente.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( const QVector<SmartUtente> v, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    table = new TableModel( v, this );

    proxyModel = new QSortFilterProxyModel( this );
    proxyModel->setSourceModel( table );
    proxyModel->sort( 0, Qt::AscendingOrder );
    proxyModel->setDynamicSortFilter( true );

    tableView = new QTableView( this );
    tableView->setModel( proxyModel );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setStyleSheet( "background: white" );

    connect( tableView, SIGNAL( clicked( const QModelIndex& ) ),
             table, SLOT( tableClickedSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( userToRemoveSignal( const QModelIndex& ) ),
             this, SLOT( userToRemoveSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( openChangeUserTypeSignal( const QModelIndex& ) ),
             this, SLOT( openChangeUserTypeSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( contactToRemoveSignal( const QModelIndex& ) ),
             this, SLOT( contactToRemoveSlot( const QModelIndex& ) ) );
    connect( this, SIGNAL( updateContactsListSignal(const SmartUtente&) ),
             this, SLOT( updateContactsListSlot( const SmartUtente& ) ) );
    connect( this, SIGNAL( updateTableRowSignal( const SmartUtente& ) ),
             table, SLOT( updateTableRowSlot( const SmartUtente& ) ) );

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

// METODO UserListWidget::hideColumn
void UserListWidget::hideColumn( int i ) {
    tableView->hideColumn( i );
}

// SLOT UserListWidget::updateUserListSlot
void UserListWidget::updateUserListSlot( LinQedInAdmin* admin, const QString& un ) {
    emit updateTableRowSignal( admin->findUser( un ) );

    // table->setList( admin->getUsersList() );
}

// SLOT
void UserListWidget::userToRemoveSlot( const QModelIndex& i ) {
    emit updateListUserRemovedSignal( table->data( table->index( i.row(), 0 ), Qt::DisplayRole )
                                      .toString() );
}

// SLOT
void UserListWidget::openChangeUserTypeSlot( const QModelIndex& i ) {
    QString username = table->data( table->index( i.row(), 0 ), Qt::DisplayRole ).toString();
    QString type = table->data( table->index( i.row(), i.column() - 1 ), Qt::DisplayRole )
            .toString();

    ChangeUserTypeDialog *changeUserTypeDialog = new ChangeUserTypeDialog( username, type, this );
    connect( changeUserTypeDialog, SIGNAL( changeUserTypeSignal( const QString&, const QString& ) ),
             this, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ) );
    changeUserTypeDialog->exec();
}

// SLOT
void UserListWidget::contactToRemoveSlot( const QModelIndex& i ) {
    emit updateListContactRemovedSignal( table->data( table->index( i.row(), 0 ), Qt::DisplayRole )
                                         .toString() );
}

// SLOT
void UserListWidget::updateContactsListSlot( const SmartUtente& su ) {
    //table->setList( su->getContactsList() );
}
