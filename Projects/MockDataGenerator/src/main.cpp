#include <mysqlx/xdevapi.h>
#include <iostream>
#include <random>
#include <vector>

// Function to generate random names
std::string generateRandomName()
{
    std::vector<std::string> names = {"John", "Jane", "Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi"};
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, names.size() - 1);
    return names[dist(mt)] + std::to_string(dist(mt, std::uniform_int_distribution<int>(1, 99)));
}

// Function to generate random emails
std::string generateRandomEmail(const std::string &name)
{
    std::vector<std::string> domains = {"example.com", "test.com", "mockmail.com"};
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, domains.size() - 1);
    return name + "@" + domains[dist(mt)];
}

int main()
{
    try
    {
        // Database connection details from environment variables
        const std::string url = std::getenv("DB_URL");
        const std::string user = std::getenv("DB_USER");
        const std::string password = std::getenv("DB_PASSWORD");

        mysqlx::Session session(url, user, password);

        // Accessing the database
        mysqlx::Schema db = session.getSchema("your_database"); // Ensure this matches your MySQL database
        mysqlx::Table table = db.getTable("users");

        // Inserting 10 mock records
        for (int i = 0; i < 10; ++i)
        {
            std::string name = generateRandomName();
            std::string email = generateRandomEmail(name);
            table.insert("name", "email").values(name, email).execute();
        }

        std::cout << "Mock data generated and inserted successfully." << std::endl;
        session.close();
    }
    catch (const mysqlx::Error &err)
    {
        std::cerr << "MySQL Error: " << err.what() << std::endl;
        return 1;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Standard Exception: " << ex.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown Exception." << std::endl;
        return 1;
    }
    return 0;
}
