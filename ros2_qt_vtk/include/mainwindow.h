#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QApplication>

#include "rviz_common/ros_integration/ros_node_abstraction.hpp"

#include "lidarView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication * app, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QApplication * _app;
    LidarView *lidarView;
public slots:
    // void updateTopicInfo(QString);
};
#endif // MAINWINDOW_H
