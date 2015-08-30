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
    connect( tableView, SIGNAL( clicked( const QModelIndex& ) ),
             model, SLOT( tableClickedSlot( const QModelIndex& ) ) );
    connect( model, SIGNAL( openChangeUserTypeSignal( const QModelIndex& ) ),
             this, SLOT( openChangeUserTypeSlot( const QModelIndex& ) ) );
}

// METODO UserListWidget::setupUI
void UserListWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    proxyModel->sort( 0, Qt::AscendingOrder );
    proxyModel->setDynamicSortFilter( true );

    tableView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    tableView->setAlternatingRowColors( true );
    tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    tableView->setSortingEnabled( true );
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

// METODO UserListWidget::loadUserList
void UserListWidget::loadUserList() {
    QList<QVector<QString> > l = model->getList();

    if( l.isEmpty() )
        qDebug() << "No user found!";
    else {
        QListIterator<QVector<QString> > it( l );
        while( it.hasNext() ) {
            QVector<QString> aux = it.next();
            addUser( aux[0], aux[1], aux[2], aux[3] );
        }
    }
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

// SLOT UserListWidget::openChangeUserTypeSlot
void UserListWidget::openChangeUserTypeSlot( const QModelIndex& i ) {
    QString username = model->data( model->index( i.row(), 0 ), Qt::DisplayRole ).toString();

    if( usersList.contains( username ) ) {
        ChangeUserTypeDialog *changeUserTypeDialog =
                new ChangeUserTypeDialog( usersList.value( username ), this );

        changeUserTypeDialog->exec();
    }
}
