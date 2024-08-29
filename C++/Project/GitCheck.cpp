#include <iostream>
#include <cstdlib> // For system()
#include <fstream>
#include <sstream>

using namespace std;

// Function to execute a command and capture its output
string executeCommand(const string &command)
{
    // Create a temporary file to store command output
    const char *tempFile = "temp_git_output.txt";
    string fullCommand = command + " > " + tempFile;

    // Execute the command
    system(fullCommand.c_str());

    // Read the output from the temporary file
    ifstream file(tempFile);
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    // Remove the temporary file
    // remove(tempFile);

    return buffer.str();
}

int main()
{
    // Check if the directory is a Git repository
    string gitStatus = executeCommand("git status --short");
    if (gitStatus.empty())
    {
        cout << "Not a git repository or no changes found." << endl;
        return 1;
    }

    // Display changes
    cout << "Changes in the repository:" << endl;
    cout << gitStatus << endl;

    // Show detailed changes with 'git diff'
    string gitDiff = executeCommand("git diff");
    if (!gitDiff.empty())
    {
        cout << "Detailed changes:" << endl;
        cout << gitDiff << endl;
    }
    else
    {
        cout << "No detailed changes found." << endl;
    }

    return 0;
}
