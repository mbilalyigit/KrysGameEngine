#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

#include "characters/basecharacter.h"

class gameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit gameWindow(QWidget *parent = nullptr);

    void addWidgetToScreen(QWidget *w, QPoint location = {1,2});

private slots:
    void heroMoved(QRect heroGeo);

signals:

};

#endif // GAMEWINDOW_H
