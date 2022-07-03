#ifndef FORCECLASS_H
#define FORCECLASS_H

#include <QObject>
#include <QPoint>
#include <QTimer>

class forceClass : public QObject
{
    Q_OBJECT
public:
    explicit forceClass(QObject *parent = nullptr);

    void applyForce(QPoint direction, int applyTimeEpoch=-1);
    void applyForce(int dirX, int dirY, int applyTimeMs=-1){applyForce(QPoint(dirX, dirY), applyTimeMs);}

    void setForce(QPoint direction, int applyTimeEpoch=-1);
    void setForce(int dirX, int dirY, int applyTimeMs=-1){setForce(QPoint(dirX, dirY), applyTimeMs);}

    QPoint getForce(){return forceDir;}

private:
    QList<QPair<QPoint, int>> forceDirections;
    QPoint forceDir;
    void updateForceDirections();

    QTimer *refreshTimer;

signals:
    void forceCallback(QPoint direction);

private slots:
    void refreshRateCallback();
};

#endif // FORCECLASS_H
