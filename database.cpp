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

// CLASSE Database::Database_rapp
class Database::Database_rapp {

    // NOTE:
    // È stato deciso di memorizzare gli utenti nel database come mappa, dove l'username
    // è la chiave associata allo SmartUtente. La scelta di utilizzare la classe interna
    // Database_rapp per nascondere i campi dati di Database è data dal fatto che in questo
    // modo il codice è indipendente dalla rappresentazione.
    // È stato deciso di utilizzare una mappa in quanto in questo modo la ricerca di un
    // utente viene fatta in tempo O(1). Stesso discorso vale inserimento e rimozione.

public:
    QMap<QString, SmartUtente> users_list;

    /** Costruttore di default.
     *  Inizializza il campo users_list con una QMap di SmartUtente con chiavi QString, le
     *  quali corrispondono all'username dell'utente.
     */
    Database_rapp() :
        users_list( QMap<QString, SmartUtente>() )
    {}

    /** Distruttore di Database_rapp.
     *  Invoca il metodo clear() sulla mappa degli utenti del database.
     *  clear() a sua volta richiama il distruttore di SmartUtente per ogni utente.
     *
     * @param void* p  Puntatore all'oggetto da distruggere.
     */
    void operator delete( void* p ) {
        if( p ) {
            Database_rapp* p_aux = static_cast<Database_rapp*>( p );
            if( !p_aux->users_list.isEmpty() )
                p_aux->users_list.clear();
        }
    }
};

// METODO Database::parseProfile
void Database::parseProfile( QXmlStreamReader& xmlReader, SmartUtente u ) {
    if( xmlReader.name() == "name" )
        u->setName( xmlReader.readElementText() );
    if( xmlReader.name() == "surname" )
        u->setSurname( xmlReader.readElementText() );
    if( xmlReader.name() == "birthday" )
        parseDate( xmlReader, u );
    if( xmlReader.name() == "maritialStatus" )
        u->setMaritialStatus( xmlReader.readElementText() );
}

// METODO Database::parseDate
void Database::parseDate( QXmlStreamReader& xmlReader, SmartUtente u ) {
    int year = 0;
    int month = 0;
    int day = 0;
    while( ( xmlReader.name() != "birthday"
             && xmlReader.name() != "date"
             && xmlReader.name() != "dateAttended"
             && xmlReader.name() != "begin"
             && xmlReader.name() != "end" )
           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        xmlReader.readNext();
        if( xmlReader.name() == "year" )
            year = xmlReader.readElementText().toInt();
        if( xmlReader.name() == "month" )
            month = xmlReader.readElementText().toInt();
        if( xmlReader.name() == "day" )
            day = xmlReader.readElementText().toInt();
    }
    u->setBirthday( QDate( year, month, day ) );
}

// METODO Database::parseNet
void Database::parseNet( QXmlStreamReader& xmlReader, SmartUtente su ) {
    xmlReader.readNext();
    while( xmlReader.name() != "net" ||
           xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        su->addContact( xmlReader.text().toString() );
        xmlReader.readNext();
    }
    xmlReader.readNext();
}

// METODO Database::parseEducation
void Database::parseEducation( QXmlStreamReader& xmlReader, SmartUtente u ) {
    Titolo* t = new Titolo();
    xmlReader.readNext();
    while( xmlReader.name() != "title"
           || xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
        if( xmlReader.name() == "school" )
            t->setSchool( xmlReader.readElementText() );
        if( xmlReader.name() == "dateAttended" )
            parseDate( xmlReader, u );
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

// METODO Database::parseExperience
void Database::parseExperience( QXmlStreamReader& xmlReader, SmartUtente u ) {
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
        if( xmlReader.name() == "begin" )
            parseDate( xmlReader, u );
        if( xmlReader.name() == "end" )
            parseDate( xmlReader, u );
        xmlReader.readNext();
    }
    u->addExperience( j );
}

// METODO Database::parseUser
void Database::parseUser( QXmlStreamReader& xmlReader ) {
    if( xmlReader.tokenType() != QXmlStreamReader::StartElement &&
        xmlReader.name() != "user" ) {
        qDebug() << "Nessun elemento utente!";
        return;
    }

    Utente* u = 0;
    QString un = xmlReader.attributes().value( "login" ).toString();
    QString type = xmlReader.attributes().value( "type" ).toString();
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
        xmlReader.readNext();
        if( xmlReader.name() == "profile" ) {
            xmlReader.readNext();
            while( xmlReader.name() != "profile" ||
                   xmlReader.tokenType() != QXmlStreamReader::EndElement ) {
                parseProfile( xmlReader, u );
                xmlReader.readNext();
            }
        }

        // L'aggiunta della lista dei contatti è necessario farla in un momento successivo,
        // quanto tutti gli utenti presenti nel file XML sono stati aggiunti al database.

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
    }

    this->insert( u );
}

// COSTRUTTORE Database
Database::Database() : database_rapp( new Database_rapp ) {}

// DISTRUTTORE Database
Database::~Database() {
    delete database_rapp;
}

// METODO Database::contains
bool Database::contains( const QString& un ) const {
    return database_rapp->users_list.contains( un );
}

// METODO Database::find( QString )
SmartUtente Database::find( const QString& un ) {
    // un deve essere presente come chiave nel database
    return database_rapp->users_list.find( un ).value();
}

// METODO Database::loadUserList
void Database::loadUsersList() {

    QString path( "users.xml" );
    QFile file( path );

    if( !file.open( QIODevice::ReadWrite | QIODevice::Text ) ) {
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

    xmlReader.clear();
    xmlReader.setDevice( &file );
    while( !xmlReader.atEnd() && !xmlReader.hasError() ) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if( token == QXmlStreamReader::StartDocument )
            continue;
        if( token == QXmlStreamReader::StartElement) {
            if( xmlReader.name() == "user" )
                loadUsersNet( xmlReader );
        }
    }
}

// METODO Database::saveUsersList
void Database::saveUsersList() const {

    QString path( "users.xml" );
    QFile file( path );
    file.open( QFile::WriteOnly );

    QXmlStreamWriter xmlWriter( &file );
    xmlWriter.setAutoFormatting( true );
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement( "users" );

    QMapIterator<QString, SmartUtente> it( database_rapp->users_list );
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
        // <birthday>
        xmlWriter.writeStartElement( "birthday" );
        QDate birthday = u->getBirthday();
        if( birthday.isValid() ) {
            QStringList list = birthday.toString( "yyyy/MM/dd" ).split( "/" );
            xmlWriter.writeTextElement( "year", list[0] );
            xmlWriter.writeTextElement( "month", list[1] );
            xmlWriter.writeTextElement( "day", list[2] );
        }
        xmlWriter.writeEndElement();
        // </birthday>
        xmlWriter.writeTextElement( "maritialStatus", u->getMaritialStatus() );
        xmlWriter.writeEndElement();
        // </profile>

        // <net>
        xmlWriter.writeStartElement( "net" );
        QVectorIterator<QString> contacts_it( u->getContactsList() );
        while( contacts_it.hasNext() ) {
            xmlWriter.writeTextElement( "contact", contacts_it.next() );
        }
        xmlWriter.writeEndElement();
        // </net>

        // <educations>
        xmlWriter.writeStartElement( "educations" );
        Formazione::Iteratore educations_it( u->getEducationsIterator() );
        while( educations_it.hasNext() ) {
            // <title>
            Titolo* t = educations_it.next();
            xmlWriter.writeStartElement( "title" );
            xmlWriter.writeTextElement( "school", t->getSchool());

            // <dateAttended>
            xmlWriter.writeStartElement( "dateAttended" );
            QDate d = t->getDateAttended();
            if( d.isValid() ) {
                QStringList list = d.toString( "yyyy/MM/dd" ).split( "/" );
                xmlWriter.writeTextElement( "year", list[0] );
                xmlWriter.writeTextElement( "month", list[1] );
                xmlWriter.writeTextElement( "day", list[2] );
            }
            xmlWriter.writeEndElement();
            // </dateAttended>

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
            // <begin>
            xmlWriter.writeStartElement( "begin" );
            QDate begin = j->getBegin();
            if( begin.isValid() ) {
                QStringList list = begin.toString( "yyyy/MM/dd" ).split( "/" );
                xmlWriter.writeTextElement( "year", list[0] );
                xmlWriter.writeTextElement( "month", list[1] );
                xmlWriter.writeTextElement( "day", list[2] );
            }
            xmlWriter.writeEndElement();
            // </begin>
            // <end>
            xmlWriter.writeStartElement( "end" );
            QDate end = j->getEnd();
            if( end.isValid() ) {
                QStringList list = end.toString( "yyyy/MM/dd" ).split( "/" );
                xmlWriter.writeTextElement( "year", list[0] );
                xmlWriter.writeTextElement( "month", list[1] );
                xmlWriter.writeTextElement( "day", list[2] );
            }
            xmlWriter.writeEndElement();
            // </end>
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

// METODO Database::loadUserNet
void Database::loadUsersNet( QXmlStreamReader& xmlReader ) {
    if( xmlReader.tokenType() != QXmlStreamReader::StartElement &&
        xmlReader.name() != "user" ) {
        return;
    }

    QString un = xmlReader.attributes().value( "login" ).toString();
    SmartUtente su = database_rapp->users_list.find( un ).value();

    // l'elemento <net> è sicuramente presente ed eventualmente vuoto
    while( xmlReader.name() != "net" )
        xmlReader.readNext();

    if( xmlReader.tokenType() != QXmlStreamReader::EndElement )
        parseNet( xmlReader, su );

    xmlReader.readNext();
}

// METODO Database::insert
bool Database::insert( SmartUtente su ) {
    if( contains( su->getUsername() ) )
        return false;
    database_rapp->users_list.insert( su->getUsername(), su );
    // NB: gli oggetti su di un contenitore vengono inseriti di copia
    return true;
}

// METODO Database::remove
bool Database::remove( QString u ) {
    return database_rapp->users_list.remove( u );
}

// METODO getUserList Database
QVector<SmartUtente> Database::getUsersList() const {
    QVector<SmartUtente> v;
    QMapIterator<QString, SmartUtente> it( database_rapp->users_list );
    while( it.hasNext() )
        v.append( it.next().value() );
    return v;
}

// OPERATOR << Database
QDebug operator <<( QDebug qdbg, const Database& d ) {
    qdbg << "UTENTI DATABASE: \n";
    if( d.database_rapp ) {
        QMapIterator<QString, SmartUtente> it( d.database_rapp->users_list );
        while( it.hasNext() )
            qdbg << it.next().key() << "\n";
    }
    return qdbg;
}
