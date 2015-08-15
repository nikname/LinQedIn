#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "editdialog.h"

// COSTRUTTORE EditDialog
EditDialog::EditDialog( QWidget *parent ) :
    QDialog( parent )
{}

// DISTRUTTORE EditDialog
EditDialog::~EditDialog() {}

// METODO EditDialog::setButtonEnabledProperties( QPushButton * )
void EditDialog::setButtonEnabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white; color: #069;"
                "outline: none; }"
        "QPushButton:pressed { background: #EEE; border: 5px solid #EEE; }"
    );
}

// METODO EditDialog::setButtonDisabledProperties( QPushButton * )
void EditDialog::setButtonDisabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white;"
            "color: rgba(0,102,153,0.38); outline: none; }"
    );
}

// METODO EditDialog::setButtonDisabled( QPushButton *, bool )
void EditDialog::setButtonDisabled( QPushButton *button, bool state ) {
    button->setDisabled( state );
    setButtonDisabledProperties( button );
}

// METODO EditDialog::setButtonEnabled( QPushButton *, bool )
void EditDialog::setButtonEnabled( QPushButton *button, bool state ) {
    button->setEnabled( state );
    setButtonEnabledProperties( button );
}

// METODO EditDialog::setLineEditProperties( QLineEdit * )
void EditDialog::setLineEditProperties( QLineEdit *lineEdit ) {
    lineEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #069; border-top: none; border-right: none;"
            "border-left: none; color: rgba(0,0,0,0.87); }"
    );
}

// METODO EditDialog::paintEvent
void EditDialog::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
