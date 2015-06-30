#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

// CLASSE Rete_rapp
class Rete::Rete_rapp {
public:
    QList<QString> contactsList;

    /** Costruttore di default.
     *  Inizializza il campo contactsList con una QList di QString vuota.
     */
    Rete_rapp() :
        contactsList( QList<QString>() ) {}

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
void Rete::addContact( const QString& un ) {
    contacts->contactsList.append( un );
}

// METODO removeContact di Rete
void Rete::removeContact( const QString& un ) {
    contacts->contactsList.removeOne( un );
}

// METODO getContactsList di Rete
QVector<QString> Rete::getContactsList() const {
    QVector<QString> v;
    QListIterator<QString> it( contacts->contactsList );
    while( it.hasNext() )
        v.push_back( it.next() );
    return v;
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
