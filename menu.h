/**
 * @file menu.h
 * @brief 游戏菜单类的头文件
 * @details 定义了Menu类，负责游戏菜单的创建和交互处理
 */
#ifndef MENU_H
#define MENU_H
#include "qsoundeffect.h"
#include <QWidget>

/**
 * @class Menu
 * @brief 游戏菜单类
 * @details 创建游戏菜单，包括重新开始、关于、帮助和退出等功能按钮
 */
class Menu
{
public:
    /**
     * @brief 构造函数
     * @param game 游戏主窗口指针
     * @param bgm 背景音乐指针
     * @details 创建游戏菜单栏，包括重新开始、关于、帮助和退出等功能按钮
     */
    Menu(QWidget* game, QSoundEffect* bgm);
};

#endif // MENU_H
