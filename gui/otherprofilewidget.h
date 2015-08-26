#ifndef OTHERPROFILEWIDGET_H
#define OTHERPROFILEWIDGET_H

#include <QWidget>
#include "smartlavoro.h"
#include "profilewidget.h"
#include "smarttitolo.h"
#include "smartutente.h"

class QPushButton;

class OtherProfileWidget : public ProfileWidget {
    Q_OBJECT
private:
    QPushButton *addContactButton;
    QPushButton *removeContactButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI.
     *
     * @param bool  true se è un contatto dell'utente del client; 0 altrimenti.
     */
    void setupUI( bool );
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale mostrare le informazioni.
     * @param bool  true se è un contatto dell'utente del client; 0 altrimenti.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit OtherProfileWidget( const SmartUtente&, bool, QWidget *parent = 0 );
signals:
    /** */
    void showContactSignal( const SmartUtente& );

    /** */
    void addContactSignal( const SmartUtente& );

    /** */
    void removeContactSignal( const SmartUtente& );
protected slots:
    /** */
    void addContact();

    /** */
    void removeContact();
};

#endif // OTHERPROFILEWIDGET_H
