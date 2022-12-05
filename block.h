#ifndef BLOCK_H
#define BLOCK_H
#include <QPushButton>
#include <QWidget>
#include <utility>

class Block:public QPushButton
{
public:
    Block(QWidget* parent,int x,int y,int num, std::vector<Block*>& v, std::vector< std::pair<int,int> >& no):QPushButton(parent) {
        this->roguelike(no);
        this->num = num;
        this->clck(parent, v);
        this->resize(50, 50);
        this->move(110 + 50 * x, 80 + 50 * y);
        this->show();
    }
    Block(){};

    int num;
    static int lastnum;     //上一点击序号
    static int lastflag;    //上一点击标志
    static int count;       //剩余方块数
    void roguelike( std::vector< std::pair<int,int> >& no);         //方块随机初始化
    void clck(QWidget* parent, std::vector<Block*>& v);             //方块点击效果

    int flag = -1;
};

#endif // BLOCK_H
