#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 初始化 ROS2
    rclcpp::init(argc,argv);

    QApplication a(argc, argv);

    MainWindow w(&a);
    w.show();
    
    while(rclcpp::ok()) {
        a.processEvents();
    }

    return a.exec();
}
