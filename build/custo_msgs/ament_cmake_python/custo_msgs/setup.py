from setuptools import find_packages
from setuptools import setup

setup(
    name='custo_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('custo_msgs', 'custo_msgs.*')),
)
