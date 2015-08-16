#ifndef HTMLVIEW_H
#define HTMLVIEW_H

#include <QWebView>

class HtmlView : public QWebView
{
    Q_OBJECT
public:
    explicit HtmlView(QWidget *parent = 0);
    
signals:
    
public slots:
    void loadNewPage(const QUrl &url);
    
};

#endif // HTMLVIEW_H
