#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

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
  for (int row=0; row < 10; ++row) {
    for (int col=0; col < 10; ++col) {
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

vector<string> splitString(string s, string delimiter) {
  vector<string> split;

  size_t last = 0;
  size_t next = 0;

  while ((next = s.find(delimiter, last)) != string::npos) {
    split.push_back(s.substr(last, next-last));
    last = next + 1;
  }
  split.push_back(s.substr(last));

  return split;
  
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
  vector<string> words_arr = splitString(words, ";");

  // Manipulate with reference
  bool solved = fillCrossWord(words_arr, 0, crossword);

  // cout << solved << "\n";
  // for (string cross : crossword) {
  //   cout << cross << "\n";
  // }
  return crossword;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

