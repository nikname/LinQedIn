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

void Formazione::Titolo::setSchool( QString scuola ) {
    school = scuola;
}

void Formazione::Titolo::setDateAttended( QDate dataDiploma ) {
    dateAttended = dataDiploma;
}

void Formazione::Titolo::setDegree( QString laurea ) {
    degree = laurea;
}

void Formazione::Titolo::setFieldOfStudy( QString campoDiStudio ) {
    fieldOfStudy = campoDiStudio;
}

void Formazione::Titolo::setGrade( QString valutazione ) {
    grade = valutazione;
}

QDebug operator <<( QDebug qdbg, const Formazione::Titolo& t ) {
    qdbg << "Scuola: " << t.getSchool() << "\n"
         << "Data diploma: " << t.getDateAttended().toString( "yyyy" ) << "\n"
         << "Laurea: " << t.getDegree() << "\n"
         << "Campo di studio: " << t.getFieldOfStudy() << "\n"
         << "Votazione: " << t.getGrade() << "\n";
    return qdbg;
}

bool operator ==( const Formazione::Titolo& t1, const Formazione::Titolo& t2 ) {
    return ( t1.getSchool() == t2.getSchool() ) &&
           ( t1.getDateAttended() == t2.getDateAttended() ) &&
           ( t1.getDegree() == t2.getDegree() ) &&
           ( t1.getFieldOfStudy() == t2.getFieldOfStudy() ) &&
           ( t1.getGrade() == t2.getGrade() );
}

class Formazione::Titolo_rapp {
public:
    QList<Formazione::Titolo> titlesList;
};

Formazione::Formazione() : titles( new Titolo_rapp ) {}

Formazione::~Formazione() {
    delete titles;
}

void Formazione::addEducation( const Titolo& t ) {
    titles->titlesList.append( t );
}

void Formazione::removeEducation( Titolo t ) {
    titles->titlesList.removeOne( t );
}

QDebug operator <<( QDebug qdbg, const Formazione& f ) {
    qdbg << "TITOLI DI STUDIO:\n";
    QListIterator<Formazione::Titolo> it( f.titles->titlesList );
    while ( it.hasNext() )
        qdbg << it.next() << "\n";
    return qdbg;
}
