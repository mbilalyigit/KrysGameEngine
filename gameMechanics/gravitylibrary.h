#ifndef GRAVITYLIBRARY_H
#define GRAVITYLIBRARY_H

#include <QObject>
#include "forceclass.h"

#define DEFAULT_GRAVITY     1

class gravityLibrary : public QObject
{
    Q_OBJECT
public:
    explicit gravityLibrary(QObject *parent = nullptr);

    void gravityEnable(bool en);
    QPoint getGravityForce(){return gravForce->getForce();}

private:
    forceClass *gravForce;

signals:

};

#endif // GRAVITYLIBRARY_H
