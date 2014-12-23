#ifndef RETE_H
#define RETE_H
#include <vector>
#include "smart_utente.h"
#include "username.h"

using std::vector;

class Rete {
public:
    vector<SmartUtente> net;
    void add( Username );
    void remove( Username );
};

#endif
