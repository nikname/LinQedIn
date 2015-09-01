#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class MySortFilterProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
private:
    QMap<int, QString> columnPatterns;
protected:
    /** */
    bool filterAcceptsRow( int, const QModelIndex& ) const Q_DECL_OVERRIDE;

    /** */
    //bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;
public:
    /** Costruttore ad 1 parametro con 1 parametro di default.
     *
     * @param QObject
     */
    explicit MySortFilterProxyModel( QObject *parent = 0 );

    /** */
    void setFilterKeyColumns( const QList<int>& = QList<int>() );

    /** */
    void addFilterFixedString( int, const QString& );
signals:

public slots:

};

#endif // MYSORTFILTERPROXYMODEL_H
