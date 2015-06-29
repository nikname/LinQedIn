#ifndef TABPROFILO_H
#define TABPROFILO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "linqedin_client.h"

class TabProfilo : public QWidget {
    Q_OBJECT
private:
    QLabel *nameLabel;
    QLabel *userNameLabel;
    QLineEdit *nameLineEdit;

    QLabel *surnameLabel;
    QLabel *userSurnameLabel;
    QLineEdit *surnameLineEdit;

    QLabel *usernameLabel;
    QLabel *userUsernameLabel;
    QLineEdit *usernameLineEdit;

    QLabel *accountTypeLabel;
    QLabel *userAccountTypeLabel;
    QLineEdit *accountTypeLineEdit;

    QLabel *maritialStatusLabel;
    QLabel *userMaritialStatusLabel;
    QLineEdit *maritialStatusLineEdit;

    QPushButton *editButton;
    QPushButton *saveButton;
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param SmartUtente  Utente utilizzatore del client.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit TabProfilo( SmartUtente, QWidget *parent = 0 );
signals:
    /** */
    void updateUserInfoSignal( const QString&, const QString& );
private slots:
    /** */
    void editInfo();

    /** */
    void saveInfo();
};

#endif // TABPROFILO_H
