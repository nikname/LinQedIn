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
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"

// COSTRUTTORE UserListWidget
UserListWidget::UserListWidget( const QVector<SmartUtente> v, QWidget *parent ) :
    QWidget( parent )
{
    for( int i = 0; i < v.size(); i++ )
        usersList.insert( v[i]->getUsername(), v[i] );

    model = new TableModel( usersList.values(), this );

    proxyModel = new QSortFilterProxyModel( this );
    proxyModel->setSourceModel( model );

    tableView = new QTableView( this );
    tableView->setModel( proxyModel );

    initUI();
    setupUI();
}

// METODO UserListWidget::initUI
void UserListWidget::initUI() {
    connect( tableView->selectionModel(),
             SIGNAL( selectionChanged( QItemSelection, QItemSelection ) ),
             this, SIGNAL( selectionChanged( QItemSelection ) ) );

    connect( this, SIGNAL( changeUserTypeSignal( QString, QString ) ),
             this, SLOT( changeUserTypeSlot( QString, QString ) ) );
}

// METODO UserListWidget::setupUI
void UserListWidget::setupUI() {
    proxyModel->setDynamicSortFilter( true );
    proxyModel->sort( 0, Qt::AscendingOrder );

    tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setStyleSheet( "background: white" );

    QVBoxLayout *layout = new QVBoxLayout( this );
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

// SLOT UserListWidget::addUserTableSlot
void UserListWidget::addUserTableSlot( const SmartUtente& su ) {
    usersList.insert( su->getUsername(), su );
    addUser( su->getUsername(), su->getName(), su->getSurname(), su->getAccountType() );
}

// SLOT UserListWidget::addUser
void UserListWidget::addUser( QString username, QString name, QString surname, QString type ) {
    model->insertRows( 0, 1, QModelIndex() );

    QModelIndex index = model->index( 0, 0, QModelIndex() );
    model->setData( index, username, Qt::EditRole );
    index = model->index( 0, 1 );
    model->setData( index, name, Qt::EditRole );
    index = model->index( 0, 2 );
    model->setData( index, surname, Qt::EditRole );
    index = model->index( 0, 3 );
    model->setData( index, type, Qt::EditRole );
}

// SLOT UserListWidget::removeUser
void UserListWidget::removeUser() {
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();

    foreach( QModelIndex index, indexes ) {
        int row = proxyModel->mapToSource( index ).row();
        model->removeRows( row, 1, QModelIndex() );
    }
}

// SLOT UserListWidget::changeUserTypeSlot
void UserListWidget::changeUserTypeSlot( const QString& un, const QString& t ) {
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel *>( tableView->model() );
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    foreach( QModelIndex index, indexes ) {
        int row = proxy->mapToSource( index ).row();

        QModelIndex typeIndex = model->index( row, 3, QModelIndex() );
        model->setData( typeIndex, t, Qt::DisplayRole );
        qDebug() << t;
    }
}

// SLOT UserListWidget::openChangeTypeDialog
void UserListWidget::openChangeTypeDialog() {
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel *>( tableView->model() );
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    int row = -1;
    QString username;
    QString type;

    QModelIndexList indexes = selectionModel->selectedRows();
    foreach( QModelIndex index, indexes ) {
        row = proxy->mapToSource( index ).row();

        QModelIndex usernameIndex = model->index( row, 0, QModelIndex() );
        QVariant un = model->data( usernameIndex, Qt::DisplayRole );
        type = un.toString();

        QModelIndex typeIndex = model->index( row, 3, QModelIndex() );
        QVariant t = model->data( typeIndex, Qt::DisplayRole );
        type = t.toString();
    }

    ChangeUserTypeDialog *changeUserTypeDialog = new ChangeUserTypeDialog( username, type, this );
    connect( changeUserTypeDialog, SIGNAL( sendDetails( QString, QString ) ),
             this, SIGNAL( changeUserTypeSignal( QString, QString ) ) );

    changeUserTypeDialog->exec();
}

// SLOT UserListWidget::updateUserListSlot
void UserListWidget::updateUserListSlot( const QString& un, const SmartUtente& su ) {
    usersList.remove( un );
    usersList.insert( un, su );
}

// SLOT UserListWidget::clearSelections
void UserListWidget::clearSelections() {
    tableView->clearSelection();
}
