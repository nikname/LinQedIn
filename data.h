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
    /** Costruttore a 3 parametri. Nonostante comprenda il costruttore di default sono accettate solo le date che comprendono .
     *
     * @param string  Giorno della data. Valore di default "".
     * @param string  Mese della data. Valore di default "".
     * @param string  Anno della data. Valore di default "".
     */
    Data( string d = "", string m = "", string y = "" ) : day(d), month(m), year(y) {}

    /** Ritorna il giorno del mese.
     *
     * @return string  Giorno della data.
     */
    string getDay() const {
        return day;
    }

    /** Ritorna il mese della data.
     *
     * @return string  Mese della data.
     */
    string getMonth() const {
        return month;
    }

    /** Ritorna l'anno della data.
     *
     * @return string  Anno della data.
     */
    string getYear() const {
        return year;
    }

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

    /** Confronta la data dell'oggetto di invocazione con quella passata come parametro.
     *
     * @param Data  Data da confrontare con quella dell'oggetto di invocazione.
     * @return int  1 in caso la data dell'oggetto di invocazione sia maggiore di quella passata come parametro, 0 se uguali, -1 altrimenti.
     */
    int compare( Data ) const;

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

    // Costruttore di copia di default. Non sono necessarie copie profonde.
};

/** Stampa su standard output la data nel formato dd/mm/yyyy.
 *
 * @param ostream  ostream per riferimento.
 * @param Data  Istanza della classe Data da stampare su standard output.
 * @return ostream  ostream per riferimento.
 */
ostream& operator<< ( ostream& os, const Data& d ) {
    return os << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
}

#endif // DATA_H
