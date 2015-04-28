#include "tablemodel.h"
#include "linqedin_admin.h"

#include "utente.h"
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_express.h"

// COSTRUTTORE TableModel
TableModel::TableModel( LinQedInAdmin *adminClient, QObject *parent ) :
    QAbstractTableModel( parent )
{
    userList = adminClient->getUsersList();
}

// METODO TableModel::rowCount
int TableModel::rowCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return userList.size();
}

// METODO TableModel::columnCount
int TableModel::columnCount( const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return 4;
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
        case 0:
            return user->getUsername();
        case 1:
            return user->getName();
        case 2:
            return user->getSurname();
        case 3:
            if( dynamic_cast<UtenteBasic*>( user.operator ->() ) )
                return QString( "Utente Basic" );
            if( dynamic_cast<UtenteBusiness*>( user.operator ->() ) )
                return QString( "Utente Business" );
            return QString( "Utente Express" );
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
        case 0:
            return tr( "Username" );
        case 1:
            return tr( "Nome" );
        case 2:
            return tr( "Cognome" );
        case 3:
            return tr( "Tipo" );
        }
    }

    return QVariant();
}

// METODO TableModel::flags
Qt::ItemFlags TableModel::flags( const QModelIndex &index ) const {
    if( !index.isValid() )
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags( index ) | Qt::ItemIsEditable;
}

// METODO TableModel::setData
bool TableModel::setData( const QModelIndex &index, const QVariant &value, int role ) {
    qDebug() << "#";

    if( index.isValid() && role == Qt::EditRole ) {
        int row = index.row();

        SmartUtente u = userList.value( row );

        switch ( index.column() ) {
        case 0:
            break;
        case 1:
            //u->setName( value.toString() );
            break;
        case 2:
            //u->setSurname( value.toString() );
            break;
        case 3:
            break;
        default:
            return false;
        }

        //userList.replace( row, u );
        emit( dataChanged( index, index ) );

        return true;
    }

    return false;
}

bool TableModel::insertRows( int position, int rows, const QModelIndex &index ) {
    Q_UNUSED( index );
    beginInsertRows( QModelIndex(), position, position + rows - 1 );

    for( int row = 0; row < rows; row++ ) {
        SmartUtente su( new UtenteBasic( "username", "name", "surname" ) );
        userList.push_back( su );
    }

    endInsertRows();
    return true;
}

// METODO TableModel::getList
QVector<SmartUtente> TableModel::getList() {
    return userList;
}
