#ifndef USERSEARCHWIDGET_H
#define USERSEARCHWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class UserSearchWidget : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *searchLabel;
    QLineEdit *search;

    QWidget *typeCheckbox;
    QLabel *typeLabel;
    QCheckBox *typeCheckboxBasic;
    QCheckBox *typeCheckboxExecutive;
    QCheckBox *typeCheckboxBusiness;

    QWidget *fieldCheckbox;
    QLabel *fieldLabel;
    QCheckBox *fieldCheckboxUsername;
    QCheckBox *fieldCheckboxName;
    QCheckBox *fieldCheckboxSurname;

    QWidget *searchWidget;
    QVBoxLayout *searchWidgetLayout;
    QPushButton *searchButton;
    QPushButton *searchSettingsButton;
    QPushButton *hideSearchSettingsButton;
    QPushButton *resetButton;
public:
    /** Costruttore esplicito ad 1 parametro con 1 parametro di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit UserSearchWidget( QWidget *parent = 0 );
signals:

public slots:
    /** Mostra le opzioni per la ricerca avanzata. */
    void showAdvancedSettings();

    /** Nasconde le opzioni per la ricerca avanzata. */
    void hideAdvancedSettings();

    void searchUsers();
};

#endif // USERSEARCHWIDGET_H
