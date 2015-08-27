#ifndef LINQEDINWINDOW_H
#define LINQEDINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;

class LinQedInWindow : public QMainWindow {
    Q_OBJECT
private:
    /** Inizializza la GUI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu. Associa le action al menu ed inserisce il menu nella barra del menu. */
    void createMenus();
protected:
    QMenu *menu;
    QAction *logoutAct;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di default.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit LinQedInWindow( QWidget *parent = 0 );

    /** Disturuttore ridefinito. Ripulisce lo heap. */
    virtual ~LinQedInWindow();
signals:

protected slots:
    /** Esegue il log out dall'applicazione. Mostra la finestra di log in. */
    void logout();

    /** Mostra le informazioni dell'applicazione su di una finestra di dialogo. */
    void about();
};

#endif // LINQEDINWINDOW_H
