#include <string>
#include <vector>

using namespace std;

struct Themes {
    string name;
    vector<string> words;
};

string toLowercase(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

bool isLetterofWord(const string& word, char letter) {
    return toLowercase(word).find(tolower(letter)) != string::npos;
}

void updateGuess(string& guessWord, const string& word, char letter) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (tolower(word[i]) == tolower(letter)) {
            guessWord[i] = word[i];
        }
    }
}
