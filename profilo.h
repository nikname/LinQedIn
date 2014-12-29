#ifndef PROFILO_H
#define PROFILO_H
#include <iostream>
#include <string>
#include "data.h"

using std::ostream;
using std::string;


class Profilo {
private:
    class InfoPersonali;
    InfoPersonali* personalInfo;
public:
    /** Costruttore a 4 parametro con 2 parametri di default.
     *
     * @param string  Nome dell'utente.
     * @param string  Cognome dell'utente.
     * @param Data()  Data di nascita dell'utente.
     * @param string  Stato civile dell'utente.
     */
    Profilo( const string& = "",
             const string& = "",
             const Data& = Data(),
             const string& = "" );

    /** Ritorna il nome dell'utente.
     *
     * @return string  Nome dell'utente.
     */
    string getName() const;

    /** Ritorna il cognome dell'utente.
     *
     * @return string  Cognome dell'utente.
     */
    string getSurname() const;

    /** Ritorna la data di nascita dell'utente.
     *
     * @return Data  Data di nascita dell'utente.
     */
    Data getBirthday() const;

    /** Ritorna lo stato civile dell'utente.
     *
     * @return string  Stato civile dell'utente.
     */
    string getMaritialStatus() const;

    /** Modifica il nome dell'utente.
     *
     * @param string  Nome dell'utente.
     */
    void setName( string );

    /** Modifica il cognome dell'utente.
     *
     * @param string  Cognome dell'utente.
     */
    void setSurname( string );

    /** Modifica la data di nascita dell'utente.
     *
     * @param Data  Data di nascita dell'utente.
     */
    void setBirthday( Data );

    /** Modifica lo stato civile dell'utente.
     *
     * @param string  Stato civile dell'utente.
     */
    void setMaritialStatus( string );

    friend ostream& operator <<( ostream&, Profilo );
};

/** Overloading dell'operatore <<.
 *  Stampa su standard output le informazioni associate al profilo.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Profilo  Profilo dell'utente.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Profilo );

#endif
