#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Data {
private:
    string day;
    string month;
    string year;
public:
    /** Costruttore di default. */
    Data();

    /** Costruttore a 3 parametri.
     *
     * @param string  Giorno della data. Valore di default "".
     * @param string  Mese della data. Valore di default "".
     * @param string  Anno della data. Valore di default "".
     */
    Data( string, string, string );

    /** Ritorna il giorno del mese.
     *
     * @return string  Giorno della data.
     */
    string getDay() const;

    /** Ritorna il mese della data.
     *
     * @return string  Mese della data.
     */
    string getMonth() const;

    /** Ritorna l'anno della data.
     *
     * @return string  Anno della data.
     */
    string getYear() const;

    /** Imposta il giorno della data.
     *
     * @param string  Giorno della data da impostare.
     */
    void setDay( string );

    /** Imposta il mese della data.
     *
     * @param string  Mese della data da impostare.
     */
    void setMonth( string );

    /** Imposta l'anno della data.
     *
     * @param string  Anno della data da impostare.
     */
    void setYear( string );

    string toString() const {
        string data;
        if( !getDay().empty() && !getMonth().empty() ) {
            data += getDay();
            data += "/";
            data += getMonth();
            data += "/";
        }
        data += getYear();
        return data;
    }

    /** Overloading dell'operatore <. Confronta due date.
     *
     * @param const Data&  Data da confrontare.
     * @return bool  true se l'oggetto Data di invocazione è minore del parametro di tipo Data; false altrimenti.
     */
    bool operator <( const Data& ) const;

    /** Overloading dell'operatore >. Confronta due date.
     *
     * @param const Data&  Data da confrontare.
     * @return bool  true se l'oggetto Data di invocazione è maggiore del parametro di tipo Data; false altrimenti.
     */
    bool operator >( const Data& ) const;

    /** Overloading dell'operatore ==. Contronta due date.
     *
     * @param const Data&  Data da confrontare.
     * @return bool  true se l'oggetto Data di invocazione è uguale al parametro di tipo Data; false altrimenti.
     */
    bool operator ==( const Data& ) const;
};

/** Stampa su standard output la data nel formato dd/mm/yyyy.
 *
 * @param ostream  ostream per riferimento.
 * @param Data  Istanza della classe Data da stampare su standard output.
 * @return ostream  ostream per riferimento.
 */
ostream& operator <<( ostream&, const Data& );

#endif // DATA_H
