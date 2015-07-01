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
    QPixmap removeContactIcon;
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param QVector<SmartUtente>  Utenti da visualizzare sulla tabella.
     * @param QObject  QObject padre.
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

    /** Ritorna un vettore contenente degli oggetti SmartUtente contenuti nella tabella.
     *
     * @return QVector<SmartUtente>  Vettore degli oggetti SmartUtente contenuti nella tabella.
     */
    QVector<SmartUtente> getList();

    /** Imposta la lista degli oggetti di tipo SmartUtente della tabella.
     *  Emette il segnale layoutChanged() per notificare la view della modifica.
     *
     * @param QVector<SmartUtente>  Nuovo vettore di oggetti SmartUtente da mostrare nella tabella.
     */
    void setList( const QVector<SmartUtente> );
signals:
    /** Notifica il model quale cella è stata selezionata.
     *
     * @param QModelIndex  Indice della tabella selezionato.
     */
    void tableClickedSignal( const QModelIndex& );

    /** Notifica che l'utente corrispondente all'indice della tabella è da rimuovere.
     *
     * @param QModelIndex  Indice della tabella selezionato.
     */
    void removeUserSignal( const QModelIndex& );

    /** Notifica al parent quale riga della tabella (utente) è da rimuovere.
     *
     * @param QModelIndex  Indice delle tabella dove la riga corrisponde all'utente da rimuovere.
     */
    void updateUserListSignal( const QModelIndex& );

    /** Notifica il parent che è stata selezionata la cella corrispondente al cambio di tipologia
     *  dell'account di un'utente.
     *
     * @param QModelIndex  Indice della tabella, dove, la riga corrisponde ad un utente del database,
     * mentre la colonna corrisponde al cambio di tipologia dell'account.
     */
    void openChangeAccountTypeSignal( const QModelIndex& );

    /** Notifica al parent quale riga della tabella (contatto) è da rimuovere.
     *
     * @param QModelIndex  Indice della tabella, la quale riga corrisponde al contatto da rimuovere.
     */
    void removeContactSignal( const QModelIndex& );
private slots:
    /** In base all'indice della colonna selezionata, se a questo è associata un'azione, emette un
     *  apposito segnale.
     *
     * @param QModelIndex  Indice della tabella selezionato.
     */
    void tableClickedSlot( const QModelIndex& );
};

#endif // TABLEMODEL_H
