#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptDecryptFile(const string &filename, char key);
void encryptFile(const string &filename, char key);
void decryptFile(const string &filename, char key);

int main()
{
    string filename;
    char key;
    int choice;

    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter encryption/decryption key (single character): ";
    cin >> key;
    cout << "1. Encrypt\n2. Decrypt\nChoose an option: ";
    cin >> choice;

    if (choice == 1)
    {
        encryptFile(filename, key);
    }
    else if (choice == 2)
    {
        decryptFile(filename, key);
    }
    else
    {
        cout << "Invalid option." << endl;
    }

    return 0;
}

void encryptDecryptFile(const string &filename, char key)
{
    ifstream file(filename, ios::binary);
    ofstream outputFile(filename + (key ? ".enc" : ".dec"), ios::binary);
    char ch;

    while (file.get(ch))
    {
        outputFile.put(ch ^ key); // XOR operation for encryption/decryption
    }

    file.close();
    outputFile.close();
}

void encryptFile(const string &filename, char key)
{
    encryptDecryptFile(filename, key);
    cout << "File encrypted successfully." << endl;
}

void decryptFile(const string &filename, char key)
{
    encryptDecryptFile(filename, key);
    cout << "File decrypted successfully." << endl;
}
