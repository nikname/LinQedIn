#ifndef UTENTE_H
#define UTENTE_H
#include "profilo.h"
#include "rete.h"
#include "username.h"

class Utente {
public:
    Profilo profile;
    Rete* net;
    Username username;
    Utente( Username un ) : username( un ) {}
    virtual ~Utente() {}
};

#endif
