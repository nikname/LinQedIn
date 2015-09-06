#ifndef LINQEDINWINDOW_H
#define LINQEDINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;

class LinQedInWindow : public QMainWindow {
    Q_OBJECT
private:
    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Crea le varie action necessarie. */
    void createMenuActions();

    /** Crea il menu. Associa le action al menu ed inserisce il menu nella barra del menu. */
    void createMenus();
protected:
    QMenu *menu;
    QAction *exitAct;
    QMenu *helpMenu;
    QAction *aboutAct;
public:
    /** Costruttore esplicito ad 1 parametro con 1 valore di dafault.
     *  Come da buona pratica, delega l'inizializzazione della GUI ad un metodo ausiliario.
     *  Mostra la GUI.
     *
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit LinQedInWindow(QWidget *parent = 0);

    /** Distruttore virtuale puro.
     *  Ripulisce lo heap.
     */
    virtual ~LinQedInWindow() = 0;
signals:

public slots:
    /** Mostra le informazioni dell'applicazione su di una finestra pop-up. */
    void about();
};

#endif // LINQEDINWINDOW_H
