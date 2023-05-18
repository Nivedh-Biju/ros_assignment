#include<sstream>
#include<ros/ros.h>
#include<std_msgs/String.h>

using namespace std;

void callback(const std_msgs::String::ConstPtr& msg1){
    cout<<(msg1->data.c_str())<<endl;
}

int main(int argc,char **argv){
    string subn1;
    cout<<"Enter the subscriber name : "<<endl;
    getline(cin,subn1);
    ros::init(argc,argv,subn1);
    ros::NodeHandle nr1;
    cout<<"Enter the data stream : "<<endl;
    string datas;
    getline(cin,datas);
    ros::Subscriber sub1=nr1.subscribe(datas,1000,callback);

    ros::spin();
    return 0;
}
