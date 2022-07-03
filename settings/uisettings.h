#ifndef UISETTINGS_H
#define UISETTINGS_H

#include <QObject>
#include <QSettings>

class uiSettings : public QObject
{
    Q_OBJECT
public:
    explicit uiSettings(QObject *parent = nullptr);

private:
    const QString settingsName = "uiSettings";
    void initDefaults();

signals:

};

#endif // UISETTINGS_H
