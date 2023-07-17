#include "pclView.h"

PCLView::PCLView(QWidget *parent)
: QVTKWidget(parent)
{

    // 初始化显示窗口
    _viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    _viewer->setBackgroundColor(0, 0, 0);
    // _viewer->addCoordinateSystem(1.0);
    _viewer->initCameraParameters();
    _viewer->setCameraPosition(0, 0, 0, 0, -1, 0);


    // 读取点云文件
    _cloud = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    _cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    _cloud->resize (200);
    // Fill the cloud with some points
    for (auto& point: *_cloud)
    {
        point.x = 1024 * rand () / (RAND_MAX + 1.0f);
        point.y = 1024 * rand () / (RAND_MAX + 1.0f);
        point.z = 1024 * rand () / (RAND_MAX + 1.0f);
    }

    // 显示点云
    _viewer->addPointCloud<pcl::PointXYZ>(_cloud, "cloud");
    _viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");

    this->SetRenderWindow(_viewer->getRenderWindow());
    _viewer->setupInteractor(this->GetInteractor(), this->GetRenderWindow());

    refreshView();
}

void PCLView::refreshView()
{
#if VTK_MAJOR_VERSION > 8
  this->renderWindow()->Render();
#else
  this->update();
#endif
}

