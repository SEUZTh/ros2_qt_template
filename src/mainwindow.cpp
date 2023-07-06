#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load(":/icon/images/foxy.jpg");
    img.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 初始化 ROS2
    int argc=0;
    char **argv=NULL;
    rclcpp::init(argc,argv);

    // 实例化节点（可以在这里实例化多个节点，用于不同的功能）
    commNode = new rclcomm();
    connect(commNode, SIGNAL(emitTopicData(QString)), this, SLOT(updateTopicInfo(QString)));
}
void MainWindow::updateTopicInfo(QString data){
    ui->label_4->clear();
    ui->label_4->setText(data);
}
MainWindow::~MainWindow()
{
    delete ui;
}

