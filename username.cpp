#include "username.h"

QString Username::getLogin() const {
    return login;
}

void Username::changeLogin( const QString& l ) {
    //TODO: controllare che la login non sia già utilizzata da qualcuno
    login = l;
}

QDebug operator <<( QDebug qdbg, const Username& un ) {
    qdbg << "LOGIN: " << un.getLogin();
    return qdbg;
}
