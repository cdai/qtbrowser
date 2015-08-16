#ifndef ADDRESSBAR_H
#define ADDRESSBAR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QUrl>
#include <QString>

class AddressBar : public QWidget
{
    Q_OBJECT
public:
    explicit AddressBar(QWidget *parent = 0);    
    
signals:
    void go(const QUrl&);
    void back();
    void forward();
    void newPage();
    
public slots:
    void handleGoToSite();
    void handleAddressChanged(const QUrl&);

private:
    QLineEdit *addressEdit;
    QPushButton *newButton;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QPushButton *goButton;
    QHBoxLayout *layout;
};

#endif // ADDRESSBAR_H
