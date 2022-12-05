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
            a->move(418,320);
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

    if (this->flag == 0)
        this->setStyleSheet("border-image:url(://image/img/1.png)");
    if (this->flag == 1)
        this->setStyleSheet("border-image:url(://image/img/2.png)");
    if (this->flag == 2)
        this->setStyleSheet("border-image:url(://image/img/3.png)");
    if (this->flag == 3)
        this->setStyleSheet("border-image:url(://image/img/4.png)");
    if (this->flag == 4)
        this->setStyleSheet("border-image:url(://image/img/5.png)");
    if (this->flag == 5)
        this->setStyleSheet("border-image:url(://image/img/6.png)");
    if (this->flag == 6)
        this->setStyleSheet("border-image:url(://image/img/7.png)");
    if (this->flag == 7)
        this->setStyleSheet("border-image:url(://image/img/8.png)");
    if (this->flag == 8)
        this->setStyleSheet("border-image:url(://image/img/9.png)");
    if (this->flag == 9)
        this->setStyleSheet("border-image:url(://image/img/10.png)");
    if (this->flag == 10)
        this->setStyleSheet("border-image:url(://image/img/11.png)");
    if (this->flag == 11)
        this->setStyleSheet("border-image:url(://image/img/12.png)");
    if (this->flag == 12)
        this->setStyleSheet("border-image:url(://image/img/13.png)");
    if (this->flag == 13)
        this->setStyleSheet("border-image:url(://image/img/14.png)");
    if (this->flag == 14)
        this->setStyleSheet("border-image:url(://image/img/15.png)");
    if (this->flag == 15)
        this->setStyleSheet("border-image:url(://image/img/16.png)");
    if (this->flag == 16)
        this->setStyleSheet("border-image:url(://image/img/17.png)");
    if (this->flag == 17)
        this->setStyleSheet("border-image:url(://image/img/18.png)");
    if (this->flag == 18)
        this->setStyleSheet("border-image:url(://image/img/19.png)");
    if (this->flag == 19)
        this->setStyleSheet("border-image:url(://image/img/20.png)");
    if (this->flag == 20)
        this->setStyleSheet("border-image:url(://image/img/21.png)");
    if (this->flag == 21)
        this->setStyleSheet("border-image:url(://image/img/22.png)");
    if (this->flag == 22)
        this->setStyleSheet("border-image:url(://image/img/23.png)");
    if (this->flag == 23)
        this->setStyleSheet("border-image:url(://image/img/24.png)");
    if (this->flag == 24)
        this->setStyleSheet("border-image:url(://image/img/25.png)");
    if (this->flag == 25)
        this->setStyleSheet("border-image:url(://image/img/26.png)");
    if (this->flag == 26)
        this->setStyleSheet("border-image:url(://image/img/27.png)");
    if (this->flag == 27)
        this->setStyleSheet("border-image:url(://image/img/28.png)");
    if (this->flag == 28)
        this->setStyleSheet("border-image:url(://image/img/29.png)");
    if (this->flag == 29)
        this->setStyleSheet("border-image:url(://image/img/30.png)");
    if (this->flag == 30)
        this->setStyleSheet("border-image:url(://image/img/31.png)");
    if (this->flag == 31)
        this->setStyleSheet("border-image:url(://image/img/32.png)");
    if (this->flag == 32)
        this->setStyleSheet("border-image:url(://image/img/33.png)");
    if (this->flag == 33)
        this->setStyleSheet("border-image:url(://image/img/34.png)");
    if (this->flag == 34)
        this->setStyleSheet("border-image:url(://image/img/35.png)");
    if (this->flag == 35)
        this->setStyleSheet("border-image:url(://image/img/36.png)");
    if (this->flag == 36)
        this->setStyleSheet("border-image:url(://image/img/37.png)");
    if (this->flag == 37)
        this->setStyleSheet("border-image:url(://image/img/38.png)");
    if (this->flag == 38)
        this->setStyleSheet("border-image:url(://image/img/39.png)");
    if (this->flag == 39)
        this->setStyleSheet("border-image:url(://image/img/40.png)");
    if (this->flag == 40)
        this->setStyleSheet("border-image:url(://image/img/41.png)");
    if (this->flag == 41)
        this->setStyleSheet("border-image:url(://image/img/42.png)");
    if (this->flag == 42)
        this->setStyleSheet("border-image:url(://image/img/43.png)");
    if (this->flag == 43)
        this->setStyleSheet("border-image:url(://image/img/44.png)");
    if (this->flag == 44)
        this->setStyleSheet("border-image:url(://image/img/45.png)");
    if (this->flag == 45)
        this->setStyleSheet("border-image:url(://image/img/46.png)");
    if (this->flag == 46)
        this->setStyleSheet("border-image:url(://image/img/47.png)");
    if (this->flag == 47)
        this->setStyleSheet("border-image:url(://image/img/48.png)");
    if (this->flag == 48)
        this->setStyleSheet("border-image:url(://image/img/49.png)");
    if (this->flag == 49)
        this->setStyleSheet("border-image:url(://image/img/50.png)");
    if (this->flag == 50)
        this->setStyleSheet("border-image:url(://image/img/51.png)");
    if (this->flag == 51)
        this->setStyleSheet("border-image:url(://image/img/52.png)");
    if (this->flag == 52)
        this->setStyleSheet("border-image:url(://image/img/53.png)");
    if (this->flag == 53)
        this->setStyleSheet("border-image:url(://image/img/54.png)");
    if (this->flag == 54)
        this->setStyleSheet("border-image:url(://image/img/55.png)");
    if (this->flag == 55)
        this->setStyleSheet("border-image:url(://image/img/56.png)");
    if (this->flag == 56)
        this->setStyleSheet("border-image:url(://image/img/57.png)");
    if (this->flag == 57)
        this->setStyleSheet("border-image:url(://image/img/58.png)");
}
