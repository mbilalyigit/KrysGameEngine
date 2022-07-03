#include "basecharacter.h"

#include <QVBoxLayout>
#include <QDebug>

baseCharacter::baseCharacter(QWidget *parent)
    : QWidget{parent}
{
    if(this->layout() == nullptr)
        this->setLayout(new QVBoxLayout(this));

    this->layout()->setMargin(0);
    this->layout()->setSpacing(0);

    uiBaseObject = new QPushButton("Hero", this);
    this->layout()->addWidget(uiBaseObject);
    connect(uiBaseObject, SIGNAL(clicked(bool)), this, SLOT(charClicked(bool)));

    movementCtrl = new forceClass(this);
    connect(movementCtrl, SIGNAL(forceCallback(QPoint)), this, SLOT(moveChar(QPoint)));

    gravityCtrl = new gravityLibrary(this);
}

baseCharacter::~baseCharacter()
{
    qDebug() << uiBaseObject->text() << " is deleted";
}

void baseCharacter::charClicked(bool)
{
    moveCharacterRelative(10, 10);
}

void baseCharacter::moveChar(QPoint moveDir)
{
    if(this->isVisible()){
        moveCharacterRelative(moveDir.x() + gravityCtrl->getGravityForce().x(), moveDir.y() + gravityCtrl->getGravityForce().y());
        emit heroMoved(this->geometry());
    }
}
