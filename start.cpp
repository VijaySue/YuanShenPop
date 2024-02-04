#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QScreen>
#include <windows.h>
#include <QSoundEffect>
#include "start.h"
#include "game.h"

Start::Start()
{

    QWidget* start = new QWidget;
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();        //获取屏幕尺寸

    QSoundEffect* bgm = new QSoundEffect;            //开始音乐
    bgm->setSource(QUrl::fromLocalFile("://sound/Start.wav"));
    bgm->setLoopCount(QSoundEffect::Infinite);
    bgm->play();

    start->setWindowTitle("原神消消乐");
    start->resize(1920, 1200);
    start->setWindowIcon(QIcon("://image/favicon.png"));
    start->move((screenRect.width()-start->width()) / 2, (screenRect.height()-start->height()) / 2 - 30); //使窗口出现在屏幕中央
    start->setFixedSize(start->width(), start->height());       //禁止调整窗口尺寸
    start->setStyleSheet("border-image:url(://image/Start.jpg)");
    start->show();

    QPushButton* btn = new QPushButton(start);
    btn->resize(400, 100);
    btn->setStyleSheet("border-image:url(://image/Play.png)");
    btn->move(760, 1000);
    btn->show();


    QSoundEffect* effect = new QSoundEffect(start);        //"开始游戏"按钮点击音效
    effect->setSource(QUrl::fromLocalFile("://sound/Play.wav"));
    effect->setLoopCount(1);
    effect->setVolume(0.4);

    QAbstractButton::connect(btn,&QPushButton::clicked,start,[=]() {
        effect->play();
        bgm->stop();
        Game a;
        start->close();
    });
}
