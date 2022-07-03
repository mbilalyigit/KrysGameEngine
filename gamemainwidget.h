#ifndef GAMEMAINWIDGET_H
#define GAMEMAINWIDGET_H

#include "windows/gamewindow.h"
#include "pages/startpage.h"

#include <QWidget>

class gameMainWidget : public QWidget
{
    Q_OBJECT

public:
    gameMainWidget(QWidget *parent = nullptr);
    ~gameMainWidget();

private:
    StartPage *startPage;
    gameWindow *window;


};
#endif // GAMEMAINWIDGET_H
