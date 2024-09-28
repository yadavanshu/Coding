# Use an official image with GCC and CMake
FROM ubuntu:22.04

# Install required packages
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    libmysqlcppconn-dev \
    mysql-client

# Set the working directory
WORKDIR /app

# Copy the project files
COPY . .

# Build the application
RUN cmake . && make

# Run the application
CMD ["./MockDataGenerator"]
