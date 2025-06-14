from setuptools import find_packages, setup

package_name = 'py_srvcli'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nihit',
    maintainer_email='sudhashevade@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [        
        'service = py_srvcli.service_member_function:main',
        'client = py_srvcli.client_member_function:main',
        'publish = py_srvcli.publisher_node:main',
        'subscribe = py_srvcli.subscriber_node:main',
        'actionserv = py_srvcli.fibonacci_action_server:main',
        'actioncli = py_srvcli.fibonacci_action_client:main'
        ],
    },
)
