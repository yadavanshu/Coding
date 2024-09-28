# Use Maven to build the application
FROM maven:3.8.6-openjdk-11 AS builder
WORKDIR /app
COPY pom.xml .
COPY src ./src
RUN mvn clean package

# Use a slim JDK to run the application
FROM openjdk:11-jdk-slim
WORKDIR /app
COPY --from=builder /app/target/mock-data-generator-1.0-SNAPSHOT.jar /app/MockDataGenerator.jar
CMD ["java", "-jar", "MockDataGenerator.jar"]
