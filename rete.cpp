#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

class Rete::Contatti {
public:
    QList<SmartUtente> contactsList;

    /** Costruttore di default ridefinito.
     *  Inizializza il campo contactsList con una QList vuota.
     */
    Contatti() : contactsList( QList<SmartUtente>() ) {}

    ~Contatti() {
        if( !contactsList.isEmpty() )
        contactsList.clear();
    }

    /** Aggiunge un nuovo SmartUtente alla lista dei contatti.
     *
     * @param SmartUtente su  SmartUtente da aggiungere alla lista dei contatti.
     */
    void add( const SmartUtente& su ) {
        contactsList.append( su );
    }
};

Rete::Rete() : contacts( new Contatti ) {}

Rete::~Rete() {
    qDebug() << "** DISTRUTTORE Rete **";
}

void Rete::addContact( const Username& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        SmartUtente* su = new SmartUtente( user );
        contacts->add( *su );
    }
}

void Rete::removeContact( const Username& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        contacts->contactsList.removeOne( SmartUtente( user ) );
        delete user;
    }
}

QString Rete::getUsernamesList() const {
    QString usernames = "";
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() ) {
        Utente* u = it.next().getUser();
        usernames.append( u->getUsername().getLogin() );
        if( it.hasNext() )
            usernames.append( ", ");
    }
    return usernames;
}

void Rete::operator delete( void* n ) {
    if( n ) {
        Rete* net = static_cast<Rete*>( n );
        if( net->contacts ) {
            if( net->references )
                net->references--;
            else delete net->contacts;
        }
    }
}

QDebug operator <<( QDebug qdbg, const Rete& r ) {
    qdbg << "CONTATTI: \n";
    if( r.contacts && !r.contacts->contactsList.isEmpty()) {
        QListIterator<SmartUtente> it( r.contacts->contactsList );
        while( it.hasNext() ) {
            qdbg << it.next().getUser()->getUsername().getLogin();
            if( it.hasNext() )
                qdbg << ", ";
        }
        qdbg << "\n";
    } else qdbg << " ** No contacts found! **";
    return qdbg;
}
