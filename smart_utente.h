#ifndef SMART_UTENTE_H
#define SMART_UTENTE_H

class Utente;

class SmartUtente {
private:
    Utente* user;
public:
    Utente* getUser() const {
        return user;
    }
};

ostream& operator<< ( ostream& os, SmartUtente) {
    return os;
}

#endif
