#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "smartutente.h"

class LinQedInAdmin;

class TableModel : public QAbstractTableModel {
    Q_OBJECT
private:
    QVector<SmartUtente> userList;
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit TableModel( QWidget *parent = 0 );

    /** Costruttore a 2 parametri con 1 parametro di default.
     *  Inizializza il campo userList con la lista degli utenti del database.
     *
     * @param LinQedInAdmin  Puntatore all'oggetto LinQedInAdmin.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    TableModel( LinQedInAdmin *adminClient, QWidget *parent = 0 );

    /** Ritorna il numero di righe della tabella della lista degli utenti.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelIndex  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @return int  Numero di righe della tabella.
     */
    int rowCount( const QModelIndex &parent ) const Q_DECL_OVERRIDE;

    /** Ritorna il numero di colonne della tabella della lista degli utenti.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelIndex  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @return int  Numero di colonne della tabella.
     */
    int columnCount( const QModelIndex &parent ) const Q_DECL_OVERRIDE;

    /** Ritorna il dato immagazzinato sotto l'attributo selezionato all'indice selezionato.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelItem  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @param int  Attributo di interesse.
     * @return QVariant  Oggetto rappresentativo per i tipi Qt principali.
     */
    QVariant data( const QModelIndex &index, int role ) const Q_DECL_OVERRIDE;

    QVariant headerData( int section, Qt::Orientation orientation, int role ) const Q_DECL_OVERRIDE;

    Qt::ItemFlag flags( const QModelIndex &index ) const Q_DECL_OVERRIDE;

    bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole )
        Q_DECL_OVERRIDE;

    bool insertRows( int position, int rows, const QModelIndex &index = QModelIndex() )
        Q_DECL_OVERRIDE;

    bool removeRows( int position, int rows, const QModelIndex &index = QModelIndex() )
        Q_DECL_OVERRIDE;

    QVector<SmartUtente> getList();
};

#endif // TABLEMODEL_H
