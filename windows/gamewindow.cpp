#include "gamewindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QDebug>

gameWindow::gameWindow(QWidget *parent)
    : QWidget{parent}
{

    baseCharacter *hero = new baseCharacter(this);
    connect(hero, SIGNAL(heroMoved(QRect)), this, SLOT(heroMoved(QRect)));

}

void gameWindow::addWidgetToScreen(QWidget *w, QPoint location)
{
    //    this->layout()->addWidget()
}

void gameWindow::heroMoved(QRect heroGeo)
{
    baseCharacter *hero = static_cast<baseCharacter*>(sender());
    if(this->geometry().intersects(heroGeo) == false){
        hero->deleteLater();
    }
}
