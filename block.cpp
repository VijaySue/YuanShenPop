/**
 * @file block.cpp
 * @brief 游戏方块类的实现文件
 * @details 实现了Block类的方法，包括方块的点击事件和随机初始化
 */
#include "block.h"
#include <QPushButton>
#include <QSoundEffect>
#include <algorithm>
#include <QLabel>

// 初始化静态成员变量
int Block::lastnum;    // 上一次点击的方块编号
int Block::lastflag;   // 上一次点击的方块类型
int Block::count;      // 剩余方块数量

/**
 * @brief 设置方块点击事件
 * @param parent 父窗口指针
 * @param v 方块指针数组
 * @details 设置方块的点击效果，包括声音和消除逻辑
 */
void Block::clck(QWidget* parent, std::vector<Block*>& v) {
    // 创建点击音效
    QSoundEffect* effect1 = new QSoundEffect(parent);
    effect1->setSource(QUrl::fromLocalFile("://sound/click.wav"));          // 点击音效
    effect1->setLoopCount(1);

    // 创建消除音效
    QSoundEffect* effect2 = new QSoundEffect(parent);
    effect2->setSource(QUrl::fromLocalFile("://sound/Delete.wav"));         // 消除音效
    effect2->setLoopCount(1);

    // 连接点击信号
    QAbstractButton::connect(this, &QPushButton::clicked, parent, [=,&v]() {
        effect1->play();  // 播放点击音效

        // 判断是否与上一次点击的方块类型相同且不是同一个方块
        if(Block::lastnum != this->num && Block::lastflag == this->flag) {
            effect2->play();  // 播放消除音效

            // 删除当前方块和上一次点击的方块
            delete this;
            delete v[Block::lastnum];

            // 重置上一次点击的方块信息
            Block::lastflag = -1;
            Block::lastnum = -1;
            count -= 2;  // 减少剩余方块数
        }
        else {
            // 更新上一次点击的方块信息
            Block::lastnum = this->num;
            Block::lastflag = this->flag;
        }

        // 游戏通关判断
        if(Block::count == 0) {                     // 当方块数为0时
            QLabel* a = new QLabel(parent);
            a->setStyleSheet("font:bold 20px; border-image:url("")");
            a->move(810, 550);
            a->setText("恭喜您成功通关游戏！");
            a->show();
        }
    });
}

/**
 * @brief 随机初始化方块类型
 * @param no 方块类型数组
 * @details 随机选择一种方块类型，并设置相应的外观
 */
void Block::roguelike(std::vector<std::pair<int, int> >& no) {      // 方块随机初始化
    // 随机选择一种方块类型，确保每种类型的方块都成对出现
    int temp = rand() % 80;
    while(!(no[temp].second < 2)) {  // 当该类型方块已经有2个时，重新选择
        temp = rand() % 80;
    }

    // 设置方块类型和计数
    this->flag = no[temp].first;
    ++no[temp].second;

    // 根据方块类型设置外观
    for (int i = 0; i <= 57; ++i) {
        if (this->flag == i) {
            this->setStyleSheet(
                (QString)"QPushButton { border-image:url(://image/img/" + QString::number(i + 1) + ".png) }\
                QPushButton:pressed{ border:40px}"
                );
        }
    }
}
