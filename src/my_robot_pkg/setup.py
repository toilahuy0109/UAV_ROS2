from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'my_robot_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share',package_name,'launch'),glob('launch/*.py')),
        (os.path.join('share',package_name,'description'),glob('description/*.xacro')),
        (os.path.join('share', package_name, 'config'),glob('config/*.yaml')),
        (os.path.join('share',package_name,'')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='huy',
    maintainer_email='huymax0109@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ps4_controller_node = my_robot_pkg.ps4_controller_node:main',
            'drone_controller = my_robot_pkg.drone_controller:main',
        ],
    },
)
