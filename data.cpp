#include "data.h"

Data::Data() {
    day = "";
    month = "";
    year = "";
}

Data::Data(string d, string m, string y ) : day(d), month(m), year(y) {}

string Data::getDay() const {
    return day;
}

string Data::getMonth() const {
    return month;
}

string Data::getYear() const {
    return year;
}

void Data::setDay( string d ) {
    day = d;
}

void Data::setMonth( string m ) {
    month = m;
}

void Data::setYear( string y ) {
    year = y;
}

bool Data::operator <( const Data& d ) const {
    if( getYear() < d.getYear() )
        if( getMonth() < d.getMonth() )
            if( getDay() < d.getDay() )
                return true;
            else return false;
        else return false;
    else return false;
}

bool Data::operator >( const Data& d ) const {
    if( getYear() > d.getYear() )
        if( getMonth() > d.getMonth() )
            if( getDay() > d.getDay() )
                return true;
            else return false;
        else return false;
    else return false;
}

bool Data::operator ==( const Data& d ) const {
    if( getYear() == d.getYear() && getMonth() == d.getMonth() && getDay() == d.getDay() )
        return true;
    else return false;
}

ostream& operator <<( ostream& os, const Data& d ) {
    return os << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
}
