# Use an official Ubuntu as a parent image
FROM ubuntu:18.04

# Set the working directory in the container
WORKDIR /usr/src/app

# Install GCC 7.2.0
RUN apt-get update && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y g++-7 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 10

# Copy the local header file to the container's working directory
COPY catch.hpp ./

# Copy the local source file to the container's working directory
COPY interval_map.cpp ./

# Set the GCC 7.2.0 as the default g++
RUN update-alternatives --set g++ /usr/bin/g++-7

# Command to compile the C++ program
RUN g++ -std=c++17 interval_map.cpp -o interval_map

# Command to run the program
CMD ["./interval_map"]
