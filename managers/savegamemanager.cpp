#include "savegamemanager.h"

saveGameManager* saveGameManager::singleObj = nullptr; // should be assigned to nullptr

saveGameManager *saveGameManager::getInstance()
{
    if(singleObj == nullptr){
        singleObj = saveGameManager();
    }
    return singleObj;
}

saveGameManager::saveGameManager()
    : QObject{parent}
{

}
