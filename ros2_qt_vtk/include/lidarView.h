#ifndef LIDARVIEW_H
#define LIDARVIEW_H

#include <QWidget>
#include <QThread>
#include <QApplication>

#include "rclcpp/rclcpp.hpp"
#include "rviz_common/display.hpp"
#include "rviz_common/render_panel.hpp"
#include "rviz_rendering/render_window.hpp"
#include "rviz_common/ros_integration/ros_node_abstraction.hpp"
#include "rviz_common/visualization_manager.hpp"
#include "rviz_common/window_manager_interface.hpp"

namespace rviz_common
{
class Display;
class RenderPanel;
class VisualizationManager;
} // namespace rviz_common

class LidarView : public QThread
{
    Q_OBJECT
public:
    LidarView();
    std::shared_ptr<rviz_common::RenderPanel> _render_panel;
protected:
    void run();
private:
    std::shared_ptr<rviz_common::ros_integration::RosNodeAbstraction> _rvizRosNodeTmp;
    rviz_common::ros_integration::RosNodeAbstractionIface::WeakPtr _rvizRosNode;
    std::shared_ptr<rviz_common::VisualizationManager> _manager;
    
    rviz_common::Display * _grid;
    rviz_common::Display * _pointcloud;
};

#endif // LIDARVIEW_H
