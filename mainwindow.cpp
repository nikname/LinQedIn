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

    QWidget *topVFiller = new QWidget;
    topVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    titleLabel = new QLabel( tr( "<h1>LinQedIn</h1>" ) );
    titleLabel->setAlignment( Qt::AlignHCenter );

    QWidget *middleVFiller = new QWidget;
    middleVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    loginArea = new QVBoxLayout;
    loginArea->setAlignment( Qt::AlignCenter );

    userUsername = new QLineEdit;
    userUsername->setPlaceholderText( "Username" );
    userUsername->setMaximumWidth( 400 );
    userPassword = new QLineEdit;
    userPassword->setPlaceholderText( "Password" );
    userPassword->setMaximumWidth( 400 );
    loginButton = new QPushButton( "Log In" ); // width = 400

    loginArea->addWidget( userUsername );
    loginArea->addWidget( userPassword );
    loginArea->addWidget( loginButton );

    QWidget *bottomVFiller = new QWidget;
    bottomVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QFrame *line = new QFrame;
    line->setFrameShape( QFrame::HLine );
    line->setFrameShadow( QFrame::Sunken );

    adminArea = new QHBoxLayout;

    adminLabel = new QLabel( "Accesso amministratore:" );

    QWidget *middleHFiller = new QWidget;
    middleHFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    adminLogin = new QHBoxLayout;

    adminPassword = new QLineEdit;
    adminPassword->setPlaceholderText( "Password" );
    adminPassword->setMaximumWidth( 150 );
    adminButton = new QPushButton( "Log In" );
    adminButton->setFixedWidth( 50 );

    adminLogin->addWidget( adminPassword );
    adminLogin->addWidget( adminButton );

    adminArea->addWidget( adminLabel );
    adminArea->addWidget( middleHFiller );
    adminArea->addLayout( adminLogin );

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( topVFiller );
    layout->addWidget( titleLabel );
    layout->addWidget( middleVFiller );
    layout->addLayout( loginArea );
    layout->addWidget( bottomVFiller );
    layout->addWidget( line );
    layout->addLayout( adminArea );

    widget->setLayout( layout );

    widget->setStyleSheet(
        "QWidget { background: #069; font-family: Helvetica; }"
        //"QWidget { background: qradialgradient(cx: 0.5, cy: 0.5, fx: 0.5,"
        //  "fy: 0.5, radius: 0.5, stop: 0 white, stop: 1 #069); }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QPushButton { border-radius: 5px; background: #003D5C; color: white; }"
    );

    setStyleSheet( "QLabel { color: white; }" );

    setWindowTitle( "LinQedIn" );
    setMinimumSize( 600, 400 );
    setMaximumSize( 1000, 600 );
}

void MainWindow::createActions() {
    exitAct = new QAction( tr( "Exit" ), this );
    exitAct->setStatusTip( tr( "Esci dall'applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr( "About" ), this );
    aboutAct->setStatusTip( tr( "Mostra le informazioni dell'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

void MainWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
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
