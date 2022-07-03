#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "gameMechanics/forceclass.h"
#include "gameMechanics/gravitylibrary.h"

#include <QWidget>
#include <QPushButton>

class baseCharacter : public QWidget
{
    Q_OBJECT
public:
    explicit baseCharacter(QWidget *parent = nullptr);
    ~baseCharacter();

protected:
    void moveCharacter(int x, int y){this->move(x, y);}
    void moveCharacterRelative(int x, int y){moveCharacter(this->geometry().x()+x, this->geometry().y()+y);}

private:
    QPushButton *uiBaseObject;
    forceClass *movementCtrl;
    gravityLibrary *gravityCtrl;

private slots:
    void charClicked(bool);
    void moveChar(QPoint moveDir);

signals:
    void heroMoved(QRect geo);
};

#endif // BASECHARACTER_H
