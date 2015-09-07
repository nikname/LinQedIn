#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class MySortFilterProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
private:
    QMap<int, QString> columnPatterns;
protected:
    /** Override. Permette di eseguire la ricerca su più colonne.
     *
     * @param int  Indice della riga della tabella.
     * @param QModelIndex
     */
    bool filterAcceptsRow( int, const QModelIndex& ) const Q_DECL_OVERRIDE;
public:
    /** Costruttore ad 1 parametro con 1 parametro di default.
     *
     * @param QObject  Parent.
     */
    explicit MySortFilterProxyModel( QObject *parent = 0 );

    /** Aggiunge una lista di colonne alle colonne da considerare.
     *
     * @param QList<int>  Lista di indici delle colonne da considerare.
     */
    void setFilterKeyColumns( const QList<int>& = QList<int>() );

    /** Aggiunge la stringa da utilizzare come filtro nella colonna.
     *
     * @param int  Indice della colonna alla quale aggiungere un filtro.
     * @param QString  Filtro da applicare alla colonna.
     */
    void addFilterFixedString( int, const QString& );
signals:

public slots:

};

#endif // MYSORTFILTERPROXYMODEL_H
