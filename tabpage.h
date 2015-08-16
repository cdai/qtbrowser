#ifndef TABPAGE_H
#define TABPAGE_H

#include <QTabWidget>
#include <QList>
#include "htmlview.h"

class TabPage : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabPage(QWidget *parent = 0);
    ~TabPage();
    
signals:
    void urlChanged(const QUrl&);
    
public slots:
    void handleNewTab();
    void handleLoadNewPage(const QUrl&);
    void handleBack();
    void handleForward();

private slots:
    void handleTabChanged(int);
    void handleTabClosed(int);
    void handleLinkClicked(const QUrl&);
    void handleTitleChanged(QString);

private:    
    QList<QWebView*> viewList;
};

#endif // TABPAGE_H
