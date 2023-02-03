#include <iostream>
#include <stdio.h>

using namespace std;

void solution() {
  int n;
  string s;

  int pos[] = {0, 0};

  cin >> n;
  cin >> s;

  bool found = false;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U') {
      pos[1]++;
    }
    if (s[i] == 'D') {
      pos[1]--;
    }
    if (s[i] == 'R') {
      pos[0]++;
    }
    if (s[i] == 'L') {
      pos[0]--;
    }

    if (pos[0] == 1 && pos[1] == 1) {
      found = true;
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
