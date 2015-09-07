#ifndef UTENTE_H
#define UTENTE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "profilo.h"
#include "esperienza.h"
#include "formazione.h"
#include "smartlavoro.h"
#include "smarttitolo.h"
#include "smartutente.h"

class Rete;

class Utente {
    friend class SmartUtente;
    friend QDebug& operator <<( QDebug&, const Utente& );
private:
    int references; // Gestito da SmartUtente
protected:
    QString username;
    Profilo profile;
    Rete* net;
    Formazione* educations;
    Esperienza* experiences;
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Costruisce un utente associandgli username, nome e cognome.
     *  Inizializza il contatore di riferimenti ad 1.
     *
     * @param QString  Username dell'utente da creare.
     * @param QString  Nome dell'utente da creare.
     * @param QString  Cognome dell'utente da creare.
     */
    Utente( const QString& = "", const QString& = "", const QString& = "" );

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
    void addEducation( const SmartTitolo& );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *  Invoca il metodo removeEducation() del campo dati educations dell'utente.
     *
     * @param SmartTitolo  Titolo di studio da rimuovere.
     */
    void removeEducation( const SmartTitolo& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getEducationsList() del campo dati educations dell'utente.
     *
     * @return QVector<SmartTitolo>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartTitolo> getEducationsList() const;

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
    void addExperience( const SmartLavoro& );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *  Invoca il metodo removeExperience() del campo dati experiences dell'utente.
     *
     * @param SmartLavoro  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( const SmartLavoro& );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getExperiencesList() del campo dati experiences dell'utente.
     *
     * @return QVector<SmartLavoro>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<SmartLavoro> getExperiencesList() const;

    /** Restituisce un iteratore sulla lista delle esperienze lavorative dell'utente.
     *  Invoca il metodo begin() di Esperienza.
     *
     * @return Esperienza::Iteratore  Iteratore sulla lista delle esperienza lavorative dell'utente.
     */
     Esperienza::Iteratore getExperiencesIterator() const;

    /** Ricerca polimorfa, virtuale pura.
     *  In base alla tipologia di account ritorna una lista delle informazione visualizzabili.
     *
     * @return QList<QString>  Lista delle informazioni visualizzabili.
     */
    virtual QList<QString> getUserInfo() const = 0;
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param QDebug  QDebug.
 * @param Utente  Oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug& operator <<( QDebug&, const Utente& );

#endif
