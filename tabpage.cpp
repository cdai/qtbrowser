#include "tabpage.h"
#include <QtDebug>

TabPage::TabPage(QWidget *parent) :
    QTabWidget(parent)
{
    // Set property
    this->setTabsClosable(true);

    // Connect built-in signal to customized one
    connect(this, SIGNAL(currentChanged(int)), SLOT(handleTabChanged(int)));
    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(handleTabClosed(int)));

    // Create new tab for home page
    this->handleNewTab();
}

TabPage::~TabPage()
{    
}

void TabPage::handleNewTab()
{
    HtmlView *view = new HtmlView;
    view->load(QUrl("qrc:/html/welcome.html"));
    //view->page()->setForwardUnsupportedContent(true);
    view->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    // Monitor linkClicked signal    
    connect(view, SIGNAL(linkClicked(const QUrl&)), this, SLOT(handleLinkClicked(const QUrl&)));
    connect(view, SIGNAL(titleChanged(QString)), this, SLOT(handleTitleChanged(QString)));

    // Add and activate this new tab
    int index = this->addTab(view, "Welcome");
    this->setCurrentIndex(index);

    viewList.append(view);

    emit urlChanged(QUrl(""));
}

void TabPage::handleLoadNewPage(const QUrl &url)
{
    qDebug() << "loadNewPage: " << url.toString();
    HtmlView *view = (HtmlView*) this->currentWidget();
    view->load(url);
}

void TabPage::handleBack()
{
    HtmlView *view = (HtmlView*) this->currentWidget();
    view->back();
    emit urlChanged(view->url());
}

void TabPage::handleForward()
{
    HtmlView *view = (HtmlView*) this->currentWidget();
    view->forward();
    emit urlChanged(view->url());
}

void TabPage::handleTabChanged(int index)
{
    if (index > viewList.length() - 1)
        return;

    // index is the new tab index
    QWebView* view = viewList[index];
    if (view->url().toString() == "qrc:/html/welcome.html")
        emit urlChanged(QUrl(""));
    else
        emit urlChanged(view->url());
}

void TabPage::handleTabClosed(int index)
{
    if (index > viewList.length() - 1 || viewList.length() == 1)
        return;

    this->removeTab(index);
    QWebView* view = viewList[index];
    viewList.removeAt(index);

    delete view;
}

void TabPage::handleLinkClicked(const QUrl& url)
{
    qDebug() << "handleLinkClicked: " << url.toString();
    HtmlView *view = (HtmlView*) this->currentWidget();
    view->load(url);
    emit urlChanged(url);
}

void TabPage::handleTitleChanged(QString title)
{
    qDebug() << "handleTitleChanged: " << title;
    QString tabText = title;
    if (title.isEmpty())
        tabText = "Welcome";
    if (title.length() > 10)
        tabText = title.left(10);
    this->setTabText(this->currentIndex(), tabText);
    this->setTabToolTip(this->currentIndex(), title);
}
