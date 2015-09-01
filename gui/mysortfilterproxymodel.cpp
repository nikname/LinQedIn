#include <QDebug>
#include "mysortfilterproxymodel.h"

// COSTRUTTORE MySortFilterProxyModel
MySortFilterProxyModel::MySortFilterProxyModel( QObject *parent ) :
    QSortFilterProxyModel( parent )
{}

// METODO MySortFilterProxyModel::filterAcceptsRow
bool MySortFilterProxyModel::filterAcceptsRow( int sourceRow, const QModelIndex& sourceParent ) const {
    if( columnPatterns.isEmpty() )
        return true;

    bool test = false;
    for( QMap<int, QString>::const_iterator it = columnPatterns.constBegin();
         it != columnPatterns.constEnd(); ++it )
    {
        QModelIndex index = sourceModel()->index( sourceRow, it.key(), sourceParent );
        test = test || ( index.data().toString().contains( it.value(), Qt::CaseInsensitive ) );
    }
    return test;
}

// METODO MySortFilterProxyModel::setFilterKeyColumns
void MySortFilterProxyModel::setFilterKeyColumns( const QList<int> &filterColumns ) {
    columnPatterns.clear();

    foreach( int column, filterColumns )
        columnPatterns.insert( column, QString() );
}

// METODO MySortFilterProxyModel::addFilterFixedString
void MySortFilterProxyModel::addFilterFixedString( int column, const QString &pattern ) {
    if( !columnPatterns.contains( column ) )
        return;

    columnPatterns[column] = pattern;
}
