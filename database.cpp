#include "database.h"
#include "smartutente.h"
#include <QList>
#include <QListIterator>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include "utente_basic.h"
#include "utente_express.h"
#include "utente_business.h"

class Database::ListaUtenti {
public:
    QList<SmartUtente> users;
};

void Database::parseUser( QXmlStreamReader& xmlReader ) {

    if( xmlReader.tokenType() != QXmlStreamReader::StartElement &&
        xmlReader.name() != "user" ) {
        qDebug() << "Nessun elemento utente!";
        return;
    }

    Utente* u = 0;
    QString type = xmlReader.attributes().value( "type" ).toString();
    QString un = xmlReader.attributes().value( "login" ).toString();
    if( type == "basic" )
        u = new UtenteBasic( un );
    else if( type == "express" )
        u = new UtenteExpress( un );
    else if( type == "business" )
        u = new UtenteBusiness( un );
    else qDebug() << "#"; // throw

    xmlReader.readNext();

    while( xmlReader.name() != "user" ||
           xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        if( xmlReader.name() == "profile" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "profile" ||
                   xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                if( xmlReader.name() == "name" )
                    u->getProfile().setName( xmlReader.readElementText() );
                if( xmlReader.name() == "surname" )
                    u->getProfile().setSurname( xmlReader.readElementText() );
                if( xmlReader.name() == "birthday" ) {
                    QString b = xmlReader.readElementText();
                    QStringList list = b.split( "/" );
                    if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                        u->getProfile().setBirthday( QDate( list[2].toInt(),
                                                            list[1].toInt(),
                                                            list[0].toInt() ) );
                    else u->getProfile().setBirthday( QDate() );
                }
                if( xmlReader.name() == "maritialStatus" )
                    u->getProfile().setMaritialStatus( xmlReader.readElementText() );
                xmlReader.readNext();
            }
        }
        if( xmlReader.name() == "net" ) {
            xmlReader.readNext();
            continue;
        }
        if( xmlReader.name() == "educations" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "educations"
                   || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                if( xmlReader.name() == "title" ) {
                    Formazione::Titolo t = Formazione::Titolo();
                    xmlReader.readNext();
                    while( xmlReader.name() != "title"
                           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                        if( xmlReader.name() == "school" )
                            t.setSchool( xmlReader.readElementText() );
                        if( xmlReader.name() == "dateAttended" ) {
                            QStringList list = xmlReader.readElementText().split( "/" );
                            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                                u->getProfile().setBirthday( QDate( list[2].toInt(),
                                                                    list[1].toInt(),
                                                                    list[0].toInt() ) );
                            else u->getProfile().setBirthday( QDate() );
                        }
                        if( xmlReader.name() == "degree" )
                            t.setDegree( xmlReader.readElementText() );
                        if( xmlReader.name() == "fieldOfStudy" )
                            t.setFieldOfStudy( xmlReader.readElementText() );
                        if( xmlReader.name() == "grade" )
                            t.setGrade( xmlReader.readElementText() );
                        if( xmlReader.name() == "activities" )
                            t.setActivity( xmlReader.readElementText() );
                        xmlReader.readNext();
                    }
                    u->getEducations()->addEducation( t );
                }
                xmlReader.readNext();
            }
        }
        if( xmlReader.name() == "experiences" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "experiences"
                   || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                if( xmlReader.name() == "job" ) {
                    Esperienza::Lavoro j = Esperienza::Lavoro();
                    xmlReader.readNext();
                    while( xmlReader.name() != "job"
                           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                        if( xmlReader.name() == "companyName" )
                            j.setCompanyName( xmlReader.readElementText() );
                        if( xmlReader.name() == "title" )
                            j.setTitle( xmlReader.readElementText() );
                        if( xmlReader.name() == "location" )
                            j.setLocation( xmlReader.readElementText() );
                        if( xmlReader.name() == "begin" ) {
                            QStringList list = xmlReader.readElementText().split( "/" );
                            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                                u->getProfile().setBirthday( QDate( list[2].toInt(),
                                                                    list[1].toInt(),
                                                                    list[0].toInt() ) );
                            else u->getProfile().setBirthday( QDate() );
                        }
                        if( xmlReader.name() == "end" ) {
                            QStringList list = xmlReader.readElementText().split( "/" );
                            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                                u->getProfile().setBirthday( QDate( list[2].toInt(),
                                                                    list[1].toInt(),
                                                                    list[0].toInt() ) );
                            else u->getProfile().setBirthday( QDate() );
                        }
                        xmlReader.readNext();
                    }
                    u->getExperiences()->addExperience( j );
                }
                xmlReader.readNext();
            }
        }
        xmlReader.readNext();
    }

    this->insert( u );
}

Database::Database() : usersList( new ListaUtenti ) {}

Database::~Database() {
    delete usersList;
}

void Database::loadUsersList() {

    QString path( "users.xml" );
    QFile file( path );

    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        qDebug() << "Cannot read file: " << file.errorString();
        return;
    }

    QXmlStreamReader xmlReader( &file );
    while( !xmlReader.atEnd() && !xmlReader.hasError() ) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if( token == QXmlStreamReader::StartDocument )
            continue;
        if( token == QXmlStreamReader::StartElement ) {
            if( xmlReader.name() == "user" )
                parseUser( xmlReader );
        }
    }
}

void Database::saveUsersList() const {

    QString path( "users.xml" );
    QFile file( path );
    file.open( QFile::WriteOnly );

    QXmlStreamWriter xmlWriter( &file );
    xmlWriter.setAutoFormatting( true );
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement( "users" );

    QListIterator<SmartUtente> it( usersList->users );
    while( it.hasNext() ) {
        Utente* u = it.next().getUser();
        Username un = u->getUsername();
        Profilo p = u->getProfile();
        Rete* n = u->getNet();
        Formazione* ed = u->getEducations();
        Esperienza* ex = u->getExperiences();

        // <user>
        xmlWriter.writeStartElement( "user" );
        xmlWriter.writeAttribute( "login", un.getLogin() );

        if( UtenteBasic* ub = dynamic_cast<UtenteBasic*>( u ) )
            xmlWriter.writeAttribute( "type", "basic" );
        else if( UtenteExpress* ue = dynamic_cast<UtenteExpress*>( u ) )
            xmlWriter.writeAttribute( "type", "express" );
        else if( UtenteBusiness* ub = dynamic_cast<UtenteBusiness*>( u ) )
            xmlWriter.writeAttribute( "type", "business" );

        // <profile>
        xmlWriter.writeStartElement( "profile" );
        xmlWriter.writeTextElement( "name", p.getName() );
        xmlWriter.writeTextElement( "surname", p.getSurname() );
        xmlWriter.writeTextElement( "birthday", p.getBirthday().toString( "dd/MM/yyyy" ) );
        xmlWriter.writeTextElement( "maritialStatus", p.getMaritialStatus() );
        xmlWriter.writeEndElement();
        // </profile>

        // <net>
        xmlWriter.writeStartElement( "net" );
        // <contacts>
        xmlWriter.writeTextElement( "contacts", n->getUsernamesList() );
        xmlWriter.writeEndElement();
        // </contacts>
        xmlWriter.writeEndElement();
        // </net>

        // <educations>
        xmlWriter.writeStartElement( "educations" );
        for( int i = 1; i <= ed->titlesNumber(); i++ ) {
            // <title>
            Formazione::Titolo t = ed->getTitleByIndex( i );
            xmlWriter.writeStartElement( "title" );
            xmlWriter.writeTextElement( "school", t.getSchool());
            xmlWriter.writeTextElement( "dateAttended", t.getDateAttended().toString("dd/MM/yyyy") );
            xmlWriter.writeTextElement( "degree", t.getDegree() );
            xmlWriter.writeTextElement( "fieldOfStudy", t.getFieldOfStudy());
            xmlWriter.writeTextElement( "grade", t.getGrade() );
            xmlWriter.writeTextElement( "activities", t.getActivities() );
            xmlWriter.writeEndElement();
            // </title>
        }
        xmlWriter.writeEndElement();
        // </educations>

        // <experiences>
        xmlWriter.writeStartElement( "experiences" );
        for( int i = 1; i <= ex->experiencesNumber(); i++ ) {
            // <job>
            Esperienza::Lavoro j = ex->getJobByIndex( i );
            xmlWriter.writeStartElement( "job" );
            xmlWriter.writeTextElement( "companyName", j.getCompanyName() );
            xmlWriter.writeTextElement( "title", j.getTitle() );
            xmlWriter.writeTextElement( "location", j.getLocation() );
            xmlWriter.writeTextElement( "begin", j.getBegin().toString( "dd/MM/yyyy" ) );
            xmlWriter.writeTextElement( "end", j.getEnd().toString( "dd/MM/yyyy" ) );
            xmlWriter.writeEndElement();
            // </job>
        }
        xmlWriter.writeEndElement();
        // </experiences>

        xmlWriter.writeEndElement();
        // </user>
    }

    // </users>
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
}

Utente* Database::findUser( const Username& un ) const {
    Utente* u = 0;
    QListIterator<SmartUtente> it( usersList->users );
    while( it.hasNext() ) {
        u = it.next().getUser();
        if( u->getUsername().getLogin() != un.getLogin() )
            u = 0;
    }
    return u;
}

void Database::insert( Utente* u ) {
    SmartUtente* su = new SmartUtente( u );
    usersList->users.append( *su );
}

int Database::usersNumber() const {
    return usersList->users.length();
}

QDebug operator <<( QDebug qdbg, Database* d ) {
    if( d->usersList ) {
        QListIterator<SmartUtente> it( d->usersList->users );
        while( it.hasNext() )
            qdbg << it.next().getUser()->getUsername().getLogin();
    }
    return qdbg;
}
