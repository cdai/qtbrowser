#include "htmlview.h"

HtmlView::HtmlView(QWidget *parent) :
    QWebView(parent)
{
}

void HtmlView::loadNewPage(const QUrl &url)
{    
    this->load(url);
}

