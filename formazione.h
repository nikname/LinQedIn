#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QString>
#include <QDate>
#include <vector>

using std::vector;

class Formazione {
private:
    QString school;
    QDate dateAttended;
    QString degree;
    QString fieldOfStudy;
    QString grade;
    vector<QString> activities;
    QString Description;
public:
    Formazione( QString, QDate = QDate(), QString = "", QString = "", QString = "", QString = "", QString = "" );
    QString getSchool() const;
    QDate getDateAttended() const;
    QString getDegree() const;
    QString getFieldOfStudy() const;
    QString getGrade() const;
    QString getActivities() const;
    QString getDescription() const;
    void setSchool( QString );
    void setDateAttended( QDate );
    void setDegree( QString );
    void setFieldOfStudy( QString );
    void setGrade( QString );
    void addActivity( QString );
    void setDescription( QString );
};

#endif // TITOLO_STUDIO_H
