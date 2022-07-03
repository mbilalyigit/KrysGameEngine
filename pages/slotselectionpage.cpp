#include "slotselectionpage.h"

#include <QVariant>

slotSelectionPage::slotSelectionPage(int slotCount, QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    this->setLayout(mainLayout);

    for (int var = 0; var < slotCount; ++var) {
        QPushButton *slotButton = new QPushButton(QString("Slot %1").arg(var), this);
        slotButton->setProperty("slotNo", var);
        connect(slotButton, SIGNAL(clicked(bool)), this, SLOT(buttonClickCb(bool)));
        mainLayout->addWidget(slotButton);
    }

}

void slotSelectionPage::buttonClickCb(bool)
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    emit slotSelected(btn->property("slotNo").toInt());
}
