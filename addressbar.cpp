#include "addressbar.h"

AddressBar::AddressBar(QWidget *parent) :
    QWidget(parent)
{
    // 1.Create widget
    addressEdit = new QLineEdit;
    newButton = new QPushButton("New");
    backButton = new QPushButton("Back");
    forwardButton = new QPushButton("Forward");
    goButton = new QPushButton("Go");

    // 2.Set property

    // 3.Connect signal and slot
    connect(goButton, SIGNAL(clicked()), this, SLOT(handleGoToSite()));
    connect(addressEdit, SIGNAL(returnPressed()), this, SLOT(handleGoToSite()));
    connect(backButton, SIGNAL(clicked()), this, SIGNAL(back()));
    connect(forwardButton, SIGNAL(clicked()), this, SIGNAL(forward()));
    connect(newButton, SIGNAL(clicked()), this, SIGNAL(newPage()));

    // 4.Add to layout
    layout = new QHBoxLayout;
    layout->addWidget(newButton);
    layout->addWidget(backButton);
    layout->addWidget(forwardButton);
    layout->addWidget(addressEdit);
    layout->addWidget(goButton);
    this->setLayout(layout);
}

void AddressBar::handleGoToSite()
{
    QString address = addressEdit->text();
    emit go(QUrl(address));
}

void AddressBar::handleAddressChanged(const QUrl &url)
{
    addressEdit->setText(url.toString());
}
