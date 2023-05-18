import rospy
from std_msgs.msg import String
user=""
def send(msg1):
    msg=String()
    msg.data=user + " : "+msg1
    pub1.publish(msg)

def callbach(msg):
    if(msg.data.startswith(user)):
        return
    print("\n")
    print(msg.data)
    print("\n")


user=str(input("\nEnter your username : "))
datas=str(input("\nEnter your chat room : "))

rospy.init_node(user)
pub1=rospy.Publisher(datas,String,queue_size=1000)
rospy.Subscriber(datas,String,callbach)

rate=rospy.Rate(10)

while not rospy.is_shutdown():
    msg1=str(input("\nEnter your message here : "))
    send(msg1)

ros.spin_once()
rate.sleep()