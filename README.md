# ROS-Unity

# Usage:
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116

sudo apt-get update

sudo apt-get install ros-kinetic-desktop-full

sudo apt-get install ros-kinetic-ros-base

sudo rosdep init
rosdep update

sudo apt-get install python-rosinstall python-rosinstall-generator python-wstool build-essential
sudo apt-get install ros-kinetic-rosbridge-server

source /opt/ros/kinetic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make

copy toan bo file trong src cua fpt vao home/catkin_ws/src

cd ~/catkin_ws
catkin_make
source devel/setup.bash
roslaunch lane_detect lane_detect.launch 

khoi dong phan mem gia lap 
nhap : ws://localhost:9090

mo terminal moi va nhap:

cd ~/catkin_ws
source devel/setup.bash
rosrun image_transport republish compressed in:=Team1_image raw out:=image_decompressed

mo terminal moi va nhap:
rosrun lane_dectect control.py

