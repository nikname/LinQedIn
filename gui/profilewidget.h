#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "smartutente.h"
#include "smartlavoro.h"
#include "smarttitolo.h"

class ConnectionsWidget;
class EducationsWidget;
class ExperiencesWidget;
class QLabel;
class OtherInfoWidget;
class QPushButton;

class ProfileWidget : public QWidget {
    Q_OBJECT
protected:
    SmartUtente user;

    QLabel *profilePicLabel;

    QWidget *profileSummary;
    QLabel *nameSurnameLabel;

    QVector<QPushButton *> tabButtons;
    QPushButton *otherInfoTabButton;

    OtherInfoWidget *otherInfoTab;

    /** Inizializza la UI. */
    void initUI();

    /** Realizza la UI. Mostra la GUI. */
    void setupUI();

    /** Applica delle proprietà dei pulsanti del menu interno al profilo.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setProfileButtonProperties( QPushButton* );

    /** Modifica la GUI mostrando quale pulsante del menu interno al profilo è stato selezionato.
     *
     * @param QPushButton  Pulsante al quale applicare le proprietà.
     */
    void setProfileButtonSelected( QPushButton* );
public:
    /** Costruttore esplicito a 2 parametri con 1 parametro di default.
     *
     * @param SmartUtente  Utente del quale mostrare le informazioni.
     * @param QWidget  Puntatore al QWidget padre. Se nullo si riferisce a quello top-level.
     */
    explicit ProfileWidget( const SmartUtente&, QWidget *parent = 0 );

    /** Distruttore virtuale puro. Ripulisce lo heap. */
    virtual ~ProfileWidget() = 0;
signals:

protected slots:
};

#endif // PROFILEWIDGET_H
