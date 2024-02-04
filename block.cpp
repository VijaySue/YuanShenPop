#include "block.h"
#include <QPushButton>
#include <QSoundEffect>
#include <algorithm>
#include <QLabel>

int Block::lastnum;
int Block::lastflag;
int Block::count;

void Block::clck(QWidget* parent, std::vector<Block*>& v) {
    QSoundEffect* effect1 = new QSoundEffect(parent);
    effect1->setSource(QUrl::fromLocalFile("://sound/click.wav"));          //点击音效
    effect1->setLoopCount(1);

    QSoundEffect* effect2 = new QSoundEffect(parent);
    effect2->setSource(QUrl::fromLocalFile("://sound/Delete.wav"));         //消除音效
    effect2->setLoopCount(1);

    QAbstractButton::connect(this,&QPushButton::clicked,parent,[=,&v]() {
        effect1->play();

        if(Block::lastnum != this->num && Block::lastflag == this->flag) {
            effect2->play();

            delete this;
            delete v[Block::lastnum];

            Block::lastflag = -1;
            Block::lastnum = -1;
            count -= 2;
        }
        else {
            Block::lastnum = this->num;
            Block::lastflag = this->flag;
        }

        if(Block::count == 0) {                     //当方块数为0时
            QLabel* a = new QLabel(parent);
            a->setStyleSheet("font:bold 20px; border-image:url("")");
            a->move(810,550);
            a->setText("恭喜您成功通关游戏！");
            a->show();
        }
    });
}

void Block::roguelike(std::vector<std::pair<int, int> >& no) {      //方块随机初始化
    int temp = rand() % 80;
    while(!(no[temp].second < 2)) {
        temp = rand() % 80;
    }

    this->flag = no[temp].first;
    ++no[temp].second;

    for (int i = 0; i <= 57; ++i) {
        if (this->flag == i) {
            this->setStyleSheet(
                (QString)"QPushButton { border-image:url(://image/img/" + QString::number(i + 1) + ".png) }\
                QPushButton:pressed{ border:40px}"
                );
        }
    }
}
