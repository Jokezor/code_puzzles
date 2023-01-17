#include <cctype>
#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

void solution() {
  // Go through the string s, if c is not the next possible char, then break.
  string s;
  string full_string = "Yes";

  cin >> s;

  for (int i = 0; i < 18; i++) {
    full_string += "Yes";
  }

  if (full_string.find(s) != string::npos) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int t;

  cin >> t;

  while (t) {
    solution();
    t--;
  }
}
