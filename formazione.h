#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <string>
#include <vector>
#include "data.h"

using std::string;
using std::vector;

class Formazione {
private:
    string school;
    Data dateAttended;
    string degree;
    string fieldOfStudy;
    string grade;
    vector<string> activities;
    string Description;
public:
    Formazione( string, Data = Data(), string = "", string = "", string = "", string = "", string = "" );
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
