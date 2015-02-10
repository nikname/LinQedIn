#include "database.h"
#include "smartutente.h"
#include <QMap>
#include <QMapIterator>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include "utente_basic.h"
#include "utente_express.h"
#include "utente_business.h"
#include "rete.h"

// CLASSE Database_rapp
class Database::Database_rapp {
public:
    QMap<QString, SmartUtente> usersList;

    /** Costruttore di default.
     *  Inizializza il campo usersList con una QMap di valori SmartUtente e chiavi QString.
     *  Popola il database da file xml.
     */
    Database_rapp() :
        usersList( QMap<QString, SmartUtente>() ) {
        // TODO: popolare il database
    }

    /** Distruttore Database_rapp.
     *  Invoca il metodo clear() sulla mappa degli utenti del database.
     *
     * @param void* p  Puntatore all'oggetto Database_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Database_rapp* p_aux = static_cast<Database_rapp*>( p );
            if( !p_aux->usersList.isEmpty() )
                p_aux->usersList.clear();
        }
    }
};

// METODO parseProfile Database
void Database::parseProfile( QXmlStreamReader& xmlReader, Utente* u ) {
    if( xmlReader.name() == "name" )
        u->setName( xmlReader.readElementText() );
    if( xmlReader.name() == "surname" )
        u->setSurname( xmlReader.readElementText() );
    if( xmlReader.name() == "birthday" ) {
        QString b = xmlReader.readElementText();
        QStringList list = b.split( "/" );
        if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
            u->setBirthday( QDate( list[2].toInt(), list[1].toInt(), list[0].toInt() ) );
        else u->setBirthday( QDate() );
    }
    if( xmlReader.name() == "maritialStatus" )
        u->setMaritialStatus( xmlReader.readElementText() );
}

// METODO parseNet Database
void Database::parseNet( QXmlStreamReader& xmlReader, Utente* u ) {

}

// METODO parseEducation Database
void Database::parseEducation( QXmlStreamReader& xmlReader, Utente* u ) {
    Titolo* t = new Titolo();
    xmlReader.readNext();
    while( xmlReader.name() != "title"
           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        if( xmlReader.name() == "school" )
            t->setSchool( xmlReader.readElementText() );
        if( xmlReader.name() == "dateAttended" ) {
            QStringList list = xmlReader.readElementText().split( "/" );
            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                t->setDateAttended( QDate( list[2].toInt(), list[1].toInt(), list[0].toInt() ) );
            else t->setDateAttended( QDate() );
        }
        if( xmlReader.name() == "degree" )
            t->setDegree( xmlReader.readElementText() );
        if( xmlReader.name() == "fieldOfStudy" )
            t->setFieldOfStudy( xmlReader.readElementText() );
        if( xmlReader.name() == "grade" )
            t->setGrade( xmlReader.readElementText() );
        xmlReader.readNext();
    }
    u->addEducation( t );
}

// METODO parseExperience Database
void Database::parseExperience( QXmlStreamReader& xmlReader, Utente* u ) {
    Lavoro* j = new Lavoro();
    xmlReader.readNext();
    while( xmlReader.name() != "job"
           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        if( xmlReader.name() == "companyName" )
            j->setCompanyName( xmlReader.readElementText() );
        if( xmlReader.name() == "title" )
            j->setTitle( xmlReader.readElementText() );
        if( xmlReader.name() == "location" )
            j->setLocation( xmlReader.readElementText() );
        if( xmlReader.name() == "begin" ) {
            QStringList list = xmlReader.readElementText().split( "/" );
            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                j->setBegin( QDate( list[2].toInt(), list[1].toInt(), list[0].toInt() ) );
            else j->setBegin( QDate() );
        }
        if( xmlReader.name() == "end" ) {
            QStringList list = xmlReader.readElementText().split( "/" );
            if( !list[0].isEmpty() && !list[1].isEmpty() && !list[2].isEmpty() )
                j->setEnd( QDate( list[2].toInt(), list[1].toInt(), list[0].toInt() ) );
            else j->setEnd( QDate() );
        }
        xmlReader.readNext();
    }
    u->addExperience( j );
}

// METODO parseUser Database
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
                parseProfile( xmlReader, u );
                xmlReader.readNext();
            }
        }
        if( xmlReader.name() == "net" ) { // Necessario farla in un secondo momento!
            xmlReader.readNext();
            while( xmlReader.name() != "net" ||
                   xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                parseNet( xmlReader, u );
                xmlReader.readNext();
            }
        }
        if( xmlReader.name() == "educations" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "educations"
                   || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                if( xmlReader.name() == "title" )
                    parseEducation( xmlReader, u );
                xmlReader.readNext();
            }
        }
        if( xmlReader.name() == "experiences" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "experiences"
                   || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                if( xmlReader.name() == "job" )
                    parseExperience( xmlReader, u );
                xmlReader.readNext();
            }
        }
        xmlReader.readNext();
    }

    this->insert( u );
}

// COSTRUTTORE Database
Database::Database() : dbUsers( new Database_rapp ) {}

// DISTRUTTORE Database
Database::~Database() {
    delete dbUsers;
}

// METODO loadUserList Database
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

    QMapIterator<QString, SmartUtente> it( dbUsers->usersList );
    while( it.hasNext() ) {
        Utente* u = it.next().value().operator ->();

        // <user>
        xmlWriter.writeStartElement( "user" );
        xmlWriter.writeAttribute( "login", u->getUsername() );

        if( dynamic_cast<UtenteBasic*>( u ) )
            xmlWriter.writeAttribute( "type", "basic" );
        else if( dynamic_cast<UtenteExpress*>( u ) )
            xmlWriter.writeAttribute( "type", "express" );
        else if( dynamic_cast<UtenteBusiness*>( u ) )
            xmlWriter.writeAttribute( "type", "business" );

        // <profile>
        xmlWriter.writeStartElement( "profile" );
        xmlWriter.writeTextElement( "name", u->getName() );
        xmlWriter.writeTextElement( "surname", u->getSurname() );
        xmlWriter.writeTextElement( "birthday", u->getBirthday().toString( "dd/MM/yyyy" ) );
        xmlWriter.writeTextElement( "maritialStatus", u->getMaritialStatus() );
        xmlWriter.writeEndElement();
        // </profile>

        // <net>
        xmlWriter.writeStartElement( "net" );
        QVector<SmartUtente> v = u->getContactsList();
        for( int i = 0; i < v.size(); i++ ) {
            // <contact>
            xmlWriter.writeTextElement( "contact", v[i]->getUsername() );
            // </contact>
        }
        xmlWriter.writeEndElement();
        // </net>

        // <educations>
        xmlWriter.writeStartElement( "educations" );
        Formazione::Iteratore it_ed( u->getEducationsIterator() );
        while( it_ed.hasNext() ) {
            // <title>
            Titolo* t = it_ed.next();
            xmlWriter.writeStartElement( "title" );
            xmlWriter.writeTextElement( "school", t->getSchool());
            xmlWriter.writeTextElement( "dateAttended", t->getDateAttended().toString("dd/MM/yyyy") );
            xmlWriter.writeTextElement( "degree", t->getDegree() );
            xmlWriter.writeTextElement( "fieldOfStudy", t->getFieldOfStudy());
            xmlWriter.writeTextElement( "grade", t->getGrade() );
            xmlWriter.writeEndElement();
            // </title>
        }
        xmlWriter.writeEndElement();
        // </educations>

        // <experiences>
        xmlWriter.writeStartElement( "experiences" );
        Esperienza::Iteratore it_ex( u->getExperiencesIterator() );
        while( it_ex.hasNext() ) {
            // <job>
            Lavoro* j = it_ex.next();
            xmlWriter.writeStartElement( "job" );
            xmlWriter.writeTextElement( "companyName", j->getCompanyName() );
            xmlWriter.writeTextElement( "title", j->getTitle() );
            xmlWriter.writeTextElement( "location", j->getLocation() );
            xmlWriter.writeTextElement( "begin", j->getBegin().toString( "dd/MM/yyyy" ) );
            xmlWriter.writeTextElement( "end", j->getEnd().toString( "dd/MM/yyyy" ) );
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

// METODO contains Database
bool Database::contains( const QString& un ) const {
    return dbUsers->usersList.contains( un );
}

// METODO insert Database
void Database::insert( Utente* u ) {
    qDebug() << u;
    if( contains( u->getUsername() ) )
        return;
    dbUsers->usersList.insert( u->getUsername(), SmartUtente( u ) );
}

// METODO getDbUserList Database
QVector<SmartUtente> Database::getDbUsersList() const {
    QVector<SmartUtente> v;
    QMapIterator<QString, SmartUtente> it( dbUsers->usersList );
    while( it.hasNext() )
        v.append( it.next().value() );
    return v;
}

// OPERATOR << Database
QDebug operator <<( QDebug qdbg, Database* d ) {
    qdbg << "UTENTI DATABASE: \n";
    if( d->dbUsers ) {
        QMapIterator<QString, SmartUtente> it( d->dbUsers->usersList );
        while( it.hasNext() )
            qdbg << it.next().key() << "\n";
    }
    return qdbg;
}
