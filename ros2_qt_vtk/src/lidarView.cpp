#include "lidarView.h"

LidarView::LidarView()
{
    _rvizRosNodeTmp = std::make_shared<rviz_common::ros_integration::RosNodeAbstraction>("rviz_render_node");
    _rvizRosNode = _rvizRosNodeTmp;

    QApplication::processEvents();
    _render_panel = std::make_shared<rviz_common::RenderPanel>();
    QApplication::processEvents();
    _render_panel->getRenderWindow()->initialize();
    rviz_common::WindowManagerInterface * wm = nullptr;
    auto clock = _rvizRosNode.lock()->get_raw_node()->get_clock();
    _manager = std::make_shared<rviz_common::VisualizationManager>(_render_panel.get(), _rvizRosNode, wm, clock);
    _render_panel->initialize(_manager.get());
    QApplication::processEvents();

    _manager->setFixedFrame("livox_frame");
    _manager->initialize();
    _manager->startUpdate();

    // 添加网格显示
    _grid = _manager->createDisplay("rviz_default_plugins/Grid", "adjustable grid", true);
    if (_grid == NULL) {
        throw std::runtime_error("Error creating grid display");
    }

    // 配置网格样式
    _grid->subProp("Line Style")->setValue("Billboards");
    _grid->subProp("Line Style")->subProp("Line Width")->setValue(0.02f);
    _grid->subProp("Color")->setValue(QColor(Qt::yellow));
    _grid->subProp("Cell Size")->setValue(1.0f);

    // 添加点云显示
    _pointcloud = _manager->createDisplay("rviz_default_plugins/PointCloud2", "pointcloud", true);
    if (_pointcloud == NULL) {
        throw std::runtime_error("Error creating pointcloud display");
    }

    // 配置点云样式
    _pointcloud->subProp("Topic")->setValue("/livox/lidar");
    _pointcloud->subProp("Style")->setValue("Points");
    _pointcloud->subProp("Size (Pixels)")->setValue("2");
    _pointcloud->subProp("Color Transformer")->setValue("Intensity");
    _pointcloud->subProp("Invert Rainbow")->setValue("true");
    _pointcloud->subProp("Decay Time")->setValue("5");

    this->start();
}

void LidarView::run()
{
    // rclcpp::WallRate loop_rate(10); // 10HZ
    while (rclcpp::ok())
    {
        QApplication::processEvents();
        // rclcpp::spin_some(_rvizRosNode.lock()->get_raw_node());
        // loop_rate.sleep();
    }
    // rclcpp::shutdown();
}
