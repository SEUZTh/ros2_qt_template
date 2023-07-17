#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QApplication * app, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _app(app)

{
    ui->setupUi(this);
    
    lidarView = new LidarView();
    ui->scrollArea->setWidget(lidarView->_render_panel.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

