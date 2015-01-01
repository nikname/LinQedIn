#include "formazione.h"
#include <QList>
#include <QListIterator>

QString Formazione::Titolo::getSchool() const {
    return school;
}

QDate Formazione::Titolo::getDateAttended() const {
    return dateAttended;
}

QString Formazione::Titolo::getDegree() const {
    return degree;
}

QString Formazione::Titolo::getFieldOfStudy() const {
    return fieldOfStudy;
}

QString Formazione::Titolo::getGrade() const {
    return grade;
}

QString Formazione::Titolo::getActivities() const {
    return activities;
}

void Formazione::Titolo::setSchool( QString s ) {
    school = s;
}

void Formazione::Titolo::setDateAttended( QDate d ) {
    dateAttended = d;
}

void Formazione::Titolo::setDegree( QString d ) {
    degree = d;
}

void Formazione::Titolo::setFieldOfStudy( QString f ) {
    fieldOfStudy = f;
}

void Formazione::Titolo::setGrade( QString g ) {
    grade = g;
}

void Formazione::Titolo::setActivity( QString a ) {
    activities = a;
}

QDebug operator <<( QDebug qdbg, const Formazione::Titolo& t ) {
    qdbg << "Scuola: " << t.getSchool() << "\n"
         << "Data diploma: " << t.getDateAttended().toString( "yyyy" ) << "\n"
         << "Laurea: " << t.getDegree() << "\n"
         << "Campo di studio: " << t.getFieldOfStudy() << "\n"
         << "Votazione: " << t.getGrade() << "\n"
         << "Attività svolte: " << t.getActivities() << "\n";
    return qdbg;
}

class Formazione::TitoliStudio {
public:
    QList<Titolo> titlesList;
};

Formazione::Formazione() : titles( new TitoliStudio ) {}

QDebug operator <<( QDebug qdbg, const Formazione& f ) {
    qdbg << "TITOLI DI STUDIO:\n";
    QListIterator<Formazione::Titolo> it( f.titles->titlesList );
    while ( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}
