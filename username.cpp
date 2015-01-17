#include "username.h"

QString Username::getLogin() const {
    return login;
}

QDebug operator <<( QDebug qdbg, const Username& un ) {
    qdbg << "LOGIN: " << un.getLogin();
    return qdbg;
}
