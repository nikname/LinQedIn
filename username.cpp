#include "username.h"

using std::ostream;

Username::Username( QString l ) : login( l ) {}

QString Username::getLogin() const {
    return login;
}

void Username::changeLogin( QString l ) {
    //TODO: controllare che la login non sia già utilizzata da qualcuno
    login = l;
}

ostream& operator<< ( ostream& os, Username un ) {
    return os << "LOGIN: " << un.getLogin();
}
