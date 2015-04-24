#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>

class LinQedInClient;

class ClientWindow : public QMainWindow {
    Q_OBJECT
private:
    LinQedInClient *client;
public:
    explicit ClientWindow( QWidget *parent = 0 );
};

#endif // CLIENTWINDOW_H
