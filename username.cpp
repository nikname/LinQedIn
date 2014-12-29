#include "username.h"

using std::ostream;
using std::string;

// USERNAME

Username::Username( string l ) : login( l ) {}

string Username::getLogin() const {
    return login;
}

void Username::changeLogin( string l ) {
    //TODO: controllare che la login non sia già utilizzata da qualcuno
    login = l;
}

// Altro

ostream& operator<< ( ostream& os, Username un ) {
    return os << "LOGIN: " << un.getLogin();
}
