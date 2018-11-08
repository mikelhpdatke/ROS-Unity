/**
* @copyright 2018 VeCaN Lab
* @file image_lane_detector_node.cpp
* @brief the node to detect tha lane and stop line.
* @author zhyan
* @date 05/02/2018
*/

#include <ros/ros.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include <iostream>
#include <string>

//#include <local_messages/Road.h>

#include "../include/lane_detector.h"
#include "../include/lane.h"
#include "../include/launch_para.h"

//global image

vecan::perception::LaneDetector lane_detector(true, true, true);
cv::Mat image_source;
void imageCallback(const sensor_msgs::ImageConstPtr &msg)
{
    try
    {
        //std::cout << "frame: " << frame_index << "    ";
        //std::cout << image_source << " ??" << launch_para.image_topic_name << "??? "
          //      << "\n";
        //lane_detector.PublishRoadMsg(road_msg);
        //road_pub.publish(road_msg);
        //frame_index++;
        std::cout <<"wtf\n";
        cv::Mat tmp = cv_bridge::toCvShare(msg, "bgr8")->image;
        image_source = tmp.clone();
        std::vector<vecan::perception::Lane> ans;
        lane_detector.DetectLane(image_source);
        lane_detector.GetDetectionResult(ans, image_source);
        std::cout<< ans.size() <<"??\n";
    }
    catch (cv_bridge::Exception &e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_lane_detector");
    /*----------------------------------------------------*/
    vecan::perception::LaunchPara launch_para;
    vecan::perception::GetParametersFromLaunch(launch_para);

    /*----------------------------------------------------*/
    ros::NodeHandle img_handle;
    image_transport::ImageTransport it(img_handle);
    launch_para.image_topic_name = "unity_image";
    image_transport::Subscriber camera_sub = it.subscribe(launch_para.image_topic_name, 1, imageCallback);

    //ros::NodeHandle road_handle;
    //ros::Publisher road_pub = road_handle.advertise<local_messages::Road>(launch_para.road_topic_name, 10);

    /*----------------------------------------------------*/
    
    //local_messages::Road road_msg;

    //off-line pictures path
    std::string pictures_path_prefix = launch_para.pictures_path;
    std::string pictures_path;
    //int frame_index = 1;
    char postfix_buffer[20];
    ros::spin();


return 0;
}
