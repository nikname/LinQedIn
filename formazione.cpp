#include "formazione.h"

Formazione::Formazione() {}

Formazione::Formazione( QString scuola,
                        QDate dataDiploma,
                        QString laurea,
                        QString corsoDiStudio,
                        QString votazione,
                        QString attivita,
                        QString descrizione ) :
    school( scuola ),
    dateAttended( dataDiploma ),
    degree( laurea ),
    fieldOfStudy( corsoDiStudio ),
    grade( votazione ),
    activities( attivita ),
    description( descrizione ) {}

QString Formazione::getSchool() const {
    return school;
}

QDate Formazione::getDateAttended() const {
    return dateAttended;
}

QString Formazione::getDegree() const {
    return degree;
}

QString Formazione::getFieldOfStudy() const {
    return fieldOfStudy;
}

QString Formazione::getGrade() const {
    return grade;
}

QString Formazione::getActivities() const {
    return activities;
}

QString Formazione::getDescription() const {
    return description;
}

void Formazione::setSchool( QString s ) {
    school = s;
}

void Formazione::setDateAttended( QDate d ) {
    dateAttended = d;
}

void Formazione::setDegree( QString d ) {
    degree = d;
}

void Formazione::setFieldOfStudy( QString f ) {
    fieldOfStudy = f;
}

void Formazione::setGrade( QString g ) {
    grade = g;
}

void Formazione::setActivity( QString a ) {
    activities = a;
}

void Formazione::setDescription( QString d ) {
    description = d;
}

QDebug& operator <<( QDebug& qdbg, const Formazione& f ) {
    qdbg << "TITOLI DI STUDIO:\n"
         << "Scuola: " << f.getSchool() << "\n"
         << "Data diploma: " << f.getDateAttended().toString( "yyyy" ) << "\n"
         << "Laurea: " << f.getDegree() << "\n"
         << "Campo di studio: " << f.getFieldOfStudy() << "\n"
         << "Votazione: " << f.getGrade() << "\n"
         << "Attività svolte: " << f.getActivities() << "\n"
         << "Descrizione: " << f.getDescription() << "\n";
    return qdbg;
}
