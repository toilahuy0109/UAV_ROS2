from setuptools import find_packages, setup

package_name = 'ps4_controller'

setup(
    name= package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/ps4_servo_launch.py']),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='huy',
    maintainer_email='huy@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ps4_controller_node = ps4_controller.ps4_controller:main',
            'servo_controller_node = ps4_controller.servo_controller:main'
        ],
    },
)
