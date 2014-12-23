#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Data {
private:
    /** Giorno della data. */
    string day;
    /** Mese della data. */
    string month;
    /** Anno della data. */
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
    /** Confronta la data dell'oggetto di invocazione con quella passata come parametro.
     *
     * @param Data  Data da confrontare con quella dell'oggetto di invocazione.
     * @return int  1 in caso la data dell'oggetto di invocazione sia maggiore di quella passata come parametro, 0 se uguali, -1 altrimenti.
     */
    int compare( Data ) const;

    // Costruttore di copia di default. Non sono necessarie copie profonde.
};

/** Stampa su standard output la data nel formato dd/mm/yyyy.
 *
 * @param ostream  ostream per riferimento.
 * @param Data  Istanza della classe Data da stampare su standard output.
 * @return ostream  ostream per riferimento.
 */
ostream& operator<< ( ostream&, const Data& );

#endif // DATA_H
