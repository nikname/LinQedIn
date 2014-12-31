#include "username.h"

Username::Username( QString l ) : login( l ) {}

QString Username::getLogin() const {
    return login;
}

void Username::changeLogin( QString l ) {
    //TODO: controllare che la login non sia già utilizzata da qualcuno
    login = l;
}
/*
ostream& operator<< ( const ostream& os, const Username& un ) {
    return os << "LOGIN: " << un.getLogin();
}
*/
QDebug& operator <<( QDebug& qdbg, const Username& un ) {
    qdbg << "LOGIN: " << un.getLogin();
    return qdbg;
}
