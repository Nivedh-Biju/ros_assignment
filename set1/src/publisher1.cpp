#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(int argc,char **argv){
    string pubn1;
    cout<<"Enter publisher name : "<<endl;
    getline(cin,pubn1);
    ros::init(argc,argv,pubn1);
    ros::NodeHandle nh1;
    cout<<"Enter the data stream : "<<endl;
    string datas1;
    getline(cin,datas1);
    ros::Publisher pub1=nh1.advertise<std_msgs::String>(datas1,1000);
    ros::Rate loop_rate(10);
    cout<<"publisher node is created"<<endl;

    while(ros::ok()){
        cout<<"Input : "<<endl;
        string message1;
        getline(cin,message1);
        message1=pubn1+" : "+message1;
        std_msgs::String msg1;
        msg1.data=message1;

        pub1.publish(msg1);
        cout<<"Message sent"<<endl;
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

