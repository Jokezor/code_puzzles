#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  string code;
  cin >> code;

  int cur = 1;
  int moves = 0;

  for (char c : code) {
    int pos = (c - '0');
    int diff;

    if (cur == 0 && pos != 0) {
      diff = abs(10 - pos);
    } else if (pos == 0 && cur != 0) {
      diff = abs(10 - cur);
    } else {
      diff = abs(pos - cur);
    }
    moves += (diff + 1);
    cur = pos;
  }

  cout << moves << "\n";

  // Solve the problem.
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
