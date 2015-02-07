#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

// CLASSE Rete_rapp
class Rete::Rete_rapp {
public:
    QList<SmartUtente> contactsList;

    /** Costruttore di default ridefinito.
     *  Inizializza il campo contactsList con una QList di SmartUtente vuota.
     */
    Rete_rapp() :
        contactsList( QList<SmartUtente>() ) {}

    /** Distruttore Rete_rapp.
     *  Invoca il metodo clear() sulla lista dei contatti dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Rete_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Rete_rapp* p_aux = static_cast<Rete_rapp*>( p );
            if( !p_aux->contactsList.isEmpty() )
                p_aux->contactsList.clear();
        }
    }
};

// COSTRUTTORE Rete
Rete::Rete() :
    contacts( new Rete_rapp ),
    user_ref( 1 ) {}

// METODO addContact di Rete
void Rete::addContact( const QString& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user ) {
        SmartUtente* su = new SmartUtente( user );
        contacts->contactsList.append( *su );
    }
    // if( user ) delete user;
    // else ::delete user;
}

// METODO removeContact di Rete
void Rete::removeContact( const QString& un, Database* db ) {
    Utente* user = db->findUser( un );
    if( user )
        contacts->contactsList.removeOne( SmartUtente( user ) );
    // if( user ) delete user;
    // else ::delete user;
}

// METODO getContactsList di Rete
QVector<SmartUtente> Rete::getContactsList() const {
    QVector<SmartUtente> c;
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() )
        c.push_back( it.next() );
    return c;
}

// OPERATOR delete di Rete
void Rete::operator delete( void* p ) {
    if( p ) {
        Rete* p_aux = static_cast<Rete*>( p );
        p_aux->user_ref--;
        if( p_aux->user_ref == 0 )
            delete p_aux->contacts;
    }
}

// OPERATOR << di QDebug
QDebug operator <<( QDebug qdbg, const Rete& r ) {
    qdbg << "CONTATTI: \n";
    if( r.contacts && !r.contacts->contactsList.isEmpty()) {
        QVector<SmartUtente> c = r.getContactsList();
        for( int i = 0; i < c.size(); i++ ) {
            qdbg << c[i].getUser()->getUsername();
            if( i < c.size() - 1 )
                qdbg << ", ";
        }
        qdbg << "\n";
    } else qdbg << " ** No contacts found! **";
    return qdbg;
}
