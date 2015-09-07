#ifndef OTHERPROFILEWIDGET_H
#define OTHERPROFILEWIDGET_H

#include <QWidget>
#include "profilewidget.h"

class ConnectionsWidget;
class EducationsWidget;
class ExperiencesWidget;
class QPushButton;
class SmartUtente;

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
    /** Notifica il parent di aprire il profilo di un contatto. Emesso dalla scheda dei contatti.
     *
     * @param SmartUtente  Utente da visualizzare.
     */
    void showContactSignal( const SmartUtente& );

    /** Notifica il parent di aggiungere un utente ai contatti
     *
     * @param SmartUtente  Utente da aggiungere ai contati.
     */
    void addContactSignal( const SmartUtente& );

    /** Notifica il parent di rimuovere un utente dai contatti.
     *
     * @param SmartUtente  Utente da rimuovere dai contatti.
     */
    void removeContactSignal( const SmartUtente& );
protected slots:
    /** Emette il segnale per l'aggiunta di un utente tra i contatti.
     *  Mostra il pulsante per la rimozione dell'utente dai contatti.
     */
    void addContact();

    /** Emette il segnale per la rimozione di un utente dai contatti.
     *  Mostra il pulsante per l'aggiunta dell'utente dai contatti.
     */
    void removeContact();

    /** Mostra la scheda della panoramica dell'utente. */
    void showBackgroundTab();

    /** Mostra la scheda dei contatti dell'utente. */
    void showConnectionsTab();

    /** Mostra la scheda delle altre informazioni dell'utente. */
    void showOtherInfoTab();
};

#endif // OTHERPROFILEWIDGET_H
