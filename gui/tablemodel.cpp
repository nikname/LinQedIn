#include "tablemodel.h"
#include "linqedin_admin.h" // se omesso: invalid use of incomplete type 'class Utente'

// COSTRUTTORE TableModel
TableModel::TableModel( const QVector<SmartUtente> v, QObject *parent ) :
    QAbstractTableModel( parent ),
    userList( v )
{
    detailIcon = QPixmap( ":/icons/icon/account-switch.png" );
    deleteIcon = QPixmap( ":/icons/icon/delete.png" );
    removeContactIcon = QPixmap( ":icons/icon/account-remove.png" );
}

// METODO TableModel::rowCount
int TableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return userList.size();
}

// METODO TableModel::columnCount
int TableModel::columnCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return 7;
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
        case 6: return removeContactIcon;
        }
    }

    if( role == Qt::SizeHintRole ) {
        switch ( index.column() ) {
        case 4: return detailIcon.size();
        case 5: return deleteIcon.size();
        case 6: return removeContactIcon.size();
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
        case 4: return tr( "Change Type" );
        case 5: return tr( "Delete" );
        case 6: return tr( "Remove" );
        }
    }
    if( orientation == Qt::Vertical )
        return QString( "%1" ).arg( section + 1 );

    return QVariant();
}

// METODO TableModel::removeRows
bool TableModel::removeRows( int row, int count, const QModelIndex& parent ) {
    Q_UNUSED( parent );
    beginRemoveRows( QModelIndex(), row, row + count - 1 );
    while( count ) {
        userList.removeAt( row );
        count--;
    }
    endRemoveRows();
    emit layoutChanged();
    return true;
}

// METODO TableModel::getList
QVector<SmartUtente> TableModel::getList() {
    return userList;
}

// METODO TableModel::setList
void TableModel::setList( const QVector<SmartUtente> v ) {
    //emit layoutAboutToBeChanged();
    userList = v;
    emit layoutChanged();
}

// SLOT TableModel::tableClickedSlot
void TableModel::tableClickedSlot( const QModelIndex& i ) {
    switch( i.column() ) {
    case 4:
        emit openChangeUserTypeSignal( i );
        break;
    case 5:
        emit userToRemoveSignal( i );
        removeRows( i.row(), 1, QModelIndex() );
        break;
    case 6:
        emit contactToRemoveSignal( i );
        break;
    default: break;
    }
}
