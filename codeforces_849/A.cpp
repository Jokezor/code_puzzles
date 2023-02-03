#include <iostream>
#include <stdio.h>

using namespace std;

void solution() {
  char c;
  cin >> c;
  bool found = false;

  string str = "codeforces";

  for (int i = 0; i < str.length(); i++) {
    if (c == str[i]) {
      found = true;
      break;
    }
  }

  if (found) {
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
