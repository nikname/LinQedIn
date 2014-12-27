#ifndef PROFILO_H
#define PROFILO_H
#include <iostream>
#include <string>
#include <vector>
#include "esperienza.h"
#include "data.h"
#include "titolo_studio.h"

using std::ostream;
using std::string;


class Profilo {
private:
    class Info; //Dichiarazione incompleta
    Info* info; //Information hiding!
public:

    Profilo();

    /** Costruttore a 4 parametro con 2 parametri di default.
     *
     * @param Info*  Informazioni del profilo dell'utente.
     */
    Profilo( string, string, Data, string );

    string getName() const;

    string getSurname() const;

    Data getBirthday() const;

    string getMaritialStatus() const;

    void setName( string );

    void setSurname( string );

    void setBirthday( Data );

    void setMaritialStatus( string );

    friend ostream& operator <<( ostream&, Profilo );
};

/** Overloading dell'operatore <<.
 *  Stampa su standard output le informazioni associate al profilo.
 *
 * @param ostream&  ostream passato per riferimento.
 * @param Profilo  Profilo dell'utente del quale verranno stampate le informazioni.
 * @return ostream&  ostream per riferimento.
 */
ostream& operator <<( ostream&, Profilo );

#endif
