#include <QVBoxLayout>
#include "utente.h"
#include "userpreviewwidget.h"
#include "searchresultswidget.h"

// COSTRUTTORE SearchResultsWidget
SearchResultsWidget::SearchResultsWidget( QVector<SmartUtente> ul,
                                          const SmartUtente& su,
                                          const QString& query,
                                          QWidget *parent ) :
    QWidget( parent ),
    usersList( ul )
{
    initUI( su, query );
    setupUI();
}

// METODO SearchResultsWidget::initUI
void SearchResultsWidget::initUI( const SmartUtente& su, const QString& query ) {
    for( int i = 0; i < usersList.size(); i++ ) {
        if( usersList[i] != su && (
                usersList[i]->getName().contains( query, Qt::CaseInsensitive ) ||
                usersList[i]->getSurname().contains( query, Qt::CaseInsensitive ) ) )
            userPreviewWidgetsList.append( new UserPreviewWidget( usersList[i], this ) );
    }
}

// METODO SearchResultsWidget::setupUI
void SearchResultsWidget::setupUI() {
    QVBoxLayout *userPreviewWidgetsLayout = new QVBoxLayout( this );
    userPreviewWidgetsLayout->setMargin( 0 );

    for( int i = 0; i < userPreviewWidgetsList.size(); i++ ) {
        userPreviewWidgetsList[i]->hideRemoveUserButton();
        userPreviewWidgetsLayout->addWidget( userPreviewWidgetsList[i] );
    }
}
