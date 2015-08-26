#ifndef PERSONALPROFILEWIDGET_H
#define PERSONALPROFILEWIDGET_H

#include <QWidget>
#include "smartlavoro.h"
#include "profilewidget.h"
#include "smarttitolo.h"
#include "smartutente.h"

class QPushButton;

class PersonalProfileWidget : public ProfileWidget {
    Q_OBJECT
private:
    QPushButton *editProfileButton;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale mostrare le informazioni.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit PersonalProfileWidget( const SmartUtente&, QWidget *parent = 0 );
signals:
    /** */
    void showContactSignal( const SmartUtente& );

    /** */
    void removeContactSignal( const SmartUtente& );
protected slots:
    /** */
    void openEditProfileDialog();

    /** */
    void updateProfileInfoSlot( const QString&, const QString& );

    /** */
    void jobToAddSlot( const SmartLavoro& );

    /** */
    void jobToRemoveSlot( const SmartLavoro& );

    /** */
    void updateLastJobInfoSlot( const SmartLavoro& );

    /** */
    void titleToAddSlot( const SmartTitolo& );

    /** */
    void titleToRemoveSlot( const SmartTitolo& );

    /** */
    void updateLastTitleInfoSlot( const SmartTitolo& );

    /** */
    void contactToRemoveSlot( const SmartUtente& );
};

#endif // PERSONALPROFILEWIDGET_H
