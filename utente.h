#ifndef UTENTE_H
#define UTENTE_H
#include <QDebug>
#include <QString>
#include <QDate>
#include "profilo.h"
#include "rete.h"
#include "formazione.h"
#include "esperienza.h"
#include "smartutente.h"

class Utente {
    // Classe astratta
private:
    QString username;
    Profilo profile;
    Rete* net;
    Formazione* educations;
    Esperienza* experiences;
public:
    /** Costruttore a 2 parametri con 2 parametri di default.
     *  Costruisce un utente associandgli username, nome e cognome.
     *
     * @param QString un  Username dell'utente da creare.
     * @param QString name  Nome dell'utente da creare.
     * @param QString surname  Cognome dell'utente da creare.
     */
    Utente( const QString& un = "",
            const QString& name = "",
            const QString& surname = "" ) :
        username( un ),
        profile( name, surname ),
        net( new Rete ),
        educations( new Formazione ),
        experiences( new Esperienza ) {}

    /** Costruttore di copia di Utente.
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
    QString getUsername();

    /** Imposta l'username dell'utente.
     *
     * @param QString  Nuovo username.
     */
    void setUsername( const QString& );

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
    void addContact( const QString&, Database* );

    /** Rimuove un contatto dalla lista dei contatti dell'utente.
     *  Invoca il metodo removeContact() del campo dati net di tipo Rete.
     *
     * @param QString  Username del contatto da rimuovere.
     * @param Database*  Database sul quale ricercare l'username dell'utente da rimuovere.
     */
    void removeContact( const QString&, Database* );

    /** Ritorna un QVector di QString contenente la login dei contatti nella rete dell'utente.
     *  Invoca il metodo getContactsList() del campo dati net di tipo Rete.
     *
     * @return QVector<QString>  Login dei contatti nella rete dell'utente.
     */
    QVector<QString> getContactsList() const;



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
 * @param Utente*  Puntatore all'oggetto Utente.
 * @param QDebug  QDebug.
 */
QDebug operator <<( QDebug, Utente* );

#endif
