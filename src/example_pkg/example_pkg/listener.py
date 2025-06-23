import rclpy
from rclpy.node import Node
from custom_msgs.msg import TheUltimateMsg
import pickle

from std_msgs.msg import String

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__("listener")
        self.subscription = self.create_subscription(
            TheUltimateMsg,
            'topic',
            self.listener_callback,
            10
        )
        self.subscription

        print("Subscriber Initialized")

    def listener_callback(self,msg):
        recv_msg = [bytes(element) for element in msg.byte_stream]
        recv_msg = b''.join(recv_msg)
        recv_msg = pickle.loads(recv_msg)

        print("received message:")
        print(recv_msg[0])

def main(args = None):
    rclpy.init(args = args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)

    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()