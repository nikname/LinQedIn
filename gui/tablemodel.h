#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QPixmap>
#include "adminwindow.h"
#include "smartutente.h"

class TableModel : public QAbstractTableModel {
    Q_OBJECT
private:
    QVector<SmartUtente> userList;
    QPixmap detailIcon;
    QPixmap deleteIcon;
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param QVector<SmartUtente>  Utenti da visualizzare sulla tabella.
     * @param QObject
     */
    explicit TableModel( const QVector<SmartUtente>, QObject* = 0 );

    /** Ritorna il numero di righe della tabella della lista degli utenti.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelIndex  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @return int  Numero di righe della tabella.
     */
    int rowCount( const QModelIndex& ) const Q_DECL_OVERRIDE;

    /** Ritorna il numero di colonne della tabella della lista degli utenti.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelIndex  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @return int  Numero di colonne della tabella.
     */
    int columnCount( const QModelIndex& ) const Q_DECL_OVERRIDE;

    /** Ritorna il dato immagazzinato sotto l'attributo selezionato all'indice selezionato.
     *  Necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param QModelIndex  Indice per gli oggetti del modello. Se invalido si riferisce all'elemento
     * top-level del modello.
     * @param int  Caratteristica dell'oggetto selezionato.
     * @return QVariant  Oggetto rappresentativo per i tipi Qt principali.
     */
    QVariant data( const QModelIndex&, int ) const Q_DECL_OVERRIDE;

    /** Ritorna l'informazione associata alla riga/colonna selezionata, per l'orientamento desiderato.
     *  Non è necessaria la ridefinizione per le sottoclassi di QAbstractTableModel.
     *
     * @param int  Riga/colonna di interesse.
     * @param Qt::Orientation  Orientamento di interesse.
     * @param int  Caratteristica dell'oggetto selezionato.
     * @return QVariant  Oggetto rappresentativo per i tipi Qt principali.
     */
    QVariant headerData( int, Qt::Orientation, int ) const Q_DECL_OVERRIDE;

    /** */
    QVector<SmartUtente> getList();
};

#endif // TABLEMODEL_H
