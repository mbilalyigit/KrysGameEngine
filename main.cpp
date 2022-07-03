#include "gamemainwidget.h"

#include <QApplication>
#include "settings/uisettings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    uiSettings uiStg;

    gameMainWidget w;
    w.show();
    return a.exec();
}
