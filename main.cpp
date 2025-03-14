/**
 * @file main.cpp
 * @brief 程序入口文件
 * @details 包含main函数，负责创建Qt应用程序并启动游戏初始界面
 */
#include <QApplication>
#include "start.h"

/**
 * @brief 程序主函数
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 应用程序执行结果
 * @details 创建QApplication实例并启动Start界面
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // 创建Qt应用程序实例
    Start w;                     // 创建并初始化游戏启动界面
    return a.exec();             // 进入应用程序主事件循环
}
