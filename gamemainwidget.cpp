#include "gamemainwidget.h"

#include <QVBoxLayout>

gameMainWidget::gameMainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(800,600);

    if(this->layout() == nullptr)
        this->setLayout(new QVBoxLayout(this));

    startPage = new StartPage(this);
    this->layout()->addWidget(startPage);


    window = new gameWindow(this);
    window->hide();
    this->layout()->addWidget(window);

}

gameMainWidget::~gameMainWidget()
{
}

