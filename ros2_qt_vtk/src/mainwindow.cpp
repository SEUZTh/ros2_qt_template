#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QApplication * app, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _app(app)

{
    ui->setupUi(this);
    
    lidarView = new LidarView();
    QVBoxLayout * lidar_layout = new QVBoxLayout;
    lidar_layout->setSpacing(0);
    lidar_layout->setMargin(0);
    lidar_layout->addWidget(lidarView->_render_panel.get());
    ui->wdgtLidarView->setLayout(lidar_layout);


    pclView = new PCLView();
    QVBoxLayout * pcl_layout = new QVBoxLayout;
    pcl_layout->setSpacing(0);
    pcl_layout->setMargin(0);
    pcl_layout->addWidget(pclView);
    ui->qvtkWidget->setLayout(pcl_layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

