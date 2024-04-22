#include "Hangman.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <random>

using namespace std;

int main() {
    srand(time(0));

    vector<Themes> themeSelection = {
        {"Cities", {
            "Chicago", "LosAngeles", "Toronto", "Vancouver", "Moscow", "Amsterdam", "Manila", "Tokyo", "Nagasaki", "Sydney", "Coppenhagen", "Melbourn"
            }},

        {"Countries", {
            "Canada", "USA", "Japan", "Chile", "Portugal", "Spain", "Mexico", "Venuzuela", "France", "Egypt", "India", "Philippines", "Netherlands"
            }},

        {"Sports", {
            "Basketball", "Soccer", "Football", "Golf", "Aerobics", "Baseball", "Volleyball", "Boxing", "Snowboarding", "Swimming", "Tennis"
            }},

        {"Basketball Teams", {
            "Hawks", "Raptors", "Nuggets", "76ers", "Celtis", "Warriors", "Timberwolves", "Knicks", "Pistons", "Nets", "Mavericks", "Pacers",
            "Hornets", "Bulls", "Thunder", "Pelicans", "Bucks", "Cavaliers", "Lakers", "Suns", "Heat", "Kings", "Magic", "Rockets", "Clippers",
            "Wizards", "Trailblazers", "Jazz", "Grizzlies", "Spurs"
        }},
        {"Colours (Lower Amount)", {"Red", "Green", "Blue", "Yellow", "Purple", "Violet", "Orange"}}
    };

    bool playagain = true;











    while (playagain == true) {
    cout << "Hi Welcome to my project of hangman.\n\n\n\n Please choose which theme you would like to play!\n";
    for (size_t i = 0; i < themeSelection.size(); ++i) {
        cout << i + 1 << ". " << themeSelection[i].name << endl;
    }


    bool validChoice = false;
    while (!validChoice) {
         int themeChoice;
        cout << "To choose, Please type the number corresponding to the theme. Choice: ";
        cin >> themeChoice;
    
        if (themeChoice < 1 || themeChoice > themeSelection.size()) {
            cout << "invalid choice, enter number betwen 1 and " << themeSelection.size() << ".\n\n";
            
    } else {
         validChoice = true;
    }



    const Themes& chosenTheme = themeSelection[themeChoice - 1];

    int randomWord = rand() % chosenTheme.words.size();
    string secretWord = chosenTheme.words[randomWord];

    string guessWord(secretWord.length(), '_');
    cout << "\n\nWelcome to hangman. Your theme is " << chosenTheme.name << "\n\n\nYou Have 8 chances. Make it count." << endl;



    int attempts = 8;
    string guessletters;

    while (attempts > 0) {
        cout << "Guessed Word: " << guessWord << "\n";

        char guess;
        
        while (true) {
        cout << "Enter a letter: ";
        cin >> guess;
        guess = tolower(guess);

        if (guessletters.find(guess) != string::npos) {
            cout << "\nLetter has already been guessed!\n\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        else if (!isalpha(guess) || cin.peek() != '\n') {
            cout << "\nType one letter please!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            guessletters += guess;
            break;
        }

        }

        if (isLetterofWord(secretWord, guess)) {
            cout << "correct.\n\n\n";
            updateGuess(guessWord, secretWord, guess);
         } else {
            cout << "\nX. You have " << --attempts << " attempts left.\n\n\n";
        }

        if (guessWord == secretWord) {
            cout << "Congrats. You have guessed the word: " << secretWord << "\n\nGood Job! \n\n";
            break;
        }

          if (attempts == 0) {
        cout << "Sorry ran out of guesses. It was " << secretWord << ". Womp Womp.\n\n\n";
    }
   }
   
        cout << "Wanna try again? Press y to try again. To exit, press any key.";
        char playagainInput;
        cin >> playagainInput;
        cin.ignore();

        if (tolower(playagainInput) != 'y') {
            cout << "Play again soon! :)\n";
            playagain = false;
        } else {
            playagain = true;
        }
        }
    }
    return 0;
}