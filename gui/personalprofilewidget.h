#ifndef PERSONALPROFILEWIDGET_H
#define PERSONALPROFILEWIDGET_H

#include <QWidget>
#include "profilewidget.h"

class ConnectionsWidget;
class EducationsWidget;
class ExperiencesWidget;
class QPushButton;
class SmartLavoro;
class SmartTitolo;
class SmartUtente;

class PersonalProfileWidget : public ProfileWidget {
    Q_OBJECT
private:
    QPushButton *editProfileButton;

    QLabel *lastExperienceLabel;
    QLabel *lastEducationLabel;
    QLabel *connectionsNumber;

    QPushButton *backgroundTabButton;
    QPushButton *connectionsTabButton;

    QWidget *backgroundTab;
    QLabel *experiencesLabel;
    ExperiencesWidget *experiencesWidget;
    QLabel *educationsLabel;
    EducationsWidget *educationsWidget;

    ConnectionsWidget *connectionsTab;

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
    /** Notifica il parent di aprire il profilo di un contatto. Emesso dalla scheda dei contatti.
     *
     * @param SmartUtente  Utente da visualizzare.
     */
    void showContactSignal( const SmartUtente& );

    /** Notifica il parent di rimuovere un utente dai contatti. Emesso dalla scheda dei contatti.
     *
     * @param SmartUtente  Utente da rimuovere dai contatti.
     */
    void removeContactSignal( const SmartUtente& );
protected slots:
    /** Mostra la scheda della panoramica dell'utente. */
    void showBackgroundTab();

    /** Mostra la scheda dei contatti dell'utente. */
    void showConnectionsTab();

    /** Mostra la scheda delle altre informazioni dell'utente. */
    void showOtherInfoTab();

    /** Apre la finestra di dialogo per la modifica di nome e cognome dell'utente. */
    void openEditProfileDialog();

    /** Aggiorna nome e cognome utente dopo la modifica.
     *
     * @param QString  Nuovo nome dell'utente.
     * @param QString  Nuovo cognome dell'utente.
     */
    void updateProfileInfoSlot( const QString&, const QString& );

    /** Aggiunge un'esperienza lavorativa all'elenco delle esperienze lavorative dell'utente.
     *  L'aggiunta effettiva in ExperiencesWidget è gestita dalla classe ExperiencesWidget stessa.
     *  Aggiorna le informazioni nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa da aggiungere.
     */
    void jobToAddSlot( const SmartLavoro& );

    /** Rimuove un'esperienza lavorativa dall'elenco delle esperienze lavorative dell'utente.
     *  L'aggiunta effettiva in ExperiencesWidget è gestita dalla classe ExperiencesWidget stessa.
     *  Nel caso questa fosse l'ultima, aggiorna le infomazioni nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa da rimuovere.
     */
    void jobToRemoveSlot( const SmartLavoro& );

    /** Aggiorna le informazioni nell'header riguardo all'ultima esperienza lavorativa.
     *
     * @param SmartLavoro  Ultima esperienza lavorativa.
     */
    void updateLastJobInfoSlot( const SmartLavoro& );

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio dell'utente.
     *  L'aggiunta effettiva in EducationsWidget è gestita dalla classe EducationsWidget stessa.
     *  Aggiorna le informazioni nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa da aggiungere.
     */
    void titleToAddSlot( const SmartTitolo& );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio dell'utente.
     *  L'aggiunta effettiva in EducationsWidget è gestita dalla classe EducationsWidget stessa.
     *  Nel caso questa fosse l'ultimo, aggiorna le infomazioni nell'header del profilo.
     *
     * @param SmartLavoro  Esperienza lavorativa da rimuovere.
     */
    void titleToRemoveSlot( const SmartTitolo& );

    /** Aggiorna le informazioni nell'header riguardo all'ultimo titolo di studio.
     *
     * @param SmartUtente  Ultimo titolo di studio.
     */
    void updateLastTitleInfoSlot( const SmartTitolo& );

    /** Rimuove un contatto dalla lista dei contatti dell'utente nel caso di rimozione dalla
     *  scheda dei contatti. Aggiorna il numero di contatti nell'header del profilo.
     *
     * @param SmartUtente  Utente da rimuovere.
     */
    void contactToRemoveSlot( const SmartUtente& );

    /** Aggiorna le informazioni personali aggiuntive dell'utente.
     *
     * @param QDate  Nuova data di nascita.
     * @param QString  Nuovo stato civile.
     */
    void updatePersonalInfoSlot( const QDate&, const QString& );
};

#endif // PERSONALPROFILEWIDGET_H
