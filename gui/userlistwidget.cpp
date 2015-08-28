#include <QDebug>
#include <QHeaderView>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include "changeusertypedialog.h"
#include "linqedin_admin.h"
#include "tablemodel.h"
#include "userlistwidget.h"
#include "utente.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( const QVector<SmartUtente> v, QWidget *parent ) :
    usersList( v ),
    QWidget( parent )
{
    initUI();
    setupUI();
}

// METODO UserListWidget::initUI
void UserListWidget::initUI() {
    model = new TableModel( usersList, this );
    tableView = new QTableView( this );
    proxyModel = new QSortFilterProxyModel( this );

    connect( tableView, SIGNAL( clicked( const QModelIndex& ) ),
             model, SLOT( tableClickedSlot( const QModelIndex& ) ) );
    connect( model, SIGNAL( userToRemoveSignal( const QModelIndex& ) ),
             this, SLOT( userToRemoveSlot( const QModelIndex& ) ) );
    connect( model, SIGNAL( openChangeUserTypeSignal( const QModelIndex& ) ),
             this, SLOT( openChangeUserTypeSlot( const QModelIndex& ) ) );
    connect( this, SIGNAL( updateTableRowSignal( const SmartUtente& ) ),
             model, SLOT( updateTableRowSlot( const SmartUtente& ) ) );
}

// METODO UserListWidget::setupUI
void UserListWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    proxyModel->setSourceModel( model );
    proxyModel->sort( 0, Qt::AscendingOrder );
    proxyModel->setDynamicSortFilter( true );

    tableView->setModel( proxyModel );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setStyleSheet( "background: white" );

    loadUserList();

    layout->addWidget( tableView );

    setStyleSheet(
        "QScrollBar:vertical { padding-left: 2px; width: 6px; }"
        "QScrollBar::handle:vertical { background: rgba(0,0,0,0.38); border-radius: 2px;"
            "min-height: 10px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { border: none; }"
        "QScrollBar:horizontal { padding-top: 2px; height: 6px; }"
        "QScrollBar::handle:horizontal { background: rgba(0,0,0,0.38); border-radius: 2px;"
            "min-height: 10px; }"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { border: none; }"
    );
}

// METODO UserListWidget::addUser
void UserListWidget::addItem( QString username, QString name, QString surname, QString type ) {
    QModelIndex index = model->index( 0, 0 );
    model->setData( index, username, Qt::EditRole );
    index = model->index( 0, 1 );
    model->setData( index, name, Qt::EditRole );
    index = model->index( 0, 2 );
    model->setData( index, surname, Qt::EditRole );
    index = model->index( 0, 3 );
    model->setData( index, type, Qt::EditRole );
}

// METODO UserListWidget::loadUserList
void UserListWidget::loadUserList() {
    QVector<SmartUtente> v = model->getList();

    if( v.isEmpty() )
        qDebug() << "No user found!";
    else {
        QVectorIterator<SmartUtente> it( v );
        while( it.hasNext() ) {
            SmartUtente aux = it.next();
            addItem( aux->getUsername(), aux->getName(), aux->getSurname(), aux->getAccountType() );
        }
    }
}

// SLOT UserListWidget::updateUserListSlot
void UserListWidget::updateUserListSlot( LinQedInAdmin* admin, const QString& un ) {
    emit updateTableRowSignal( admin->findUser( un ) );

    // table->setList( admin->getUsersList() );
}

// SLOT UserListWidget::userToRemoveSlot
void UserListWidget::userToRemoveSlot( const QModelIndex& i ) {
    emit updateListUserRemovedSignal(
                model->data( model->index( i.row(), 0 ), Qt::DisplayRole ).toString() );
}

// SLOT UserListWidget::openChangeUserTypeSlot
void UserListWidget::openChangeUserTypeSlot( const QModelIndex& i ) {
    QString username = model->data( model->index( i.row(), 0 ), Qt::DisplayRole ).toString();
    QString type = model->data(
                model->index( i.row(), i.column() - 1 ), Qt::DisplayRole ).toString();

    ChangeUserTypeDialog *changeUserTypeDialog = new ChangeUserTypeDialog( username, type, this );
    connect( changeUserTypeDialog, SIGNAL( changeUserTypeSignal( const QString&, const QString& ) ),
             this, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ) );
    changeUserTypeDialog->exec();
}
