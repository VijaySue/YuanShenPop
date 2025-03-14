/**
 * @file start.cpp
 * @brief 游戏启动界面类的实现文件
 * @details 实现了Start类的构造函数，负责创建游戏启动界面的窗口、按钮和相关音效
 */
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QScreen>
#include <windows.h>
#include <QSoundEffect>
#include "start.h"
#include "game.h"

/**
 * @brief Start类的构造函数
 * @details 创建游戏启动界面，包括背景、开始按钮和相关音效
 */
Start::Start()
{
    // 创建启动界面窗口
    QWidget* start = new QWidget;
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();        // 获取屏幕尺寸

    // 创建并播放背景音乐
    QSoundEffect* bgm = new QSoundEffect;            // 开始音乐
    bgm->setSource(QUrl::fromLocalFile("://sound/Start.wav"));
    bgm->setLoopCount(QSoundEffect::Infinite);      // 设置无限循环播放
    bgm->play();

    // 设置窗口属性
    start->setWindowTitle("原神消消乐");
    start->resize(1920, 1200);
    start->setWindowIcon(QIcon("://image/favicon.png"));
    start->move((screenRect.width()-start->width()) / 2, (screenRect.height()-start->height()) / 2 - 30); // 使窗口出现在屏幕中央
    start->setFixedSize(start->width(), start->height());       // 禁止调整窗口尺寸
    start->setStyleSheet("border-image:url(://image/Start.jpg)");
    start->show();

    // 创建开始游戏按钮
    QPushButton* btn = new QPushButton(start);
    btn->resize(400, 100);
    btn->setStyleSheet("border-image:url(://image/Play.png)");
    btn->move(760, 1000);
    btn->show();

    // 创建按钮点击音效
    QSoundEffect* effect = new QSoundEffect(start);        // "开始游戏"按钮点击音效
    effect->setSource(QUrl::fromLocalFile("://sound/Play.wav"));
    effect->setLoopCount(1);
    effect->setVolume(0.4);

    // 连接按钮点击信号与槽
    QAbstractButton::connect(btn, &QPushButton::clicked, start, [=]() {
        effect->play();           // 播放按钮点击音效
        bgm->stop();              // 停止背景音乐
        Game a;                   // 创建游戏对象，启动游戏
        start->close();           // 关闭启动界面
    });
}
