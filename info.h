#ifndef INFO_H
#define INFO_H
#include <string>
#include <vector>
#include "info.h"
#include "esperienza.h"
#include "data.h"
#include "titolo_studio.h"

using std::string;
using std::vector;

class Info {
private:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;
    vector<Esperienza> experiences;
    vector<TitoloStudio> educations;
    vector<string> interests;
public:
    string getName() const;
    string getSurname() const;
    Data getBirthday() const;
    string getMaritialStatus() const;
    string getExperiences() const;
    string getEducations() const;
    string getInterests() const;
    void setName( string );
    void setSurname( string );
    void setBirthday( Data );
    void setMaritialStatus( bool );
    void addExperiences( string );
    void addEducations( string );
    void addInterests( string );
};

#endif
