#ifndef PROFILO_H
#define PROFILO_H
#include <string>
#include "info.h"
#include "esperienza.h"
#include "data.h"
#include "titolo_studio.h"

class Profilo {
private:
    string name;
    string surname;
    Data birthday;
    string maritialStatus;
    std::vector<Esperienza> experiences;
    std::vector<TitoloStudio> educations;
    std::vector<string> interests;
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
    void modificaProfilo();
    Info* visualizzaProfilo() const;
};

#endif
