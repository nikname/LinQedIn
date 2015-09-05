#include <QList>
#include <QListIterator>
#include "rete.h"
#include "smartutente.h"
#include "utente.h"

// CLASSE Rete_rapp
class Rete::Rete_rapp {
public:
    QList<SmartUtente> contactsList;
    int references;

    /** Costruttore ad 1 parametro con 1 valore di default.
     *  Inizializza a 1 il numero di riferimenti.
     */
    Rete_rapp( QList<SmartUtente> l = QList<SmartUtente>() ) :
        contactsList( l ),
        references( 1 ) // Gestito da Rete
    {}

    /** Distruttore Rete_rapp.
     *  Invoca il metodo clear() sulla lista dei contatti dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Rete_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Rete_rapp* p_aux = static_cast<Rete_rapp*>( p );
            p_aux->references--;
            if( !p_aux->references )
                p_aux->contactsList.clear();
        }
    }

    /** Metodo di utilità necessario per creare copie profonde di oggetti di tipo Rete_rapp.
     *
     * @return Rete_rapp *  Copia implicita della lista di contatti.
     */
    Rete_rapp *clone() const {
        return new Rete_rapp( contactsList );
    }
};

// COSTRUTTORE Rete
Rete::Rete() :
    contacts( new Rete_rapp ),
    user_ref( 1 )
{}

// COSTRUTTORE di COPIA Rete
Rete::Rete( const Rete& n ) :
    contacts( n.contacts )
{
    user_ref++;
    contacts->references++;
}

// DISTRUTTORE Rete
Rete::~Rete() {
    contacts->references--;
    if( contacts->references == 0 )
        delete contacts;
}

// METODO Rete::addContact( SmartUtente )
void Rete::addContact( const SmartUtente& su ) {
    if( !isContact( su ) )
        contacts->contactsList.append( su );
}

// METODO Rete::removeContact( SmartUtente )
void Rete::removeContact( const SmartUtente& su ) {
    if( isContact( su ) )
        contacts->contactsList.removeOne( su );
}

// METODO Rete::isContact( SmartUtente )
bool Rete::isContact( const SmartUtente& su ) const {
    return contacts->contactsList.contains( su );
}

// METODO Rete::getContactsList
QVector<SmartUtente> Rete::getContactsList() const {
    QVector<SmartUtente> v;
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() )
        v.push_back( it.next() );
    return v;
}

// OVERLOADING
QDebug& operator <<( QDebug& qdbg, const Rete& n ) {
    qdbg << "CONTATTI: " << "\n";
    QVector<SmartUtente> c = n.getContactsList();
    if( c.size() == 0 )
        qdbg << " ** Nessun contatto! **" << "\n";
    else {
        for( int i = 0; i < c.size(); i++ )
            qdbg << " " << c[i]->getName() << c[i]->getSurname() << "\n";
    }
}
