/**
 * @file block.h
 * @brief 游戏方块类的头文件
 * @details 定义了Block类，继承自QPushButton，负责游戏中方块的创建、显示和交互
 */
#ifndef BLOCK_H
#define BLOCK_H
#include <QPushButton>
#include <QWidget>
#include <utility>

/**
 * @class Block
 * @brief 游戏方块类
 * @details 继承自QPushButton，表示游戏中的可点击方块，负责方块的创建、显示和交互
 */
class Block:public QPushButton
{
public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针
     * @param x 方块在游戏中的横坐标
     * @param y 方块在游戏中的纵坐标
     * @param num 方块的编号
     * @param v 方块指针数组
     * @param no 方块类型数组
     * @details 创建并初始化一个游戏方块，设置位置和外观
     */
    Block(QWidget* parent, int x, int y, int num, std::vector<Block*>& v, std::vector<std::pair<int,int>>& no):QPushButton(parent) {
        this->roguelike(no);     // 随机初始化方块类型
        this->num = num;         // 设置方块编号
        this->clck(parent, v);   // 设置点击事件
        this->resize(100, 100);  // 设置方块大小
        this->move(160 + 100 * x, 100 + 100 * y);  // 设置方块位置
        this->show();            // 显示方块
    }
    
    /**
     * @brief 默认构造函数
     */
    Block(){};

    int num;                 ///< 方块的编号
    static int lastnum;      ///< 上一次点击的方块编号
    static int lastflag;     ///< 上一次点击的方块类型
    static int count;        ///< 剩余方块数量
    
    /**
     * @brief 随机初始化方块类型
     * @param no 方块类型数组
     * @details 随机选择一种方块类型，并设置相应的外观
     */
    void roguelike(std::vector<std::pair<int,int>>& no);
    
    /**
     * @brief 设置方块点击事件
     * @param parent 父窗口指针
     * @param v 方块指针数组
     * @details 设置方块的点击效果，包括声音和消除逻辑
     */
    void clck(QWidget* parent, std::vector<Block*>& v);

    int flag = -1;           ///< 方块的类型标志
};

#endif // BLOCK_H
