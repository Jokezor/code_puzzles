#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canPlaceWordInRow(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        if (col + i >= 10) return false;
        if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) return false;
    }
    return true;
}

bool canPlaceWordInCol(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        if (row + i >= 10) return false;
        if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) return false;
    }
    return true;
}

void placeWordInRow(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        crossword[row][col + i] = word[i];
    }
}

void placeWordInCol(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        crossword[row + i][col] = word[i];
    }
}

void removeWordFromRow(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        crossword[row][col + i] = '-';
    }
}

void removeWordFromCol(vector<string> &crossword, string word, int row, int col) {
    int m = word.length();
    for (int i = 0; i < m; ++i) {
        crossword[row + i][col] = '-';
    }
}

bool fillCrossWord(vector<string> words, int word_ind, vector<string> &crossword) {
    if (word_ind == words.size()) {
        return true;
    }

    string word = words[word_ind];
    int m = word.length();

    // Check each row to adjust
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (canPlaceWordInRow(crossword, word, row, col)) {
                placeWordInRow(crossword, word, row, col);
                if (fillCrossWord(words, word_ind + 1, crossword)) {
                    return true;
                }
                removeWordFromRow(crossword, word, row, col);
            }
            if (canPlaceWordInCol(crossword, word, row, col)) {
                placeWordInCol(crossword, word, row, col);
                if (fillCrossWord(words, word_ind + 1, crossword)) {
                    return true;
                }
                removeWordFromCol(crossword, word, row, col);
            }
        }
    }

    return false;
}

int main() {
    vector<string> crossword = {
        "+-++++++++",
        "+-++++++++",
        "+-------++",
        "+-++++++++",
        "+-++++++++",
        "+------+++",
        "+-+++-++++",
        "+++++-++++",
        "+++++-++++",
        "++++++++++"
    };

    vector<string> words = {"AGRA", "NORWAY", "ENGLAND", "GWALIOR"};

    if (fillCrossWord(words, 0, crossword)) {
        for (const auto &row : crossword) {
            cout << row << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
