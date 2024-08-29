import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Random;

public class MockDataGenerator {
    // Database connection details from environment variables
    private static final String URL = System.getenv("DB_URL"); // e.g., "jdbc:mysql://db:3306/your_database"
    private static final String USER = System.getenv("DB_USER");
    private static final String PASSWORD = System.getenv("DB_PASSWORD");

    public static void main(String[] args) {
        // Generate and insert 10 mock records
        for (int i = 0; i < 10; i++) {
            String name = generateRandomName();
            String email = generateRandomEmail(name);
            insertUserIntoDB(name, email);
        }
        System.out.println("Mock data generated and inserted into the database successfully.");
    }

    // Method to generate random names
    private static String generateRandomName() {
        String[] names = { "John", "Jane", "Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi" };
        return names[new Random().nextInt(names.length)] + new Random().nextInt(100);
    }

    // Method to generate random emails based on the name
    private static String generateRandomEmail(String name) {
        String[] domains = { "example.com", "test.com", "mockmail.com" };
        return name.toLowerCase() + "@" + domains[new Random().nextInt(domains.length)];
    }

    // Method to insert a user record into the database
    private static void insertUserIntoDB(String name, String email) {
        String sql = "INSERT INTO users (name, email) VALUES (?, ?)";

        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement preparedStatement = connection.prepareStatement(sql)) {

            preparedStatement.setString(1, name);
            preparedStatement.setString(2, email);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error inserting data into the database: " + e.getMessage());
        }
    }
}
