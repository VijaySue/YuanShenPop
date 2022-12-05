#include "game.h"
#include "menu.h"
#include "block.h"
#include <QScreen>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QSoundEffect>
#include <vector>

Game::Game()
{
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();        //获取屏幕尺寸
    QWidget* game = new QWidget;

    QSoundEffect* bgm = new QSoundEffect;
    bgm->setSource(QUrl::fromLocalFile("://sound/game.wav"));       //游戏音效
    bgm->setLoopCount(QSoundEffect::Infinite);

    bgm->play();

    game->setWindowTitle("原神");             //游戏窗体
    game->resize(1031, 645);
    game->setWindowIcon(QIcon("://image/favicon.png"));
    game->move((screenRect.width()-game->width()) / 2, (screenRect.height()-game->height()) / 2 - 30);
    game->setFixedSize(game->width(), game->height());
    game->setStyleSheet("border-image:url(://image/Game.jpg)");

    Menu menu(game,bgm);

    srand(time(NULL));
    std::vector< std::pair<int,int> > no(80);       //确保方块成对出现
    for (auto& n : no) {
        n.first = rand() % 58;
        n.second = 0;
    }

    int num = 0;
    static std::vector<Block*> v(160);
    Block::lastflag = -1;
    Block::lastnum = -1;
    Block::count = 160;

    for (int i = 0; i < 16; ++i) {
        for(int j = 0; j < 10; ++j){
            v[num] = new Block(game, i, j, num, v, no);
            ++num;
        }
    }
    game->show();
}
