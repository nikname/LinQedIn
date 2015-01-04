#include "database.h"
#include "smartutente.h"
#include <QList>
#include <QListIterator>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>

class Database::ListaUtenti {
public:
    QList<SmartUtente> users;
};

void Database::parseUser( QXmlStreamReader& xmlReader ) {

    QString login = xmlReader.attributes().value( "login" ).toString();
    SmartUtente su( new Utente( Username( login ) ) );
    usersList->users.append( su );
}

Database::Database() : usersList( new ListaUtenti ) {}

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
            if( xmlReader.name() == "utente" ) {
                parseUser( xmlReader );
            }
        }
    }
}

void Database::saveUsersList() const {

    QString path( "users.xml" );
    QFile file( path );
    file.open( QFile::WriteOnly );

    QXmlStreamWriter xmlWriter( &file );
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement( "utenti" );

    QListIterator<SmartUtente> it( usersList->users );
    while( it.hasNext() ) {
        Utente* u = it.next().getUser();
        xmlWriter.writeStartElement( "utente" );
        xmlWriter.writeAttribute( "login", u->getUsername().getLogin() );
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

}

Utente* Database::find( Username un ) const {
    Utente* u;
    QListIterator<SmartUtente> it( usersList->users );
    while( it.hasNext() ) {
        SmartUtente su = it.next();
        if( su.getUser()->getUsername().getLogin() == un.getLogin() )
            u = su.getUser();
    }
    return u;
}
