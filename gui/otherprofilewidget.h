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
    QLabel *lastExperienceLabel;
    QLabel *lastEducationLabel;
    QLabel *connectionsNumber;

    QPushButton *backgroundTabButton;
    QPushButton *connectionsTabButton;

    QPushButton *addContactButton;
    QPushButton *removeContactButton;

    QWidget *backgroundTab;
    QLabel *experiencesLabel;
    ExperiencesWidget *experiencesWidget;
    QLabel *educationsLabel;
    EducationsWidget *educationsWidget;

    ConnectionsWidget *connectionsTab;

    /** Inizializza la UI in base alle informazioni visualizzabili.
     *
     * @param QList<QString>  Lista delle informazioni visualizzabili.
     */
    void initUI( QList<QString> );

    /** Realizza la UI. Mostra la GUI.
     *
     * @param bool  true se è un contatto dell'utente del client; 0 altrimenti.
     */
    void setupUI( bool );
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale mostrare le informazioni.
     * @param QList<QString>  Lista delle informazioni da visualizzare.
     * @param bool  true se è un contatto dell'utente del client; 0 altrimenti.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit OtherProfileWidget( const SmartUtente&, QList<QString>, bool, QWidget *parent = 0 );
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

    /** Mostra la scheda della panoramica dell'utente. */
    void showBackgroundTab();

    /** Mostra la scheda dei contatti dell'utente. */
    void showConnectionsTab();

    /** Mostra la scheda delle altre informazioni dell'utente. */
    void showOtherInfoTab();
};

#endif // OTHERPROFILEWIDGET_H
