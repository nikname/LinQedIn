#ifndef UTENTE_H
#define UTENTE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "profilo.h"
#include "smartutente.h"
#include "formazione.h"
#include "esperienza.h"

class Database;
class Rete;

class Utente {
    friend class SmartUtente;
    friend QDebug operator <<( QDebug, const Utente& );
private:
    int references; // Gestito da SmartUtente
protected:
    QString username;
    Profilo profile;
    Rete* net;
    Formazione* educations;
    Esperienza* experiences;

    class FuntoreRicerca {
    public:
        int searchType;

        /** Costruttore ad 1 parametro con 1 parametro di default.
         *  Imposta il tipo di ricerca che l'utente può effettuare nel database.
         *
         * @param int type  Tipo di ricerca.
         */
        FuntoreRicerca( int type = 0 ) : searchType( type ) {}

        /** Overloading dell'operatore di "chiamata a funzione".
         *  Invoca il funtore passando come parametro un oggetto SmartUtente, del quale si
         *  vogliono ottenere le informazioni.
         *  L'effetto di questo varia in base al tipo di utente che lo invoca.
         *
         * @param SmartUtente  SmartUtente del quale si vogliono ottenere le informazioni.
         */
        SmartUtente operator ()( const SmartUtente& ) const;
    };
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Costruisce un utente associandgli username, nome e cognome.
     *  Inizializza il contatore di riferimenti ad 1.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    Utente( const QString& un = "", const QString& name = "", const QString& surname = "" );

    /** Costruttore di copia di Utente.
     *  Incrementa il contatore di riferimenti all'oggetto utente di 1.
     *  Utilizza la tecnica del references counting per i campi dati net, educations ed experiences.
     *
     * @param Utente  Utente da copiare.
     */
    Utente( const Utente& );

    /** Distruttore virtuale puro. Anche se puro deve essere definito.
     *  Decrementa i campi references di net, educations ed experiences.
     *  In caso il valore diventi 0 invoca il distruttore dell'oggetto.
     */
    virtual ~Utente() = 0;

    /** Ritorna la tipologia dell'account sotto forma di stringa.
     *  Il metodo viene ridefinito in ogni sottoclasse concreta in modo che all'invocazione su di
     *  un qualsiasi utente ritorni la tipologia corretta.
     *
     * @return QString  Tipologia dell'account.
     */
    virtual QString getAccountType() const = 0;

    /** Ritorna l'username dell'utente.
     *
     * @return QString  Username dell'utente.
     */
    QString getUsername() const;

    /** Ritorna il nome dell'utente.
     *  Invoca il metodo getName() del campo dati profile di tipo Profilo.
     *
     * @return QString  Nome dell'utente.
     */
    QString getName() const;

    /** Ritorna il cognome dell'utente.
     *  Invoca il metodo getSurname() del campo dati profile di tipo Profilo.
     *
     * @return QString  Cognome dell'utente.
     */
    QString getSurname() const;

    /** Ritorna la data di nascita dell'utente.
     *  Invoca il metodo getBirthday() del campo dati profile di tipo Profilo.
     *
     * @return QDate  Data di nascita dell'utente.
     */
    QDate getBirthday() const;

    /** Ritorna lo stato civile dell'utente.
     *  Invoca il metodo getMaritialStatus() del campo dati profile di tipo Profilo.
     *
     * @return QString  Stato civile dell'utente.
     */
    QString getMaritialStatus() const;

    /** Imposta il nome dell'utente.
     *  Invoca il metodo setName() del campo dati profile di tipo Profilo.
     *
     * @param QString  Nome dell'utente.
     */
    void setName( const QString& );

    /** Imposta il cognome dell'utente.
     *  Invoca il metodo setSurname() del campo dati profile di tipo Profilo.
     *
     * @param QString  Cognome dell'utente.
     */
    void setSurname( const QString& );

    /** Imposta la data di nascita dell'utente.
     *  Invoca il metodo setBirthday() del campo dati profile di tipo Profilo.
     *
     * @param QDate  Data di nascita dell'utente.
     */
    void setBirthday( const QDate& );

    /** Modifica lo stato civile dell'utente.
     *  Invoca il metodo setMaritialStatus() del campo dati profile di tipo Profilo.
     *
     * @param QString  Stato civile dell'utente.
     */
    void setMaritialStatus( const QString& );

    /** Aggiunge un contatto alla lista dei contatti dell'utente.
     *  Invoca il metodo addContact() del campo dati net di tipo Rete.
     *
     * @param SmartUtente  Contatto da aggiungere.
     */
    void addContact( const SmartUtente& );

    /** Rimuove un contatto dalla lista dei contatti dell'utente.
     *  Invoca il metodo removeContact() del campo dati net di tipo Rete.
     *
     * @param SmartUtente  Contatto da rimuovere.
     */
    void removeContact( const SmartUtente& );

    /** Controlla se un utente è presente tra i contatti dell'utente.
     *  Invoca il metodo isContact() del campo dati net di tipo Rete.
     *
     * @param SmartUtente  Utente da cercare tra i contatti.
     * @return bool  true se è presente; false altrimenti.
     */
    bool isContact( const SmartUtente& );

    /** Elimina il campo dati net di tipo Rete *. */
    void unsetContactsList();

    /** Controlla se il campo dati net di tipo Rete è un puntatore valido.
     *
     * @return bool  true se è valido; false altrimenti (i.e. punta all'indirizzo 0)
     */
    bool isContactsListSet();

    /** Ritorna un QVector di SmartUtente contenente i contatti nella rete dell'utente.
     *  Invoca il metodo getContactsList() del campo dati net di tipo Rete.
     *
     * @return QVector<SmartUtente>  Vettore dei contatti nella rete dell'utente.
     */
    QVector<SmartUtente> getContactsList() const;

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *  Invoca il metodo addEducation() del campo dati educations dell'utente.
     *
     * @param SmartTitolo  Titolo di studio da aggiungere.
     */
    void addEducation( SmartTitolo );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *  Invoca il metodo removeEducation() del campo dati educations dell'utente.
     *
     * @param SmartTitolo  Titolo di studio da rimuovere.
     */
    void removeEducation( SmartTitolo );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getEducationsList() del campo dati educations dell'utente.
     *
     * @return QVector<SmartTitolo>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartTitolo> getEducationsList() const;

    /** Crea una nuova lista dei titoli di studio. Rimuove un'eventuale lista preesistente.
     *  Invoca il metodo setEducationsList( QVector<SmartTitolo> ) del campo dati educations di tipo
     *  Formazione.
     *
     * @param  QVector<SmartTitolo>  Lista dei nuovi titoli di studio dell'utente.
     */
    void setEducationsList( QVector<SmartTitolo> );

    /** Elimina il campo dati educations di tipo Formazione *. */
    void unsetEducationsList();

    /** Controlla se il campo dati educations di tipo Formazione è un puntatore valido.
     *
     * @return bool  true se è valido; false altrimenti (i.e. punta all'indirizzo 0)
     */
    bool isEducationsListSet();

    /** Restituisce un iteratore sulla lista dei titoli di studio dell'utente.
     *  Invoca il metodo begin() di Formazione.
     *
     * @return Formazione::Iteratore  Iteratore sulla lista dei titoli di studio dell'utente.
     */
    Formazione::Iteratore getEducationsIterator() const;

    /** Aggiunge un'esperienza alle esperienze lavorative.
     *  Invoca il metodo addExperience() del campo dati experiences dell'utente.
     *
     * @param SmartLavoro  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( SmartLavoro );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *  Invoca il metodo removeExperience() del campo dati experiences dell'utente.
     *
     * @param SmartLavoro  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( SmartLavoro );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getExperiencesList() del campo dati experiences dell'utente.
     *
     * @return QVector<SmartLavoro>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartLavoro> getExperiencesList() const;

    /** Crea una nuova lista delle esperienze lavorative. Rimuove un'eventuale lista preesistente.
     *  Invoca il metodo setExperiencesList( QVector<SmartLavoro> ) del campo dati educations di tipo
     *  Esperienza.
     *
     * @param  QVector<SmartLavoro>  Lista delle nuove esperienze lavorative.
     */
    void setExperiencesList( QVector<SmartLavoro> );

    /** Elimina il campo dati experiences di tipo Esperienza *. */
    void unsetExperiencesList();

    /** Controlla se il campo dati experiences di tipo Esperienza è un puntatore valido.
     *
     * @return bool  true se è valido; false altrimenti (i.e. punta all'indirizzo 0)
     */
    bool isExperiencesListSet();

    /** Restituisce un iteratore sulla lista delle esperienze lavorative dell'utente.
     *  Invoca il metodo begin() di Esperienza.
     *
     * @return Esperienza::Iteratore  Iteratore sulla lista delle esperienza lavorative dell'utente.
     */
     Esperienza::Iteratore getExperiencesIterator() const;

    /** Ricerca polimorfa, virtuale pura.
    *  In base alla tipologia di account ritorna una lista di utenti con determinate informazioni.
    *
    * @param QVector<SmartUtente>  Lista di utenti sulla quale cercare.
    */
    virtual QVector<SmartUtente> searchUsers( QVector<SmartUtente> ) const = 0;

    /** Ridefinizione operatore di assegnazione. Effettua un'assegnazione profonda dei campi dati.
     *
     * @param SmartUtente  Utente dal quale creare il nuovo utente.
     * @return SmartUtente&  Oggetto SmartUtente da assegnare.
     */
    SmartUtente& operator =( const SmartUtente& );

    /** Metodo virtuale puro di utilità necessario per creare copie profonde di oggetti di tipo
     *  Utente. Ogni classe concreta derivata da utente restituisce una copia profonda di un
     *  utente della sua stessa tipologia.
     *
     * @param Utente *  Utente dal quale fare la copia profonda.
     * @param Utente *  Copia profonda dell'oggetto Utente.
     */
    virtual Utente *clone() const = 0;
protected:
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param QDebug  QDebug.
 * @param Utente  Oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Utente& );

#endif
