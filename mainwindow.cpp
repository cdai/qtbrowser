#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    //ui->setupUi(this);
    // 0.Global setting
    QWebSettings* defaultSettings = QWebSettings::globalSettings();
    // We use JavaScript, so set it to be enabled.
    defaultSettings->setAttribute(QWebSettings::JavascriptEnabled, true);
    // Plug-ins must be set to be enabled to use plug-ins.
    defaultSettings->setAttribute(QWebSettings::PluginsEnabled,true);
    defaultSettings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    defaultSettings->setObjectCacheCapacities(0, 0, 0);

    // 1.Create widget
    QWidget *centralWidget = new QWidget(this);
    AddressBar *bar = new AddressBar;    
    TabPage *tab = new TabPage(this);

    // 2.Set property
    this->setCentralWidget(centralWidget);
    this->setWindowTitle("My Browser v1.0");
    this->resize(800, 600);

    // 3.Connect widget        
    QObject::connect(bar, SIGNAL(newPage()),tab, SLOT(handleNewTab()));
    QObject::connect(bar, SIGNAL(back()),tab, SLOT(handleBack()));
    QObject::connect(bar, SIGNAL(forward()),tab, SLOT(handleForward()));
    QObject::connect(bar, SIGNAL(go(QUrl)), tab, SLOT(handleLoadNewPage(QUrl)));
    QObject::connect(tab, SIGNAL(urlChanged(QUrl)), bar, SLOT(handleAddressChanged(QUrl)));

    // 4.Add widget to layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(bar, 0, 0, 1, 10);
    layout->addWidget(tab, 1, 0, 1, 10);
    centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    //delete ui;
}
