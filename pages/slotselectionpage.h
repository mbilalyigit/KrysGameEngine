#ifndef SLOTSELECTIONPAGE_H
#define SLOTSELECTIONPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class slotSelectionPage : public QWidget
{
    Q_OBJECT
public:
    explicit slotSelectionPage(int slotCount, QWidget *parent = nullptr);

private slots:
    void buttonClickCb(bool);

signals:
    void slotSelected(int slotNo);

};

#endif // SLOTSELECTIONPAGE_H
