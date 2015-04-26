#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>

class AdminSearchWidget : public QWidget {
    Q_OBJECT
private:
    QLineEdit *search;

    QCheckBox *userType;
public:
    explicit AdminSearchWidget( QWidget *parent = 0 );
signals:

public slots:

};

#endif // SEARCH_WIDGET_H
