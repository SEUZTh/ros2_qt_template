
- 如果是使用 `ros2_qt_template` 这个功能包模板进行二次开发，可以克隆 v1 分支：
    ```shell
    git clone --branch v1 https://github.com/SEUZTh/ros2_qt_template.git
    ```
- 如果是学习该教程代码，可以克隆 `master` 分支：
    ```shell
    git clone https://github.com/SEUZTh/ros2_qt_template.git
    ```

- 使用 QT 编译，然后执行功能包：

# ROS2 QT 教程

## 教程一：ros2_qt_templete
```shell
source install/setup.sh
ros2 run ros2_qt_template ros2_qt_template
```
![](docs/images/ros2_qt_template.png)

## 教程二：ros2_qt_rviz2
```shell
source install/setup.sh
ros2 run ros2_qt_rviz2 ros2_qt_rviz2
```
![](docs/images/ros2_qt_rviz2.png)

# PCL QT 教程
## 教程一：ros2_qt_vtk
为了在使用 ROS2 的同时，显示单帧点云，调用 PCL 点云库进行一些处理，这里介绍如何在 QT 中显示点云，直接在 ros2_qt_rviz2 的基础上进行修改。
```shell
source install/setup.sh
ros2 run ros2_qt_vtk ros2_qt_vtk
```
![](docs/images/ros2_qt_vtk.png)