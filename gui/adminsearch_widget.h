#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>

class AdminSearchWidget : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *searchLabel;
    QLineEdit *search;
    QWidget *checkbox;
    QCheckBox *checkboxEntry1;
    QCheckBox *checkboxEntry2;
    QCheckBox *checkboxEntry3;
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
    explicit AdminSearchWidget( QWidget *parent = 0 );
signals:

public slots:
    void showAdvancedSettings();

    void hideAdvancedSettings();

    void searchUsers();
};

#endif // SEARCH_WIDGET_H
