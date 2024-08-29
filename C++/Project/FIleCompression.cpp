#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bitset>

using namespace std;

void compressFile(const string &filename);
void decompressFile(const string &filename);

int main()
{
    string filename;
    int choice;

    cout << "Enter filename: ";
    cin >> filename;
    cout << "1. Compress\n2. Decompress\nChoose an option: ";
    cin >> choice;

    if (choice == 1)
    {
        compressFile(filename);
    }
    else if (choice == 2)
    {
        decompressFile(filename);
    }
    else
    {
        cout << "Invalid option." << endl;
    }

    return 0;
}

// Simplified compression function (does not implement actual compression)
void compressFile(const string &filename)
{
    ifstream file(filename, ios::binary);
    ofstream compressedFile(filename + ".comp", ios::binary);
    char ch;

    while (file.get(ch))
    {
        // Example: Write raw data (replace with actual compression)
        compressedFile.put(ch);
    }

    file.close();
    compressedFile.close();
    cout << "File compressed successfully." << endl;
}

// Simplified decompression function (does not implement actual decompression)
void decompressFile(const string &filename)
{
    ifstream file(filename, ios::binary);
    ofstream decompressedFile(filename + ".decomp", ios::binary);
    char ch;

    while (file.get(ch))
    {
        // Example: Write raw data (replace with actual decompression)
        decompressedFile.put(ch);
    }

    file.close();
    decompressedFile.close();
    cout << "File decompressed successfully." << endl;
}
