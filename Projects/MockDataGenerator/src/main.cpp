#include <mysqlx/xdevapi.h>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
// Function to generate random names
string generateRandomName()
{
    vector<string> names = {"John", "Jane", "Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi"};
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, names.size() - 1);
    return names[dist(mt)] + to_string(dist(mt, uniform_int_distribution<int>(1, 99)));
}

// Function to generate random emails
string generateRandomEmail(const string &name)
{
    vector<string> domains = {"example.com", "test.com", "mockmail.com"};
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, domains.size() - 1);
    return name + "@" + domains[dist(mt)];
}

int main()
{
    try
    {
        // Database connection details from environment variables
        const string url = getenv("DB_URL");
        const string user = getenv("DB_USER");
        const string password = getenv("DB_PASSWORD");

        mysqlx::Session session(url, user, password);

        // Accessing the database
        mysqlx::Schema db = session.getSchema("your_database"); // Ensure this matches your MySQL database
        mysqlx::Table table = db.getTable("users");

        // Inserting 10 mock records
        for (int i = 0; i < 10; ++i)
        {
            string name = generateRandomName();
            string email = generateRandomEmail(name);
            table.insert("name", "email").values(name, email).execute();
        }

        cout << "Mock data generated and inserted successfully." << endl;
        session.close();
    }
    catch (const mysqlx::Error &err)
    {
        cerr << "MySQL Error: " << err.what() << endl;
        return 1;
    }
    catch (const exception &ex)
    {
        cerr << "Standard Exception: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown Exception." << endl;
        return 1;
    }
    return 0;
}
