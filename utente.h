#ifndef UTENTE_H
#define UTENTE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "profilo.h"
#include "smartutente.h"
#include "formazione.h"
#include "esperienza.h"

// Dichiarazioni incomplete
class Rete;
class Database;

class Utente {

    // NOTE:
    // Rimossa la possibilità di cambiare username. Il cambio di username avrebbe significato la
    // necessità di controllare la presenza di un altro utente nel database con lo stesso username.

    friend class SmartUtente;
private:
    QString username;
    Profilo profile;
    Rete* net;
    Formazione* educations;
    Esperienza* experiences;
    int references; // Gestito da SmartUtente
public:
    /** Costruttore a 3 parametri con 3 parametri di default.
     *  Costruisce un utente associandgli username, nome e cognome.
     *  Inizializza il contatore di riferimenti ad 1.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    Utente( const QString& un = "",
            const QString& name = "",
            const QString& surname = "" );

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
     * @param QString  Username del contatto da aggiungere.
     * @param Database*  Database sul quale ricercare l'username dell'utente da inserire.
     */
    void addContact( Utente*, Database* );

    /** Rimuove un contatto dalla lista dei contatti dell'utente.
     *  Invoca il metodo removeContact() del campo dati net di tipo Rete.
     *
     * @param QString  Username del contatto da rimuovere.
     * @param Database*  Database sul quale ricercare l'username dell'utente da rimuovere.
     */
    void removeContact( Utente*, Database* );

    /** Ritorna un QVector di SmartUtente contenente i contatti nella rete dell'utente.
     *  Invoca il metodo getContactsList() del campo dati net di tipo Rete.
     *
     * @return QVector<SmartUtente>  Vettore dei contatti nella rete dell'utente.
     */
    QVector<SmartUtente> getContactsList() const;

    /** Aggiunge un titolo di studio all'elenco dei titoli di studio.
     *  Invoca il metodo addEducation() del campo dati educations dell'utente.
     *
     * @param Titolo*  Titolo di studio da aggiungere.
     */
    void addEducation( Titolo* );

    /** Rimuove un titolo di studio dall'elenco dei titoli di studio.
     *  Invoca il metodo removeEducation() del campo dati educations dell'utente.
     *
     * @param Titolo*  Titolo di studio da rimuovere.
     */
    void removeEducation( Titolo* );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getTitlesList() del campo dati educations dell'utente.
     *
     * @return QVector<Titolo*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Titolo*> getTitlesList() const;

    /** Restituisce un iteratore sulla lista dei titoli di studio dell'utente.
     *  Invoca il metodo begin() di Formazione.
     *
     * @return Formazione::Iteratore  Iteratore sulla lista dei titoli di studio dell'utente.
     */
    Formazione::Iteratore getEducationsIterator() const;

    /** Aggiunge un'esperienza alle esperienze lavorative.
     *  Invoca il metodo addExperience() del campo dati experiences dell'utente.
     *
     * @param Lavoro*  Esperienza da aggiungere alle esperienze lavorative.
     */
    void addExperience( Lavoro* );

    /** Rimuove un'esperienza dalle esperienze lavorative.
     *  Invoca il metodo removeExperience() del campo dati experiences dell'utente.
     *
     * @param Lavoro*  Esperienza da riumuovere dalle esperienze lavorative.
     */
    void removeExperience( Lavoro* );

    /** Ritorna un vettore di puntatori ai titoli di studio dell'utente.
     *  Invoca il metodo getExperiencesList() del campo dati experiences dell'utente.
     *
     * @return QVector<Lavoro*>  Vettore di puntatori ai titoli di studio dell'utente.
     */
    QVector<Lavoro*> getExperiencesList() const;

    /** Restituisce un iteratore sulla lista delle esperienze lavorative dell'utente.
     *  Invoca il metodo begin() di Esperienza.
     *
     * @return Esperienza::Iteratore  Iteratore sulla lista delle esperienza lavorative dell'utente.
     */
     Esperienza::Iteratore getExperiencesIterator() const;

    /** Ricerca polimorfa, virtuale pura.
     *  Esegue la ricerca degli utenti nel database in base alla tipologia di account.
     *
     * @param Database  Database nel quale verrà effettuata la ricerca.
     */
    virtual void userSearch( const Database& ) const = 0;
protected:
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
        void operator ()( const SmartUtente& ) const;
    };
};

/** Overloading operatore di output di QDebug.
 *  Stampa su standard output tutte le informazioni associate all'utente.
 *
 * @param QDebug  QDebug.
 * @param Utente  Puntatore all'oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, const Utente& );

#endif
