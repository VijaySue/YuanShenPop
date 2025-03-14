/**
 * @file game.cpp
 * @brief 游戏主界面类的实现文件
 * @details 实现了Game类的构造函数，负责创建游戏主界面、方块、菜单和相关音效
 */
#include "game.h"
#include "menu.h"
#include "block.h"
#include <QScreen>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QSoundEffect>
#include <vector>

/**
 * @brief Game类的构造函数
 * @details 创建游戏主界面，包括背景、方块、菜单和相关音效
 */
Game::Game()
{
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();        // 获取屏幕尺寸
    QWidget* game = new QWidget;

    // 创建并播放背景音乐
    QSoundEffect* bgm = new QSoundEffect;
    bgm->setSource(QUrl::fromLocalFile("://sound/game.wav"));       // 游戏音效
    bgm->setLoopCount(QSoundEffect::Infinite);
    bgm->play();

    // 设置游戏窗口属性
    game->setWindowTitle("原神消消乐");             // 游戏窗体
    game->resize(1920, 1200);
    game->setWindowIcon(QIcon("://image/favicon.png"));
    game->move((screenRect.width()-game->width()) / 2, (screenRect.height()-game->height()) / 2 - 30);
    game->setFixedSize(game->width(), game->height());
    game->setStyleSheet("border-image:url(://image/Game.jpg)");

    // 创建游戏菜单
    Menu menu(game, bgm);

    // 初始化随机数生成器
    srand(time(NULL));
    
    // 创建方块对数组，确保方块成对出现
    std::vector<std::pair<int,int>> no(80);       // 确保方块成对出现
    for (auto& n : no) {
        n.first = rand() % 58;     // 随机生成方块类型
        n.second = 0;              // 初始化方块数量
    }

    // 创建游戏方块
    int num = 0;
    static std::vector<Block*> v(160);  // 创建方块指针数组
    
    // 初始化Block类的静态成员变量
    Block::lastflag = -1;   // 上一次点击的方块类型
    Block::lastnum = -1;    // 上一次点击的方块编号
    Block::count = 160;     // 初始方块总数

    // 创建16行10列的方块阵列
    for (int i = 0; i < 16; ++i) {
        for(int j = 0; j < 10; ++j){
            v[num] = new Block(game, i, j, num, v, no);
            ++num;
        }
    }
    
    // 显示游戏窗口
    game->show();
}
