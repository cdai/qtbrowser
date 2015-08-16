#ifndef GOBUTTON_H
#define GOBUTTON_H

#include <QPushButton>

class GoButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GoButton(QObject *parent = 0);
    
signals:
    clicked(QUrl);
    
public slots:
    
};

#endif // GOBUTTON_H
