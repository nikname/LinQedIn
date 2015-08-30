#include <QSortFilterProxyModel>
#include "tablemodel.h"
#include "utente.h"

// COSTRUTTORE TableModel
TableModel::TableModel( const QList<SmartUtente> v, QObject *parent ) :
    QAbstractTableModel( parent )
{
    for( int i = 0; i < v.size(); i++ ) {
        SmartUtente su = v[i];
        QVector<QString> aux;
        aux.append( su->getUsername() );
        aux.append( su->getName() );
        aux.append( su->getSurname() );
        aux.append( su->getAccountType() );
        usersList.append( aux );
    }

    detailIcon = QPixmap( ":/icons/icon/account-switch.png" );
    deleteIcon = QPixmap( ":icons/icon/account-remove.png" );
}

// METODO TableModel::rowCount
int TableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return usersList.size();
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

    if( index.row() >= usersList.size() || index.row() < 0 )
        return QVariant();

    if( role == Qt::DisplayRole ) {
        QVector<QString> user_info = usersList.at( index.row() );

        switch( index.column() ) {
        case 0: return user_info.at( 0 );
        case 1: return user_info.at( 1 );
        case 2: return user_info.at( 2 );
        case 3: return user_info.at( 3 );
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
        case 4: return tr( "Change Type" );
        case 5: return tr( "Remove" );
        }
    }
    if( orientation == Qt::Vertical )
        return QString( "%1" ).arg( section + 1 );

    return QVariant();
}

// METODO TableModel::insertRows
bool TableModel::insertRows( int position, int rows, const QModelIndex &index ) {
    Q_UNUSED( index );
    beginInsertRows( QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        QVector<QString> aux;
        for( int i = 0; i < 4; i++ )
            aux.append( "" );
        usersList.insert( position, aux );
    }

    endInsertRows();
    return true;
}

// METODO TableModel::removeRows
bool TableModel::removeRows( int position, int rows, const QModelIndex& parent ) {
    Q_UNUSED( parent );
    beginRemoveRows( QModelIndex(), position, position + rows - 1 );

    for( int row = 0; row < rows; ++row )
        usersList.removeAt( position );

    endRemoveRows();
    return true;
}

// METODO TableModel::setData
bool TableModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( index.isValid() && role == Qt::EditRole ) {
        int row = index.row();

        QVector<QString> aux = usersList.value( row );

        switch( index.column() ) {
        case 0:
            aux[0] = value.toString();
            break;
        case 1:
            aux[1] = value.toString();
            break;
        case 2:
            aux[2] = value.toString();
            break;
        case 3:
            aux[3] = value.toString();
            break;
        default: return false;
        }

        usersList.replace( row, aux );
        emit( dataChanged( index, index ) );

        return true;
    }

    return false;
}

// METODO TableModel::getList
QList<QVector<QString> > TableModel::getList() {
    return usersList;
}


// SLOT TableModel::tableClickedSlot
void TableModel::tableClickedSlot( const QModelIndex& i ) {
    switch( i.column() ) {
    case 4:
        emit openChangeUserTypeSignal( i );
        break;
    case 5:
        break;
    default: break;
    }
}
