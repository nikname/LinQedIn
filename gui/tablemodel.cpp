#include "tablemodel.h"
#include "linqedin_admin.h"

// COSTRUTTORE TableModel
TableModel::TableModel( LinQedInAdmin *adminClient, QObject *parent ) :
    QAbstractTableModel( parent ),
    userList( adminClient->getUsersList() ),
    detailIcon( QPixmap( ":/icons/icon/information.png" ) ),
    deleteIcon( QPixmap( ":/icons/icon/delete.png" ) )
{}

// METODO TableModel::rowCount
int TableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return userList.size();
}

// METODO TableModel::columnCount
int TableModel::columnCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return 6;
}

// METODO TableModel::date
QVariant TableModel::data( const QModelIndex &index, int role ) const {
    if( !index.isValid() )
        return QVariant();

    if( index.row() >= userList.size() || index.row() < 0 )
        return QVariant();

    if( role == Qt::DisplayRole ) {
        SmartUtente user = userList.at( index.row() );

        switch( index.column() ) {
        case 0: return user->getUsername();
        case 1: return user->getName();
        case 2: return user->getSurname();
        case 3: return user->getAccountType();
        }
    }

    if( role == Qt::DecorationRole ) {
        switch ( index.column() ) {
        case 4: return detailIcon;
        case 5: return deleteIcon;
        }
    }

    if( role == Qt::SizeHintRole ) {
        switch ( index.column() ) {
        case 4: return detailIcon.size();
        case 5: return deleteIcon.size();
        }
    }

    return QVariant();
}

// METODO TableModel::headerData
QVariant TableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole )
        return QVariant();

    if( orientation == Qt::Horizontal ) {
        switch ( section ) {
        case 0: return tr( "Username" );
        case 1: return tr( "Name" );
        case 2: return tr( "Surname" );
        case 3: return tr( "Type" );
        case 4: return tr( "Details" );
        case 5: return tr( "Delete" );
        }
    }
    if( orientation == Qt::Vertical )
        return QString( "%1" ).arg( section + 1 );

    return QVariant();
}

// METODO TableModel::getList
QVector<SmartUtente> TableModel::getList() {
    return userList;
}
