#include "uisettings.h"

#include <QApplication>
#include <QCoreApplication>
#include <QFont>

uiSettings::uiSettings(QObject *parent)
    : QObject{parent}
{
    initDefaults();
}

void uiSettings::initDefaults()
{
    QSettings uiSettings(QCoreApplication::organizationName(), settingsName);
    uiSettings.setValue("resX", uiSettings.value("resX", "800"));
    uiSettings.setValue("resY", uiSettings.value("resY", "600"));
    uiSettings.setValue("fontSize", uiSettings.value("fontSize", "16"));
    QFont currFont = QApplication::font();
    currFont.setPointSize(16);
    QApplication::setFont(currFont);
}
