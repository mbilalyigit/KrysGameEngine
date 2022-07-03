QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    characters/basecharacter.cpp \
    gameMechanics/forceclass.cpp \
    managers/savegamemanager.cpp \
    pages/startpage.cpp \
    settings/uisettings.cpp \
    pages/slotselectionpage.cpp \
    windows/gamewindow.cpp \
    gameMechanics/gravitylibrary.cpp \
    main.cpp \
    gamemainwidget.cpp

HEADERS += \
    characters/basecharacter.h \
    gameMechanics/forceclass.h \
    gamemainwidget.h \
    managers/savegamemanager.h \
    pages/startpage.h \
    settings/uisettings.h \
    pages/slotselectionpage.h \
    windows/gamewindow.h \
    gameMechanics/gravitylibrary.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
