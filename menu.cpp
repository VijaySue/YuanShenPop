#include "menu.h"
#include <QPushButton>
#include <QSoundEffect>
#include <QScreen>
#include <QLabel>
#include <QApplication>
#include "game.h"

Menu::Menu(QWidget* game,QSoundEffect* bgm)
{
    QSoundEffect* effect = new QSoundEffect(game);
    effect->setSource(QUrl::fromLocalFile("://sound/click.wav"));
    effect->setLoopCount(1);

    QPushButton* btn1 = new QPushButton(game);
    btn1->setStyleSheet("font:bold 18px; border-image:url("")");
    btn1->setFlat(true);
    btn1->setText("重新开始");
    btn1->resize(100,60);
    btn1->move(0,0);
    btn1->show();

    QAbstractButton::connect(btn1,&QPushButton::clicked,game,[=]() {
        bgm->stop();
        effect->play();
        Game a;
        game->close();
    });

    QPushButton* btn2 = new QPushButton(game);
    btn2->setStyleSheet("font:bold 18px; border-image:url("")");
    btn2->setFlat(true);
    btn2->setText("关于");
    btn2->resize(100, 60);
    btn2->move(100,0);
    btn2->show();

    QAbstractButton::connect(btn2,&QPushButton::clicked,game,[=]() {
        effect->play();
        QLabel* a = new QLabel;
        QRect screenRect = QGuiApplication::primaryScreen()->geometry();
        a->setWindowIcon(QIcon("://image/favicon.png"));
        a->setWindowTitle("关于");
        a->setText("作者：VijaySue\n联系方式:vijaysue@yeah.net");
        a->resize(500,200);
        a->setStyleSheet("font:bold 18px;border-image:url(://image/Game.jpg)");
        a->move((screenRect.width()-a->width()) / 2, (screenRect.height()-a->height()) / 2);
        a->setFixedSize(a->width(), a->height());
        a->show();
    });

    QPushButton* btn3 = new QPushButton(game);
    btn3->setStyleSheet("font:bold 18px; border-image:url("")");
    btn3->setFlat(true);
    btn3->setText("帮助");
    btn3->resize(100,60);
    btn3->move(200,0);
    btn3->show();

    QAbstractButton::connect(btn3,&QPushButton::clicked,game,[=]() {
        effect->play();
        QLabel* a = new QLabel;
        QRect screenRect = QGuiApplication::primaryScreen()->geometry();
        a->setWindowIcon(QIcon("://image/favicon.png"));
        a->setWindowTitle("帮助");
        a->setText("点击两个相同的方块进行消除，消除全部方块即可通关游戏");
        a->resize(500,200);
        a->setStyleSheet("font:bold 18px;border-image:url(://image/Game.jpg)");
        a->move((screenRect.width()-a->width()) / 2, (screenRect.height()-a->height()) / 2);
        a->setFixedSize(a->width(), a->height());
        a->show();
    });

    QPushButton* btn4 = new QPushButton(game);
    btn4->setStyleSheet("font:bold 18px; border-image:url("")");
    btn4->setFlat(true);
    btn4->setText("退出");
    btn4->resize(100,60);
    btn4->move(300,0);
    btn4->show();

    QAbstractButton::connect(btn4,&QPushButton::clicked,game,[=]() {
        effect->play();
        game->close();
    });
}
