#ifndef SAVEGAMEMANAGER_H
#define SAVEGAMEMANAGER_H

#include <QObject>

class saveGameManager : public QObject
{
    Q_OBJECT
public:

    saveGameManager *getInstance();

    saveGameManager(saveGameManager &other) = delete; // No clone
    saveGameManager operator =(const saveGameManager &) = delete; // No assigning

    QByteArray loadGame(int saveSlot);
    bool saveGame(QByteArray gameData, int saveSlot);
    bool deleteSave(int saveSlot);

protected:
    explicit saveGameManager();
    static saveGameManager *singleObj;

private:
    QString folderName = "savegames";
    void createFolder();

signals:

};

#endif // SAVEGAMEMANAGER_H
