#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDebug>
#include <QString>
#include <QDate>

class Esperienza {
private:
    class EspLavorative;
    EspLavorative* expiriences;
public:

    Esperienza();

    friend QDebug operator <<( QDebug, const Esperienza& );
};

QDebug operator <<( QDebug, const Esperienza& );

#endif // ESPERIENZA_H
