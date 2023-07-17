#ifndef PCLView_H
#define PCLView_H

#include <QWidget>
#include <QVTKWidget.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

class PCLView : public QVTKWidget
{
    Q_OBJECT
public:
    PCLView(QWidget *parent = nullptr);
    
    void refreshView(); // 刷新显示

    pcl::visualization::PCLVisualizer::Ptr _viewer; // 显示窗口

protected:
    

private:
    pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud; // 点云变量
    
};

#endif // PCLView_H
