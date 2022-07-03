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
    void saveGame(QByteArray gameData, int saveSlot);
    void deleteSave(int saveSlot);

protected:
    explicit saveGameManager();
    static saveGameManager *singleObj;

signals:

};

#endif // SAVEGAMEMANAGER_H
