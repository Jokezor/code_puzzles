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

pair<bool, vector<string>> fillCrossWord(vector<string> words, int word_ind, vector<string> slots) {
  if (word_ind == words.size()) {
    return {true, slots};
  }

  string word = words[word_ind];
  int m = word.length();

  vector<string> local_slots = slots;

  cout << word << "\n";
  for (int slot_ind = 0; slot_ind < slots.size(); ++slot_ind) {
    string slot = slots[slot_ind];
    cout << slot_ind << "\n";
    if (slot.length() < m) {
      cout << slot.length() << ", " << m << "\n";
      continue;
    }
    for (int i=0; i < slot.length() - m + 1; ++i) {
      // Try and fit current word in slot
      for (int j=i; j < i+m; ++j) {
        if (local_slots[slot_ind][j] == '-') {
          local_slots[slot_ind][j] = word[j-i];
        }
      }
      cout << local_slots[slot_ind] << "\n";
      // The word fits, now check next word.
      if (local_slots[slot_ind].find(word) != string::npos) {
        pair<bool, vector<string>> res = fillCrossWord(words, word_ind+1, local_slots);

        if (res.first) {
          cout << "oi\n";
          return {true, res.second};
        }
        else {
          local_slots[slot_ind] = slots[slot_ind];
        }
      }
      else {
        // Reset the slot.
        local_slots[slot_ind] = slots[slot_ind];
      }

    }
  }
  // cout << "hm" << word_ind << "\n";
  // for (string slot : local_slots) {
  //   cout << slot << "\n";
  // }
  return {false, local_slots};

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

  size_t min_word = 10;
  for (string word : words_arr) {
    min_word = min(min_word, word.length());
  }

  vector<pair<pair<int, int>, string>> slots;

  // First check horizontal slots
  for (int row=0; row < 10; ++row) {
    string curr = "";
    int start = 100;
    int end = 0;
    for (int col=0; col < 10; ++col) {
      if (crossword[row][col] == '-') {
        curr += '-';
        start = min(start, col);
      }
      else if (curr.length() >= min_word) {
        end = col-1;
        slots.push_back({{start, end}, curr});
        curr = "";
      }
    }
    if (curr.length() >= min_word) {
      end = 9;
      slots.push_back({{start, end}, curr});
    }
  }

  int horizontal_slots = slots.size();

  for (int col=0; col < 10; ++col) {
    string curr = "";
    int start = 100;
    int end = 0;
    for (int row=0; row < 10; ++row) {
      if (crossword[row][col] == '-') {
        curr += '-';
        start = min(start, row);
      }
      else if (curr.length() >= min_word) {
        end = row-1;
        slots.push_back({{start, end}, curr});
        curr = "";
      }
    }
    if (curr.length() >= min_word) {
      end = 9;
      slots.push_back({{start, end}, curr});
    }
  }


  vector<string> raw_slots;

  for (pair<pair<int, int>, string> slot : slots) {
    raw_slots.push_back(slot.second);
  }

  // Vertical slots

  pair<bool, vector<string>> solved_slots = fillCrossWord(words_arr, 0, raw_slots);

  cout << solved_slots.first << "\n";

  for (string slot : solved_slots.second) {
    cout << slot << "\n";
  }


  // Add back slots

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

