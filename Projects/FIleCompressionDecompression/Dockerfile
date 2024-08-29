# Use an official Maven image to build the application
FROM maven:3.8.5-openjdk-17 AS build

# Set the working directory inside the container
WORKDIR /app

# Copy the project files
COPY src ./src
COPY pom.xml ./

# Build the Java application
RUN mvn clean package

# Use an official OpenJDK image to run the application
FROM openjdk:17-jdk-slim

# Set the working directory
WORKDIR /app

# Copy the built jar file from the build stage
COPY --from=build /app/target/FileCompressionDecompression-1.0-SNAPSHOT.jar ./FileCompressionDecompression.jar

# Command to run the application
CMD ["java", "-jar", "FileCompressionDecompression.jar"]
