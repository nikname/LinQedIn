#include "tablemodel.h"
#include "linqedin_admin.h"

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
int TableModel::columnCount( const QModelIndex & parent ) const {
    Q_UNUSED( parent );
    return 8;
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
            return QString( "Utente" );
        case 1:
            return user->getUsername();
        case 2:
            return user->getName();
        case 3:
            return user->getSurname();
        case 4:
            if( dynamic_cast<UtenteBasic*>( user.operator ->() ) )
                return QString( "Utente Basic" );
            if( dynamic_cast<UtenteBusiness*>( user.operator ->() ) )
                return QString( "Utente Business" );
            return QString( "Utente Express" );
        default:
            return QVariant();
        }
    }

    return QVariant();
}


