#ifndef TITOLO_STUDIO_H
#define TITOLO_STUDIO_H
#include <string>
#include "data.h"

class TitoloStudio {
private:
    string school;
    Data dateAttended;
    string degree;
    string fieldOfStudy;
    string grade;
    std::vector<string> activities;
    string Description;
public:
    TitoloStudio( string, Data = Data(), string = "", string = "", string = "", string = "", string = "" );
    string getSchool() const;
    Data getDateAttended() const;
    string getDegree() const;
    string getFieldOfStudy() const;
    string getGrade() const;
    string getActivities() const;
    string getDescription() const;
    void setSchool( string );
    void setDateAttended( Data );
    void setDegree( string );
    void setFieldOfStudy( string );
    void setGrade( string );
    void addActivity( string );
    void setDescription( string );
};

#endif // TITOLO_STUDIO_H
