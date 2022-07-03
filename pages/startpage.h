#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFrame>

class StartPage : public QWidget
{
    Q_OBJECT
public:
    explicit StartPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;

    QHBoxLayout *topLayout;
    QPushButton *highScoresButton;

    QFrame      *pageFrame;
    QVBoxLayout *gameButtonsLayout;
    QPushButton *continueGameButton;
    QPushButton *newGameButton;
    QPushButton *loadGameButton;

    QHBoxLayout *buttomLayout;
    QPushButton *settingsButton;

private slots:
    void highScoresButtonClicked(bool);
    void continueButtonClicked(bool);
    void newGameButtonClicked(bool);
    void loadGameButtonClicked(bool);
    void settingsButtonClicked(bool);
signals:

};

#endif // STARTPAGE_H
