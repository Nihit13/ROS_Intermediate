import os
from glob import glob
from setuptools import setup

package_name = 'launch_tutorial'

setup(
    name=package_name,
    version='0.0.0',
    packages=[],
    py_modules=[],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'rviz'), glob('config/*.rviz')),  # Optional
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='gargie',
    maintainer_email='your@email.com',
    description='Launch tutorial package for ROS 2 turtlesim TF example',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)

