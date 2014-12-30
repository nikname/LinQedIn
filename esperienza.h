#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QString>
#include <QDate>

class Esperienza {
private:
    QString companyName;
    QString title;
    QString location;
    QDate begin;
    QDate end;
    QString description;
public:
    QString getCompanyName() const;
    QString getTitle() const;
    QString getLocation() const;
    QDate getPeriod() const;
    QDate getDescription() const;
    void setCompanyName( QString );
    void setTitle( QString );
    void setLocation( QString );
    void setBegin( QDate );
    void setEnd( QDate );
    void setDescription( QString );
};

#endif // ESPERIENZA_H
