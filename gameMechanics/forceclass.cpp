#include "forceclass.h"

#include <QDateTime>

forceClass::forceClass(QObject *parent)
    : QObject{parent}
{
    double refreshTime = 1000/60;
    refreshTimer = new QTimer(this);
    refreshTimer->setInterval(refreshTime);
    refreshTimer->setSingleShot(false);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refreshRateCallback()));
    refreshTimer->start();
}

void forceClass::applyForce(QPoint direction, int applyTimeEpoch)
{
    QPair<QPoint, int> force;
    force.first = direction;
    force.second = applyTimeEpoch;
    forceDirections.append(force);
}

void forceClass::setForce(QPoint direction, int applyTimeEpoch)
{
    forceDirections.clear();
    this->applyForce(direction, applyTimeEpoch);
}

void forceClass::updateForceDirections()
{
    forceDir = QPoint(0,0);
    QPair<QPoint, int> forceDirection;
    foreach (forceDirection, forceDirections) {
        if(forceDirection.second < QDateTime::currentMSecsSinceEpoch()){
            if(forceDirection.second != -1){
                forceDirections.removeOne(forceDirection);
                continue;
            }
        }
        forceDir += forceDirection.first;
    }
}

void forceClass::refreshRateCallback()
{
    updateForceDirections();
    emit forceCallback(forceDir);
}
