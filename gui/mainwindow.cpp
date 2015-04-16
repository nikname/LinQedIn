#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
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

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    infoLabel = new QLabel( tr(
        "<h1>Benvenuto su LinQedIn!</h1>"
        "<p>Seleziona la modalità di accesso.</p>" ) );
    infoLabel->setAlignment( Qt::AlignCenter );

    QWidget *middleFiller = new QWidget;
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QHBoxLayout *choicesLayout = new QHBoxLayout;

    QPushButton *userButton = new QPushButton( tr( "Utente" ) );
    connect( userButton, SIGNAL( clicked() ), this, SLOT( loginUser() ) );

    QPushButton *adminButton = new QPushButton( tr( "Amministratore" ) );
    connect( adminButton, SIGNAL( clicked() ), this, SLOT( loginAdmin() ) );

    choicesLayout->addWidget( userButton );
    choicesLayout->addWidget( adminButton );

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( topFiller );
    layout->addWidget( infoLabel );
    layout->addWidget( middleFiller );
    layout->addLayout( choicesLayout );
    layout->addWidget( bottomFiller );

    widget->setLayout( layout );

    setStyleSheet( "QPushButton { margin: 0 10 0 10; padding: 5; }");
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
    accountMenu = menuBar()->addMenu( tr( "&Account" ) );
    accountMenu->addAction( loginUserAct );
    accountMenu->addAction( loginAdminAct );
    accountMenu->addSeparator();
    accountMenu->addAction( exitAct );
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
