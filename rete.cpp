#include <vector>
#include "rete.h"

using std::vector;

vector<SmartUtente> Rete::getContacts() const {
    return contacts;
}

void Rete::add( Username u ) {
    //contacts.push_back( u );
}

void Rete::remove( Username u ) {

}
