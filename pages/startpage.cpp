#include "startpage.h"

#include <QSettings>

StartPage::StartPage(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);

    topLayout = new QHBoxLayout(this);
    mainLayout->addLayout(topLayout);
    pageFrame = new QFrame(this);
    mainLayout->addWidget(pageFrame);
    gameButtonsLayout = new QVBoxLayout(this);
    pageFrame->setLayout(gameButtonsLayout);
    buttomLayout = new QHBoxLayout(this);
    mainLayout->addLayout(buttomLayout);


    QPushButton *highScoresButton = new QPushButton("Highscores", this);
    highScoresButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    QLabel *spacerLabel = new QLabel("", this);
    topLayout->addWidget(spacerLabel);
    spacerLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    topLayout->addWidget(highScoresButton);

    QPushButton *continueGameButton = new QPushButton("Continue", this);
    QPushButton *newGameButton = new QPushButton("Start New Game", this);
    QPushButton *loadGameButton = new QPushButton("Load Game", this);
    gameButtonsLayout->addWidget(continueGameButton);
    gameButtonsLayout->addWidget(newGameButton);
    gameButtonsLayout->addWidget(loadGameButton);

    spacerLabel = new QLabel("", this);
    buttomLayout->addWidget(spacerLabel);
    spacerLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    QPushButton *settingsButton = new QPushButton("Settings", this);
    buttomLayout->addWidget(settingsButton);
    settingsButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

void StartPage::highScoresButtonClicked(bool)
{
    // TODO: add highScoresPage
}

void StartPage::continueButtonClicked(bool)
{
    // TODO: add qsettings, check which slot used last time
}

void StartPage::newGameButtonClicked(bool)
{
    // TODO: start new game by selecting new slot
}

void StartPage::loadGameButtonClicked(bool)
{
    // TODO: load game from last point
}

void StartPage::settingsButtonClicked(bool)
{

}
