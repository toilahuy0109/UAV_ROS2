import rclpy
from rclpy.node import Node
import pickle
from std_msgs.msg import String
from custo_msgs.msg import TheUltimateMsg


class MyClass:
    x = 5
    s = "hihihi"
    d = {1:0}
    l = [123, 123, 123]

    def __str__(self):
        return f"{self.x} {self.s} {self.d} {self.l}"
    
class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('talker')
        self.publisher_ = self.create_publisher(TheUltimateMsg, 'topic' , 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.i = 0
        self.msg_to_send = [MyClass()]*3

        print("Publisher Initialized")

    def timer_callback(self):
        msg = TheUltimateMsg()
        byte_stream = pickle.dumps(self.msg_to_send)
        msg.byte_stream = [element.to_bytes(2,"little") for element in byte_stream]

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing message')

def main(args = None):
    rclpy.init(args = args)

    minimal_publisher = MinimalPublisher()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    
    rclpy.shutdown()

if __name__ == '__main__':
    main()