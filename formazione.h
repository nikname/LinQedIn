#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include <QDebug>
#include <QString>
#include <QDate>

class Formazione {
private:
    QString school;
    QDate dateAttended;
    QString degree;
    QString fieldOfStudy;
    QString grade;
    QString activities;
    QString description;
public:
    Formazione(); // Just for debug

    Formazione( QString,
                QDate = QDate(),
                QString = "",
                QString = "",
                QString = "",
                QString = "",
                QString = "" );

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

    void setActivity( QString );

    void setDescription( QString );
};

QDebug& operator <<( QDebug&, const Formazione& );

#endif // TITOLO_STUDIO_H
