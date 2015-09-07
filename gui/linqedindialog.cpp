#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "linqedindialog.h"

// COSTRUTTORE LinQedInDialog
LinQedInDialog::LinQedInDialog( QWidget *parent ) :
    QDialog( parent )
{}

// DISTRUTTORE LinQedInDialog
LinQedInDialog::~LinQedInDialog() {}

// METODO LinQedInDialog::setButtonEnabledProperties( QPushButton * )
void LinQedInDialog::setButtonEnabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white; color: #069;"
                "outline: none; }"
        "QPushButton:pressed { background: #EEE; border: 5px solid #EEE; }"
    );
}

// METODO LinQedInDialog::setButtonDisabledProperties( QPushButton * )
void LinQedInDialog::setButtonDisabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white;"
            "color: rgba(0,102,153,0.38); outline: none; }"
    );
}

// METODO LinQedInDialog::setButtonDisabled( QPushButton *, bool )
void LinQedInDialog::setButtonDisabled( QPushButton *button, bool state ) {
    button->setDisabled( state );
    if( state )
        setButtonDisabledProperties( button );
    else setButtonEnabledProperties( button );
}

// METODO LinQedInDialog::setButtonEnabled( QPushButton *, bool )
void LinQedInDialog::setButtonEnabled( QPushButton *button, bool state ) {
    button->setEnabled( state );
    if( !state )
        setButtonDisabledProperties( button );
    else setButtonEnabledProperties( button );
}

// METODO LinQedInDialog::setLineEditProperties( QLineEdit * )
void LinQedInDialog::setLineEditProperties( QLineEdit *lineEdit ) {
    lineEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #069; border-top: none; border-right: none;"
            "border-left: none; color: rgba(0,0,0,0.87); }"
    );
}


// METODO LinQedInDialog::setTitleLabelProperties( QLabel * )
void LinQedInDialog::setTitleLabelProperties( QLabel *label ) {
    label->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); font: 12px; }" );
}

// METODO LinQedInDialog::paintEvent( QPaintEvent * )
void LinQedInDialog::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
