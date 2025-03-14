/**
 * @file menu.cpp
 * @brief 游戏菜单类的实现文件
 * @details 实现了Menu类的构造函数，负责创建游戏菜单栏的各个按钮及其交互逻辑
 */
#include "menu.h"
#include <QPushButton>
#include <QSoundEffect>
#include <QScreen>
#include <QLabel>
#include <QApplication>
#include "game.h"

/**
 * @brief Menu类的构造函数
 * @param game 游戏主窗口指针
 * @param bgm 背景音乐指针
 * @details 创建游戏菜单栏，包括重新开始、关于、帮助和退出等功能按钮
 */
Menu::Menu(QWidget* game, QSoundEffect* bgm)
{
    // 创建按钮点击音效
    QSoundEffect* effect = new QSoundEffect(game);
    effect->setSource(QUrl::fromLocalFile("://sound/click.wav"));
    effect->setLoopCount(1);

    // 创建"重新开始"按钮
    QPushButton* btn1 = new QPushButton(game);
    btn1->setStyleSheet("font:bold 18px; border-image:url("")");
    btn1->setFlat(true);
    btn1->setText("重新开始");
    btn1->resize(100,60);
    btn1->move(0,0);
    btn1->show();

    // 连接"重新开始"按钮的点击信号
    QAbstractButton::connect(btn1, &QPushButton::clicked, game, [=]() {
        bgm->stop();                // 停止当前背景音乐
        effect->play();             // 播放点击音效
        Game a;                     // 创建新游戏实例
        game->close();              // 关闭当前游戏窗口
    });

    // 创建"关于"按钮
    QPushButton* btn2 = new QPushButton(game);
    btn2->setStyleSheet("font:bold 18px; border-image:url("")");
    btn2->setFlat(true);
    btn2->setText("关于");
    btn2->resize(100, 60);
    btn2->move(100,0);
    btn2->show();

    // 连接"关于"按钮的点击信号
    QAbstractButton::connect(btn2, &QPushButton::clicked, game, [=]() {
        effect->play();             // 播放点击音效
        QLabel* a = new QLabel;     // 创建关于信息窗口
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

    // 创建"帮助"按钮
    QPushButton* btn3 = new QPushButton(game);
    btn3->setStyleSheet("font:bold 18px; border-image:url("")");
    btn3->setFlat(true);
    btn3->setText("帮助");
    btn3->resize(100,60);
    btn3->move(200,0);
    btn3->show();

    // 连接"帮助"按钮的点击信号
    QAbstractButton::connect(btn3, &QPushButton::clicked, game, [=]() {
        effect->play();             // 播放点击音效
        QLabel* a = new QLabel;     // 创建帮助信息窗口
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

    // 创建"退出"按钮
    QPushButton* btn4 = new QPushButton(game);
    btn4->setStyleSheet("font:bold 18px; border-image:url("")");
    btn4->setFlat(true);
    btn4->setText("退出");
    btn4->resize(100,60);
    btn4->move(300,0);
    btn4->show();

    // 连接"退出"按钮的点击信号
    QAbstractButton::connect(btn4, &QPushButton::clicked, game, [=]() {
        effect->play();             // 播放点击音效
        game->close();              // 关闭游戏窗口
    });
}
