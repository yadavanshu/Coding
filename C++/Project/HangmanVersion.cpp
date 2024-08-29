#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

const int MAX_TRIES = 5;

void welcomeMessage();
string getRandomWord(const vector<string> &words);
int letterFill(char guess, const string &secretWord, string &guessWord, set<char> &usedLetters);
void displayStatus(const string &unknown, int triesLeft, const set<char> &usedLetters);
char getValidGuess(const set<char> &usedLetters);
int getCategoryChoice();
vector<string> getWordsForCategory(int category);

int main()
{
    welcomeMessage();

    int categoryChoice = getCategoryChoice();
    vector<string> words = getWordsForCategory(categoryChoice);

    string word = getRandomWord(words);
    string unknown(word.length(), '*');
    set<char> usedLetters;

    int num_of_wrong_guesses = 0;

    while (num_of_wrong_guesses < MAX_TRIES)
    {
        displayStatus(unknown, MAX_TRIES - num_of_wrong_guesses, usedLetters);

        char letter = getValidGuess(usedLetters);

        if (letterFill(letter, word, unknown, usedLetters) == 0)
        {
            cout << "\nWhoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << "\nYou found a letter! Isn't that exciting!" << endl;
        }

        if (word == unknown)
        {
            cout << "\n"
                 << word << "\nYeah! You got it!" << endl;
            break;
        }
    }

    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        cout << "The word was: " << word << endl;
    }

    return 0;
}

void welcomeMessage()
{
    cout << "\n\nWelcome to hangman...Guess a word from your chosen category!";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try.";
    cout << "\n\nYou have " << MAX_TRIES << " tries to guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

int getCategoryChoice()
{
    int choice;
    cout << "\nChoose a category:";
    cout << "\n1. Countries";
    cout << "\n2. Mobile Phones";
    cout << "\n3. Harry Potter Characters";
    cout << "\n4. Programming Languages";
    cout << "\n5. Famous Scientists";
    cout << "\nEnter your choice (1-5): ";

    while (true)
    {
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid choice. Please enter a number between 1 and 5: ";
        }
        else
        {
            break;
        }
    }

    return choice;
}

vector<string> getWordsForCategory(int category)
{
    if (category == 1)
    {
        return {"india", "pakistan", "nepal", "malaysia", "philippines", "australia", "iran", "ethiopia", "oman", "indonesia"};
    }
    else if (category == 2)
    {
        return {"iphone", "samsung", "nokia", "oneplus", "xiaomi", "motorola", "huawei", "google", "sony", "lg"};
    }
    else if (category == 3)
    {
        return {"harry", "hermione", "ron", "dumbledore", "voldemort", "snape", "draco", "hagrid", "sirius", "lupin"};
    }
    else if (category == 4)
    {
        return {"python", "java", "cplusplus", "javascript", "ruby", "swift", "kotlin", "golang", "rust", "typescript"};
    }
    else
    {
        return {"einstein", "newton", "galileo", "curie", "darwin", "tesla", "hawking", "bohr", "fermi", "planck"};
    }
}

// string getRandomWord(const vector<string> &words)
// {
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> dis(0, words.size() - 1);
//     return words[dis(gen)];
// }

string getRandomWord(const vector<string> &words)
{
    srand(time(0));                          
    int randomIndex = rand() % words.size(); 
    return words[randomIndex];               
}

int letterFill(char guess, const string &secretWord, string &guessWord, set<char> &usedLetters)
{
    int matches = 0;
    int len = secretWord.length();

    for (int i = 0; i < len; i++)
    {
        if (guess == secretWord[i])
        {
            guessWord[i] = guess;
            matches++;
        }
    }

    return matches;
}

void displayStatus(const string &unknown, int triesLeft, const set<char> &usedLetters)
{
    cout << "\n\n"
         << unknown;
    cout << "\n\nYou have " << triesLeft << " guesses left.";
    cout << "\nUsed letters: ";
    for (char c : usedLetters)
    {
        cout << c << ' ';
    }
    cout << "\n";
}

char getValidGuess(const set<char> &usedLetters)
{
    char guess;
    while (true)
    {
        cout << "\nGuess a letter: ";
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess))
        {
            cout << "Invalid input. Please enter a letter." << endl;
        }
        else if (usedLetters.find(guess) != usedLetters.end())
        {
            cout << "You've already guessed that letter. Try again." << endl;
        }
        else
        {
            break;
        }
    }
    return guess;
}
