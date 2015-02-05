#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

// CLASSE Contatti
class Rete::Contatti {
public:
    QList<SmartUtente> contactsList;

    /** Costruttore di default ridefinito.
     *  Inizializza il campo contactsList con una QList di SmartUtente vuota.
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

// COSTRUTTORE Rete
Rete::Rete() : contacts( new Contatti ) {}

// DISTRUTTORE Rete
Rete::~Rete() {}

// METODO addContact di Rete
void Rete::addContact( const QString& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        SmartUtente* su = new SmartUtente( user );
        contacts->add( *su );
    }
}

// METODO removeContact di Rete
void Rete::removeContact( const QString& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        contacts->contactsList.removeOne( SmartUtente( user ) );
        delete user;
    }
}

// METODO getContactsList di Rete
QVector<QString> Rete::getContactsList() const {
    QVector<QString> c;
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() )
        c.push_back( it.next().getUser()->getUsername() );
    return c;
}

// OPERATOR delete di Rete
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

// OPERATOR << di QDebug
QDebug operator <<( QDebug qdbg, const Rete& r ) {
    qdbg << "CONTATTI: \n";
    if( r.contacts && !r.contacts->contactsList.isEmpty()) {
        QVector<QString> c = r.getContactsList();
        for( int i = 0; i < c.size(); i++ ) {
            qdbg << c[i];
            if( i < c.size() - 1 )
                qdbg << ", ";
        }
        qdbg << "\n";
    } else qdbg << " ** No contacts found! **";
    return qdbg;
}
