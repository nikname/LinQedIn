#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    initializeGUI();

    this->show();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initializeGUI() {

    QWidget *widget = new QWidget;
    setCentralWidget( widget );

    createActions();
    createMenus();

    infoLabel = new QLabel( tr(
        "<h1>Benvenuto su LinQedIn!</h1>" ) );
    infoLabel->setAlignment( Qt::AlignCenter );

    QGroupBox *userLoginBox = new QGroupBox( tr( "Login utente" ) );
    QGridLayout *userLoginArea = new QGridLayout;
    QLabel *userUsernameLabel = new QLabel( tr( "Username" ) );
    userUsername = new QLineEdit();
    QLabel *userPasswordLabel = new QLabel( tr( "Password" ) );
    userPassword = new QLineEdit();
    userLoginArea->addWidget( userUsernameLabel, 0, 0 );
    userLoginArea->addWidget( userUsername, 0, 1 );
    userLoginArea->addWidget( userPasswordLabel, 1, 0 );
    userLoginArea->addWidget( userPassword, 1, 1 );
    userLoginBox->setLayout( userLoginArea );

    QGroupBox * adminLoginBox = new QGroupBox( tr( "Login amministratore" ) );
    QGridLayout * adminLoginArea = new QGridLayout;
    QLabel *adminUsernameLabel = new QLabel( tr( "Username" ) );
    adminUsername = new QLineEdit();
    QLabel *adminPasswordLabel = new QLabel( tr( "Password" ) );
    adminPassword = new QLineEdit();
    adminLoginArea->addWidget( adminUsernameLabel, 0, 0 );
    adminLoginArea->addWidget( adminUsername, 0, 1 );
    adminLoginArea->addWidget( adminPasswordLabel, 1, 0 );
    adminLoginArea->addWidget( adminPassword, 1, 1 );
    adminLoginBox->setLayout( adminLoginArea );

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( infoLabel );
    layout->addWidget( userLoginBox );

    QFrame *line = new QFrame;
    line->setFrameShape( QFrame::HLine );
    line->setFrameShadow( QFrame::Sunken );
    layout->addWidget( line );

    layout->addWidget( adminLoginBox );

    widget->setLayout( layout );

    setWindowTitle( "LinQedIn" );
    setMinimumSize( 400, 300 );
    setMaximumSize( 400, 300 );
}

void MainWindow::createActions() {
    loginUserAct = new QAction( tr( "Login as User" ), this );
    loginUserAct->setStatusTip( tr( "Accesso come utente" ) );
    connect( loginUserAct, SIGNAL( triggered() ), this, SLOT( loginUser() ) );
    loginAdminAct = new QAction( tr( "Login as Admin"), this );
    loginAdminAct->setStatusTip( tr( "Accesso come amministratore" ) );
    connect( loginAdminAct, SIGNAL( triggered() ), this, SLOT( loginAdmin() ) );
    exitAct = new QAction( tr( "Exit" ), this );
    exitAct->setStatusTip( tr( "Esci dall'applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr( "About" ), this );
    aboutAct->setStatusTip( tr( "Mostra le informazioni dell'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

void MainWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( loginUserAct );
    menu->addAction( loginAdminAct );
    menu->addSeparator();
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

void MainWindow::loginAdmin() {

}

void MainWindow::loginUser() {

}

void MainWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}
