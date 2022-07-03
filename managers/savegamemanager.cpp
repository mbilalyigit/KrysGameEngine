#include "savegamemanager.h"

#include <QFile>
#include <QDir>
#include <QDebug>

saveGameManager* saveGameManager::singleObj = nullptr; // should be assigned to nullptr

saveGameManager *saveGameManager::getInstance()
{
    if(singleObj == nullptr){
        singleObj = new saveGameManager();
    }
    return singleObj;
}

saveGameManager::saveGameManager()
{
    createFolder();
}

QByteArray saveGameManager::loadGame(int saveSlot)
{
    QByteArray retBytes;
    QString filename = QString("%1/saveSlot%2").arg(folderName).arg(saveSlot);
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return retBytes;
    retBytes = file.readAll();
    file.close();
    return retBytes;
}

void saveGameManager::createFolder()
{
    QDir directory(folderName);
    if(!directory.exists()){
        directory.mkdir(folderName);
    }
}

bool saveGameManager::saveGame(QByteArray gameData, int saveSlot)
{
    bool retval = true;
    QString filename = QString("%1/saveSlot%2").arg(folderName).arg(saveSlot);
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
        return false;
    try{
        file.write(gameData);
    }
    catch(...){
        qWarning() << "Error happened while saving the game!";
        retval = false;
    }
    file.close();
    return retval;
}

bool saveGameManager::deleteSave(int saveSlot)
{
    QString filename = QString("%1/saveSlot%2").arg(folderName).arg(saveSlot);
    QFile file(filename);
    if(file.exists())
        return file.remove();
    return true;
}
