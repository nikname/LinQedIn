#include <QDebug>
#include <QHeaderView>
#include <QPushButton>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>

#include "changeusertypedialog.h"
#include "gui/tablemodel.h"
#include "gui/userlist_widget.h"
#include "linqedin_admin.h"
#include "utente.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( const QVector<SmartUtente> v, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    table = new TableModel( v, this );

    tableView = new QTableView( this );
    tableView->setModel( table );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setStyleSheet( "background: white" );

    connect( tableView, SIGNAL( clicked( const QModelIndex& ) ),
             table, SIGNAL( tableClickedSignal( const QModelIndex& ) ) );
             // table, SLOT( tableClickedSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( updateUserListSignal( const QModelIndex& ) ),
             this, SLOT( updateUserListSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( openChangeAccountTypeSignal( const QModelIndex& ) ),
             this, SLOT( openChangeAccountTypeSlot( const QModelIndex& ) ) );
    connect( table, SIGNAL( removeContactSignal( const QModelIndex& ) ),
             this, SLOT( removeContactSlot( const QModelIndex& ) ) );
    connect( this, SIGNAL( updateContactsListSignal(const SmartUtente&) ),
             this, SLOT( updateContactsListSlot( const SmartUtente& ) ) );

    loadUserList();

    layout->addWidget( tableView );

    setLayout( layout );
}

// DISTRUTTORE UserListWidget
UserListWidget::~UserListWidget() {
    delete table;
    delete tableView;
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
void UserListWidget::updateUserListSlot( LinQedInAdmin* admin ) {
    table->setList( admin->getUsersList() );
}

void UserListWidget::updateUserListSlot( const QModelIndex& i ) {
    emit updateUserListSignal( table->data( table->index( i.row(), 0 ), Qt::DisplayRole ).toString() );
}

void UserListWidget::openChangeAccountTypeSlot( const QModelIndex& i ) {
    QString username = table->data( table->index( i.row(), 0 ), Qt::DisplayRole ).toString();
    QString type = table->data( table->index( i.row(), i.column() - 1 ), Qt::DisplayRole ).toString();
    ChangeUserTypeDialog *changeUserTypeDialog = new ChangeUserTypeDialog( username, type, this );
    connect( changeUserTypeDialog, SIGNAL( changeAccountTypeSignal( const QString&, const QString& ) ),
             this, SIGNAL( updateUserListSignal( const QString&, const QString& ) ) );
    changeUserTypeDialog->exec();
}

void UserListWidget::removeContactSlot( const QModelIndex& i ) {
    emit updateContactsSignal( table->data( table->index( i.row(), 0 ), Qt::DisplayRole ).toString() );
}

void UserListWidget::updateContactsListSlot( const SmartUtente& su ) {
    //table->setList( su->getContactsList() );
}
