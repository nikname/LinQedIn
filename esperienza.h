#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <string>
#include "data.h"

using std::string;

class Esperienza {
private:
    string companyName;
    string title;
    string location;
    Data begin;
    Data end;
    string description;
public:
    string getCompanyName() const;
    string getTitle() const;
    string getLocation() const;
    Data getPeriod() const;
    Data getDescription() const;
    void setCompanyName( string );
    void setTitle( string );
    void setLocation( string );
    void setBegin( Data );
    void setEnd( Data );
    void setDescription( string );
};

#endif // ESPERIENZA_H
