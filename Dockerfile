# ROS

# This is an auto generated Dockerfile for ros:robot
# generated from docker_images/create_ros_image.Dockerfile.em
# FROM ros:melodic-ros-base-bionic

# # install ros packages
# RUN apt-get update && apt-get install -y --no-install-recommends \
#     ros-melodic-robot=1.4.1-0* \
#     && rm -rf /var/lib/apt/lists/*
####################################################################

FROM ubuntu:18.04
LABEL Description="Build environment"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget

# Let us add some heavy dependency
RUN cd ${HOME} && \
    wget --no-check-certificate --quiet \
        https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz && \
        tar xzf ./boost_1_77_0.tar.gz && \
        cd ./boost_1_77_0 && \
        ./bootstrap.sh && \
        ./b2 install && \
        cd .. && \
        rm -rf ./boost_1_77_0
COPY . .
###########################################################################33
# FROM ubuntu

# WORKDIR /ManucatureStation_ws

# COPY manufacture_station/ /ManucatureStation_ws
# CMD ./build/mantis_interview
# sudo docker run -it 3da47df46d81186da8d39d63b47c0adfc958eb01f6b5f90192b874fa2966ef19
###################################################
